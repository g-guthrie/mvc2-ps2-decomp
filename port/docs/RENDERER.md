# Port F: app skeleton + renderer core

The render library ("fl", `0x003DB000-0x003F0FFF` plus `0x00411C10-0x00421300`) is
re-implemented at its **API level** on GL ES 3.0 / WebGL2 (GLSL ES 3.00), as
`RENDER_PATH.md` §9 option B recommends. The **browser is the primary target**:
Emscripten, wasm32 and WebGL2, installable as a PWA for iPhone Safari, Android
and desktop. A native SDL2 build of the same code is kept for debugging. No GS
or VU emulation is involved, and no ROM is read at runtime: assets come from
the user's own disc image.

## Layout

| Path | What |
|---|---|
| `port/platform/gl.h`, `gl_load.c`, `gl_alias.h` | GL entry points. Native builds load every function through `SDL_GL_GetProcAddress`, so one binary runs on a GL ES 3 context (preferred) or a desktop GL 3.3 core context (fallback). Emscripten links WebGL2 directly. `gl_shader_header()` returns `#version 300 es` or `#version 330 core`, so the shader bodies are shared. |
| `port/platform/platform.h`, `platform_sdl.c` | SDL2 window and context, fixed 60 Hz loop, input merge, lifecycle (pause/resume) |
| `port/platform/pad.h`, `pad.c` | PS2 pad model: raw libpad word, then the fl device word, then the game word (tables from the decomp) |
| `port/platform/touch.h`, `touch.c` | On-screen touch pad: 8-way d-pad, LP HP A1 / LK HK A2, START (layout and hit-testing) |
| `port/platform/fs.h`, `fs.c` | File layer: `FsSource` (read_at callback), ISO9660 walk, AFS by (partition, index). C ports of `iso.py` and `afs.py`, with 64-bit offsets |
| `port/platform/png_write.c` | Small PNG writer (stored deflate) for headless captures |
| `port/render/render.h` | Public fl API (the table below) |
| `port/render/r_gl.c` | State (`func_003DF850`), blend mapping, texture and palette handle tables, batching, 2D prims, canvas, present, window-space overlay |
| `port/render/r_char.c` | Character banks: `func_00411C10` and `func_00412260` on an index-texture atlas |
| `port/render/r_mesh.c` | 3D mesh path (VU1 replacement): POL load (`func_00415320`/`func_00415590`/`func_003EE6F0`), descriptor selection (`func_003E0F60`), draw (`func_003F0500` + setup callbacks) with one uber-shader, node walk (`func_001538B0`), battle camera (`func_00413F50`) and the VU0 matrix helpers |
| `port/render/decode.c`, `decode.h` | LZ16 (`func_00176230`), tile LZ (`func_00413A80`), TEX-pack records, TIM2 (CSM1 unswizzle), ARGB1555 |
| `port/apps/viewer.c` | The viewer app |
| `port/web/` | `shell.html` (file picker, IndexedDB cache, visibility), `manifest.webmanifest`, `sw.js`, procedural icons (no game art) |
| `port/cmake/frontend.cmake` | Defines the targets `port_platform`, `port_render` and `viewer`. It is additive to Port A's `mvc2_game` and does not link it. |
| `port/frontend/CMakeLists.txt`, `CMakePresets.json` | Standalone project with the presets `native` and `web` |

## Build and run

```sh
# native debug build (64-bit is fine; nothing assumes 32-bit pointers)
cd port/frontend && cmake --preset native && cmake --build --preset native
SDL_VIDEODRIVER=offscreen ../../build/port-native/viewer --iso ../../private/disc/mvc2.iso \
    --frame 200 --screenshot ../../private/converted/viewer_pl00_f200.png --frames 5
#   other options: --char N --pal P --stage-tex N --plain (character only, on black)
#   --desktop-gl --present integer|sharp --touch --size WxH --window-shot OUT.png
#   3D stage (default stage 0; --stage -1 = the old texture backdrop):
#   --stage N (0..16 = STG00..STG10) --stage-only (no 2D layers) --roots 0|world|all
#   --nearest --fog (per-stage fog from D_00477060) --lit (desc 0 demo) --cam-x X
SDL_VIDEODRIVER=offscreen ../../build/port-native/viewer --iso ../../private/disc/mvc2.iso \
    --stage 1 --screenshot ../../private/converted/mesh/viewer_stage01.png --frames 2
# soundtest: render 3 s of BGM track 3, or open it headless for 60 frames
SDL_VIDEODRIVER=offscreen SDL_AUDIODRIVER=dummy ../../build/port-native/soundtest \
    --iso ../../private/disc/mvc2.iso --track 3 --render /tmp/t3.wav --seconds 3

# web build (an emcmake equivalent through the preset's toolchain file)
source /home/user/emsdk/emsdk_env.sh
cmake --preset web && cmake --build --preset web     # build/port-web/viewer.{html,js,wasm}
(cd ../../build/port-web && python3 -m http.server 8766)  # open http://127.0.0.1:8766/viewer.html
```

If the Emscripten SDL2 port download from `github.com/.../archive/*.zip` is blocked
(it was in this container: HTTP 403), clone it with git instead and point emcc at
the clone:
`git clone --depth 1 -b release-2.32.10 https://github.com/libsdl-org/SDL <dir>`, then
`export EMCC_LOCAL_PORTS=sdl2=<dir>` (a `git clone` of SDL2 `release-2.x`; on this machine `/home/user/deps/SDL2`). Set the variable for every web build.

Integration with Port A: the top-level `port/CMakeLists.txt` (`mvc2_game`, 32-bit
only) can `include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/frontend.cmake)` in its
Emscripten configuration. The native debug viewer stays in the standalone
`port/frontend` project, because Port A rejects 64-bit builds and only 64-bit
SDL2 is installed.

## Platform layer

- **Loop** (`plat_frame`): accumulate real time (clamped to 0.25 s), then for
  each 1/60 s step run `plat_poll_input()` immediately followed by
  `app->update()`, with at most 8 steps per frame. After the steps, `render()`
  and swap. Native builds loop in `plat_run`; Emscripten uses
  `emscripten_set_main_loop_arg(..., 0, 0)` (requestAnimationFrame, returns at
  once). No threads are used. In fixed-step mode (headless capture) each frame
  runs exactly one step.
- **Lifecycle:** pause on `SDL_APP_*BACKGROUND`, `WINDOWEVENT_HIDDEN/MINIMIZED`
  and, on the web, `visibilitychange` (`emscripten_set_visibilitychange_callback`).
  While paused no steps run and time does not accumulate. `on_pause(user, 1/0)` is
  called on each transition, so audio can be suspended without losing state.
  Losing focus releases all touches.
- **Input:** every source ORs into one `PadRaw` per port, in libpad bit layout:
  - keyboard for P1: arrows, A S D = LP HP A1 (Square Triangle L1),
    Z X C = LK HK A2 (Cross Circle R1), Q W = L2 R2, Enter = Start, RShift = Select;
  - SDL GameController, which the Emscripten SDL port feeds from the browser
    Gamepad API. Joysticks that SDL cannot map fall back to the W3C "standard"
    gamepad layout;
  - the touch overlay. Taps shorter than one frame are latched.

  `pad_fl_word()` reproduces `func_003EDA60` + `func_003ED920`: the
  `D_00478D50` bit map, the `D_00478DE0` opposite-direction cancel, and the
  stick nibbles from `D_00478D10` (`func_003EE690`).
  `pad_game_word()` reproduces `func_0012F0B0`. Checked: UP→0x2000,
  Square→0x0200, L1→0x0080, Start→0x8000, UP+DOWN→0, analog up-left→0x2800.
  The mapping of MvC2 button names to PS2 buttons (LP=Square, and so on) is a
  default, not taken from the game's config screen.
- **Touch overlay:** the layout is recomputed for the drawable size. In portrait
  it sits in the letterbox below the picture; in landscape it overlaps the picture
  edges. It appears after the first touch, or with `--touch` or the H key. The
  port draws it in window pixels after present (`r_overlay_*`).
- **Files:** `FsSource` abstracts reading. Native builds use stdio; the web build
  uses a MEMFS file (`/disc.iso`) written from the picked `File`. The `File` blob
  is cached in IndexedDB (`mvc2-port/disc/iso`), so the disc is chosen only once,
  and a "Forget cached disc" button clears it. The whole 208 MB image goes into
  MEMFS, which stores it as a JS ArrayBuffer outside the wasm heap; `fread` copies
  only the ranges read. `PORT_PRELOAD` (CMake cache var) bakes a file in with
  `--preload-file` for local testing only.

## Renderer design

- **Canvas:** a 640x480 RGBA8 + DEPTH24 FBO. The PS2's 640x224 interlaced Y/2
  is dropped: the game's 640x480 coordinates are used directly.  The PS2
  displays only rows 0..447 (DISPLAY DH = 447 for the 224-line FRAME buffer,
  set by the game's `func_00100590`); the game frontend passes that to
  `fl_set_display(640, 448)` and present shows only that part.
- **Canvas binding and clear:** every draw entry binds the canvas first
  (`r_canvas_bind`: FBO, viewport, scissor), because the game draws some
  scenes from its logic step, before `func_00170D30`, and present binds the
  window in between.  In the game frontend (`fl_set_flip_clear(1)`) the clear
  colour (state 0x14) and Z are cleared at the first draw after each flip
  (`fl_frame_flip`, `func_003ECD00`), as the PS2 fills the next draw buffer at
  the flip before the frame's chain runs.  The viewer and soundtest keep the
  clear in `fl_frame_begin`.
- **Present** (`func_003ECD00` role): `glBlitFramebuffer` to the window.
  - `INTEGER` mode uses the largest integer scale with NEAREST (default on native).
  - `SHARP_FIT` mode (default on the web) does a NEAREST prescale to the next
    integer multiple, then a LINEAR downscale to fit 4:3. Phones use it because
    640 px rarely fits an integer scale there.
- **One shader program, three modes:**
  - flat;
  - RGBA texture;
  - **index texture (R8) + palette atlas.** The palette atlas is RGBA8,
    256 x 1024 rows, read with `texelFetch`. A palette swap is one
    `glTexSubImage2D` of a single row. Bilinear filtering (state 0x62) is done by
    hand with 4 taps for index textures, honouring the 0x63 clamp/repeat setting.
  The palette row is a per-vertex attribute, so parts with different palettes
  (character part flags) batch together.
- **Colour:** `out = tex * vcol`. Vertex colours are converted exactly as
  `func_003E0CB0` does: textured prims halve every channel (0xFF→0x80) and
  untextured prims halve only alpha; the GS value g is then mapped to g*255/128,
  so 0x80 means 1.0 (GS MODULATE x2). The alpha test discards fragments with
  alpha == 0, matching the GS TEST "alpha != 0".
- **Depth:** NDC z = -z_game, the depth buffer is cleared to 0, and the test is
  GEQUAL/GREATER: larger Z is nearer, as on the GS.
- **Coordinates** are truncated to integers after subtracting the scroll origin,
  matching `fptosi` in the packet builders.
- **Perspective ST:** the clip w is set to 1/q, so GL's perspective-correct
  interpolation reproduces the GS's STQ.
- **Batching:** one dynamic VBO of 65,536 vertices. It is flushed when the
  texture or mode changes, when blend, depth, filter, wrap or scissor state
  changes, or on texture uploads. The viewer frame is 6-7 draw calls.

### Mesh path (`r_mesh.c`, format in `ASSET_FORMATS.md` §6, notes in `MESH_NOTES.md`)

- **Load** (`fl_model_load`, the role of `func_00415320` + `func_00415590`): for
  each mesh it applies `func_00415A00` (render states 0x65, 0x15, 0x61, 0x1A,
  0x12, 0xC from the per-mesh flags), loads the mesh's materials into slots
  0x39+j, does the state-1 dance, and then builds the mesh the way
  `func_003EE6F0` does: the format word is `D_004C2AD4` at that moment, the key
  is `0x21000 | multi<<22 | kind`, and `func_003E0F60` is ported as
  `desc_select`. A mesh without a descriptor is not drawn, as on the PS2.
  Strips become a static `GL_TRIANGLES` IBO (zero-area triangles dropped; no
  culling, as the GS has none). The VBO holds pos/normal/colour bytes/UV.
  Consecutive strips that share a material slot form one draw range, which
  captures that slot's material colour and texture handle (the
  `func_003EFA40` packet).
- **Draw** (`fl_mesh_draw` = `func_003F0500` + setup callback): MVP =
  slot 0x19 × view 0x16 × projection 0x17. The viewport (state 0x18,
  `func_003DD5D0`: x scale `(w/2)/1.333333`, y scale `-h/2`, origin
  `(x + w/2, y + h/2)`, depth `-(fb - fa)`) is applied in the vertex shader, so a
  mesh lands in the same 640x480 canvas and depth convention as the 2D prims.
  One program, with feature flags taken from the format word:
  - vertex colour `ftoi0(byte * 0.5 * mod)` or material colour
    `ftoi0(min(128, d * 128) * mod)`;
  - `mod` = state 0x66 when the format has 0x20000;
  - UV matrix slot 0x1A (0x4000);
  - fog (0x8000) `F = (far - w) / (far - near) * 255` with states 0x10/0x11/0xF;
  - lit (0x100) with three directional lights brought into model space as the
    `func_003E1B20` setup does.

  The fragment stage does GS MODULATE (`tex * c / 128`), FOG, alpha test
  `a != 0`, the blend from 0x5D and Z GEQUAL. Colour and fog are interpolated
  **affinely in screen space**, as on the GS: GLSL ES 3.00 has no
  `noperspective`, so the shader interpolates `c * w` and `w` and divides. Only
  UV is perspective-correct. The texture filter (0x62) and wrap (0x63) are read
  at draw time, as `func_003EFF10` does.
- **Walk** (`fl_model_draw` = `func_00152180` + `func_001538B0` + `func_001537D0`):
  the game's exact (non-recursive) node walk, per-mesh blend from flag 0x100,
  UV scroll from flag 2 + object flag 0x20000, and flag 0x200 (half alpha in
  0x66). It also handles the object-flag Z and clamp overrides.
- **Camera** (`fl_camera_apply` = `func_00413F50`, defaults `func_00122DA0`):
  - eye (0, 95, 320 / tan 21.5°), target (0, 95 + 98.4, 0) with `n = 1`;
  - horizontal FOV 43° over 640 px, near 1, far 120000 (2200000 on stages 1/0xA);
  - viewport {0, -16, 640, 480, 0, 1}.

  With this camera 1 world unit is 1 pixel at z = 0, and y = 0 is the floor line.

### Entry point mapping

| Render-library entry point | Port (`port/render/render.h`) | Notes |
|---|---|---|
| `func_003DF850(id, v)` state setter | `fl_set_render_state(id, uintptr_t v)` | Same switch, with storage mirrored. 4-7 hold the texture handle `(pal<<16)\|tex`. 0x5D and 0xD set blend; 0x62 filter; 0x63 wrap; 0x6B/0x6C Z write/test (**the original 0x6C falls through into 0x6B; kept**); 0x14 clear colour; 0x19-0x38 matrices; 0xE, 0xF, 0x10, 0x11, 0x66, 0x5F and the mode flags are stored. Materials (0x39-0x58, 76 bytes) and lights (0x59-0x5B, 100 bytes, direction normalised) are stored for the mesh path; 0x18 stores the viewport `{x, y, w, h, fa, fb}` and sets the scissor as `func_003DD4E0` does. `fl_get_render_state` = `func_003DFF80` (ids 1, 0x15, 4-7, 0x14, matrices, materials). |
| `func_003E06D0` blend packet | `set_blend_from_state()` | Each accepted src\|dst pair is decoded from the GS ALPHA value it emits, so GL gives the GS result. Rejected pairs keep the previous blend, as on the PS2. Two deviations from the RENDER_PATH table, following the actual ALPHA values: 0x31 = `Cs - Cd*As` (FUNC_SUBTRACT, ONE, SRC_ALPHA) and 0x51 = `Cs - Cd*Ad`. 0x11 with 0x400 = `Cs - Cd`. For 0x11 with 0x800 the PS2 register value is undefined; the port uses ONE, ONE. |
| `func_003DF7D0` defaults | `fl_default_state()` | `D_004C2AD4=0x102`, `D_004C2AD0=0x38B032`, Z GEQUAL (+ write via the fall-through), bilinear, full scissor |
| `func_00170D30` / `func_00170D70` frame begin/end | `fl_frame_begin()` / `fl_frame_end()` | begin binds the canvas, clears colour (state 0x14) and Z=0, sets blend 0x32 and nearest |
| `func_003EC160` init | `plat_init()` + `r_init()` | |
| `func_003ECD00` flip | `r_present(w, h, mode)` + `plat_swap()` | |
| `func_003E00D0` scissor | `fl_set_scissor()` | Assumed to be in 640x480 space. **Check the callers**: the original clamps to `D_004C2AE4/E0` (framebuffer w/h). |
| `func_003E00B0` clear colour | `fl_set_clear_color()` | |
| `D_0062BF8C/90` scroll origin | `fl_set_origin()` | |
| `func_003DF0C0` textured gouraud tri | `fl_tri_tex(const FlTri *)` | Byte-compatible struct (0x54 bytes). Rejects unknown handles, as the original rejects textures without a VRAM record. |
| `func_003DEE00` untextured tri | `fl_tri(const FlTri *)` | |
| `func_003DF490` textured sprite | `fl_sprite_tex(const FlSprite *)` | 0x34 bytes. One RGBAQ, so Q = v0.w and uv1 is scaled by w1/w0, as on the GS. Z comes from v1. Affine. |
| `func_003ED1C0(mode, c)` fill | `fl_fill_screen()` | mode 0: TEST AFAIL=ZB_ONLY writes only Z=0 (depth clear). mode 1: colour with A=0, plus Z. Both respect the scissor. |
| `func_00420BF0` batch-writer quad | `fl_quad_tex(const FlQuad *)` | Two FlTri back to back; the strip is t0.v0-2 plus t1.v2. The `func_00420980..00421270` writer bookkeeping is not needed. |
| `func_00418200` TIM2 → texture (+CLUT) | `fl_tex_load_tim2()` | 4/8 bpp: R8 index texture plus a palette row; CSM1 swizzle undone; 16/24/32 bpp: RGBA8. Returns `(pal<<16)\|tex`. |
| `func_003E8B30` / `func_003E9010` blank texture/palette | `fl_tex_create()` / `fl_pal_create()` | |
| `func_003EA660` ensure resident | (implicit) | Textures are uploaded at creation; there is no VRAM LRU. |
| `func_003E9580`/`95E0`/`EA070`/`EA0D0` lock/unlock | `fl_tex_update()` / `fl_pal_update()` | |
| `func_00411C10` character slot setup | `fl_char_bank_create()` | 16 consecutive palette rows = `slot.d[0..15]`, converted from ARGB1555 (`<<3`, A = bit15) |
| `func_00412260` character draw | `fl_char_draw(bank, frame, m[16], argb, palette)` | Tiles are decoded lazily into 1024x1024 R8 atlas pages (shelf packer, 1 px gutter), replacing the 26-page PSMT4 LRU. Placement is cumulative `pos -= (dx,dy)`; a flip anchors at `fw8*8 - size` (equivalent to the per-sub-block placement). Palette = `((flags>>4)+palette)&15`. Colour `(c+1)>>1`. Corners are transformed by the row-major matrix (translation `m[12..13]`, depth `m[14]`). Negative scale mirrors; axis-aligned results are integer-snapped. |
| palette animation (`func_00174BC0`, `D_004F54D0`) | `fl_char_set_palette_1555()` / `fl_char_load_palette()` | One row upload |
| `func_00415590` mesh build (+ `func_00415320`, `func_00415A00`, `func_003EE6F0`, `func_003E0F60`) | `fl_model_load(pol, size, &{tex[], ntex, b34, b30, keep_state})` | `tex[i]` = handle of TEX record i. `b34`/`b30` = `D_004C2B34`/`D_004C2B30` (4 / 1 for stages). |
| `func_003F0500` mesh draw (+ setup callbacks, `func_003EFA40`) | `fl_mesh_draw(model, mesh)` | All 49 descriptors map to one program. Clip variants rely on GL clipping. Lit+modulate variants multiply the lit colour by 0x66 (not checked against their microcode). |
| `func_00152180` / `func_001538B0` / `func_001537D0` object draw | `fl_model_draw(model, root, objm, objflags, u, v)` | The caller sets 0x66 (`func_00152400`). |
| `func_00413F50`, `func_003DD2E0`/`DD360`, `func_003DD5D0`, `func_003DDF20`, `func_003DE160`, `func_003DD260` | `fl_camera_apply`, `fl_mat_perspective`, state 0x18, `fl_mat_look_at`, `fl_mat_mul`, `fl_mat_identity` | |

## Evidence (all files under `private/converted/`, gitignored)

- `viewer_pl00_f200.png`: native, headless (SDL offscreen, Mesa llvmpipe, GL ES 3.2
  context). Ryu PL00 frame 200 at (320,400) over STG00TEX record 1 tiled with
  REPEAT, a floor strip (record 3 modulated by 0x909090), untextured gouraud HUD
  bars with an additive (0x12) sheen, a translucent shadow pass (y-scale -0.15), a
  mirrored copy with palette +1, and debug text from `/FONT8_8.TM2` drawn through
  the quad path.
- **Pixel-exact characters:** `--plain` renders of frames 200, 108 (H-flip), 3
  (palette offset from the part flags), 140 and 100 were compared with
  `chars.py` output: **0 mismatching pixels and 0 stray pixels** on all five
  (`verify/c_f*.png` against `verify/pl00_f*_p0.png`).
- **TIM2:** the 512x512 8bpp texture drawn 1:1 matches `tim2.py`
  (`tex/802_STG00TEX/001.png`) on 117,760 / 117,760 texels.
- **GL ES 3.2 against GL 3.3 core (`--desktop-gl`):** the same frame renders on
  both. 1,078 pixels differ, by at most 1 LSB (rounding in the vertex-colour
  modulate).
- **Web, desktop viewport** (`web_desktop*.png`): headless Chromium (Playwright,
  SwiftShader WebGL2):
  - context "WebGL 2.0 (OpenGL ES 3.0 Chromium)";
  - the ISO is picked through the file input, cached in IndexedDB (208,695,296
    bytes), and reloaded from the cache without the picker after a page reload;
  - `visibilitychange` gave `viewer: paused` / `viewer: resumed`.
- **Web, phone viewport** (`web_phone.png`, 390x844 at dpr 2, touch): tapping LP
  changed the palette to 1 and tapping the d-pad's right edge advanced to frame 201.
  The overlay is drawn in the letterbox.
- **Native portrait capture** with the overlay: `native_touch_portrait.png`.
- **Mesh path** (`private/converted/mesh/`, details in `MESH_NOTES.md`):
  - All 17 stages, root 0, were rendered by the GL path
    (`c_root0_nearest_NN.png`) and by the independent pure-Python rasteriser in
    `mesh.py` (`stgNNpol/stgNNpol_ref.png`), both with nearest sampling and no fog.
    In 16 stages, 99.6-100 % of pixels agree within 2 levels (most of the rest
    are texel-edge sampling differences). STG0D agrees on 97.2 %; the band of
    differences there looks like coplanar or translucent overlap (unresolved).
    The numbers are in `compare_c_vs_python.txt` and the diff images are
    `diff_NN.png`.
  - The full composition (`viewer_stage00_full.png`) puts the stage, Z clear,
    HUD and two characters on the projected floor line. STG00 matches the
    stage-select thumbnail 000 (airship) and STG01 matches thumbnail 001 (desert).
  - Web (headless Chromium, SwiftShader WebGL2): `web_stage00.png`, and
    `web_stage01_world.png` after pressing W (R2, next stage).
  - The lit program (desc 0) demo is `c_stg00_lit_desc0.png`. Stages never use it.

## Done / remaining

Done:
- Platform: window/context (ES 3 preferred, 3.3 core fallback); 60 Hz loop with
  input polled before each update; keyboard, controller and touch merged into the
  PS2 pad layers; lifecycle pause; ISO/AFS reader; PNG capture.
- Renderer: render state with blend, depth, filter and wrap; texture and palette
  handle tables; TIM2; all five 2D prim entry points; fill; character
  bank + draw; integer and sharp-fit present; window overlay.
- Mesh path: POL load → GL buffers, descriptor selection, one uber-shader
  (vertex or material colour, modulate, UV matrix, fog, lit), the game's node
  walk and the battle camera.
- Viewer: native and web/PWA, headless capture, IndexedDB-cached disc, 3D stages
  with stage select (HP / R2 / L2) and 2D layers on top.

Remaining / next steps:
1. **Mesh path follow-ups.** The VBO/IBO conversion and the uber-shader are done
   (above, `MESH_NOTES.md`). Stage geometry turned out to use descs 45/41/33/16/18,
   not 11/12. Open items:
   - **Stage objects:** only root 0 (the static set) is placed faithfully. The
     other roots are positioned by the per-stage scripts
     (`func_003D0FA0` → `D_00476DB0[stage][]`). The viewer's default
     "world roots" mode is a heuristic. This resolves itself once Port A runs the
     scripts and calls `fl_model_draw` per object.
   - **Fog:** decoded from `D_00477060` and implemented, but off by default in the
     viewer. With the decoded parameters the STG00 sky (z ≈ -100000, far 12000)
     would be fully fogged, which contradicts its UV-matrix (scroll) flag. One link
     in the fog chain, probably who enables `D_004F1D20` in battle, is unverified.
   - **Lit programs:** desc 0 is implemented from its microcode but untested
     against the game. The lit+modulate, specular (0x106) and extra-attribute
     (0x121235, 0x06xxxxxx) variants approximate or are not covered. The clip
     variants rely on GL clipping. Triangles that cross the guard band are
     dropped by ADC on the PS2 but kept here.
   - **Alpha above 0x80:** GL clamps the source alpha to 1.0, while the GS
     over-brightens (seen in neither the stages nor the tests).
   - **Battle stage filter:** `func_00152720` sets bilinear before list 6, but
     the other battle draw paths keep nearest. The viewer uses bilinear.
   - **2D path:** done: colours are interpolated affinely (`c * w / w`).
   - **Packet vertex writes:** done: `fl_clay_vertices` keeps a CPU copy of
     each clay mesh; the frontend re-reads the game's VU1 packet after a
     write pass (`fe_mesh.c`, BOOT_NOTES renderer pass).
   - **Colour scale:** done: untextured descriptors use 255 (D_004779F0 +0x28).
2. Hook the API into the game once Port A links: the `func_XXXXXXXX` symbols
   become thin wrappers around `fl_*`. The prims take the game's structs as is;
   pointers in render states are host pointers (`uintptr_t`).
3. Check scissor units against game callers (`D_004C2AE0` = 224 or 448?).
   Check the colour/alpha semantics of `func_00413DF0`'s `0xAAFFFFFF` argument
   to `func_00412260`; the port treats it as ARGB with `(c+1)>>1`.
4. The third cache path in `func_00412260` (tiles larger than 0x400 px) was
   assumed to match the others; the pixel-exact checks above cover 64x64 tiles.
5. Palette atlas rows are not reclaimed on release. Add a free list when
   characters are swapped often.
6. `func_00418410`, `func_00418570` and `func_00415B00` resource kinds are not
   implemented (only TIM2, kind 1).
7. Touch overlay labels: buttons are only colour-coded; draw LP/HP/... with the
   debug font. Make the button mapping configurable.
8. The web build holds the full ISO in MEMFS (about 208 MB of JS memory). If iOS
   memory becomes a problem, read byte ranges from the `File` in a worker
   (WORKERFS or FileReaderSync), or extract only the AFS entries needed into
   IndexedDB.
9. `-sMAXIMUM_MEMORY=2GB` and SDL2 2.32.10 from emsdk. The PWA service worker
   is network-first and caches the shell for offline start.

## Debugging aids (game frontend)

- `MVC2_MESH_DUMP=F`: at game frame F, log every clay draw (world matrix,
  format, descriptor, texture, 0x66, material colour, screen bounds, NDC Z
  range, the canvas pixel at the centre, scissor, blend and depth state) and
  where `func_00170D30` falls among them.
- `MVC2_LOG_STATE=1`: each distinct value of render states 0x5D, 0xD, 0x62,
  0x63, 0x6B and 0x6C once, with the frame it first appeared.
- `MVC2_NO_VTXWRITE=1`: ignore the game's packet vertex writes (A/B tests).
- `-v`: also checks each new clay's packet against its GL mesh.
