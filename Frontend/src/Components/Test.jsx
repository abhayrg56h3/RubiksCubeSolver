


// src/CubeScanner.jsx (REVISED with Pre-Trained Color Model)

import React, { useContext,useCallback, useEffect, useRef, useState } from "react";
import * as THREE from "three";
import { Canvas, useFrame } from "@react-three/fiber";
import { OrbitControls } from "@react-three/drei";
import RubiksTopBanner from "./RubiksBanner";
import Context, { CubeContext } from "./Context";
import axios from "axios";

import { Edges } from "@react-three/drei";
import { useNavigate } from "react-router-dom";

// Put this near top of file (once)
const DEFAULT_FACE = [
  ['N', 'N', 'N'],
  ['N', 'N', 'N'],
  ['N', 'N', 'N']
];

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

  // --- keep your exact mapping logic (unchanged) ---
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

  // defensive fallback so we never do undefined.map()
  if (!Array.isArray(stickerColors)) {
    console.warn('Cubie: stickerColors undefined for pos', pos, '— falling back to all N');
    stickerColors = ['N', 'N', 'N', 'N', 'N', 'N'];
  }

  const colorMap = {
    // make 'N' very dark so gaps look like black lines
    'N': '#222222',
    'R': '#FF0000',
    'G': '#00C000',
    'B': '#0000FF',
    'W': '#FFFFFF',
    'Y': '#FFD500',
    'O': '#FF8A00',
  };

  useEffect(() => {
    if (!mesh.current) return;
    mesh.current.position.set(x, y, z);
  }, [x, y, z]);

  // geometry reused per cubie
  const boxArgs = [size, size, size];

  return (
    <group>
      {/* Slightly larger back-faced box to create bold black outline between cubies */}
      <mesh
        position={[x, y, z]}
        scale={[1.03, 1.03, 1.03]}
      >
        <boxGeometry args={boxArgs} />
        <meshBasicMaterial color="#000000" side={THREE.BackSide} />
      </mesh>

      {/* actual cubie */}
      <mesh ref={mesh}>
        <boxGeometry args={boxArgs} />

        {/* per-face sticker materials (keeps your mapping/logic exactly) */}
        {(stickerColors || ['N', 'N', 'N', 'N', 'N', 'N']).map((color, i) => (
          <meshStandardMaterial
            key={i}
            attach={`material-${i}`}
            color={colorMap[color] ?? '#000000'}
            flatShading={true}
            roughness={0.35}        // slight gloss
            metalness={0.02}
            polygonOffset={true}
            polygonOffsetFactor={1}
            polygonOffsetUnits={1}
          />
        ))}

        {/* thin vector edges for crisp look */}
        <Edges threshold={15} color="black" />

      </mesh>
    </group>
  );
}



function RubiksCube({ mainGroup, face0Color, face1Color, face2Color, face3Color, face4Color, face5Color }) {
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

function RotatingCube({
  rotateTrigger,
  setRotateTrigger,
  isRotating,
  setIsRotating,
  direction,
  face0Color,
  face1Color,
  face2Color,
  face3Color,
  face4Color,
  face5Color,
  onRotationComplete 
}) {
  const group = useRef();
  const targetRotation = useRef([0, 0, 0]); // [x, y, z]
  const wasMoving = useRef(false);

  // helper to snap angle to nearest 90deg multiple
  const snapTo90 = (angle) => {
    const step = Math.PI / 2;
    return Math.round(angle / step) * step;
  };

  useEffect(() => {
    if (rotateTrigger) {
      // update targetRotation depending on direction mapping (same mapping you had)
      if (direction === 1) { // Clockwise Y
        targetRotation.current[1] += Math.PI / 2;
      } else if (direction === -1) { // Anti-clockwise Y
        targetRotation.current[1] -= Math.PI / 2;
      } else if (direction === 2) { // X +90
        targetRotation.current[0] += Math.PI / 2;
      } else if (direction === -2) { // X -180? (you used -Math.PI earlier)
        targetRotation.current[0] -= Math.PI;
      } else if (direction === 3) {
        targetRotation.current[0] += Math.PI;
      } else if (direction === -3) {
        targetRotation.current[0] -= Math.PI / 2;
      }
      // mark as moving
      wasMoving.current = true;
      // reset trigger for next time
      setRotateTrigger(false);
    }
  }, [rotateTrigger, direction, setRotateTrigger]);

  useFrame(() => {
    if (!group.current) return;

    // Smoothly interpolate each axis separately toward targetRotation
    const lerpFactor = 0.12;
    let anyMoving = false;
    ["x", "y", "z"].forEach((axis, i) => {
      const current = group.current.rotation[axis];
      const target = targetRotation.current[i];
      const diff = target - current;
      if (Math.abs(diff) > 0.001) {
        anyMoving = true;
        group.current.rotation[axis] = current + diff * lerpFactor;
      } else {
        // small diff -> snap to exact target to avoid drift
        group.current.rotation[axis] = target;
      }
    });

    if (anyMoving) {
      wasMoving.current = true;
    } else if (wasMoving.current) {
      // rotation just finished (we were moving, now all diffs tiny)
      wasMoving.current = false;

      // snap rotations to exact multiples of 90deg to avoid float drift
      group.current.rotation.x = snapTo90(group.current.rotation.x);
      group.current.rotation.y = snapTo90(group.current.rotation.y);
      group.current.rotation.z = snapTo90(group.current.rotation.z);

      // also snap targetRotation to same multiples (keeps them in sync)
      targetRotation.current[0] = group.current.rotation.x;
      targetRotation.current[1] = group.current.rotation.y;
      targetRotation.current[2] = group.current.rotation.z;

      // notify parent that visual rotation finished
      if (typeof onRotationComplete === "function") {
        onRotationComplete();
      }
    }
  });

  return (
    <group ref={group}>
      <RubiksCube
        mainGroup={null}
        face0Color={face0Color}
        face1Color={face1Color}
        face2Color={face2Color}
        face3Color={face3Color}
        face4Color={face4Color}
        face5Color={face5Color}
      />
    </group>
  );
}



function DisplayFace({ currentColorMatrix, currentColor, orientation, onStickerClick }) {
  const orientationMap = {
    0: [0, 1, 2, 3, 4, 5, 6, 7, 8],
    1: [2, 5, 8, 1, 4, 7, 0, 3, 6],
    2: [8, 7, 6, 5, 4, 3, 2, 1, 0],
    3: [6, 3, 0, 7, 4, 1, 8, 5, 2]
  };

  const mapIndices = orientationMap[orientation];

  // Flatten face to 1D array
  const flatFace = currentColorMatrix.flat();

  // Remap colors for rendering
  const remappedColors = mapIndices.map(i => flatFace[i]);

  // Convert back to 3x3
  const remappedMatrix = [
    remappedColors.slice(0, 3),
    remappedColors.slice(3, 6),
    remappedColors.slice(6, 9)
  ];

  return (
    <div>
      {remappedMatrix.map((row, rowIndex) => (
        <div key={rowIndex} className="flex justify-center items-center">
          {row.map((color, colIndex) => {
            const flatIndex = rowIndex * 3 + colIndex; // index in rotated view
            const originalIndex = mapIndices[flatIndex]; // map back to original

            return (
              <div
                key={colIndex}
                onClick={() => {
                  // notify parent which original index was clicked
                  onStickerClick(originalIndex);
                }}
                className={`w-10 h-10 border-2 border-black cursor-pointer ${color === "W"
                  ? "bg-white"
                  : color === "R"
                    ? "bg-red-500"
                    : color === "G"
                      ? "bg-green-500"
                      : color === "Y"
                        ? "bg-yellow-500"
                        : color === "O"
                          ? "bg-orange-500"
                          : color === "B"
                            ? "bg-blue-500"
                            : "bg-gray-500"
                  }`}
              />
            );
          })}
        </div>
      ))}
    </div>
  );
}


// The standard order of faces for cube solvers
const FACE_NAMES = ['Up (White)', 'Left (Orange)',- 'Front (Green)', 'Right (Red)', 'Back (Blue)', 'Down (Yellow)'];
const COLOR_NAMES = ['white', 'orange', 'green', 'red', 'blue', 'yellow'];
const COLOR_MAP = {
    white: 'bg-white',
    red: 'bg-red-500',
    green: 'bg-green-500',
    blue: 'bg-blue-500',
    yellow: 'bg-yellow-400',
    orange: 'bg-orange-500',
    black: 'bg-gray-900',
    lightgray: 'bg-gray-200',
    unknown: 'bg-gray-600'
};

//================================================================================
// Pre-Trained Color Profiles (Approximation)
//================================================================================
// These are pre-defined HSV (Hue, Saturation, Value) color profiles.
// This approach is less accurate than on-the-spot calibration because it
// cannot account for variations in lighting, camera sensors, or cube sticker shades.
// H is in degrees [0-360], S and V are percentages [0-100].
const PRE_TRAINED_COLORS = {
    // For white, we check for low saturation and high value, as hue is irrelevant.
    white:  { s_thresh: 25, v_thresh: 70 },
    // For chromatic colors, we define a target HSV value.
    yellow: { h: 55, s: 80, v: 90 }, // Hue range: 45-65
    green:  { h: 120, s: 70, v: 60 },// Hue range: 90-150
    blue:   { h: 220, s: 80, v: 70 },// Hue range: 190-250
    red:    { h: 0, s: 85, v: 80 },  // Hue is a special case, near 0/360
    orange: { h: 25, s: 85, v: 95 }, // Hue range: 10-40
};


//================================================================================
// CubeDisplay Component
//================================================================================
function CubeDisplay({ colors, small = false }) {
    const sizeClass = small ? "w-28 h-28" : "w-24 h-24 md:w-32 md:h-32";
    return (
        <div className={`grid grid-cols-3 grid-rows-3 ${sizeClass} p-1 gap-1 bg-gray-900/50 rounded-lg overflow-hidden mx-auto shadow-inner`}>
            {colors.map((color, index) => (
                <div key={index} className={`w-full h-full rounded-sm ${COLOR_MAP[color] || 'bg-gray-700'}`} />
            ))}
        </div>
    );
}

//================================================================================
// Camera Component (Using Pre-Trained Model)
//================================================================================
function Camera({ onFaceScanned, setMessage }) {
    const videoRef = useRef(null);
    const canvasRef = useRef(null);
    const overlayRef = useRef(null);
    const requestRef = useRef();
    const [isCameraReady, setIsCameraReady] = useState(false);
    const [liveColors, setLiveColors] = useState(Array(9).fill('unknown'));

    // Converts RGB color values to HSV. This is crucial for reliable color detection.
    const rgbToHsv = (r, g, b) => {
        r /= 255; g /= 255; b /= 255;
        let max = Math.max(r, g, b), min = Math.min(r, g, b);
        let h = 0, s, v = max;
        let d = max - min;
        s = max === 0 ? 0 : d / max;
        if (max !== min) {
            switch (max) {
                case r: h = (g - b) / d + (g < b ? 6 : 0); break;
                case g: h = (b - r) / d + 2; break;
                case b: h = (r - g) / d + 4; break;
                default: break;
            }
            h /= 6;
        }
        return [h * 360, s * 100, v * 100];
    };

    // Finds the closest color from the pre-trained profiles.
    const findClosestColorPretrained = useCallback((hsv) => {
        if (!hsv) return 'unknown';
        const [h, s, v] = hsv;

        // Handle white separately as it's achromatic (has no hue).
        if (s < PRE_TRAINED_COLORS.white.s_thresh && v > PRE_TRAINED_COLORS.white.v_thresh) {
            return 'white';
        }

        let minDistance = Infinity;
        let bestColor = 'unknown';

        // Iterate through the chromatic (non-white) colors.
        for (const colorName in PRE_TRAINED_COLORS) {
            if (colorName === 'white') continue;

            const profile = PRE_TRAINED_COLORS[colorName];
            
            // Calculate hue distance, handling the 360-degree wrap-around for red.
            const hueDiff = Math.min(Math.abs(h - profile.h), 360 - Math.abs(h - profile.h));
            
            // Calculate a weighted distance in HSV space. Hue is most important.
            const distance = (hueDiff * 2.5) + (Math.abs(s - profile.s) * 1.2) + Math.abs(v - profile.v);

            if (distance < minDistance) {
                minDistance = distance;
                bestColor = colorName;
            }
        }

        // If no color is close enough, it's 'unknown'.
        // This threshold is looser than it would be for a calibrated model.
        if (minDistance > 180) return 'unknown';

        return bestColor;
    }, []);

    // Processes each frame from the camera feed for scanning.
    const processFrame = useCallback(() => {
        if (!isCameraReady || !window.cv || !videoRef.current || !canvasRef.current || !overlayRef.current) {
            requestRef.current = requestAnimationFrame(processFrame);
            return;
        }

        const video = videoRef.current;
        const processCanvas = canvasRef.current;
        const overlayCanvas = overlayRef.current;
        const processCtx = processCanvas.getContext('2d', { willReadFrequently: true });
        const overlayCtx = overlayCanvas.getContext('2d');
        const { videoWidth: width, videoHeight: height } = video;

        if (width > 0 && height > 0) {
            if (processCanvas.width !== width || processCanvas.height !== height) {
                processCanvas.width = width;
                processCanvas.height = height;
                overlayCanvas.width = width;
                overlayCanvas.height = height;
            }

            processCtx.drawImage(video, 0, 0, width, height);
            overlayCtx.clearRect(0, 0, width, height);
            let src = window.cv.imread(processCanvas);

            // --- GRID-BASED SCANNING LOGIC ---
            setMessage('Align cube face with the grid');
            const gridContainerSize = Math.min(width, height) * 0.75;
            const gridX = (width - gridContainerSize) / 2;
            const gridY = (height - gridContainerSize) / 2;
            const cellSize = gridContainerSize / 3;
            const sampleMargin = cellSize * 0.3;
            const sampleSize = cellSize - 2 * sampleMargin;
            
            const detectedColors = Array(9).fill('unknown');

            // Draw the main 3x3 grid
            overlayCtx.beginPath();
            overlayCtx.strokeStyle = "rgba(255, 255, 255, 0.7)";
            overlayCtx.lineWidth = 2;
            for (let i = 0; i <= 3; i++) {
                overlayCtx.moveTo(gridX + i * cellSize, gridY);
                overlayCtx.lineTo(gridX + i * cellSize, gridY + gridContainerSize);
                overlayCtx.moveTo(gridX, gridY + i * cellSize);
                overlayCtx.lineTo(gridX + gridContainerSize, gridY + i * cellSize);
            }
            overlayCtx.stroke();

            // Sample color from the center of each grid cell
            for (let r = 0; r < 3; r++) {
                for (let c = 0; c < 3; c++) {
                    const roiRect = new window.cv.Rect(
                        gridX + c * cellSize + sampleMargin,
                        gridY + r * cellSize + sampleMargin,
                        sampleSize,
                        sampleSize
                    );
                    
                    // Draw the sampling area rectangles
                    overlayCtx.strokeStyle = "rgba(0, 255, 255, 0.8)";
                    overlayCtx.lineWidth = 2;
                    overlayCtx.strokeRect(roiRect.x, roiRect.y, roiRect.width, roiRect.height);

                    const roi = src.roi(roiRect);
                    const meanRgba = window.cv.mean(roi);
                    const hsv = rgbToHsv(...meanRgba);
                    detectedColors[r * 3 + c] = findClosestColorPretrained(hsv);
                    roi.delete();
                }
            }
            setLiveColors(detectedColors);
            src.delete();
        }
        requestRef.current = requestAnimationFrame(processFrame);
    }, [isCameraReady, findClosestColorPretrained, setMessage]);

    // Sets up the camera and starts the processing loop.
    useEffect(() => {
        async function setupCamera() {
             if (!navigator.mediaDevices || !navigator.mediaDevices.getUserMedia) {
                setMessage('Camera API not supported by this browser.');
                return;
            }
            setMessage('Requesting camera access...');
            try {
                const constraints = { video: { facingMode: 'environment', width: { ideal: 640 }, height: { ideal: 640 } } };
                const stream = await navigator.mediaDevices.getUserMedia(constraints);
                if (videoRef.current) {
                    videoRef.current.srcObject = stream;
                    videoRef.current.oncanplay = () => {
                        setIsCameraReady(true);
                        requestRef.current = requestAnimationFrame(processFrame);
                    };
                }
            } catch (err) {
                console.error("Camera Error:", err.name, err.message);
                setMessage('Camera permission denied. Please allow access and reload.');
            }
        }

        const interval = setInterval(() => {
            if (window.cv) {
                clearInterval(interval);
                setupCamera();
            }
        }, 100);

        return () => {
            cancelAnimationFrame(requestRef.current);
            if (videoRef.current && videoRef.current.srcObject) {
                videoRef.current.srcObject.getTracks().forEach(t => t.stop());
            }
        };
    }, [processFrame, setMessage]);

    return (
        <div className="flex flex-col items-center">
            <div className="relative w-full max-w-md mx-auto bg-black rounded-2xl overflow-hidden shadow-2xl shadow-indigo-500/20 ring-1 ring-white/10 aspect-square">
                <video ref={videoRef} className="absolute w-full h-full object-cover" autoPlay playsInline muted />
                <canvas ref={overlayRef} className="absolute w-full h-full object-cover" />
                <canvas ref={canvasRef} className="hidden" />
            </div>
            <div className="p-4 w-full max-w-md">
                <h3 className="text-center font-semibold mb-2 text-indigo-300">Live Detection</h3>
                <CubeDisplay colors={liveColors} small={true} />
                <button onClick={() => onFaceScanned(liveColors)}  className="w-full mt-4 bg-gradient-to-r from-green-500 to-teal-500 text-white font-bold py-3 rounded-xl shadow-lg hover:scale-105 transition-transform disabled:from-gray-600 disabled:to-gray-700 disabled:cursor-not-allowed disabled:scale-100">
                    Capture Face
                </button>
            </div>
        </div>
    );
}

//================================================================================
// Main CubeScanner Component
//================================================================================
function CubeScanner() {





     const mainGroup = useRef();
      const { solutionMoves, setSolutionMoves, face0Color, setFace0Color, face1Color, setFace1Color, face2Color, setFace2Color, face3Color, setFace3Color, face4Color, setFace4Color, face5Color, setFace5Color } = useContext(CubeContext);
       const navigate=useNavigate();
      const [currentColorMatrix, setCurrentColorMatrix] = useState([['N', 'N', 'N'], ['N', 'N', 'N'], ['N', 'N', 'N']]);
      const [currentColor, setCurrentColor] = useState('');
      const [currentFace, setCurrentFace] = useState(2);
      const [rotateTrigger, setRotateTrigger] = useState(false);
      const [direction, setDirection] = useState(1);
      const [orientation, setOrientation] = useState(0);
      const [isRotating, setIsRotating] = useState(false);
        const isRotatingRef = useRef(false);
    
    
    
    
      function handlePaintSticker(originalIndex) {
    
        console.log(currentFace, orientation);
        if (!currentColor) return;
        setCurrentColorMatrix(prev => {
          const flat = prev.flat();
          flat[originalIndex] = currentColor;
          const newMat = [flat.slice(0, 3), flat.slice(3, 6), flat.slice(6, 9)];
    
          switch (currentFace) {
            case 0: setFace0Color(newMat); break;
            case 1: setFace1Color(newMat); break;
            case 2: setFace2Color(newMat); break;
            case 3: setFace3Color(newMat); break;
            case 4: setFace4Color(newMat); break;
            case 5: setFace5Color(newMat); break;
            default: break;
          }
    
          return newMat;
        });
      }
    
    
      function beginRotate() {
        isRotatingRef.current = true;
        setIsRotating(true);
      }
      function endRotate() {
        isRotatingRef.current = false;
        setIsRotating(false);
      }
    
    
      function handleRotateNext() {
    
        console.log(isRotatingRef.current,isRotating);
        if (isRotatingRef.current) return; // block repeated clicks immediately
        beginRotate();
    
        console.log("Current face before rotation:", currentFace);
        if (currentFace == 2) {
          setDirection(-1); setRotateTrigger(true);
          setCurrentFace(1);
          setFace2Color(currentColorMatrix);
          setCurrentColorMatrix(face1Color);
        }
       else if (currentFace == 1) {
          setDirection(-1); setRotateTrigger(true);
          setCurrentFace(5);
          setFace1Color(currentColorMatrix);
          setCurrentColorMatrix(face5Color);
        }
       else if (currentFace == 5) {
          setDirection(-1); setRotateTrigger(true);
          setCurrentFace(4);
          setFace5Color(currentColorMatrix);
          setCurrentColorMatrix(face4Color);
        }
       else if (currentFace == 4) {
          setDirection(-1); setRotateTrigger(true);
          setCurrentFace(2);
          setFace4Color(currentColorMatrix);
          setTimeout(function () {
            setDirection(2); setRotateTrigger(true);
            setCurrentFace(0);
            setCurrentColorMatrix(face0Color);
          }, 500);
    
    
    
        }
       else if (currentFace == 0) {
          setDirection(-2); setRotateTrigger(true);
          setCurrentFace(3);
          setFace0Color(currentColorMatrix);
          setCurrentColorMatrix(face3Color);
        }
        else {
              endRotate();
        }
    
      }
    
    
    
    
      function handleRotatePrev() {
        console.log(isRotatingRef.current,isRotating);
          if (isRotatingRef.current) return;
        beginRotate();
        if (currentFace == 3) {
          setDirection(3); setRotateTrigger(true);
          setCurrentFace(0);
          setFace3Color(currentColorMatrix);
          setCurrentColorMatrix(face0Color);
        }
        else if (currentFace == 0) {
          setDirection(-3); setRotateTrigger(true);
          setCurrentFace(2);
          setFace0Color(currentColorMatrix);
          setCurrentColorMatrix(face2Color);
          setTimeout(function () {
            setDirection(1); setRotateTrigger(true);
            setCurrentFace(4);
            setCurrentColorMatrix(face4Color);
          }, 500);
        }
        else if (currentFace == 4) {
          setDirection(1); setRotateTrigger(true);
          setCurrentFace(5);
          setFace4Color(currentColorMatrix);
          setCurrentColorMatrix(face5Color);
        }
        else if (currentFace == 5) {
          setDirection(1); setRotateTrigger(true);
          setCurrentFace(1);
          setFace5Color(currentColorMatrix);
          setCurrentColorMatrix(face1Color);
    
    
    
        }
        else if (currentFace == 1) {
          setDirection(1); setRotateTrigger(true);
          setCurrentFace(2);
          setFace1Color(currentColorMatrix);
          setCurrentColorMatrix(face2Color);
        }
         else {
              endRotate();
        }
    
      }
    
      function parseMoves(moveString) {
      // Regex matches: U, U', U2, D, D', D2, ... etc.
      const regex = /([UDLRFB][2']?)/g;
      return moveString.match(regex) || [];
    }
    
    
    
    
    
      async function handleSolve(num) {
    
         
        let colorMap = {
          R: face0Color[1][1] === 'R' ? 'U' : face1Color[1][1] === 'R' ? 'R' : face2Color[1][1] === 'R' ? 'F' : face3Color[1][1] === 'R' ? 'D' : face4Color[1][1] === 'R' ? 'L' : face5Color[1][1] === 'R' ? 'B' : '',
          G: face0Color[1][1] === 'G' ? 'U' : face1Color[1][1] === 'G' ? 'R' : face2Color[1][1] === 'G' ? 'F' : face3Color[1][1] === 'G' ? 'D' : face4Color[1][1] === 'G' ? 'L' : face5Color[1][1] === 'G' ? 'B' : '',
          W: face0Color[1][1] === 'W' ? 'U' : face1Color[1][1] === 'W' ? 'R' : face2Color[1][1] === 'W' ? 'F' : face3Color[1][1] === 'W' ? 'D' : face4Color[1][1] === 'W' ? 'L' : face5Color[1][1] === 'W' ? 'B' : '',
          O: face0Color[1][1] === 'O' ? 'U' : face1Color[1][1] === 'O' ? 'R' : face2Color[1][1] === 'O' ? 'F' : face3Color[1][1] === 'O' ? 'D' : face4Color[1][1] === 'O' ? 'L' : face5Color[1][1] === 'O' ? 'B' : '',
          Y: face0Color[1][1] === 'Y' ? 'U' : face1Color[1][1] === 'Y' ? 'R' : face2Color[1][1] === 'Y' ? 'F' : face3Color[1][1] === 'Y' ? 'D' : face4Color[1][1] === 'Y' ? 'L' : face5Color[1][1] === 'Y' ? 'B' : '',
          B: face0Color[1][1] === 'B' ? 'U' : face1Color[1][1] === 'B' ? 'R' : face2Color[1][1] === 'B' ? 'F' : face3Color[1][1] === 'B' ? 'D' : face4Color[1][1] === 'B' ? 'L' : face5Color[1][1] === 'B' ? 'B' : '',
        }
    
        
        let string = "";
        face0Color.flat().forEach((color) => {
          string += colorMap[color];
        });
        face1Color.flat().forEach((color) => {
          string += colorMap[color];
        });
        face2Color.flat().forEach((color) => {
          string += colorMap[color];
        });
        face3Color.flat().forEach((color) => {
          string += colorMap[color];
        });
        face4Color.flat().forEach((color) => {
          string += colorMap[color];
        });
        face5Color.flat().forEach((color) => {
          string += colorMap[color];
        });
    
     
     
        try{    
          if(num==1){
              const response=await axios.post(`${import.meta.env.BACKEND_URL}/api/solution1`,{
                scramble: string
              });
              
               
               const cubeState = {
          solutionMoves: parseMoves(response.data.solution),
        //   solutionMoves:[ "B2", "D2", "F2", "L2", "D2", "R2",
        // "B'", "B2", "D'", "D'", "R'", "B",
        // "R", "L'", "D'", "D'", "R'", "B",
        // "R", "L", "D'", "B'", "L", "B"],
          face0Color,
          face1Color,
          face2Color,
          face3Color,
          face4Color,
          face5Color
        };
    
        localStorage.setItem("cubeState", JSON.stringify(cubeState));
    
        window.open("/solution", "_blank", "noopener,noreferrer");
          }
          else{
              const response=await axios.post(`${import.meta.env.BACKEND_URL}/api/solution2`,{
                scramble: string
              });
                setSolutionMoves(parseMoves(response.data.solution));
                console.log(face0Color, face1Color, face2Color, face3Color, face4Color, face5Color);
                 const cubeState = {
          solutionMoves: parseMoves(response.data.solution),
          face0Color,
          face1Color,
          face2Color,
          face3Color,
          face4Color,
          face5Color
        };
    
        localStorage.setItem("cubeState", JSON.stringify(cubeState));
    
        window.open("/solution", "_blank", "noopener,noreferrer");
               
          }
             
        }
        catch(err){
           console.error("Error fetching solution:", err);
        }
    
    
          
    
    
    
    
    
    
    
    
    
    
      }
    









    const [cubeState, setCubeState] = useState(Object.fromEntries(Array.from({ length: 6 }, (_, i) => [i, Array(9).fill('lightgray')])));
    const [currentFaceIndex, setCurrentFaceIndex] = useState(0);
    const [activeMode, setActiveMode] = useState('scanning'); // 'scanning', 'finished'
    const [message, setMessage] = useState('Loading Vision Engine...');

// src/CubeScanner.jsx

const handleFaceScanned = (colors) => {
    // 1. Convert the flat 9-element color array into a 3x3 matrix
    //    Also, map color names ('white') to single letters ('W') and 'unknown' to 'N'.
    const newMatrix = [
        colors.slice(0, 3).map(c => (c === 'unknown' ? 'N' : c.charAt(0).toUpperCase())),
        colors.slice(3, 6).map(c => (c === 'unknown' ? 'N' : c.charAt(0).toUpperCase())),
        colors.slice(6, 9).map(c => (c === 'unknown' ? 'N' : c.charAt(0).toUpperCase()))
    ];

    // 2. Update the state for the 2D face editor (as you did before)
    setCurrentColorMatrix(newMatrix);

    // 3. CRITICAL FIX: Update the correct face state for the 3D cube
    //    This uses the 'currentFace' index to know which master face state to update.
    switch (currentFace) {
        case 0: setFace0Color(newMatrix); break;
        case 1: setFace1Color(newMatrix); break;
        case 2: setFace2Color(newMatrix); break;
        case 3: setFace3Color(newMatrix); break;
        case 4: setFace4Color(newMatrix); break;
        case 5: setFace5Color(newMatrix); break;
        default: break;
    }
};

    const resetCube = () => {
        setCubeState(Object.fromEntries(Array.from({ length: 6 }, (_, i) => [i, Array(9).fill('lightgray')])));
        setCurrentFaceIndex(0);
        setActiveMode('scanning');
        setMessage('Ready to scan. Please show the Up (White) face.');
    }

    return (
       <div className="!bg-slate-50 !text-slate-900 !min-h-screen !p-4 sm:!p-8 !font-sans">
    <div className="!max-w-7xl !mx-auto">
       

        <main className="!grid !grid-cols-1 lg:!grid-cols-2 !gap-8">
            {/* ----- Left Column: Camera and Scan Status ----- */}
            <section className="!bg-white/60 !backdrop-blur-sm !p-6 !rounded-2xl !shadow-lg !ring-1 !ring-black/5">
               
                {activeMode === 'scanning' ? (
                    <Camera onFaceScanned={handleFaceScanned} setMessage={setMessage} />
                ) : (
                    <div className="!text-center !p-8 !bg-slate-100/50 !rounded-xl !aspect-square !flex !flex-col !justify-center !items-center">
                        <div>
                            <h3 className="!text-2xl !font-semibold !text-green-600">All Faces Scanned!</h3>
                            <p className="!mt-2 !text-slate-600">The cube state is ready. Solve or edit below.</p>
                        </div>
                    </div>
                )}
            </section>

            {/* ----- Right Column: 3D View, Manual Editor, and Controls ----- */}
            <section className="!bg-white/60 !backdrop-blur-sm !p-6 !rounded-2xl !shadow-lg !ring-1 !ring-black/5 !flex !flex-col !gap-6">

                {/* 3D Cube Visualization */}
                <div className="!relative !w-full !h-64 sm:!h-80 !bg-slate-200/50 !rounded-xl !ring-1 !ring-black/5 !overflow-hidden">
                    <Canvas camera={{ position: [2, 2, 5], fov: 50 }}>
                        <ambientLight intensity={1.5} />
                        <hemisphereLight skyColor={0xffffff} groundColor={0x444444} intensity={1} />
                        <directionalLight position={[10, 10, 10]} intensity={1} />
                        <directionalLight position={[-10, -10, -10]} intensity={0.5} />
                        <RotatingCube
                            face0Color={face0Color}
                            face1Color={face1Color}
                            face2Color={face2Color}
                            face3Color={face3Color}
                            face4Color={face4Color}
                            face5Color={face5Color}
                            rotateTrigger={rotateTrigger}
                            setRotateTrigger={setRotateTrigger}
                            direction={direction}
                            isRotating={isRotating}
                            setIsRotating={setIsRotating}
                            onRotationComplete={endRotate}
                        />
                    </Canvas>
                </div>

                {/* 2D Face Editor */}
                <div className="!flex !flex-col !items-center !gap-4">
                    <DisplayFace
                        currentColorMatrix={currentColorMatrix}
                        currentColor={currentColor}
                        orientation={orientation}
                        onStickerClick={handlePaintSticker}
                    />
                    <div className="!flex !items-center !gap-4">
                        <button onClick={handleRotatePrev} className="!px-6 !py-2 !text-sm !rounded-lg !bg-slate-200 !text-slate-700 !font-medium hover:!bg-slate-300 !transition !shadow-md">← Prev</button>
                        <button onClick={handleRotateNext} className="!px-6 !py-2 !text-sm !rounded-lg !bg-slate-200 !text-slate-700 !font-medium hover:!bg-slate-300 !transition !shadow-md">Next →</button>
                    </div>
                </div>

                {/* Color Palette & Actions */}
                <div className="!border-t !border-slate-200 !pt-6 !flex !flex-col !gap-6">
                    <div>
                        <div className="!flex !items-baseline !justify-between !mb-3">
                            <h3 className="!text-xl !font-bold !text-indigo-600">Color Palette</h3>
                            <div className="!text-sm !text-slate-500">Pick a color to paint</div>
                        </div>
                        <ul className="!grid !grid-cols-6 !gap-2 sm:!gap-3">
                            {['W', 'R', 'G', 'Y', 'O', 'B'].map(color => {
                                const colorMap = {
                                    W: { name: 'White', hex: '#ffffff', text: '!text-gray-700', ring: '!ring-gray-400', border: '!border-gray-500', baseBorder: '!border-gray-300' },
                                    R: { name: 'Red', hex: '#dc2626', text: '!text-white', ring: '!ring-red-300', border: '!border-red-600', baseBorder: '!border-red-400' },
                                    G: { name: 'Green', hex: '#16a34a', text: '!text-white', ring: '!ring-green-300', border: '!border-green-600', baseBorder: '!border-green-400' },
                                    Y: { name: 'Yellow', hex: '#ca8a04', text: '!text-black', ring: '!ring-yellow-300', border: '!border-yellow-600', baseBorder: '!border-yellow-400' },
                                    O: { name: 'Orange', hex: '#ea580c', text: '!text-white', ring: '!ring-orange-300', border: '!border-orange-600', baseBorder: '!border-orange-400' },
                                    B: { name: 'Blue', hex: '#2563eb', text: '!text-white', ring: '!ring-blue-300', border: '!border-blue-600', baseBorder: '!border-blue-400' },
                                };
                                const c = colorMap[color];
                                return (
                                    <li key={color}>
                                        <button
                                            onClick={() => setCurrentColor(color)}
                                            aria-pressed={currentColor === color}
                                            title={c.name}
                                            className={`!w-full !aspect-square !rounded-lg !border-2 ${currentColor === color ? `!ring-2 !ring-offset-2 !ring-offset-white ${c.ring} ${c.border}` : c.baseBorder} !flex !items-center !justify-center !transition hover:!scale-105 !focus:outline-none !shadow-md`}
                                            style={{ backgroundColor: c.hex }}
                                        >
                                            <span className={`!text-sm !font-semibold ${c.text}`}>{color}</span>
                                        </button>
                                    </li>
                                );
                            })}
                        </ul>
                    </div>

                    <div className="!flex !flex-col sm:!flex-row !gap-3">
                        <button onClick={() => handleSolve(1)} className="!w-full !px-4 !py-3 !rounded-lg !bg-indigo-600 !text-white !font-semibold hover:!bg-indigo-700 !transition !shadow-md">Kociemba Solve</button>
                        <button onClick={() => handleSolve(2)} className="!w-full !px-4 !py-3 !rounded-lg !bg-sky-600 !text-white !font-semibold hover:!bg-sky-700 !transition !shadow-md">Layer by Layer</button>
                        <button onClick={() => handlePaintSticker(null)} className="!w-full sm:!w-auto !px-4 !py-3 !rounded-lg !bg-red-500 !text-white !font-semibold hover:!bg-red-600 !transition !shadow-md">Reset</button>
                    </div>
                </div>
            </section>
        </main>
    </div>
</div>
    );
}

export default CubeScanner;

