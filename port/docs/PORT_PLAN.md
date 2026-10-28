# Port plan

The target is a native build of the decompiled game that anyone can run.
The primary target is a **browser build**: Emscripten wasm32, WebGL2 and Web
Audio, installable as a PWA, so one build covers iPhone, Android, desktop and
consoles with a browser. A native desktop build (i386 now, 64-bit later) is
kept for debugging. There is no emulator and no ROM at runtime. The player
supplies their own disc image once, and the game data is read from it.
Nothing copyrighted is shipped or committed.

## Why this shape

- **The game core is plain logic** (`0x122670..0x3DB7F0`, see ENGINE_MAP.md),
  and about 90 boundary functions form the platform layer
  (PLATFORM_SURFACE.md).
- **Rendering is replaced at the library API, not emulated.** That API is the
  state setter `func_003DF850`, the 2D primitives, the character drawer
  `func_00412260`, and the strip meshes that feed the 49 VU1 programs
  (RENDER_PATH.md). GIF, VIF and VU1 are never emulated.
- **The game assumes 32-bit pointers.** wasm32 runs it as written, so
  64-bit native builds need a pointer-arena step that is deferred.
- **Logic runs in 60 Hz lockstep** from main `func_00170C30`. This is
  deterministic, which makes rollback netcode a realistic later phase.

## Phases

Status: ✅ done · 🔄 in progress · ⬜ not started

### Phase 0: foundations ✅
| Item | Where |
|---|---|
| ✅ Engine map, platform surface, render path, asset loading | `ENGINE_MAP.md`, `PLATFORM_SURFACE.md`, `RENDER_PATH.md`, `ASSET_LOADING.md` |
| ✅ Asset converters: ISO, AFS, character sprites, TIM2, ADX, HD/BD (verified against the disc) | `port/tools/convert/`, `ASSET_FORMATS.md` |
| ✅ PS2 vs NAOMI data diff | `ARCADE_DIFF.md`, `port/tools/arcade_diff.py` |
| ✅ All 16,477 TUs compile for wasm32 (Emscripten), i386 and bare wasm32 | `port/CMakeLists.txt`, `HOST_BUILD_ISSUES.md` |

### Phase 1: link and boot 🔄
Goal: one executable that links with zero undefined symbols, then runs the
game's init path and N frames headless (under node and natively).
1. Generated glue: data aliases into data units, BSS definitions, text
   aliases, and code labels mapped to handles (about 8,800 symbols).
2. Platform stubs for syscalls, IOP/SIF, DMA, VU0 and inline asm. Each stub
   is logged and listed in a generated table.
3. Signature audit, so wasm-ld reports no mismatch traps: real prototypes,
   returns added to non-void functions with no return, and implicit
   declarations fixed.
4. Headless frame loop driven by the host, with each frame's logic state
   hashed. This is the regression oracle for everything after it.

### Phase 2: platform layer 🔄
1. App shell: SDL2 on native; on the web, a canvas with Gamepad API, keyboard
   and a touch overlay; a visibility pause.
2. Disc intake: a file picker for the user's ISO, with the AFS tables cached
   in IndexedDB so it only happens once. The native build reads a path.
3. File I/O: the game's AFS/CD reads become synchronous reads from the
   cached image, so loads are near instant.
4. Renderer at the library API: textures from TIM2/CLUT, sprites from the
   character drawer, 2D prims and stage meshes, all drawn with GL/WebGL2.
   It renders progressive at native resolution, with optional
   nearest-neighbour or CRT filters.
5. Audio: ADX streams for music and HD/BD banks for sound effects, mixed in
   an AudioWorklet (web) or SDL audio (native). The TSD command semantics
   still need tracing.
6. Saves go to `localStorage`/IndexedDB on the web and to a file natively.

### Phase 3: playable and correct ⬜
1. Boot through title, character select and a versus fight against the CPU.
2. Compare frames against PCSX2 at fixed inputs (the logic-state hash plus
   screenshots).
3. Use the C-less functions and the remaining placeholders (C_COVERAGE.md)
   to set the order of matching work that matters for gameplay.

### Phase 4: fixes for PS2 gripes ⬜
See PS2_GRIPES.md. In order:
| Fix | Cost |
|---|---|
| Progressive 60 fps output, clean scaling | falls out of phase 2 |
| Low-latency input (poll right before the logic step), full remapping | small |
| No load times | falls out of phase 2 |
| Clean audio resampling; check whether the music cut-out still happens with the port's own ADX player | small |
| "Unlock everything" option | small |
| **Arcade accuracy** toggles: frame data and boxes, damage and hit data, CPU AI, loaded from the user's own `mvsc2.zip` (ARCADE_DIFF.md §5) | medium |
| Assist invulnerability and the counter glitch: locate both in code and diff against the NAOMI decomp | medium |
| Optional "arcade slowdown" toggle | small |

### Phase 5: online ⬜
Rollback netcode over WebRTC on the web and UDP natively. It relies on the
deterministic logic step and on save/restore of the game state, which is a
plain memory region on wasm32. Both peers must use the same arcade toggles,
so their hash goes into the handshake.

### Later
- A 64-bit native build: a 32-bit pointer arena, or `u32` handle fields
  rewritten.
- A native iOS/Android wrapper around the same web build, or the native
  build with a Metal or GLES backend.

## Personal single-file build

For your own use only: one `.html` file containing the game code and the
data from your own disc. Double-click it to open it in any modern browser,
offline. Do not share or publish it.
```
source /home/user/emsdk/emsdk_env.sh; export EMCC_LOCAL_PORTS=sdl2=<SDL2 clone>
emcmake cmake -S port/frontend -B build/port-web-single -DCMAKE_BUILD_TYPE=Release -DPORT_SINGLE_FILE=ON
cmake --build build/port-web-single
python3 port/tools/pack_personal.py build/port-web-single/viewer.html private/disc/mvc2.iso private/MvC2.html
```
The output is about 170 MB: a gzip of the image (about 126 MB) as base64.
The page needs `DecompressionStream`, so Chrome/Edge 80+, Firefox 113+ or
Safari 16.4+.

## Ground rules

- The matching build stays byte-exact. All host glue lives under `port/`,
  and `src/` changes only when the matching build still verifies.
- No game data in the repo. Converted art and audio stay in the
  user's private folder.
- Each phase ends with something runnable and a screenshot or log to show for
  it.
