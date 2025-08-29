// App.jsx
import React, { useContext, useEffect, useRef, useState } from "react";
import * as THREE from "three";
import { Canvas } from "@react-three/fiber";
import { OrbitControls } from "@react-three/drei";
import RubiksTopBanner from "./RubiksBanner";
import Context from "./Context";
import { CubeContext } from "./Context";
import { Edges } from "@react-three/drei";
const DEFAULT_FACE = [
  ['N', 'N', 'N'],
  ['N', 'N', 'N'],
  ['N', 'N', 'N']
];

// Full Cubie component (place inside the same file where THREE & Edges are available).
// This version positions the outer <group> at [x,y,z] (so mainGroup.current.children have correct positions),
// preserves your existing sticker-mapping logic exactly, and has a defensive fallback.
function Cubie({
  pos,
  size = 0.98,
  face0Color = DEFAULT_FACE,
  face1Color = DEFAULT_FACE,
  face2Color = DEFAULT_FACE,
  face3Color = DEFAULT_FACE,
  face4Color = DEFAULT_FACE,
  face5Color = DEFAULT_FACE,
}) {
  const mesh = useRef();
  const [x, y, z] = pos;

  let stickerColors;

  // --- sticker mapping (kept exactly as you provided) ---
  if (x === 1 && y === 1 && z === 1) {
    stickerColors = [face1Color[0][0], 'N', face0Color[2][2], 'N', face2Color[0][2], 'N'];
  } else if (x === 1 && y === 1 && z === 0) {
    stickerColors = [face1Color[0][1], 'N', face0Color[1][2], 'N', 'N', 'N'];
  } else if (x === 1 && y === 1 && z === -1) {
    stickerColors = [face1Color[0][2], 'N', face0Color[0][2], 'N', 'N', face5Color[0][0]];
  } else if (x === 1 && y === 0 && z === 1) {
    stickerColors = [face1Color[1][0], 'N', 'N', 'N', face2Color[1][2], 'N'];
  } else if (x === 1 && y === 0 && z === 0) {
    stickerColors = [face1Color[1][1], 'N', 'N', 'N', 'N', 'N'];
  } else if (x === 1 && y === 0 && z === -1) {
    stickerColors = [face1Color[1][2], 'N', 'N', 'N', 'N', face5Color[1][0]];
  } else if (x === 1 && y === -1 && z === 1) {
    stickerColors = [face1Color[2][0], 'N', 'N', face3Color[0][2], face2Color[2][2], 'N'];
  } else if (x === 1 && y === -1 && z === 0) {
    stickerColors = [face1Color[2][1], 'N', 'N', face3Color[1][2], 'N', 'N'];
  } else if (x === 1 && y === -1 && z === -1) {
    stickerColors = [face1Color[2][2], 'N', 'N', face3Color[2][2], 'N', face5Color[2][0]];
  } else if (x === 0 && y === 1 && z === 1) {
    stickerColors = ['N', 'N', face0Color[2][1], 'N', face2Color[0][1], 'N'];
  } else if (x === 0 && y === 1 && z === 0) {
    stickerColors = ['N', 'N', face0Color[1][1], 'N', 'N', 'N'];
  } else if (x === 0 && y === 1 && z === -1) {
    stickerColors = ['N', 'N', face0Color[0][1], 'N', 'N', face5Color[0][1]];
  } else if (x === 0 && y === 0 && z === 1) {
    stickerColors = ['N', 'N', 'N', 'N', face2Color[1][1], 'N'];
  } else if (x === 0 && y === 0 && z === 0) {
    stickerColors = ['N', 'N', 'N', 'N', 'N', 'N'];
  } else if (x === 0 && y === 0 && z === -1) {
    stickerColors = ['N', 'N', 'N', 'N', 'N', face5Color[1][1]];
  } else if (x === 0 && y === -1 && z === 1) {
    stickerColors = ['N', 'N', 'N', face3Color[0][1], face2Color[2][1], 'N'];
  } else if (x === 0 && y === -1 && z === 0) {
    stickerColors = ['N', 'N', 'N', face3Color[1][1], 'N', 'N'];
  } else if (x === 0 && y === -1 && z === -1) {
    stickerColors = ['N', 'N', 'N', face3Color[2][1], 'N', face5Color[2][1]];
  } else if (x === -1 && y === 1 && z === 1) {
    stickerColors = ['N', face4Color[0][2], face0Color[2][0], 'N', face2Color[0][0], 'N'];
  } else if (x === -1 && y === 1 && z === 0) {
    stickerColors = ['N', face4Color[0][1], face0Color[1][0], 'N', 'N', 'N'];
  } else if (x === -1 && y === 1 && z === -1) {
    stickerColors = ['N', face4Color[0][0], face0Color[0][0], 'N', 'N', face5Color[0][2]];
  } else if (x === -1 && y === 0 && z === 1) {
    stickerColors = ['N', face4Color[1][2], 'N', 'N', face2Color[1][0], 'N'];
  } else if (x === -1 && y === 0 && z === 0) {
    stickerColors = ['N', face4Color[1][1], 'N', 'N', 'N', 'N'];
  } else if (x === -1 && y === 0 && z === -1) {
    stickerColors = ['N', face4Color[1][0], 'N', 'N', 'N', face5Color[1][2]];
  } else if (x === -1 && y === -1 && z === 1) {
    stickerColors = ['N', face4Color[2][2], 'N', face3Color[0][0], face2Color[2][0], 'N'];
  } else if (x === -1 && y === -1 && z === 0) {
    stickerColors = ['N', face4Color[2][1], 'N', face3Color[1][0], 'N', 'N'];
  } else if (x === -1 && y === -1 && z === -1) {
    stickerColors = ['N', face4Color[2][0], 'N', face3Color[2][0], 'N', face5Color[2][2]];
  }

  // Defensive fallback so we never call .map on undefined
  if (!Array.isArray(stickerColors)) {
    console.warn("Cubie: stickerColors undefined for pos", pos, "— falling back to all 'N'");
    stickerColors = ['N', 'N', 'N', 'N', 'N', 'N'];
  }

  const colorMap = {
    'N': '#222222', // gap / no-sticker color (dark)
    'R': '#FF0000',
    'G': '#00C000',
    'B': '#0000FF',
    'W': '#FFFFFF',
    'Y': '#FFD500',
    'O': '#FF8A00',
  };

  const boxArgs = [size, size, size];

  return (
    // Position the whole cubie group so mainGroup.current.children reflect [x,y,z]
    <group position={[x, y, z]}>
      {/* slightly larger back-faced box to create bold black outline between cubies */}
      <mesh scale={[1.03, 1.03, 1.03]}>
        <boxGeometry args={boxArgs} />
        <meshBasicMaterial color="#000000" side={THREE.BackSide} />
      </mesh>

      {/* actual cubie (centered at the group's origin) */}
      <mesh ref={mesh}>
        <boxGeometry args={boxArgs} />

        {/* per-face sticker materials (order: 0..5 corresponds to three.js box faces) */}
        {stickerColors.map((color, i) => (
          <meshStandardMaterial
            key={i}
            attach={`material-${i}`}
            color={colorMap[color] ?? '#000000'}
            flatShading={true}
            roughness={0.35}
            metalness={0.02}
            polygonOffset={true}
            polygonOffsetFactor={1}
            polygonOffsetUnits={1}
          />
        ))}

        {/* crisp vector edges */}
        <Edges threshold={15} color="black" />
      </mesh>
    </group>
  );
}


function RubiksCube({ mainGroup , face0Color, face1Color, face2Color, face3Color, face4Color, face5Color }) {
  const positions = [];
  const step = 1;
  for (let xi = -1; xi <= 1; xi++) {
    for (let yi = -1; yi <= 1; yi++) {
      for (let zi = -1; zi <= 1; zi++) {
        positions.push([xi * step, yi * step, zi * step]);
      }
    }
  }

  return (
    <group ref={mainGroup}>
      {positions.map((p, i) => (
        <Cubie key={i} pos={p} face0Color={face0Color} face1Color={face1Color} face2Color={face2Color} face3Color={face3Color} face4Color={face4Color} face5Color={face5Color} />
      ))}
    </group>
  );
}




export default function Solution() {
  const mainGroup = useRef();
  const [index,setIndex]=useState(0);
    // const { solutionMoves, setSolutionMoves, face0Color, setFace0Color, face1Color, setFace1Color, face2Color, setFace2Color, face3Color, setFace3Color, face4Color, setFace4Color, face5Color, setFace5Color } = useContext(CubeContext);
const [solutionMoves, setSolutionMoves] = useState([]);
 const [isRotating, setIsRotating] = useState(false);
    const isRotatingRef = useRef(false);
    const [isAnimation,setIsAnimation]=useState(false);
  const [faces, setFaces] = useState({});
  // Add these refs and helpers near the top with your other useState/useRef
const indexRef = useRef(index);           // keep latest index for async loop
const isAnimationRef = useRef(false);     // control flag for animation loop
const animationDelayMs = 1200;            // time between steps (tweak this)

// keep indexRef synced
useEffect(() => {
  indexRef.current = index;
}, [index]);

// cleanup on unmount (stop animation if component unmounts)
useEffect(() => {
  return () => {
    isAnimationRef.current = false;
  };
}, []);

 useEffect(() => {
    const data = localStorage.getItem("cubeState");
    if (data) {
      const parsed = JSON.parse(data);

      // restore solution moves
      setSolutionMoves(parsed.solutionMoves || []);

      // restore all faces as matrices
      setFaces({
        face0: parsed.face0Color || [],
        face1: parsed.face1Color || [],
        face2: parsed.face2Color || [],
        face3: parsed.face3Color || [],
        face4: parsed.face4Color || [],
        face5: parsed.face5Color || []
      });
    }
  }, []);

  // helper: animate a group's rotation around Y over duration (ms)
  function animateGroupRotation(group, axis = "y", angle = Math.PI / 2, duration = 300) {
    return new Promise((resolve) => {
      const start = performance.now();
      const startAngle = group.rotation[axis];
      function step(now) {
        const t = Math.min(1, (now - start) / duration);
        group.rotation[axis] = startAngle + angle * t;
        group.updateMatrixWorld(true);
        if (t < 1) requestAnimationFrame(step);
        else resolve();
      }
      requestAnimationFrame(step);
    });
  }


  const oppositeMoveMap = {
  "U": "U'",
  "U'": "U",
  "U2": "U2",

  "D": "D'",
  "D'": "D",
  "D2": "D2",

  "L": "L'",
  "L'": "L",
  "L2": "L2",

  "R": "R'",
  "R'": "R",
  "R2": "R2",

  "F": "F'",
  "F'": "F",
  "F2": "F2",

  "B": "B'",
  "B'": "B",
  "B2": "B2"
};

function beginRotate() {
    isRotatingRef.current = true;
    setIsRotating(true);
  }
  function endRotate() {
    isRotatingRef.current = false;
    setIsRotating(false);
  }






  // Map move -> { axis, layerCoord, angle }
const MOVE_MAP = {
  U:  { axis: "y", coord:  1, angle: -Math.PI / 2 },
  "U'": { axis: "y", coord:  1, angle: Math.PI / 2 },
  U2: { axis: "y", coord:  1, angle:  Math.PI },

  D:  { axis: "y", coord: -1, angle: Math.PI / 2 },
  "D'": { axis: "y", coord: -1, angle:  -Math.PI / 2 },
  D2: { axis: "y", coord: -1, angle:  Math.PI },

  L:  { axis: "x", coord: -1, angle:  Math.PI / 2 },
  "L'": { axis: "x", coord: -1, angle: -Math.PI / 2 },
  L2: { axis: "x", coord: -1, angle:  Math.PI },

  R:  { axis: "x", coord:  1, angle: -Math.PI / 2 },
  "R'": { axis: "x", coord:  1, angle:  Math.PI / 2 },
  R2: { axis: "x", coord:  1, angle:  Math.PI },

  F:  { axis: "z", coord:  1, angle: -Math.PI / 2 },
  "F'": { axis: "z", coord:  1, angle:  Math.PI / 2 },
  F2: { axis: "z", coord:  1, angle:  Math.PI },

  B:  { axis: "z", coord: -1, angle:  Math.PI / 2 },
  "B'": { axis: "z", coord: -1, angle: -Math.PI / 2 },
  B2: { axis: "z", coord: -1, angle:  Math.PI },
};

async function rotateLayer(move) {
  if (!mainGroup.current) return;

  const config = MOVE_MAP[move];
  if (!config) return; // invalid move

  const { axis, coord, angle } = config;
  const epsilon = 0.0001;

  // pick cubies in that face layer
  const layer = mainGroup.current.children.filter(cubie => {
    if (axis === "x") return Math.abs(cubie.position.x - coord) < epsilon;
    if (axis === "y") return Math.abs(cubie.position.y - coord) < epsilon;
    if (axis === "z") return Math.abs(cubie.position.z - coord) < epsilon;
    return false;
  });

  if (layer.length === 0) return;

  // create temp pivot group
  const tempGroup = new THREE.Group();
  mainGroup.current.add(tempGroup);
  layer.forEach(cubie => tempGroup.attach(cubie));

 const baseDuration = 500;
const duration = baseDuration * (Math.abs(angle) / (Math.PI / 2));
  await animateGroupRotation(tempGroup, axis, angle, duration);

  // snap back to grid
  const worldPos = new THREE.Vector3();
  layer.forEach(cubie => {
    cubie.getWorldPosition(worldPos);
    const snapped = new THREE.Vector3(
      Math.round(worldPos.x),
      Math.round(worldPos.y),
      Math.round(worldPos.z)
    );
    mainGroup.current.attach(cubie);
    mainGroup.current.worldToLocal(snapped);
    cubie.position.copy(snapped);
    cubie.updateMatrix();
  });

  mainGroup.current.remove(tempGroup);
  endRotate();
}




  


// Make handleNext async and await the rotateLayer so steps never overlap
async function handleNext() {
  if (isRotatingRef.current) return; // already rotating
  if (!solutionMoves || indexRef.current >= solutionMoves.length) return;

  beginRotate();
  await rotateLayer(solutionMoves[indexRef.current]); // waits until finished
  setIndex(prev => {
    const next = prev + 1;
    indexRef.current = next; // keep ref up-to-date
    return next;
  });
}

// Make handlePrev async similarly
async function handlePrev() {
  if (isRotatingRef.current) return;
  if (!solutionMoves || indexRef.current <= 0) return;

  beginRotate();
  await rotateLayer(oppositeMoveMap[solutionMoves[indexRef.current - 1]]);
  setIndex(prev => {
    const next = Math.max(0, prev - 1);
    indexRef.current = next;
    return next;
  });
}



// New: an async loop that steps through the moves one-by-one
async function runAnimationLoop() {
  // keep running while flag is true and we have moves left
  while (isAnimationRef.current && indexRef.current < (solutionMoves?.length || 0)) {
    // if a rotation is already in progress, wait a bit and retry
    if (isRotatingRef.current) {
      await new Promise(r => setTimeout(r, 50));
      continue;
    }

    // start and await a rotation
    beginRotate();
    await rotateLayer(solutionMoves[indexRef.current]);

    // advance index after rotation
    setIndex(prev => {
      const next = prev + 1;
      indexRef.current = next;
      return next;
    });

    // small pause between moves (tweak animationDelayMs)
    await new Promise(r => setTimeout(r, animationDelayMs));
  }

  // when finished (or stopped), make sure UI reflects stopped state
  isAnimationRef.current = false;
  setIsAnimation(false);
}


   // Toggle animation: start or stop
function handleAnimation() {
  if (isAnimationRef.current) {
    // stop
    isAnimationRef.current = false;
    setIsAnimation(false);
  } else {
    // start
    if (!solutionMoves || solutionMoves.length === 0) return;
    isAnimationRef.current = true;
    setIsAnimation(true);
    // start loop (no await here so UI remains responsive)
    runAnimationLoop();
  }
}


 

  return (
   /* Updated JSX to:
   - remove vertical scrollbar on moves list
   - ensure floating control bar is above canvas (z-50)
   - remove redundant Prev/Next buttons on right panel (only animation button left)
   All Tailwind classes forced with ! for your setup.
*/
<div className="!min-h-screen !w-screen !bg-gradient-to-br !from-indigo-50 !via-pink-50 !to-amber-50 !p-6">
  <div className="!max-w-6xl !mx-auto !flex !flex-col !gap-6">
    {/* Cube Card */}
    <div className="!relative !bg-white/80 !backdrop-blur-md !rounded-3xl !p-4 !shadow-2xl !border !border-white/30">
      {/* Moves Counter Badge */}
      <div className="!absolute !top-4 !right-4 !z-50">
        <div className="!inline-flex !items-center !gap-2 !bg-gradient-to-r !from-violet-500 !to-pink-500 !text-white !px-3 !py-2 !rounded-full !shadow-lg">
          <svg className="!w-4 !h-4" viewBox="0 0 24 24" fill="none" stroke="currentColor">
            <path strokeWidth="1.6" strokeLinecap="round" strokeLinejoin="round" d="M12 6v6l4 2" />
          </svg>
          <div className="!text-sm !font-medium">
            {solutionMoves && solutionMoves.length ? `${index} / ${solutionMoves.length}` : "0 / 0"}
          </div>
        </div>
      </div>

      {/* Cube */}
      <div className="!flex !flex-col !items-center !justify-center !gap-6">
        <div className="!w-full !rounded-2xl !overflow-hidden !border !border-slate-200 !bg-white">
          <div className="!h-[72vh] sm:!h-[76vh] !relative">
            
<Canvas
  camera={{ position: [4, 4, 12], fov: 50 }}

  className="!w-full !h-full !bg-transparent"
>
  <ambientLight intensity={1.1} />
  <hemisphereLight skyColor={0xffffff} groundColor={0xffffff} intensity={0.6} />
  <directionalLight position={[10, 10, 10]} intensity={0.6} />
  <directionalLight position={[-10, -10, -10]} intensity={0.4} />

  <RubiksCube
    mainGroup={mainGroup}
    face0Color={faces.face0}
    face1Color={faces.face1}
    face2Color={faces.face2}
    face3Color={faces.face3}
    face4Color={faces.face4}
    face5Color={faces.face5}
  />

  
</Canvas>
          </div>
        </div>
      </div>
    </div>

    {/* Control Dock */}
    <div className="!bg-white/95 !backdrop-blur-md !border !border-slate-100 !rounded-3xl !shadow-2xl !p-4 !flex !items-center !justify-between !gap-6">
      {/* Prev Button */}
      <button
        onClick={handlePrev}
        className="!flex !items-center !gap-2 !px-5 !py-2 !rounded-full !bg-slate-100 hover:!bg-slate-200 !text-slate-800 !font-semibold !shadow-sm"
      >
        <svg className="!w-4 !h-4" viewBox="0 0 24 24" fill="none" stroke="currentColor">
          <polyline points="15 18 9 12 15 6" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round" />
        </svg>
        Prev
      </button>

      {/* Step Info */}
      <div className="!flex-1 !flex !flex-col !items-center !px-3">
        <div className="!text-xs !text-slate-500">Step</div>
        <div className="!mt-2 !inline-flex !items-center !gap-3">
          <div className="!px-3 !py-1 !rounded-full !bg-gradient-to-r !from-indigo-600 !to-violet-500 !text-white !font-semibold">
            {solutionMoves && solutionMoves.length ? `${index} / ${solutionMoves.length}` : "0 / 0"}
          </div>
          <div className="!text-sm sm:!text-base !text-slate-700 !font-medium">
            {solutionMoves && solutionMoves.length ? solutionMoves[index] : "—"}
          </div>
        </div>

        <div className="!w-full !mt-3 !h-2 !bg-slate-200 !rounded-full !overflow-hidden">
          <div
            className="!h-2 !rounded-full !bg-gradient-to-r !from-emerald-400 !to-teal-400 !transition-all"
            style={{ width: solutionMoves && solutionMoves.length ? `${((index) / solutionMoves.length) * 100}%` : "0%" }}
          />
        </div>
      </div>

      {/* Next Button */}
      <button
        onClick={handleNext}
        className="!flex !items-center !gap-2 !px-5 !py-2 !rounded-full !bg-emerald-600 hover:!bg-emerald-700 !text-white !font-semibold !shadow-sm"
      >
        Next
        <svg className="!w-4 !h-4" viewBox="0 0 24 24" fill="none" stroke="currentColor">
          <polyline points="9 18 15 12 9 6" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round" />
        </svg>
      </button>
    </div>

    {/* Animation Toggle */}
    <div className="!flex !items-center !gap-3 !mt-2 !justify-center">
      <button
        onClick={handleAnimation}
        className={`!px-6 !py-2.5 !rounded-full !text-white !font-semibold transition-shadow !shadow ${isAnimation ? '!bg-rose-500 hover:!bg-rose-600' : '!bg-indigo-600 hover:!bg-indigo-700'}`}
      >
        {isAnimation ? 'Stop Animation' : 'Start Animation'}
      </button>
    </div>
  </div>
</div>


  );
}
