# Port H: mesh path progress notes

Running log so a restarted session can resume. Newest entries at the bottom.
Outputs go to `private/converted/mesh/` only (gitignored symlink).

## 1. Format decode (done)

- Loader chain read: `func_00170170` case 1 (state 1 = 0, state 2 = 0 first) →
  `func_0016F430` (LZ16 TEX → `D_004C28B0`, `func_0016F4D0` relocates the POL's three
  header offsets) → `func_00415020(0xC10)` (TEX records → handles) →
  `func_00415320` (materials) → `func_00415590(D_004F80D0, pol, 6, 0)` (asm; meshes
  and node trees; read from `asm/main.s` in the main checkout).
- POL = 3 offsets: model container (mask 1 meshes, 2 materials, 4 texture table),
  node container (type 0 = root list, others = 64-byte node records), u32 per-mesh
  draw flags. Accessors `func_003F1F10/19B0/1F90/1B10/1D10`, parsers `func_003F2EB0`
  (attr 0xDF00, kind 0x35), `func_003F2BF0` (0x9F00, kind 0x25).
- Per-mesh flags → render state in `func_00415A00` at build time: bit0 → 0x15=1
  (vertex colour) else 2 (material colour); bit1 → 0x61 (0x4000, UV matrix slot
  0x1A); bit2 → fog 0x8000 (when bit1 too); bit0&bit1 → 0xC=1 (clip 0x40); always
  0x65=1 (0x20000, global modulate). State 1 is 0 at stage load, so **stage meshes
  are unlit**. STG00: flags 7 → desc 45, 6 → desc 41, 0 → desc 17.
  The earlier RENDER_PATH guess "11/12 = most stage geometry" is wrong for stages.
- Draw: `func_001538B0` node walk (see mesh.py `walk_tree`), `func_001537D0`
  (blend from flags 0x100: `D_00444880[(f>>16)&7] | D_004448A0[(f>>19)&7]`, else
  0x01; UV matrix 0x1A from flags 2), flag 0x200 halves the 0x66 alpha.
- Camera: `func_00122DA0` defaults + `func_00413F50`; projection `func_003DD360`,
  viewport `func_003DD5D0` with `{0,-16,640,480,0,1}`.
- Root 0 of every stage is the static set in world coordinates; other roots are
  object-local models placed by per-stage scripts (not reproduced).

## 2. Python reference (done)

`port/tools/convert/mesh.py ISO OUT STAGE [--roots 0] [--render] [--info]`
→ `private/converted/mesh/stgNNpol/` OBJ + MTL + tex PNGs + `_ref.png`.
STG00 root 0 renders the airship deck; matches SELSTG thumbnail 000.

## 3. C renderer (done)

- `port/render/r_mesh.c`: `fl_model_load` (func_00415590 role, with func_00415A00
  and the state-1 dance), `desc_select` (= func_003E0F60), per-mesh VBO + IBO
  (triangle list from the strips) with per-material draw ranges, `fl_mesh_draw`
  (func_003F0500 + setup callback: one uber-shader), `fl_model_draw`
  (func_00152180/func_001538B0/func_001537D0), `fl_camera_apply` (func_00413F50).
- `r_gl.c` now stores materials 0x39.., lights 0x59.. and the viewport 0x18 (which
  also sets the scissor, as func_003DD4E0), and exposes them through
  `r_internal.h`. `fl_get_render_state` = func_003DFF80.
- GL entry points added to `platform/gl.h` / `gl_alias.h`: glUniform1f/2fv/3fv/4fv,
  glUniformMatrix4fv, glDrawElements, glDeleteBuffers, glDeleteVertexArrays,
  glDisableVertexAttribArray, glVertexAttrib4f, glDeleteProgram.
- Colour and fog are interpolated affinely in screen space (as on the GS), via
  `c * w` / `w` varyings, because GLSL ES 3.00 has no `noperspective`. This was
  found on STG0B (a 4-vertex gouraud floor): before the fix, 48k pixels were off
  by more than 32 levels; after it, 5.

## 4. Viewer (done)

`viewer --stage N` (default 0) draws: camera (func_00122FE0), stage roots, Z clear
(func_003ED1C0(0,0)), then the HUD and two characters on the projected floor line.
Keys: HP/R2 next stage, L2 previous, HK cycles root mode (root 0 / world-scale
roots / all), J/L pan. `--stage-only --nearest --roots 0` is the setting used for
comparisons with mesh.py. `--fog` enables the D_00477060 fog (read from
SLUS_204.86 on the disc at runtime). `--lit` builds every mesh with format 0x102
(desc 0) and one light, as a demo.

## 5. Evidence (private/converted/mesh/)

- `compare_c_vs_python.txt`: GL against the Python rasteriser, all 17 stages,
  root 0. In 16 stages, at least 99.6 % of pixels agree within 2 levels. STG0D
  agrees on 97.2 % (a band near the far floor: coplanar or translucent overlap,
  unresolved).
- `viewer_stage00_full.png`, `viewer_stage01.png`: full compositions.
  `web_stage00.png`, `web_stage01_world.png`: the web build in headless Chromium
  (SwiftShader), stage select with the W key.
- `c_stg00_desktopgl.png`: GL 3.3 core against GL ES 3.2, all pixels within 2 levels.
- `viewer_backdrop_mode.png` (`--stage -1`) against the old `viewer_pl00_f200.png`:
  identical except the stats text line.
- `c_world_montage.png` / `ref_montage.png`: all stages. SELSTG thumbnails
  (`selstg_montage.png`) show the same scenes (000 airship, 001 desert, 006 clock
  tower, ...). The framing cannot be compared: the thumbnails use other cameras.

## 6. Open / unverified

- Per-stage object scripts (func_003D0FA0 → D_00476DB0[stage][]) place roots 1..n.
  They are not reproduced. "World roots" is a size heuristic. STG08 has almost
  everything in non-root-0 trees.
- Fog: the decoded parameters fog the STG00 sky completely (far 12000, sky at
  about 100000), which contradicts its UV-matrix (scroll) flag. The viewer default
  is off.
- No game capture to compare with. The framing follows the decoded
  func_00122DA0/func_00413F50 maths for the initial camera, but the in-battle
  camera moves with the fighters (only pan is offered).
- The lit/specular/extra-attribute programs are not checked against captures.
