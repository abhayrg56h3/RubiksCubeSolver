const CUBE_GEOMETRY = {
    corners: {
        URF: { U: 8,  R: 11, F: 20 }, UFL: { U: 6,  F: 18, L: 38 },
        ULB: { U: 0,  L: 36, B: 47 }, UBR: { U: 2,  B: 45, R: 9  },
        DFR: { D: 32, F: 26, R: 17 }, DLF: { D: 30, L: 44, F: 24 },
        DBL: { D: 28, B: 53, L: 42 }, DRB: { D: 34, R: 15, B: 51 }
    },
    edges: {
        UR: { U: 5, R: 10 }, UF: { U: 7, F: 19 }, UL: { U: 3, L: 37 }, UB: { U: 1, B: 46 },
        DR: { D: 31, R: 16 }, DF: { D: 29, F: 25 }, DL: { D: 33, L: 43 }, DB: { D: 27, B: 52 },
        FR: { F: 23, R: 14 }, FL: { F: 21, L: 41 }, BR: { B: 48, R: 12 }, BL: { B: 50, L: 39 }
    },
    centers: {
        U: 4, R: 13, F: 22, D: 31, L: 40, B: 49
    }
};

function checkFormat(state) {
    if (state.length !== 54) {
        return { valid: false, message: `Invalid length. Expected 54, got ${state.length}.` };
    }

    const centerIndices = [4, 13, 22, 31, 40, 49];
    const centerColors = new Set(centerIndices.map(i => state[i]));

    if (centerColors.size !== 6) {
        return { valid: false, message: "Center pieces must define 6 unique colors." };
    }

    const counts = {};
    centerColors.forEach(c => counts[c] = 0);

    for (const char of state) {
        if (!centerColors.has(char)) {
            return { valid: false, message: `Invalid character '${char}' found. It does not match any of the 6 center colors.` };
        }
        counts[char]++;
    }

    for (const color in counts) {
        if (counts[color] !== 9) {
            return { valid: false, message: `Incorrect color count for '${color}'. Expected 9, found ${counts[color]}.` };
        }
    }

    return { valid: true, message: "Length, characters, and color counts are correct." };
}

function getPiece(state, pieceType, pieceName) {
    const indices = CUBE_GEOMETRY[pieceType][pieceName];
    const piece = {};
    for (const face in indices) {
        piece[face] = state[indices[face]];
    }
    return piece;
}

function findPiece(state, colorsToFind) {
    const sortedColors = [...colorsToFind].sort().join('');
    for (const pieceType of ['corners', 'edges']) {
        for (const pieceName in CUBE_GEOMETRY[pieceType]) {
            const piece = getPiece(state, pieceType, pieceName);
            const currentColors = Object.values(piece).sort().join('');
            if (currentColors === sortedColors) {
                return { type: pieceType, name: pieceName };
            }
        }
    }
    return null;
}

function getPermutationSwaps(state, pieceType, pieceNames) {
    const permutation = {};
    for (const name of pieceNames) {
        const solvedColors = name.split('');
        const foundLocation = findPiece(state, solvedColors);
        if (!foundLocation) return pieceNames.length; 
        permutation[name] = foundLocation.name;
    }
    const visited = new Set();
    let cycles = 0;
    for (const pieceName of pieceNames) {
        if (!visited.has(pieceName)) {
            cycles++;
            let current = pieceName;
            while (!visited.has(current)) {
                visited.add(current);
                current = permutation[current];
            }
        }
    }
    return pieceNames.length - cycles;
}

function checkPermutationParity(state) {
    let cornerSwaps = getPermutationSwaps(state, 'corners', Object.keys(CUBE_GEOMETRY.corners));
    let edgeSwaps = getPermutationSwaps(state, 'edges', Object.keys(CUBE_GEOMETRY.edges));
    const cornerParity = cornerSwaps % 2;
    const edgeParity = edgeSwaps % 2;
    if (cornerParity === edgeParity) {
        return { valid: true, message: `Parity matches (Corners: ${cornerSwaps} swaps, Edges: ${edgeSwaps} swaps).` };
    }
    return { valid: false, message: `Parity mismatch (Corners: ${cornerSwaps} swaps, Edges: ${edgeSwaps} swaps).` };
}

function checkEdgeFlips(state) {
    let totalFlip = 0;
    for (const edgeName in CUBE_GEOMETRY.edges) {
        const piece = getPiece(state, 'edges', edgeName);
        const faces = Object.keys(piece);
        let flip = 0;
        const onUDLayer = faces.some(f => f === 'U' || f === 'D');
        if (onUDLayer) {
            const UDFace = faces.find(f => f === 'U' || f === 'D');
            const stickerColor = piece[UDFace];
            if (stickerColor !== 'U' && stickerColor !== 'D') {
                flip = 1;
            }
        } else {
            const FBFace = faces.find(f => f === 'F' || f === 'B');
            const stickerColor = piece[FBFace];
            if (stickerColor === 'L' || stickerColor === 'R') {
                flip = 1;
            }
        }
        totalFlip += flip;
    }
    if (totalFlip % 2 === 0) {
        return { valid: true, message: `Total edge flips is ${totalFlip} (even).` };
    }
    return { valid: false, message: `Total edge flips is ${totalFlip} (odd).` };
}

function checkCornerTwists(state) {
    let totalTwist = 0;
    for (const cornerName in CUBE_GEOMETRY.corners) {
        const piece = getPiece(state, 'corners', cornerName);
        const UDFace = Object.keys(piece).find(f => f === 'U' || f === 'D');
        const stickerColor = piece[UDFace];
        if (stickerColor === 'U' || stickerColor === 'D') {
            totalTwist += 0;
        } else {
            const faceOrder = cornerName.split('');
            const udIndex = faceOrder.indexOf(UDFace);
            const stickerOnFace = Object.keys(piece).find(key => piece[key] === 'U' || piece[key] === 'D');
            const stickerIndex = faceOrder.indexOf(stickerOnFace);
            let twist = (stickerIndex - udIndex + 3) % 3;
            totalTwist += twist;
        }
    }
    if (totalTwist % 3 === 0) {
        return { valid: true, message: `Total corner twist is ${totalTwist} (divisible by 3).` };
    }
    return { valid: false, message: `Total corner twist is ${totalTwist} (not divisible by 3).` };
}

export const validateRubiksCubeState = (stateString) => {
    const state = stateString.trim().toUpperCase();
    const checks = [];
    const formatCheck = checkFormat(state);
    checks.push({ name: "Format & Colors", ...formatCheck });
    if (!formatCheck.valid) {
        return {
            isSolvable: false,
            checks: checks
        };
    }
    const colorToFaceMap = {};
    colorToFaceMap[state[4]] = 'U';
    colorToFaceMap[state[13]] = 'R';
    colorToFaceMap[state[22]] = 'F';
    colorToFaceMap[state[31]] = 'D';
    colorToFaceMap[state[40]] = 'L';
    colorToFaceMap[state[49]] = 'B';
    const abstractState = state.split('').map(color => colorToFaceMap[color] || 'N').join('');
    const parityCheck = checkPermutationParity(abstractState);
    checks.push({ name: "Permutation Parity", ...parityCheck });
    const edgeFlipCheck = checkEdgeFlips(abstractState);
    checks.push({ name: "Edge Orientation", ...edgeFlipCheck });
    const cornerTwistCheck = checkCornerTwists(abstractState);
    checks.push({ name: "Corner Orientation", ...cornerTwistCheck });
    const isSolvable = formatCheck.valid && parityCheck.valid && edgeFlipCheck.valid && cornerTwistCheck.valid;
    return {
        isSolvable,
        checks
    };
};

