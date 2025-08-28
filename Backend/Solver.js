// solver.js
import Cube from "cubejs";

// Heavy precompute (do this once on startup)
Cube.initSolver();

/**
 * Solve from a 54-char facelet string in URFDLB order.
 * Example format: "UUUUUUUUURRRRRRRRRFFFFFFFFFDDDDDDDDDLLLLLLLLLBBBBBBBBB"
 * Where letters are U,R,F,D,L,B (not color names). Map your detected colors to these.
 */
// export function solveFacelets(facelets) {
//   if (typeof facelets !== "string" || facelets.length !== 54) {
//     throw new Error("Facelet string must be exactly 54 characters.");
//   }
//   const cube = Cube.fromString("RUUBUUFFLDBBFRRDFRLLBDFRDDRLLFBDUBDUULUBLRRRFLLBUBDFFD");  // build state from facelets
//   const solution = cube.solve();  
//   console.log(solution);         // Kociemba two-phase solution (e.g., "R U R' ...")
//   return solution;
// }


const cube = Cube.fromString("RUUBUUFFLDBBFRRDFRLLBDFRDDRLLFBDUBDUULUBLRRRFLLBUBDFFD");  // build state from facelets
  const solution = cube.solve();  
  console.log(solution);         
