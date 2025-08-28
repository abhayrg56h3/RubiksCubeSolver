import express from "express";
import cors from "cors";
import dotenv from "dotenv";
import { solutionRouter } from "./Routes/Solution.js";

dotenv.config();

const app = express();

// ✅ use process.env.PORT (Render/Netlify provides this dynamically)
const PORT = process.env.PORT || 5000;

// ✅ configure CORS (allow only your frontend domain in production)
app.use(cors({
  origin: process.env.CLIENT_URL || "*", // e.g. "https://your-frontend.netlify.app"
  methods: ["GET", "POST"],
}));

app.use(express.json());

// API routes
app.use("/api", solutionRouter);

// ✅ health check route (useful for Render/Netlify)
app.get("/", (req, res) => {
  res.send("🚀 Server is running!");
});

// Start server
app.listen(PORT, () => {
  console.log(`✅ Server started on port ${PORT}`);
});
