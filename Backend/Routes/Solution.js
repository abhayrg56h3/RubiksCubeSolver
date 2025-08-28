import { Router } from "express";
import Cube from "cubejs";
import { spawn } from "child_process";
import path from "path";
import { fileURLToPath } from "url";
import fs from "fs";

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

const router = Router();

// Heavy precompute (do this once on startup)
Cube.initSolver();




 




// Kociemba two-phase algorithm
router.post('/solution1',(req,res)=>{
    try{
        console.log(req.body.scramble);
  const cube = Cube.fromString(req.body.scramble);  // build state from facelets
  const solution = cube.solve();  
  console.log({solution});  
  res.status(200).json({ solution });
}catch (error) {
  console.error("Error solving cube:", error);
  res.status(500).json({ error: "Failed to solve cube" });
}
});






















router.post('/solution2', (req, res) => {
  try {
    const scramble = req.body.scramble;
    console.log("CPP route received:", scramble, "length:", scramble?.length);

    if (typeof scramble !== "string" || scramble.length !== 54) {
      return res.status(400).json({ error: "Expected scramble to be a 54-character string" });
    }

    const binName = process.platform === 'win32' ? 'abhayji.exe' : 'abhayji';
    const binPath = path.join(__dirname, binName);


    console.log("Looking for C++ binary at:", binPath);
    if (!fs.existsSync(binPath)) {
      console.error("Binary not found at:", binPath);
      return res.status(500).json({ error: "C++ binary not found" });
    }

    // Spawn the binary (shell: false) and set cwd to binary dir
    const cpp = spawn(binPath, [scramble], {
      shell: false,
      windowsHide: true,
      cwd: path.dirname(binPath),
    });

    let result = '';
    let errData = '';

    // ensure readable text
    if (cpp.stdout) cpp.stdout.setEncoding('utf8');
    if (cpp.stderr) cpp.stderr.setEncoding('utf8');

    cpp.stdout?.on('data', (data) => {
      console.log('C++ stdout chunk:', data.toString());
      result += data.toString();
    });

    cpp.stderr?.on('data', (data) => {
      console.error('C++ stderr chunk:', data.toString());
      errData += data.toString();
    });

    cpp.on('error', (err) => {
      console.error('❌ spawn error:', err);
      return res.status(500).json({ error: 'Failed to start C++ solver', details: err.message });
    });

    cpp.on('exit', (code, signal) => {
      console.log(`C++ child exit event — code: ${code}, signal: ${signal}`);
    });

    // close fires when stdio streams are closed
    cpp.on('close', (code, signal) => {
      console.log(`C++ child close — code: ${code}, signal: ${signal}`);
      clearTimeout(killTimer);
      if (code !== 0) {
        console.error('❌ C++ finished with non-zero code or was killed. stderr:', errData);
        return res.status(500).json({ error: 'C++ solver error', code, signal, details: errData.trim() });
      }
      console.log('✅ C++ finished successfully. output:', result.trim());
      return res.json({ solution: result.trim() });
    });

    // manual safety timeout in case the process hangs
    const killTimer = setTimeout(() => {
      try {
        console.warn('Killing C++ process due to timeout');
        cpp.kill();
      } catch (e) {
        console.error('Failed to kill process:', e);
      }
    }, 15000);

  } catch (err) {
    console.error('❌ Error in /solution2:', err);
    res.status(500).json({ error: 'Server error' });
  }
});







export {router as solutionRouter    };