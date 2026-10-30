# Boot notes (Port J): running the game's own code as the game

Restart-safe log.  Worktree `/tmp/pw47` (detached at `3af18729e`).  Read
LINK_NOTES.md first.  Evidence (screenshots, logs) goes to
`private/converted/boot/` only.

## Mechanism: host replacements, one list

`port/host/host_impl.csv` is the single list of functions the port
implements on the host (columns `symbol,group,file,what`):

- **C-less functions** (no credited C; the link used to get a generated
  logging stub): the generated stubs are now `__attribute__((weak))`
  (gen_link_glue.py), so the port's definition overrides them.
- **Credited functions** (the game's C exists but touches hardware, IOP or
  the GS): hostify **R17** puts `#pragma weak name` at the top of the owning
  TU, so the port's strong definition wins, and appends
  `name__game` (an alias of the original body) so a host wrapper can still
  run the game's own code (e.g. keep the handle bookkeeping and also draw
  with GL).
- `gen_link_glue.py glue` writes `glue/mvc2_host_protos.h` (the canonical
  prototype of every listed symbol from host_sigs.json, plus `name__game`),
  which every port/host file includes, so a host definition that disagrees
  with the game's callers is a compile error, not a wasm trap.  The rows also
  go into `mvc2_fakes[]` / `stubs.csv` as `host: replaces ...`.
- group `core` = `port/host/*.c` (linked into both `mvc2_host` and `mvc2`),
  group `frontend` = `port/host/fe/*.c` (only `mvc2`: SDL, GL, audio).

## Log

### Session 1 (i386, `build/port-i386`, `-g`)

| # | Where it stopped | Why | Fix (port/host) |
|---|---|---|---|
| 1 | `func_0012F4C0` → `func_00414CB0` heap alloc | platform init `func_003EC160` was a stub | `boot.c`: C port of the asm; skipped IOP/GS steps listed in the file |
| 2 | newlib malloc of the 22 MB arena | EE `sbrk` (`func_001044E0`) reads a literal EE break | `boot.c`: sbrk over a 28 MB host block |
| 3 | `func_003ED300` → `func_0010D360` spin | libpad init over SIF RPC | `iop.c`: libpad at its API (DualShock, stable, host buttons) |
| 4 | `func_00419F70` / TSD bind | SIF RPC bind/call | `iop.c`: bind sets the server pointer (+0x24), call returns; `tsd_host.c`: TSD client → port/audio `tsd_client.c` |
| 5 | `func_00418910` → `func_003FDAA0` → `func_00410F80` spin | CRI ADXT/ADXF need the IOP | `cri.c`: the 30 CRI entry points the game calls (ADXF over the ISO via fs.c, ADXT state machine + frontend hook) |
| 6 | `func_0012DC00`, `func_001E5870`, `func_003F0E60` | C-less | `game_cless.c`: C from the asm |
| 7 | `func_00418200` crash: TIM2 image pointer 0 | `func_003F5070` / `func_003F5080` are credited `void` tail-call wrappers; MIPS returned the callee's `$v0`, R12 turned the callers' use into 0 | `host_impl.csv` column `ret` (applied over host_sigs by hostify R12 and the glue) + `game_fix.c`. Found all such functions by following `$v0` after every `jal` in the asm (incl. branch paths and delay slots): 23 hits, 4 real (`func_003F5070`, `func_003F5080`, `func_003916B0`; the rest are syscall stubs) |
| 8 | `func_003D6B70` → `func_00420340` → `func_00420150` | network leftover loads AVETCP.IRX and waits for RPC 0x01270010; `sceGsSyncV` reads GS CSR | `iop.c`: sceSifLoadModule reports loaded; `boot.c`: sceGsSyncV |

After 8: the whole init path (`func_003EC160`, `func_0012F4C0`, `func_00170BF0`,
`func_003D6B70`) completes and frame 0 starts.  font.tm2, command.tm2, the
common SE banks (AFS01 #59/#60), DM04 POL/TEX load from the disc.
| 9 | frame 0: `func_003DF7B0` reads T0_COUNT; `func_004148C0` reads literal EE BSS addresses | hardware/literal addresses in credited C | `render_core.c`, `game_fix.c` |
| 10 | front end 1/8: `func_00130040` (C-less) | the boot memory-card screen | `game_cless.c`: C from the asm (12-way jump table) |
| 11 | `func_00418D70` (C-less) + libmc | memory card request/sync | `mc.c`: libmc at its API over a host directory (`$MVC2_MEMCARD`), port 0 = formatted 8 MB card, port 1 empty; `func_00418D70` from the asm |
| 12 | crash in `func_003F1C10` → `func_003F1B10(0, 0)` | the credited C calls `func_003F1B10()` with no arguments; the EE passed `$a0/$a1` = the caller's own `a`, `b`. hostify R12 filled missing arguments with 0 | **R12 register passthrough**: `port/tools/gen_regpass.py` runs a forward dataflow over every caller's asm (which entry argument each argument register holds at each `jal`, through moves, joined over branches, clobbered by calls) and writes `port/tools/r12_regpass.csv` (261 rows: source, caller, callee, arg, caller_param); R12 now passes the caller's parameter there instead of 0 |
| 13 | save directory name "" | the game's `sprintf` (newlib `_vfprintf_r`, credited C) produced empty strings | `libc_host.c`: `func_00120A30` = host vsnprintf (EE `%l` → `%ll`), string streams filled as newlib does |
| 14 | front end 1/13 crash; then `func_00420560` resource records read garbage | **data units are not contiguous on the host**: `D_00477170` (11 entries) is indexed to 13 (the next unit `jtbl_004771A0`); a 32-byte record pair is copied out of a 16-byte unit (the terminator is in the next unit) | **R18 EE data layout**: every C data unit goes to section `.data.ee_<addr>.0x`, the zero "hole" after it (alignment, data with no C, the VU microcode, code-TU switch tables, with aliases for the names inside) to `.data.ee_<addr>.1`; mvc2_host links the data objects directly in EE address order (`host_sources.py` sorts them; `ee_data_start.c` is the hole before the first unit) and ELF sorts the sections by name.  `port/tools/check_data_layout.py BINARY`: **10,094 units, 0 misplaced** (also `_Static_assert` of every unit's size: no unit differs from the EE) |

After 14: memory-card check (no save → message, 180 frames) → 1/9 → 1/13
(notice screen, 210 frames) → 1/1 at frame 454.
| 15 | 1/1 → `func_0016F090` → `func_00414C30(p = 0)` | tail call `j func_00414C30` passes `$a0` through | gen_regpass treats `j func_X` as a call site (269 rows) |
| 16 | `func_001538B0` node walk → `func_003DE160(buf, n + 0x54, 0)` | the C assigns its parameter `a2` (`a2 = buf` / `a2 = q`) and calls with two arguments, relying on `$a2` | R12: a missing argument whose register is that of a caller parameter the C **assigns** is passed that parameter (decomp idiom) |
| 17 | `func_00415590` (C-less POL build) | meshes/node trees for every 3D model | `game_cless.c`: C from the asm |
| 18 | frame 5 hang in `func_003F0470` | `_DisableDmac` etc. are `void` syscall stubs whose callers use `$v0` | `kernel.c`: 52 syscalls with EE return values (host_impl `ret=int`) |
| 19 | wasm link: signature mismatch weak void vs host int | ret-override functions cannot be weak twins on wasm | R17 renames those (`#define f f__game`) instead; R17 is skipped in the raw sigs build so host_sigs.json keeps learning from the original definitions; every declaration of an overridden function is rewritten |
| 20 | wasm: printf crash (NULL reent) | wasm data layout: `#pragma clang section` is ignored by wasm clang, zero-init units drift to .bss, wasm-ld gc's unreferenced segments, and wasm clang over-aligns arrays >= 16 bytes | R18 uses `__attribute__((section(".data.ee_<addr>.0"), aligned(<EE address alignment, <= 16>)))` on each unit definition, holes `.1`; mvc2_host (wasm) links with `--no-gc-sections` and a `-Map`; `check_data_layout.py build/port-em/mvc2_host.map`: **0 misplaced** (ELF too) |

Both builds now run the same boot trace (node: `node mvc2_host.js --iso ...`,
NODERAWFS): 1/8 memory card → 1/9 → 1/13 notice → 1/1 (480 frames) → 1/2
intro at frame 935.  i386 faults at frame 1497 in `func_001431A0`: an intro
object has no model because `func_001428E0` (C-less, the intro timeline,
0x8BC bytes) is still a stub; wasm reads address 0 silently and continues.

### Session 1, part 2: the app (`mvc2`) and the first screens

- `port/host/game_loop.c`: main split into `mvc2_boot()` + `mvc2_frame()`
  (shared by `mvc2_host` and the app).  `port/host/fe/`: `fe_main.c` (SDL2
  app, one game frame per host frame via `plat_run`, `--shot F:path`,
  `--press F:button[:len]`, `--hidden` = SDL offscreen + fixed step),
  `fe_render.c` (render-library entry points = game body + port/render GL;
  texture/palette records converted to GL textures keyed by the game's own
  handle numbers: `fl_tex_define`/`fl_pal_define` added to r_gl.c).
- Native i386 app: Ubuntu's i386 SDL2 runtime (`apt-get install
  libsdl2-2.0-0:i386 libgl1-mesa-dri:i386 libegl1:i386 libgles2:i386`), the
  multiarch SDL2 headers through a `_real_SDL_config.h` shim in the build tree.
- More C-less code from the asm: `func_003DE230` (VU0 3x3 product, 3970
  calls in 900 frames: every object matrix), `func_00422150` (the menu text
  byte code: glyph sprites via `func_00421FB0`).

**First game screens drawn by the game's own code** (`private/converted/boot/native/`):
- `f0100.png`: front end 1/8, the memory-card check: "WARNING: No "MARVEL VS.
  CAPCOM 2" save data found." (42 glyph sprites, the game's font texture).
- `f0300.png`: front end 1/13, the CRI ADX logo.
- `f0600.png` (1/1): black; it is a 3D scene (meshes, `func_003F0500`), not yet bound.

### Session 1, part 3: meshes, VU0, the CAPCOM logo

- `fe/fe_mesh.c`: the clay path (`func_003F2B70` / `func_003EE6F0` build a GL
  mesh per game clay handle with the game's format word, `func_003F0500` draws
  it with the game's own view / projection / world / light blocks; rebuilt
  when the slot format changes; textures of the clay's ranges re-synced at
  draw time, since the game reloads records without a render-state call).
| 21 | 1/1 meshes all one grey | **VU0 macro-mode inline asm is a no-op on the host**: `func_003DE160` (4x4 product), `func_003DE3D0`, `func_003DE530`, `func_003DE5C0`, `func_004135D0` (credited C with COP2 asm) and the libvu0 routines (`vu0_a.c`, `vu0_f.c`, FN placeholders `k1a.c`/`k6a.c`/`p0a.c`/`s0h.c`/`s1k.c`, C-less RotMatrixX `func_001030E0`, vsqrt `func_003DE7A0`) left every matrix uninitialised (NaN) | `vu0_host.c`: 35 functions in C, read off the asm (Sony libvu0 names in the comments). hostify R17 no longer weakens FN() placeholders (they are dropped by R6, there is nothing to alias) |
| 22 | 1/1 second shot: ADX-logo pixels on the 2D CAPCOM plate | texture record reused with new pixels, clay draw did not re-sync | `fe_mesh.c` syncs the clay's material textures before each draw (`fl_clay_textures` in r_mesh.c) |
| 23 | 1/2 intro, frame 1497 fault | `func_001428E0` (C-less intro event timeline) stub | `game_cless.c`: C from the asm (switch on the scene clock, actor on/off, fades, BGM, scheduled effects from `D_00441E30`) |
| 24 | 1/2 `func_00141C90` → `func_001415B0(NULL)` | the C calls `func_001415B0()` with no argument; the asm keeps the local `o` in `$a0` (not a parameter, so R12 dataflow cannot see it) | `port/tools/r12_regexpr.csv`: hand-checked R12 sites, `expr` = the caller's C variable held in the register. `gen_regpass.py --unresolved FILE` lists the 546 padded arguments the dataflow does not explain (308 hold a computed value); they are checked as the boot reaches them |

Screens now (`private/converted/boot/seq4/`, `seq5/`): the 3D CAPCOM logo
flies in over the lit white backdrop (frames 480–640, `f000600.png`), fades
to white, then the flat CAPCOM plate (frame 800).
| 25 | 1/4 (attract) / 3/0 menu: crash, `ebp` = 0 after `func_003DA6F0`'s callback | `func_00146AE0(u8 *p, s32 g, s32 k, u8 m)` is called through a dispatch table with one argument and writes `g`, `k`, `m`: on i386 cdecl those slots are the caller's frame | **R19** (hostify): a function that writes one of its parameters (`=`, op=, ++/--, `&`) gets it as a local copied from a renamed parameter (`T p = p__arg;`); 1,121 parameters in 832 TUs |
| 26 | 3/1 main menu black: every world matrix has a zero 3x3 | `func_00151A90` calls `func_003DDB20(&b, sx, sy, sz)`, but the credited `func_003DDB20(u8 *p)` declares only `p` and forwards `$f12-$f14` to `func_003DDA70`: canonical prototype (void *) so R12 dropped the scale | **R20 parameter widening**: `gen_regpass.py` now iterates to a fixpoint: a caller whose own incoming register (not in its canonical prototype) reaches a callee's missing argument gets that parameter (`port/tools/r12_widen.csv`, 144 functions, e.g. `func_003DDB20(void *, float, float, float)`, `func_003DDB70/C30/D00(void *, float)` rotations, `func_003DD4E0` viewport); hostify adds `__rpN` to the definition (R20) and R12 passes them on; regpass rows 269 → 542. The pad log now records which canonical index was padded (class-aware R12 path) |
| 27 | `func_003F01B0` (C-less) | clay texture upload list | `game_cless.c` |

After 27 (`private/converted/boot/seq8/`, START at 2900 and 3100): CAPCOM
logo over the sky backdrop, the title animation (VS. and 2 forming), the full
title with PRESS START BUTTON (1/7), START → **main menu** (3/1): ARCADE /
VS / TRAINING / OPTION / SCORE RANKING / SCORE ATTACK / SECRET FACTOR /
SAVE/LOAD with the description panel, all drawn by the game's own code.
The 1/2 intro shows flat colours only (its character art is the VU1
character path, `func_00412260`, not ported yet).
| 28 | fight load hang (frame ~6900) in `func_0012DA40` | the synchronous loader spins on `func_00418AA0` until ADXT leaves PREP, calling only the ADXM server (`func_003FEAD0`), not ADXT_ExecServer | `cri.c`: the ADXM server exec also runs the ADXT tick (on the PS2 the ADX server thread kept running) |
| 29 | fight: no characters | `func_00412260` (asm only: VU1/GIF packet builder with a PSMT4 tile LRU in VRAM) | `fe/fe_char.c`: `func_00411C10` / `func_004120A0` (game body) also create / free a port/render `FlCharBank` per slot; `func_00412260` draws through `fl_char_draw` (tiles decoded into an index atlas on first use) with the 16 palettes read from the slot's CLUT records every draw (`fl_char_set_palette_rgba`, new), so the game's own palette writes show |

After 29 (`private/converted/boot/seq13/`): main menu → ARCADE → character
select (sphere, portraits, assist types, mode and speed select) → VERSUS →
**a fight on the airship stage, Ruby Heart vs Zangief, animated sprites,
HUD, life and super bars** → TIME OVER / DRAW GAME → score ranking →
CONTINUE countdown.  Open: the round timer starts at 00 (TIME OVER at once);
C-less stubs still hit: `func_00188860`, `func_00176360`, `func_00122960`,
`func_003EBF30`, `func_0032DF90`, `func_00127C50` (GS setup `func_00100590`
is not needed).
| 30 | round timer 00 → TIME OVER at once | the round-time table `D_004C21E8[8]` (indexed by option `g[0x4D]`, func_003D91B0) is EE data with **no C source**: it lived in an R18 hole, zero on the host | **EE image fill** (`port/host/ee_image.c`): `host_sources.py` writes the hole list (EE address, size) into `ee_data_start.c`; at boot (`mvc2_boot`) the holes are filled from the user's own `SLUS_204.86` on the disc (ELF PT_LOAD), 98,430 bytes; aligned words that look like EE addresses (0x00100000–0x0063FFFF, 120 of them) stay zero. No game bytes in the build. Timer now starts at 99 and counts down |
| 31 | wasm: `func_0041C010` out of bounds | `(f32 *)(pos | 0x20000000)`: the EE's uncached RAM mirror; on i386 the heap already had bit 29 set (luck), on wasm the address is out of range | **R21** (hostify): `| 0x20000000` / `| 0x30000000` dropped where the result is cast to a pointer; R10 override for `func_003EF980(m[2], m[1] | 0x20000000, ...)` in src/gr22_d.c |

### Unlock everything (host option, default on)

`port/host/game_loop.c` `unlock_everything()`, every frame before the game's
own frame (OR-only, so the defaults `func_003D6B70` writes and a loaded save
both end up unlocked).  The state, from the Secret Factor shop
(`src/fb23_f.c`), the availability test `func_0012BFB0` (src/batch5.c) and
the save loader `func_0038B8C0` (src/r3_30_d.c):

| Where (EE) | What | Set to |
|---|---|---|
| `D_004F4300` (= `*D_004C2840`, g) +0x30 | characters, bit = id (ids < 0x18; the shop uses < 0x20) | 0xFFFFFFFF |
| g +0x34 | characters, the rest (bit = id & 31) | 0xFFFFFFFF |
| g +0x38 | extra colours / costumes, ids 0x00–0x1F | 0xFFFFFFFF |
| g +0x3C | extra colours / costumes, ids 0x20–0x3A | 0x07FFFFFF (bits 27–31 crash the select screen: no such ids) |
| `D_004F7FB4`, `D_004F7FB8` | other shop items (`func_001317F0`: gallery / EX) | 0xFFFFFFFF |
| `D_004D179A` | shop level counter (0..7; saved at save +0x24) | at least 7 |

The save block itself is `D_0058C020` (loader copies: +0x14..+0x20 → g+0x30..0x3C,
+0x44/+0x48 → `D_004F7FB4/B8`, +0x24 → `D_004D179A`).  Off: `--no-unlock` (native,
mvc2 and mvc2_host), `?nounlock` or `?unlock=0` on the web page;
`MVC2_UNLOCK_PARTS` (bitmask 1 chars, 2 colours, 4 shop items, 8 level)
for debugging.  Proof: `private/converted/boot/unlock/charsel_front.png`
(all 56 portraits, no "?").

### Audio (frontend)

`fe/fe_audio.c`: `audio_init()` binds the game's Tamsoft client
(tsd_client.c) to the port's TSD driver and sets `host_adxt_ops` to the
`padx_*` ADX player (AFS loader over the disc).  SDL device natively and on
the web (WebAudio); headless runs render a frame of samples per game frame
(`MVC2_AUDIO_WAV=path` writes the mix: boot→title, RMS 0.07, music from the
CAPCOM logo on).  `MVC2_NO_AUDIO` turns it off.

### Web single-file build

`emcmake cmake -S port -B build/port-em -G Ninja -DPORT_SINGLE_FILE=ON`
(EMCC_LOCAL_PORTS=sdl2=/home/user/deps/SDL2), `ninja -C build/port-em mvc2`,
then `port/tools/pack_personal.py build/port-em/mvc2.html <iso> out.html`
(the disc embedded gzip+base64; the shell unpacks it and calls
`viewer_open_js`).  Headless Chromium (Playwright, SwiftShader WebGL2) from
file://: boots to the title, keyboard Enter → title → main menu, Z → ARCADE
→ character select → assists → VERSUS → a fight, keyboard moves and attacks
(`private/converted/boot/web/`).  Touch (overlay ST tapped on the title →
menu) and a standard-mapping gamepad (button A on the menu → character
select) also reach the game (`touch_menu.png`, `gamepad_charsel.png`).
SwiftShader runs it at about 25 fps.

### Session 1, part 4: more C-less code (gameplay)

| Function | What | Where |
|---|---|---|
| `func_00176360` | character palette animation → CLUT upload (hit flashes) | game_cless.c |
| `func_003EBF30` | VRAM placement search over the block list | game_cless.c |
| `func_003F59C0` | put pixel into an image of any format | game_cless.c |
| `func_001E7CB0` | character box overlap (pushing) | game_cless.c |
| `func_00188860` | assist / tag-in request (A1 / A2): assists now come in (`seq17/`) | game_cless.c |
| `func_00122960` | stage light colours | game_cless.c |
| `func_0032DF90` | CPU team pick (random, distinct): the CPU now picks varied teams | game_cless.c |

Still faked / open (honest list):
- `func_003DB020` (button configuration remap) is an APPROXIMATION: the
  device records are copied unmapped.  The default layout works; a changed
  button configuration in OPTION is not applied.
- `func_00127C50` (score-ranking record entry) is a stub: rankings are not recorded.
- The 1/2 attract intro shows only its flat fades: its actors deform VU1
  packet vertices in place (`func_001412D0` → `func_0041C010`), which the
  GL meshes built once at load do not follow.
- IOP / GS / DMA setup is skipped (`boot.c`); `func_00100590` (GS env) stays a stub.
- 503 R12 padded arguments the dataflow cannot explain (`gen_regpass.py
  --unresolved`); one was hand-fixed (`r12_regexpr.csv`), the rest are
  checked as they are reached.
- Memory card: a host directory natively; on the web it lives in MEMFS
  (lost on reload).  Fixed: IDBFS, see "Fidelity pass" below.
- Web: SwiftShader (headless) runs at ~25 fps.

### Session 1, part 5: the CPU-team crash (regression report from the lead)

| # | Where it stopped | Why | Fix |
|---|---|---|---|
| 32 | web: renderer "Target crashed" at the fight load; native: SIGSEGV in `func_001757E0` from `func_001A0BD0(p, q = garbage)` | with the real CPU team pick (`func_0032DF90`, part 4) the CPU can now get Spider-Man / Hulk / Venom (ids 0x0C–0x0E; reproduced with `--cpu-team 12,13,14`; every other id fought fine in a 20-team browser sweep).  One of their effect objects is updated through `func_001A0B80(p)` → `jtbl_0044AF70[..](p, owner)` → `func_001A0BB0(u8 *p) { jtbl_0044AF80[p[4]](p); }`: the asm of that dispatch head tail-jumps (`jr $v0`) with `$a1` (owner) untouched, the C passes only `p`, so `func_001A0BD0` read its owner from stack garbage.  The earlier build never reached it because the stubbed pick never chose those characters | **R22 tail forwarding**: `gen_regpass.py` finds dispatch heads (the entry block loads from a table whose every entry is a known function, and ends in `jr $reg`; switch tables point at code labels and are left alone) whose `$a1..$a3` still hold their entry values at the jump; those are widened (R20) and listed in `port/tools/r12_tailfwd.csv` (2,050 heads), and hostify passes the head's remaining parameters through the table call with an unprototyped function-pointer cast.  Headers that declare a widened function keep an unprototyped declaration in its defining TU (no conflicting types).  Widened functions 144 → 2,258; R12 passthrough rows 542 → 722; host code that declared a now-widened game function (`func_00391710` in game_fix.c) takes the new prototype |

`--cpu-team a,b,c` (app; `?args=--cpu-team%20a,b,c` on the web page) or
`MVC2_CPU_TEAM` forces the CPU's characters, for testing.  Since the pick
became credited C this is a wrapper in port/host/arcade.c: the game's pick
runs, then the ids are forced (`--p1-team ID` does the same for side 0's
point character).  The browser sweep
over all 59 ids (20 teams, Playwright, `scratchpad/pw/team.js`) is in
`private/converted/boot/web/teams/`.

Checked after 32: native `--cpu-team 12,13,14` fights (Spider-Man, Hulk,
Venom); the web build with the same team and 3 others (`web/teams2/`); the
full `run.js` (title → menu → character select → VERSUS → fight → assist,
`web/final/`) on the repacked single file; native default flow with assists
(`seq18/`); `check_data_layout.py`: 0 misplaced (ELF and wasm map).

### Rebuild against the finished decomp (2026-10-30)

The decomp moved on after the port was built (rounds 11-18, data catalogue
merges, hand-written asm as `.S`). Changes needed to rebuild:
- 10 hand-written stand-ins in `game_cless.c` (stage lights, palette
  animation, assist request, sound bank upload, VRAM search, clay texture
  list, heap compaction, put pixel, POL pack, menu text record) are now
  credited C: the stand-ins and their `host_impl.csv` rows are removed, so
  the game's own decompiled code runs.
- Platform overrides kept, with the credited prototypes: `func_003EC160`
  and `func_003ECD00` take no arguments, `func_00418CC0` returns int,
  `func_0010D5C0` takes `void *`, `func_00412260` (sprite drawer, GL) takes
  the credited 5 arguments.
- `__I_nop` (MWCC intrinsic in two matches) is a host no-op in
  `ps2_compat.h`; `&func_004180E0()` in r12_07_c.c (EE address 0) gets an R10
  override.
- Five more stand-ins are credited C now and are removed: the file
  destination table (`func_0012DC00`), the **button configuration remap**
  (`func_003DB020`, so a changed OPTION layout now applies: the old
  approximation is gone), the boot memory-card screen (`func_00130040`), the
  intro timeline (`func_001428E0`) and the CPU team pick (`func_0032DF90`).
  `func_003DE230` (VU0 macro code, `.S` in the decomp) and `func_001E7CB0`
  (not matched) keep host C.
Browser run on the repacked single file: title → menu → character select →
VERSUS → fight with attacks and an assist (`private/converted/boot/web/rebuild1/`).

### Phase 4, platform side: settings, input, pacing, audio, PWA (2026-10-30)

Port-side only (`port/platform`, `port/render`, `port/audio`, `port/host/fe`,
`port/web`). Players' description: USER_GUIDE.md.

**New pieces**
- `settings.c`: the option store and table, plus the extension point for
  the arcade toggles.
- `input.c`: bindings, the positional gamepad layout and capture.
- `fe_ui.c`: the options, the in-game menu, the FPS / latency overlay, the
  touch pad drawing and the web exports `mvc2_settings_json`,
  `mvc2_setting_set`, `mvc2_bind_*`, `mvc2_ui_hold` and `mvc2_stats_json`.
- `r_font.c`: a 5x7 overlay font.
- The present pass is now a shader (`r_present_ex`): sharp bilinear,
  scanlines and CRT.
- `r_set_discard`: frame skip that still updates textures.
- Web audio output: an AudioWorklet (AUDIO.md section 5).
- `shell.html`: the settings panel, fullscreen and install.
- `sw.js` now precaches `mvc2.*`. The icons come from `port/tools/gen_icons.py`.

**Platform loop** (`platform_sdl.c`)
- Runs from `emscripten_request_animation_frame_loop` with the vsync
  timestamp. Frame times are snapped to common refresh intervals.
- Up to 8 steps run per display frame, and only the last one is drawn.
- It draws only when a step ran.
- Pause is reported from `visibilitychange` itself.
- Keys come from events, so taps shorter than a frame still count.
- Keys used by the menus are swallowed until released.

**Desktop app test hooks:** `--wshot F:png` (the window after present) and
`--key F:NAME` (real SDL key events).

**Checked**
- Native headless (i386, offscreen): F1 menu, Video page changes, Controls
  rebinding by key capture, the settings file written
  (`video.scale = integer`, `input.p1.kb.up = U`), and the scripted flow to a
  fight (frame 6700, state 02 01 02) with the FPS overlay.
- Web, single file, headless Chromium + SwiftShader
  (`private/converted/boot/web/ux*/`):
  - Settings panel tabs.
  - Two emulated standard-mapping pads, recognised as Xbox and DualSense
    layouts: player 1 CROSS, player 2 SQUARE, stick to LEFT.
  - Rebinding through the panel (keyboard LP to J, pad LK to north with a
    swap) took effect in game and survived a reload (localStorage).
  - Back + Start opened the in-game menu, and pad navigation worked.
  - Measured latency: 0.5-6 frames, which is the display rate on a loaded
    SwiftShader box (5-20 fps).
  - Phone 390x844 portrait and 844x390 landscape: the touch pad drove the
    game (title to menu with ST, d-pad moved the menu), and size changed at
    140 %.
  - Full flow title to fight with attacks and an assist, the FPS overlay,
    scanlines, CRT, and stretch + smooth (`ux_fight/`).
  - PWA over http://localhost: manifest, every shell file cached, and an
    offline reload starts the page and offers the disc picker.

**Open**
- Two of three web runs on the loaded machine (load average 10-17) ended
  with a renderer "Target crashed" at the fight load (state 2/1/2). The third
  run, and native, fought fine.
- The baseline build could not be compared under that load (its screenshots
  timed out).
- Watch for this: it may be memory pressure in the renderer with a 180 MB
  page, or a game-side issue.


### Fidelity pass (2026-10-30, branch port-fidelity)

**Inventory of what the port still fakes** (host_impl.csv + glue stubs.csv):
- Game logic replaced although credited C exists: none left.  Removed this
  pass: `func_00418CC0` (memory-card wrapper init; the host copy returned 0
  where the game returns 1) and `func_00418D70` (card request/sync/retry
  state machine): the credited C runs on top of the host libmc.
  `func_0032DF90` (CPU team pick) runs `func_0032DF90__game`; the host
  wrapper only applies `--cpu-team` afterwards (testing; it had silently
  stopped working when the stand-in was dropped).
- Kept, with reasons: `func_003DE230` (VU0 macro code, `.S` in the decomp),
  `func_001E7CB0` (not matched, REMAINING.md); `func_003F5070/5080`,
  `func_003916B0` (credited C, transcribed only to return `$v0` as callers
  expect), `func_004148C0` (credited C reads literal EE BSS addresses; same
  compare on the host BSS).  Leftover dead stand-in code removed from
  game_cless.c.
- Platform (kept, host by design): kernel syscalls, SIF/IOP, libpad, libmc
  (host directory), sceCd, CRI ADXF/ADXT (port ADX player), Tamsoft (port
  sound driver), GS/DMA/VU1 entry points bound to GL (`fe_render.c`,
  `fe_mesh.c`, `fe_char.c`), VU0 macros, newlib vfprintf.
- Generated logging stubs: 30 code labels, 3 C-less functions
  (`func_003D6530`, `func_003F5630`, `func_003F5710`), 2 credited `.S`
  (`func_00102CA0`, `func_00106578`): none logged a hit in any run below
  (only `ps2_asm_stmt`, the inline-asm hook, does).

**Fixes, with evidence** (native: `--script`, below; web: `port/tools/web_script.js`;
screenshots under `private/converted/boot/web/`):

| What a player saw | Cause | Fix | Evidence |
|---|---|---|---|
| Crash at the fight load (native SIGSEGV in func_003F1AB0 / func_00176230 / func_00415320 from func_0016FAA0; web: silent) | "unlock everything" wrote 0xFFFFFFFF to g+0x30/+0x34; the credited CPU pick draws from those words, so the CPU took an Abyss form (bits 24..26) or a non-existent id (0x3B..0x3F, e.g. 62) | write exactly the game's own "all bought" values (func_00329AC0 tests 0xF8FFFFFF / 0x07FFFFFF; same for the colour words), assigned so a card saved by an older build is repaired | native fights with CPU 0x1d/0x31/0xd and 0x25/0xc/0x9; `fid_arcade/` |
| Crash on VS stage list entry 2 (stage 1) a few seconds into the fight (i386) | `func_00417EB0(V3 *)` called with a by-value V3 in sLa1_c.c: MWCC passes the address of a copy, i386 pushes the struct | R10 override: pass `&w` (a scan of src/ finds no other by-value struct argument) | `fid_vs2/fight_b.png` |
| Crash opening a picture in Secret Factor -> Gallery (native SIGSEGV in func_0041C4B0; web: a stray write into the wasm heap) | two credited functions store the gallery hook through the literal EE address `0x0043CD0C` | R10 overrides write `D_0043CD0C[0]` | `fid_gallery/g1.png`, `g4.png` |
| Crash in Score Ranking -> Character Ranking | R12 padded argument: `func_00150670()` gets `$a0 = &D_004CA080` in retail | `r12_regexpr.csv` row | `fid_rank/`, native `rank/r3` |
| Crash after turning VIBRATE on in Button Config | `func_0016EEC0` reads `idx` before setting it; retail reads the caller's `$s1`, which is 0 from crt0 down | R10 override `idx = 0` | `fid_btncfg/b5.png` .. `d1.png` |
| (preventive) 9 more padded arguments whose register holds a constant or a symbol address at the call | extended dataflow (constants, `%hi/%lo` addresses, `%gp_rel` loads) | `r12_regexpr.csv` rows | built; not all reached |
| Saves, options and unlocks lost on reload (web) | card directory in MEMFS | `/mvc2_memcard` is IDBFS (shell.html): loaded before main(), written back 250 ms after each close/mkdir/delete (`Module.mcPersist`, called from mc.c) and on pagehide | `fid_mc1/saved.png` then `fid_mc2/boot_mc_a.png` ("Autoload successful" after a reload) |

**Music cut-out ("one stage's music stops after the fight starts")**: not
reproduced.  `MVC2_TRACE_ADXT=1` logs every ADXT call and player status
change.  VS mode on all 16 stage-list entries (BGM AFS00 fids 0-7, 11, 0, 1,
3-7): the stage BGM starts paused at the battle setup, is unpaused at the
round start (`func_001718D0` -> `func_001E3FE0`), and no Stop/Pause/status
change follows for 20 s of fight; stages 0 and 1 (whose loops span the whole
file) keep playing through their loop points (61 s / 92 s, rendered audio
RMS stays up).  Every stage track loops (ARCADE_DIFF.md).  So the retail
cut-out is the IOP stream starving (ADXT error state under CD contention),
which the port's in-memory ADX player cannot hit; no code change.

**Still open**:
- 1/2 attract intro actors (VU1 vertices deformed in place, `func_001412D0`
  -> `func_0041C010`): not started (renderer work: rebuild or skin the GL
  mesh per frame).
- `func_00100590` GS environment stub: not started (GS register setup has no
  GL meaning beyond what fe_render already applies).
- R12: 292 padded arguments still unresolved where the register holds a
  caller local (`gen_regpass.py --unresolved`; 504 more are widened-tail
  entries); the ones on the paths above are fixed.
- Not driven yet: a full arcade run to the ending (and the Abyss stage 8 /
  its BGM fid 8), Score Attack, Survival-like modes, the shop purchase flow
  with `--no-unlock`, score-ranking entry after a finished run
  (`func_00127C50` is credited C and runs; never reached in these runs).

**Test tooling**: `mvc2 --script FILE` (native) and `?script=` (web page,
lines separated by `;`, shots to `/shots`) run a state-driven script:
`state S [MAX]`, `wait N`, `press B[+B] [LEN]` (`p2:` for pad 2),
`until S B [GAP]`, `shot NAME`, `quit` (see fe_main.c).  Scripts used here:
`port/tools/scripts/`.  `node port/tools/web_script.js URL OUTDIR SCRIPT
[PROFILE_DIR]` runs one in headless Chromium and copies the shots out;
a PROFILE_DIR keeps IndexedDB between runs (card persistence).  Native,
xvfb: `xvfb-run -a ./build/port-i386/mvc2 --hidden --size 640x480
--shot-dir D --script S private/disc/mvc2.iso` (start skips the intros, so
the menu is reached in ~600 frames).

### Integration of the fidelity, arcade and UX branches (2026-10-30)

Merged on main. Browser runs of the merged single file (`fight.js`: title →
menu → character select → VERSUS → fight, overlays, scanlines, CRT, stretch):
7 of 8 reached the end; one renderer crash ("Target crashed") right after the
fight began, with no Chromium error line. Renderer memory peaks at about
800 MB, so it is not memory pressure. It has only been seen in headless
Chromium with SwiftShader (software GL); it did not reproduce in the arcade
sweep (15 fights, all 59 characters) or the fidelity mode runs. Open: get a
crash dump from a failing run (`--enable-crash-reporter`) and check on a
real GPU.
