# MvC2 PS2 (SLUS_204.86): engine map for the native port

Scope: boot, initialisation order, the per-frame loop, the task/object system
and the game-state machine. Rendering is covered in `RENDER_PATH.md`; files,
archives and audio are covered in `ASSET_LOADING.md`.

Conventions:
- Addresses are EE virtual addresses. `private/SLUS_204.86.rom` is the *loaded
  image*: `vaddr = 0x00100000 + file_offset`, with no header (the ELF itself is
  `private/extracted/SLUS_204.86`; `tools/extract_elf.py` strips it). BSS is
  `0x004C2580..0x00634380`, and `_gp = 0x004C7270`.
- "C:" is the matching source in `src/`, from `config/matches.csv`.
  "asm" means no credited C yet, so read `asm/main.s`. "placeholder" means the
  C exists but still contains an `asm{nop}` barrier, so its logic is readable.
- Confidence tags: **[verified]** means read directly in code. **[inferred]**
  means deduced from data flow or constants.

---

## 1. What the executable is made of

| Range (approx.) | Content | Port action |
|---|---|---|
| `0x00100000-0x0011FFFF` | Sony EE runtime: libkernel/SIF RPC, libgraph (`sceGs*`), libdma, libpad, libcdvd, libmc, newlib (printf, malloc, softfloat `dpadd`/`fptosi`...) | Replace with host libc plus small shims |
| `0x00120000-0x003D5FFF` | **Game code** (Capcom): menus, select, battle, actors, effects, camera | Port as is (this is the 97% C) |
| `0x003D6000-0x003DAFFF` | Main-loop glue, the top-level state machine, the object pool/task system and the draw-list registry | Port as is |
| `0x003DB000-0x003F0FFF` | **In-house PS2 render library**: handle heap, DMA packet heap and queues, render-state API, GS texture/VRAM manager, VU1 mesh path, 2D prims, display/flip | **Replace** (see RENDER_PATH) |
| `0x003F1000-0x0040FFFF` | CRI middleware: ADXF (AFS), ADXT (ADX streaming), CVFS, SJ, SVM, PS2RNA, LSC, DVCI/HTCI/SRD/DTR/DTX | Replace (see ASSET_LOADING) |
| `0x00410000-0x00419FFF` | Engine services: resource tables, TIM2 handling, **character sprite cache and drawer**, effects back end, file-system setup, IOP module loading | Partly port, partly replace |
| `0x0041A000-0x00423FFF` | More effect/menu runtime, the batched 2D text packet writer, and the **Tamsoft sound driver client** (TSD RPC) | Port the game logic, replace TSD |
| `0x00424200-0x00437FFF` | VU1 microcode packets (`src/vu/*.vsm`) | Re-implement as GL shaders |
| `0x00438000-0x004C2580` | Data: tables, strings, the 983-entry filename table (`0x0043CDA0`), GIF packet templates (`0x004778F0..`), microcode descriptors (`0x004779F0`) | Keep as C data |

Library identification strings: `PsIIlibgraph2500` and `PsIIlibdma 2500`
(Sony SDK 2.5.0). The CRI versions are ADXF 6.24, ADXT 8.19, ADXPS2 2.33,
AIXP 1.27, CVFS 2.24, SJ 6.08, SVM 1.08, PS2RNA 1.14, LSC 2.07, DVCI/HTCI 2.50,
SRD 2.00, DTR 1.02 and DTX 1.01. Sound is "TamsoftSoundDriver" (`TSNDDRV.IRX`).
There is no Sofdec/MPEG/IPU usage, so the game has **no FMV**.

## 2. Boot sequence

```
_start                       0x00100008  asm (crt0)
  clears BSS 0x004C2580..0x00634380, sets $gp/$sp, SetupThread/SetupHeap
  func_0010CCA8              src/sdk0d.c        (kernel/heap init)
  func_00104060              src/grok_tiny_leaves.c (FlushCache-style sync)
  func_00170C30  == main     src/z2_b.c (placeholder: the logic is complete)
```

### 2.1 `main` (func_00170C30, src/z2_b.c) [verified]

```c
while (!func_003EC160(640, 480)) ;   // render library + IOP + GS init (asm)
func_0012F4C0();                    // game memory, resources, sound, fonts (src/fb38_c.c)
func_00170BF0();                    // file-queue reset + async loaders (src/grok_w5_0017.c)
func_003D6B70();                    // game globals, options, state machine init (src/w21a2_d.c)
for (;;) {  /* one iteration = one 60 Hz frame, see section 3 */ }
```

### 2.2 `func_003EC160(w, h)`: platform init (asm, 0x003EC160..0x003ECBDC) [verified]

In order:
1. Clears the render-library globals (`D_0062BC00`, 0x420 bytes).
2. `malloc(0x1600000)` (22 MB) through `func_0011CB70`, then `func_003F0940` builds
   an arena over it. A 6 MB (`0x600000`) **handle pool** is carved out
   (`func_003DCFC0`/`func_003DB980`, pool object `D_005BF280`). Every
   texture, mesh and DMA buffer later lives in this pool and is referenced by a
   1-based *handle* that `func_003DD030(handle)` resolves to an address. The pool
   can be compacted (`func_003DD040`).
3. Video parameters (all fixed in retail): `D_0062BC00 = 0` (half-height
   mode), so framebuffer width 640 and height **224**. The frame PSM code is 4,
   which means PSMCT32. The Z buffer is PSMZ32 (`D_0062BC20 = 0x30`), with Z scale
   `D_0062BC30 = 16777000.0f`. `D_0062BF8C/90` (scroll origin) start at 0.
4. IOP: `sceSifInitRpc`, `sceCdInit`, `sceCdMmode(1)`, then a reboot of the IOP with
   `cdrom0:\MODULES\IOPRP255.IMG;1` (`func_0010C098` and the `func_0010C060` poll),
   followed by a second SIF/CD init.
5. IOP modules, each loaded by `func_003DCAD0` (a retrying `sceSifLoadModule`):
   `SIO2MAN`, `PADMAN`, `USBD`, `USBMLOAD`, `USBKB`, then `func_00418C70`
   (`MCMAN`, `MCSERV`), `func_00419EE0` (`LIBSD`, `MODHSYN`, `MODMIDI`, `MODMSIN`,
   `TSNDDRV`) and `func_00418B50` (`CRI_ADXI`).
6. `func_00100478` (sceDmaReset-ish), `func_001025A8(1)`, then a fetch of the 10 DMA
   channel handles into `D_0062BF9C[0..9]`.
7. `func_00103958`, then two **DMA packet queues** are created by
   `func_003DC250(queue, capacity, handler=func_003DC3C0)`:
   - `D_0062BBA0`: channel **1 (VIF1)**, 0xC00 entries. This is the only one used per frame.
   - `D_0062BBD0`: channel **2 (GIF)**, 0x400 entries. It is created but never filled.
8. `func_001002D8(0, 1, 2, 1)`: `sceGsResetGraph(0, INTERLACE, NTSC, FRAME)`.
   `func_001020E0(&D_0062BC50, ...)` sets up `sceGsSetDefDBuff` (two 640x224
   PSMCT32 buffers, Z on, clear).
9. `func_003EB900` (GS VRAM allocator init), `func_00418CC0` (memory-card state),
   `func_00419F70` (**Tamsoft sound driver RPC bind**, `func_00422DB0`),
   `func_00418B80` (**CVFS/ADXF file-system setup**, which prints "Setup CD/DVD
   file system" and "Setup CD/DVD cache system", using a 128-entry cache from
   `0flist.dir`), `func_003DAD60`, `func_003ED000` (GS put draw env),
   `func_00100E68`, `func_00101D50`, `func_003DF7D0` (default render state).
10. Programs the INTC/DMAC masks (`0x10000810/0x10000800`) and returns 1.

### 2.3 `func_0012F4C0`: game init (src/fb38_c.c) [verified]

`func_00414CB0(0x200000)` (src/hk11_a.c) allocates the game heaps through
`func_003DCF70`:
- `D_004C28BC`: 0x7E0000 (character PAKs and big buffers)
- `D_004C28B8`: 0x200000
- `D_004C28B4`: 0x60000
- `D_004C2880`: the BSS-backed pool

If this fails it hangs. Then, in order: `func_0016F0E0` (buffer carve-up),
`func_0012DC00` (file-destination address table `D_004CA1F4..`),
`func_00174B50`, render state 0x6C=1, `func_003DB970(1)`, the resource tables
(`func_00414E30`, `func_004152E0`, `func_00415450`), `func_00416AC0`,
`func_004171E0`, `func_00413E60`, `func_00414AA0`, `func_00418910` (**ADX
init**: ADXT handle `D_004C2B50`, then `func_004189A0` mounts `afs00..03.afs`),
`func_001E2050` (**sound-effect bank load**: files 0x3B/0x3C from AFS
partition 1), and volume defaults (`func_001E41B0/41C0/46D0`, `func_001E4260`
mono/stereo). It finishes by synchronously loading the common data: AFS
partition 2 files 0x34A, 0x349, 0x94, 0x92, plus 0, 1, 0x3CA and 2, which are
**font.tm2**, **command.tm2** and other files (IDs are indices into the
filename table, see ASSET_LOADING). Fonts are turned into textures with
`func_00418200` (TIM2 to texture handle).

### 2.4 `func_003D6B70`: state init (src/w21a2_d.c)

`D_004C2840 = D_004F4300` is **the global game-state struct** (0x80+ bytes,
used everywhere). This function clears it, sets `g[0x14] = 0x20`,
`g[0x29] = 1`, the region/language byte (`func_00416A70`), defaults and options,
the clock (`func_0010FC98` sceCdReadClock), and calls `func_003D6D50`,
`func_003D6E20`, `func_00329890`, `func_0016CDA0`, `func_0016D160(10)`,
`func_003CE490`, `func_00127990`, `func_0038A6A0`, `func_00420340`.

## 3. The frame loop (body of `main`) [verified]

```c
for (;;) {
  func_0012F460();        // src/wave10b.c   frame counters; func_00402498 = ADX/CRI server tick
                          //                 func_0012F0B0 = pad/input update (src/input_update_0012f0b0.c)
  func_0016ECC0();        // src/grok_w5_0016.c  network/USB stubs (func_00418030 is empty), func_0016D260, func_001E74C0
  func_0012F3E0(D_004F4480); func_0012F3E0(D_004F4494);  // per-player button auto-repeat (30/35 frame)
  func_003D7630();        // reset overlay draw-list counters
  func_0012F450();        // empty
  if (D_004C2870 == 1 && D_004D17C2 != 1) {   // soft-reset request
      func_0016EE50(); func_00417FB0() /* = flip */; D_004C2870 = 0; }
  func_001E42A0();        // SOUND tick: master volume fade (func_001E46E0), SE fade queue (func_001E5230), func_003FEAD0
  D_004C2848 = 0; D_004C284C = 0;
  func_003D6FF0();        // GAME UPDATE: clock (func_003D7190) + func_003D7030 (state machine) + func_00174BC0 (palette/colour fx)
  func_00170D30();        // BEGIN SCENE: func_003DF7A0 (D_0062BFD4=1), blend 0x32, TEX1 nearest
  func_003D7400();        // RENDER pass 1: registered scene callbacks + debug text batch
  func_003D7640();        // RENDER pass 2: overlay callbacks + overlay text
  func_0012DD90();        // FILE LOADER tick (async AFS/ADXF read state machines + time-sliced memcpy)
  func_00170D70();        // END SCENE: blend state, func_003DF7B0 (D_0062BFD4=2, records T0 count)
  func_003ECD00(0);       // VSYNC WAIT + FLIP + kick next DMA chain (asm)
}
```

The order is: input, sound, game update (logic plus *draw-list registration*),
then render (the CPU builds the DMA chains), then file I/O, then vsync/flip.
**The GS draws frame N while the CPU builds frame N+1.** `func_003ECD00` waits
for the previous chain (`func_003DC950`), polls `GS CSR` VSINT, selects the
per-field DISPFB from `D_00478B60/70`, writes PMODE/DISPFB/BGCOLOR (through the
immediate GIF sender `func_003DBBF0`), toggles `D_0062BFD8` (buffer index),
starts the VIF1 chain that was just built (`func_003DC720`), and resets the
packet heap (`func_003DD0D0`).

Port mapping: replace `func_003ECD00` with "submit the GL frame +
`SDL_GL_SwapWindow`", paced to a fixed 60 Hz. Logic is frame-locked (every
timer counts frames) and the game has no delta time, so run exactly one
iteration per 1/60 s even when the display refreshes faster.

## 4. Task/object system [verified]

There is no preemptive scheduler. Actors, effects and UI elements are **fixed
0x1E4-byte objects** from one pool (`src/object_pool.c`):

| Function | File | Role |
|---|---|---|
| `func_003DA750(owner, kind, init)` | src/grok_w7_003c.c | Allocate if the free count > 0 (906 call sites) |
| `func_003DA780` | src/object_pool.c | Pop the free list, zero it, `obj->kind = kind`, then `D_00477850[init](owner,obj,kind)` links it (insert head/tail/before/after: `func_003DA860/8C0/930/980`) |
| `func_003DAA40(obj)` | src/object_pool.c | Unlink and free (274 call sites) |
| `func_003DA6F0(kind)` | src/g6_30p.c | For each object in `D_004D3690[kind]` list: call `obj->+0x10` (update callback) |
| `func_003DA9D0(kind)` | src/object_pool.c | For each active object: `func_003DAB30` (insert into draw priority rows) |
| `func_003DAB30` | src/active_object_priority_queue.c | Up to 96 objects per row `D_004D1970[row][]` (row = `obj+0x24`), insertion-sorted by `obj+0x31` priority |

Object header: `+3 kind`, `+8 prev`, `+0xC next`, `+0x10 update fn`,
`+0x28 pre-draw fn`, `+0x84 model/resource ptr`, `+0x88..0xC4 4x4 matrix`,
`+0xD0 draw flags`, `+0x13C active`. Per-kind list heads and tails are
`D_004D3690[]`/`D_004D3520[]`, and the counts are `D_004D3460[]`.

**Draw-list registry** (`src/grok_w7_003c.c`, `src/text_pool_append_003D7350.c`):
- `func_003D7310(fn)` appends up to 16 scene render callbacks to `D_0058C800`
  each frame; `func_003D7400` calls them in order. Game states register
  callbacks like `func_00152790` (kind 13) and `func_001527C0` (kind 6), which
  run `func_00151A20(kind)` (matrices) and `func_001520E0(kind)` (draw models).
- `D_0058C7C0` holds the overlay callbacks run by `func_003D7640`.
- `func_003D7350(x, y, attr, fmt, ...)` appends a printf text record (up to 0x80,
  0x40 bytes each, at `D_0058CC40`). These are drawn by `func_0016D4B0`
  (src/chA_a.c) through the batched quad writer `func_00420BF0`. The same
  function draws overlay text through immediate triangles `func_003DF0C0`.
- `func_003D7300` / `func_003D7630` reset the lists every frame.

## 5. Game-state machine [verified structure; screen names inferred]

The global struct `g = D_004C2840` (= `D_004F4300`) holds the state:
`g[0]` = mode, `g[1]` = sub-state, `g[2]` = step. `func_003D7030`
(src/m11b.c) runs `D_00477400[g[0]]()` unless `D_004C2850` (a startup delay
counter) is non-zero, then `func_00122880`, `func_003298E0` and the frame
counters at `g+0x1C/0x20`.

| `g[0]` | Handler | Sub-dispatch |
|---|---|---|
| 0 | `func_003D6AF0` | `jtbl_004C21D8[g[1]]`: `func_003D6B10` (step), then `func_003D6B30`, which sets `g[0]=1` (boot to front end) |
| 1 | `func_003D1580` (src/w20b0_e.c) | `D_00477170[g[1]]` (front end, 14 slots): `003D16E0` (enter/route), `003D1FB0` (uses `D_004C21C0[g[2]]`, kind 6 objects, callback `func_001527C0`), `003D1A00` to `func_00143C60`, `003D1A10` (`jtbl_004C21B8[g[2]]`), `003D17F0` (`jtbl_004C21B0[g[2]]`), `003D1F60`, `003D1FA0` to `func_00127590`, `003D21F0` (`D_004C21C8[g[2]]`, kind 13, `func_00152790`), `003D24A0`/`003D24D0` (kind 13, `D_00152930`), `003D2500` (to `g[1]=13`), `[12] 00420920`, `[13] 004206D0` (network/"transfer back end" tables `jtbl_004A6F70/4A6F40`). It also handles START to pause/menu (`g[1]=7`) and resets sound. |
| 2 | `func_003D2770` (src/m11b.c) | `D_004C21D0[g[1]]`: `func_003D27D0` (battle setup: clears `D_004F4384`, `D_004D18A0`, loads the stage and characters), then `func_003D2B30` (`D_004771B0[g[2]]`, the in-battle phases) |
| 3 | `func_003D7180` | to `func_00128A30` |

Screens (title, mode select, character select `SELTEX/SELSTG/SELVMx`, VS screen
`VS4.BIN`, battle, win screen `PLxx_WIN`, ranking, options, gallery `GALxx.TM2`,
memory card, network `ADX_NETW`/`AVETCP`) map onto mode 1 and mode 2
sub-states. The exact index-to-screen naming has not been traced yet. The tables
above are where to start: set a breakpoint in a port build, or follow which
files each sub-state requests.

## 6. Hardware touch points that must be shimmed

| Access | Where | Replace with |
|---|---|---|
| `0x12001000` GS CSR (VSINT/FIELD), `0x12000000..` PMODE/DISPFB | flip `func_003ECD00`, libgraph | Host vsync and swap |
| `0x1000A000` GIF CHCR busy-wait, `0x10009000` VIF1 | `func_003DBBF0`, libdma, `func_003DC3C0` (DMA-end IRQ handler) | Delete: the renderer is synchronous |
| `0x70000000` scratchpad (used as a packet scratch buffer) | `func_003DBBF0`, `func_003DF490` | A 16 KB static array |
| `0x10000000` T0_COUNT (profiling/frame time) | `func_003DF7B0`, `func_00418020`, many | Host timer |
| `0x10000010/0x10000800` INTC/DMAC | init, flip | Delete |
| SIF RPC (pad, mc, cd, TSD, ADX IOP) | Sony and CRI libs | Host back ends |

The code also assumes **32-bit pointers** throughout: `(u32)ptr` arithmetic,
`base + offset` relocation of loaded files (`func_0016F4D0`, `func_0016F1B0`),
handles holding addresses, and DMA tags storing `addr & 0x0FFFFFFF`. The port
therefore needs a 32-bit address model: build `-m32`/wasm32, or keep all game
memory in one arena below 4 GB with pointer-width typedefs. Emscripten
(wasm32) does this natively. Desktop x86-64/arm64 builds need the arena
approach.
