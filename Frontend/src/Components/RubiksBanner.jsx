import React from "react";

// Modern, colorful, single-file decorative top banner for Rubik's Solver
// - No separate frosted "card" — all text is integrated directly into the banner
// - Camouflage first square in the cube icon
// - Brand text uses a solid color (no gradient)
// - Purely decorative: NO buttons, NO interactivity
// - TailwindCSS utility classes assumed available in the project
// - Orange background for small devices

export default function RubiksTopBanner({ brand = "Rubik's Solver" }) {
  return (
    // removed the white center overlay (so banner is colorful edge-to-edge)
    <header className="w-full h-[34vh] min-h-[200px] flex items-center justify-center relative overflow-hidden border-b border-slate-200 dark:border-slate-800">

      {/* ---------- Local styles & animations ---------- */}
      <style>{` 
        :root{
          --accent-1: 240 82 255; /* pink/purple */
          --accent-2: 45 212 191; /* teal */
          --accent-3: 250 204 21; /* yellow */
        }

        @keyframes spin-slow { from{ transform: rotate(0deg);} to{ transform: rotate(360deg);} }
        @keyframes float-slow { 0%{ transform: translateY(0);}50%{ transform: translateY(-8px);}100%{ transform: translateY(0);} }
        @keyframes drift { 0%{ transform: translateX(0);}50%{ transform: translateX(-10px);}100%{ transform: translateX(0);} }
        @keyframes scale-pulse { 0%{ transform: scale(1);}50%{ transform: scale(1.03);}100%{ transform: scale(1);} }

        /* subtle grain */
        .rubiks-noise{ background-image: radial-gradient(rgba(255,255,255,0.02) 1px, transparent 1px); background-size:4px 4px; mix-blend-mode:overlay }

        /* sticker-like subtle separators for stickers on isometric cube */
        .sticker-line{ stroke: rgba(0,0,0,0.05); stroke-width:0.6 }

        /* responsive tweaks */
        @media (max-width:640px){
          .rubiks-title{ font-size:1.05rem }
          .rubiks-sub{ font-size:0.74rem }
        }
      `}</style>

      {/* ---------------- Background layers (colorful, saturated) ---------------- */}
      <div className="absolute inset-0 pointer-events-none">
        {/* Lighter orange background for small devices */}
        <div className="absolute inset-0 sm:hidden bg-gradient-to-br from-orange-200 via-orange-300 to-orange-400"></div>
        
        {/* Original colorful background for larger devices */}
        <div className="hidden sm:block absolute inset-0">
          {/* diagonal color wash to give strong color */}
          <div className="absolute inset-0 transform-gpu" style={{ background: 'linear-gradient(120deg, rgba(99,102,241,0.14), rgba(16,185,129,0.12) 35%, rgba(249,115,22,0.10) 70%)', mixBlendMode: 'screen' }} />

          {/* large warm blob (left) — EXPANDED so center becomes colorful (no color values changed) */}
          <div
            className="absolute -left-24 -top-40 w-[64rem] h-[64rem] rounded-[40%] opacity-85 blur-3xl transform rotate-12"
            style={{
              background: 'radial-gradient(circle at 20% 20%, rgba(250,204,21,0.95), rgba(244,63,94,0.85))',
              animation: 'scale-pulse 8s ease-in-out infinite'
            }}
          />

          {/* cool blob (right) */}
          <div className="absolute -right-24 -bottom-20 w-[36rem] h-[36rem] rounded-[40%] opacity-80 blur-2xl" style={{ background: 'radial-gradient(circle at 80% 80%, rgba(45,212,191,0.95), rgba(124,58,237,0.88))', animation: 'drift 10s ease-in-out infinite' }} />
        </div>

        {/* colorful diagonal stripes (very subtle) */}
        <svg className="absolute inset-0 w-full h-full opacity-6 rubiks-noise" viewBox="0 0 100 100" preserveAspectRatio="none" aria-hidden>
          <defs>
            <pattern id="stripes" width="8" height="8" patternUnits="userSpaceOnUse" patternTransform="rotate(25)">
              <rect width="4" height="8" fill="white" />
            </pattern>
          </defs>
          <rect width="100" height="100" fill="url(#stripes)" />
        </svg>

        {/* little floating glossy cubes for fun */}
        <svg className="absolute left-6 top-6 w-18 h-18 opacity-95" style={{ animation: 'float-slow 4.5s ease-in-out infinite' }} viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg" aria-hidden>
          <g>
            <polygon points="12,2 22,7 12,12 2,7" fill="rgba(255,255,255,0.06)" />
            <polygon points="12,12 22,7 22,17 12,22" fill="rgba(255,255,255,0.04)" />
          </g>
        </svg>

        <svg className="absolute right-10 top-12 w-24 h-24 opacity-90" style={{ transform: 'rotate(10deg)', animation: 'drift 8s ease-in-out infinite' }} viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg" aria-hidden>
          <g>
            <rect x="3" y="3" width="7" height="7" rx="1" fill="rgba(255,255,255,0.06)" />
            <rect x="14" y="3" width="7" height="7" rx="1" fill="rgba(255,255,255,0.04)" />
          </g>
        </svg>
      </div>

      {/* ---------------- Foreground: integrated content (no separate card) ---------------- */}
      <div className="relative z-10 max-w-7xl w-full px-6 sm:px-12 flex items-center gap-6">

        {/* Left: text area but visually integrated with the banner (no boxed card) */}
        <div className="flex-1 text-slate-900 dark:text-slate-100">
          <div className="flex items-center gap-4">
            <div className="flex items-center justify-center w-16 h-16 rounded-lg shadow-xl bg-gradient-to-br from-[rgba(var(--accent-1),0.95)] to-[rgba(var(--accent-2),0.95)] ring-1 ring-white/30">
              {/* compact colorful cube icon (keeps brand feeling) */}
              <svg viewBox="0 0 24 24" className="w-9 h-9" fill="none" xmlns="http://www.w3.org/2000/svg" aria-hidden>
                <defs>
                  <pattern id="camouflage" patternUnits="userSpaceOnUse" width="8" height="8" patternTransform="rotate(15)">
                    <rect width="8" height="8" fill="#c7d9b6" />
                    <path d="M0 4 C2 2 6 6 8 4 L8 0 L0 0 Z" fill="#8fa36a" />
                    <path d="M0 6 C2 8 6 4 8 6 L8 8 L0 8 Z" fill="#6b8a4d" />
                  </pattern>
                </defs>

                {/* First square: camouflaged */}
                <rect x="2" y="2" width="8" height="8" rx="1" fill="#F59E0B" />
                <rect x="14" y="2" width="8" height="8" rx="1" fill="#60E6C8" />
                <rect x="2" y="14" width="8" height="8" rx="1" fill="#FF6B6B" />
                <rect x="14" y="14" width="8" height="8" rx="1" fill="#5B8CFF" />
              </svg>
            </div>

            <div>
              {/* Brand text with solid color (no gradient) */}
              <h1 className="rubiks-title text-3xl sm:text-4xl font-extrabold tracking-tight text-gray-800 sm:text-slate-900 dark:text-slate-100">
                {brand} <span className="ml-2">🧩</span>
              </h1>

              {/* --- UPDATED: clearer, meaningful subtext --- */}
              <p className="rubiks-sub text-sm text-gray-700 sm:text-slate-700 dark:text-slate-300 mt-1">
                Scramble generator • Step-by-step solver • Algorithm visualizer
              </p>
            </div>
          </div>

          {/* badges integrated directly into banner (no separate card) */}
          <div className="flex flex-wrap items-center gap-3 mt-4">
            <span className="inline-flex items-center gap-2 px-3 py-1 rounded-full bg-white/40 backdrop-blur-sm border border-white/50 text-xs text-gray-800">
              Scramble Generator
            </span>

            <span className="inline-flex items-center gap-2 px-3 py-1 rounded-full bg-white/30 backdrop-blur-sm border border-white/40 text-xs text-gray-800">
              Interactive Tutorials
            </span>

            <span className="inline-flex items-center gap-2 px-3 py-1 rounded-full bg-white/30 backdrop-blur-sm border border-white/40 text-xs text-gray-800">
              Algorithm Visualizer
            </span>

            <span className="inline-flex items-center gap-2 px-3 py-1 rounded-full bg-white/30 backdrop-blur-sm border border-white/40 text-xs text-gray-800">
              Practice Mode
            </span>

            {/* slim version label integrated into the line */}
            <span className="ml-4 text-xs text-gray-600 sm:text-slate-700 dark:text-slate-300">v1.0</span>
          </div>

          <p className="mt-3 text-xs text-gray-600 sm:text-slate-700 dark:text-slate-300 max-w-2xl">
            This header is decorative only — controls, tools and steps are available in the section below to help you practice and learn algorithms.
          </p>

          {/* decorative progress-like strip as integrated accent */}
          <div className="mt-4 w-full max-w-md h-3 rounded-full relative overflow-hidden" aria-hidden>
            <div className="absolute inset-0 bg-gradient-to-r from-[rgba(45,212,191,0.95)] via-[rgba(99,102,241,0.9)] to-[rgba(250,204,21,0.95)]" style={{ width: '36%', transform: 'translateX(0)' }} />
            <div className="absolute inset-0 bg-white/30 dark:bg-black/20" style={{ mixBlendMode: 'overlay' }} />
          </div>
        </div>

        {/* Right: isometric cube (keeps visual balance) - larger, more modern with color overlays */}
        <div className="hidden md:flex items-center justify-center w-72 h-56 relative">
          <div className="absolute inset-0 flex items-center justify-center">
            <div className="w-60 h-44 rounded-2xl blur-3xl opacity-70" style={{ background: 'radial-gradient(circle at 20% 30%, rgba(99,102,241,0.7), transparent 30%), radial-gradient(circle at 80% 80%, rgba(45,212,191,0.55), transparent 40%)' }} />
          </div>

          <div className="relative w-52 h-52" style={{ perspective: '700px' }}>
            <div style={{ width: '200px', height: '200px', transformStyle: 'preserve-3d', transform: 'rotateX(18deg) rotateY(-22deg)', animation: 'spin-slow 26s linear infinite' }}>

              <svg viewBox="0 0 120 120" xmlns="http://www.w3.org/2000/svg" className="absolute" style={{ width: '200px', height: '200px' }} aria-hidden>
                <defs>
                  <pattern id="camouflageLarge" patternUnits="userSpaceOnUse" width="16" height="16" patternTransform="rotate(12)">
                    <rect width="16" height="16" fill="#c7d9b6" />
                    <path d="M0 8 C4 4 12 12 16 8 L16 0 L0 0 Z" fill="#8fa36a" />
                    <path d="M0 10 C4 14 12 6 16 10 L16 16 L0 16 Z" fill="#6b8a4d" />
                  </pattern>
                </defs>

                <g>
                  <polygon points="60,10 110,36 110,84 60,110 10,84 10,36" fill="rgba(2,6,23,0.02)" />

                  {/* make the first sticker (top-left) camouflaged to match request */}
                  <polygon points="60,10 110,36 60,62 10,36" fill="#F59E0B" strokeOpacity="0.06" stroke="#000" strokeWidth="0.5" />
                  <polygon points="60,62 110,36 110,84 60,110" fill="#10B981" strokeOpacity="0.04" stroke="#000" strokeWidth="0.5" />
                  <polygon points="10,36 60,62 60,110 10,84" fill="#EF4444" strokeOpacity="0.04" stroke="#000" strokeWidth="0.5" />

                  <g className="sticker-line">
                    <line x1="60" y1="10" x2="110" y2="36" />
                    <line x1="60" y1="62" x2="110" y2="36" />
                    <line x1="10" y1="36" x2="60" y2="62" />
                    <line x1="60" y1="110" x2="110" y2="84" />
                  </g>

                  <ellipse cx="78" cy="40" rx="3.4" ry="1.5" fill="#ffffff" opacity="0.22" />
                </g>
              </svg>

              {/* soft shadow */}
              <div style={{ position: 'absolute', left: '10px', top: '132px', width: '180px', height: '26px', borderRadius: '999px', filter: 'blur(14px)', background: 'rgba(2,6,23,0.14)' }} />
            </div>
          </div>
        </div>
      </div>

      {/* bottom wavy divider to transition into content */}
      <div className="absolute left-0 right-0 bottom-0 h-8 pointer-events-none">
        <svg viewBox="0 0 1440 80" className="w-full h-full" preserveAspectRatio="none" aria-hidden>
          <path d="M0 40 C200 80 400 0 720 40 C1040 80 1240 0 1440 40 L1440 80 L0 80 Z" fill="white" opacity="0.96" />
          <path d="M0 40 C200 60 400 10 720 40 C1040 70 1240 10 1440 40 L1440 80 L0 80 Z" fill="rgba(2,6,23,0.03)" />
        </svg>
      </div>

    </header>
  );
}