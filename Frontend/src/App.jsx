// App.jsx
import React, { useEffect, useRef } from "react";
import * as THREE from "three";
import { Canvas } from "@react-three/fiber";
import { OrbitControls } from "@react-three/drei";
import RubiksTopBanner from "./Components/RubiksBanner.jsx";
import Solution from "./Components/solution.jsx";
import { Routes, Route, Navigate } from "react-router-dom";
import CubeScanner from "./Components/Input.jsx";
function Cubie({ pos, size = 0.9 }) {
  const mesh = useRef();
  const [x, y, z] = pos;
  const dark = "#111";
  const faceColors = [
    x === 1 ? "#ff0000" : dark,
    x === -1 ? "#ff8c00" : dark,
    y === 1 ? "#ffffff" : dark,
    y === -1 ? "#ffff00" : dark,
    z === 1 ? "#00ff00" : dark,
    z === -1 ? "#0000ff" : dark,
  ];

  // Set initial position imperatively so React does NOT overwrite it each render
  useEffect(() => {
    if (!mesh.current) return;
    mesh.current.position.set(x, y, z);
    mesh.current.updateMatrix();
  }, [x, y, z]);

  return (
    <mesh ref={mesh}>
      <boxGeometry args={[size, size, size]} />
      <meshStandardMaterial attach="material-0" color={faceColors[0]} />
      <meshStandardMaterial attach="material-1" color={faceColors[1]} />
      <meshStandardMaterial attach="material-2" color={faceColors[2]} />
      <meshStandardMaterial attach="material-3" color={faceColors[3]} />
      <meshStandardMaterial attach="material-4" color={faceColors[4]} />
      <meshStandardMaterial attach="material-5" color={faceColors[5]} />
    </mesh>
  );
}

function RubiksCube({ mainGroup }) {
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
        <Cubie key={i} pos={p} />
      ))}
    </group>
  );
}

export default function App() {
  const mainGroup = useRef();
  let isRotating = false;
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

  async function rotateLayerU() {
    if(isRotating) return;
    if (!mainGroup.current) return;

    const epsilon = 0.0001;
    const upperLayer = mainGroup.current.children.filter(
      (cubie) => Math.abs(cubie.position.y -0) < epsilon
    );

    if (upperLayer.length === 0) return;

    // create pivot group in the same coordinate space as mainGroup
    const tempGroup = new THREE.Group();
    mainGroup.current.add(tempGroup);

    // attach cubies to tempGroup (preserves world transform)
    upperLayer.forEach((cubie) => {
      tempGroup.attach(cubie);
    });

    // animate rotation 90deg around Y
    await animateGroupRotation(tempGroup, "y", Math.PI / 2, 350);

    // After animation, snap positions to integer grid and keep rotation as-is
    // We'll compute each cubie's world position and then set their position to nearest grid
    const worldPos = new THREE.Vector3();
    upperLayer.forEach((cubie) => {
      cubie.getWorldPosition(worldPos);
      // Snap to nearest -1/0/1
      const snapped = new THREE.Vector3(
        Math.round(worldPos.x),
        Math.round(worldPos.y),
        Math.round(worldPos.z)
      );
      // Reattach to mainGroup (this preserves world transform), then set local position to snapped
      mainGroup.current.attach(cubie);
      // Convert snapped world pos to mainGroup-local coords and set local pos:
      mainGroup.current.worldToLocal(snapped);
      cubie.position.copy(snapped);
      // Optionally: normalize rotation to multiples of 90deg (skip for simplicity)
      // Keep cubie's current local rotation — stickers stay rotated correctly
      cubie.updateMatrix();
    });

    // remove tempGroup
    mainGroup.current.remove(tempGroup);
    isRotating = false;
  }

  useEffect(() => {
    function handleKeyDown(e) {
      if (e.key.toLowerCase() === "u") rotateLayerU();
    }
    window.addEventListener("keydown", handleKeyDown);
    return () => window.removeEventListener("keydown", handleKeyDown);
  }, []);

  return (
    <div className="h-screen w-screen bg-white">
        <RubiksTopBanner/>
        <Routes>
          <Route path="/" element={<CubeScanner/>} />
          <Route path="/solution" element={<Solution />} />
        </Routes>
    </div>
  );
}
