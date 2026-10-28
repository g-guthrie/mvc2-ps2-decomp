# Platform surface inventory (Port B)

Scope: everything in SLUS_204.86 that depends on the PS2, and so must be supplied by the
native platform layer (portable C + SDL + GL ES3/WebGL2, desktop + Emscripten).
Inputs: `asm/main.s`, `config/functions.csv`, `config/symbol_addrs.txt`, `config/matches.csv`
plus `src/` file names and comments, `docs/*.md`, and string, pointer and RPC-ID scans of
`private/extracted/SLUS_204.86`. Per-function results are in
[`platform_functions.csv`](platform_functions.csv), with one row for each of the 20,193
`code`/`assembly_residual` rows in `functions.csv`.

## Headline numbers

| | functions | bytes |
|---|---:|---:|
| All code (`functions.csv` code + assembly_residual) | 20,193 | 3,185,368 |
| Portable game logic (`subsystem=game`) | 18,303 (90.6%) | 2,828,148 (88.8%) |
| PS2/platform code (all non-game subsystems) | 1,890 | 357,220 |
| of which libc/libm/soft-float (replaced by the host C runtime) | 173 | 69,680 |
| of which "real" platform (kernel, GS/DMA, VU0, SIF/IOP, CRI, CD, pad, memcard, timers) | 1,717 | 287,540 |
| platform functions with no code caller and no data pointer (dead linked library code) | 514 | about 46 KB |
| **Boundary leaves**, the platform functions called directly by portable game code | **131** | |
| boundary leaves excluding libc/softfloat | **90** | |
| game functions that call a boundary leaf in a non-libc subsystem | 149 | |

There are no `syscall`, COP0, VU0/COP2 or hardware-register accesses anywhere in the game core
(`0x122670..0x3DB7F0`, 17,886 functions). All of them sit in the linked SDK, Capcom's `fl`
PS2 framework, CRI middleware, and a small amount of Capcom system glue. The game core
reaches the PS2 only by calling into those layers.

## Method

1. **Parse `asm/main.s`** into the `functions.csv` intervals, then collect for each function:
   `jal`/`j` targets (36,929 call edges, all resolved), `%hi/%lo` symbol references (function
   pointers and data), `syscall` with the preceding `addiu $v1,$zero,N`, COP0 ops
   (`ei/di/mfc0/sync.p/cache/tlb*`), VU0 macro ops (`v*`, `lqc2/sqc2/qmfc2/qmtc2/ctc2/cfc2`),
   MMI ops, and hardware-register accesses. A hardware access is a `lui 0x1000..0x12FF` or
   `0x7000` whose register is then used as a load/store base. A bare `lui 0x10000000` is
   usually a bit-flag constant in game code, and the base-register rule removes those false
   positives.
2. **Data pointers:** scan every aligned word of the ELF from `0x424200` for values equal to a
   function start (13,009 functions are referenced from data tables), and for pointers to file
   name strings.
3. **Strings:** `strings` on the ELF, mapped to vaddr (`file_off + 0xFFF80`). They are joined to
   functions through `%lo(D_xxx)` references. SDK version tags (`PsIIlibgraph2500`,
   `PsIIlibkernl2550`, `PsIIlibpad 2500`, `PsIIlibcdvd 2530`, `PsIIlibmc 2540`), CRI version
   banners and the error strings (`ADXT_Stop: parameter error`, `@flReloadTexture`, ...)
   identify the libraries and name many functions.
4. **Link-order regions:** the libraries are contiguous objects. Their edges were found from
   the version strings, `src/` file names (`sony29_*`, `newlib_*`, `gcc_*`, `vu0_*`), and the
   compiler alignment signature: CRI objects start on 8-byte boundaries, while Capcom's MWCC
   output is 16-byte aligned. The first 8-aligned function is `0x3F5F88` and the last is
   `0x411BC8`.
5. **Classify:**
   - SDK and CRI functions take the subsystem of their region (table below).
   - Capcom framework/glue functions take a subsystem from direct signals: hardware-register
     class, scratchpad, COP2, strings, or calls into SDK/CRI. Inside the `fl` framework a call
     to another platform `fl` function also counts.
   - VU0 and libc calls do not propagate upward. Their replacements are portable C, so calling
     them does not make the caller platform code.
   - Helpers whose callers are all in one platform subsystem inherit it.
   - Everything else is `game`.
6. **Boundary:** `leaf=yes` marks a platform function with at least one `game` caller. These
   functions are the minimum the port must re-implement; everything above them compiles
   unchanged.

Name column: an exact SDK/CRI name where strings, docs or `src/` comments establish it.
A trailing `?` means a role-based guess. `func_xxxxxxxx` means unnamed.

## Memory map (link order)

| range | layer | contents |
|---|---|---|
| `100000-1001E0` | crt0 | `_start` (SetupThread 0x3C, SetupHeap 0x3D), `main` = `func_00170C30` |
| `1001E0-1002D8` | SN fp runtime | `_dpflt/_dpfle/_dpfgt/_dpfge/_d_utod` |
| `1002D8-102420` | libgraph 2.5.0.0 | sceGs* (ResetGraph, DispEnv, PutDrawEnv, SyncPath, Load/StoreImage, SyncV) |
| `102420-102C70` | libdma 2.5.0.0 | sceDma* (reset, getchan, send, sync) |
| `102C70-1039C0` | libvu0 | sceVu0* macro-mode math (src/vu0_a.c, vu0_f.c) |
| `1039C0-104260` | libkernl syscalls | 138 one-instruction syscall stubs |
| `104260-105F58` | libkernl | vsync/INTC wait, cache ops, DECI2/TTY console, scePrintf, heap, thread-queue |
| `105F58-107588` | libkernl SIF | SIF DMA/cmd/RPC (sceSifInitRpc `106628`, BindRpc `106C98`, CallRpc `106E68`) |
| `107588-10AC48` | libkernl fileio | sceOpen/Close/Read/Write/Lseek/Ioctl... over RPC 0x80000001 |
| `10AC48-10C060` | libkernl iopheap/loadfile | sceSifAllocIopHeap (0x80000003), sceSifLoadModule (0x80000006) |
| `10C060-10D248` | libkernl exec/TLB | sceSifRebootIop (`rom0:UDNL`), LoadExecPS2, TLB setup, kernel hooks |
| `10D248-10E6D0` | libpad 2.5.0.0 | scePad* (RPC 0x80000100/0x80000101) |
| `10E6D0-10FD90` | libcdvd 2.5.3.0 | sceCd* (RPC 0x80000592/593/595/597/59A, 0x80000012), clock |
| `10FD90-111588` | libmc 2.5.4.0 | sceMc* (RPC 0x80000400) |
| `111588-117448` | newlib libm | atan2, pow, sqrt, sin/cos kernels, float variants, EE math wrappers |
| `117448-119DA0` | libgcc / soft-fp | `__muldi3..__umoddi3`, `dpadd/dpmul/dpdiv/...`, `fptosi/...` |
| `119DA0-122670` | newlib libc | stdio, heap, dtoa, vfprintf, qsort, strings |
| `122670-3DB7F0` | **game core** | 17,886 functions, all portable |
| `3DB7F0-3F5F88` | Capcom `fl` PS2 framework | GS/DMA/VU1 packets, texture/palette VRAM manager, prims, flip, pad, module loader, BMP/model loaders |
| `3F5F88-411C10` | CRI middleware | ADX (ADXT 8.19, ADXF 6.24, ADXPS2 2.33, AIXP 1.27), CVFS 2.24, SRD 2.00, DTR/DTX, DVCI/HTCI 2.50, LSC 2.07, PS2RNA 1.14, SJ 6.08/SJX/SJRMT, SVM 1.08 |
| `411C10-424000` | Capcom system glue (mixed) | sprite-sheet cache, game draw helpers, save UI, CRI/FS init, memcard wrapper, sound IRX load, USB/net load, Tamsoft sound driver client |

## Summary by subsystem

| subsystem | functions | bytes | boundary leaves | dead (unreferenced) | port replacement |
|---|---:|---:|---:|---:|---|
| game | 18,303 | 2,828,148 | - | 11 | compile as-is |
| (a) kernel: syscalls, threads, semas, INTC/DMAC, alarms, cache, TLB, DECI2 | 260 | 14,276 | 2 | 116 | no-ops; SDL_sem/SDL_Thread only where the sound/CRI shims need a thread |
| (b) libc/newlib/libm/soft-fp | 173 | 69,680 | 41 | 9 | host libc and libm; native float/double operators |
| (c) graphics: GS/GIF/DMA/VIF/VU1/scratchpad, `fl` renderer | 193 | 91,048 | 31 | 10 | new `fl` backend on GL ES3/WebGL2 |
| (d) VU0 math (libvu0 + inline COP2 in `fl`) | 49 | 4,216 | 6 | 28 | plain C float vector/matrix code |
| (e) SIF RPC / IOP modules (incl. Tamsoft sound client, USB/net) | 117 | 22,132 | 18 | 31 | host services; Tamsoft driver reimplemented on host audio |
| (f) CRI middleware (ADX/AFS/CVFS/SJ/...) | 940 | 112,924 | 17 | 274 | ADXF/ADXT shim: AFS reader + ADX decoder + SDL audio |
| (g) CD/DVD + fileio | 65 | 20,060 | 0 | 26 | none needed above CRI; host stdio under the shim |
| (h) pad/input | 41 | 10,168 | 4 | 12 | SDL_GameController + keyboard |
| (i) memory card/saves | 45 | 11,056 | 11 | 8 | host save directory |
| (j) timers/VSync/RTC | 7 | 1,660 | 1 | 0 | SDL vsync/timer, `time()` |

Every platform row in the CSV has a `component` column: the library or object family
(e.g. `libgraph`, `adxt_adxm_adxstm_aixp`, `tamsoft_sound_client`). The `evidence` column
records the signals behind each classification.

## The boundary (leaf platform functions)

These 131 functions are the complete set of platform functions that portable game code calls
directly. Implement them on the host and everything above them is game logic. The libc and
soft-float rows need no work: the host compiler and C library supply them.

One practical choice: the cut falls at the Capcom `fl` API (texture/palette handles, primitive
submit, flip) and the ADXF/ADXT API, not at GS packets or IOP RPC. The `fl` internals below
the cut (GS packet building, VRAM allocator, DMA chains, roughly 150 functions) and all CRI
internals are dropped, not ported. The game core never calls libgraph, libdma, fileio, libcdvd
file reads, or SIF directly.

#### Boundary: a_kernel (2)

| address | name / purpose | component | callers (game) | replacement |
|---|---|---|---|---|
| `41BAD0` | DMA-guard begin (DisableDmac wrapper) | capcom_cache_sync | 17 (17) | no-op |
| `41BB30` | cache sync + DMA-guard end | capcom_cache_sync | 17 (17) | no-op |

#### Boundary: b_libc (41)

| address | name / purpose | component | callers (game) | replacement |
|---|---|---|---|---|
| `100230` | _d_utod | sn_fp_runtime | 2 (2) | native C double compare/convert |
| `100240` | _dpflt | sn_fp_runtime | 28 (28) | native C double compare/convert |
| `100260` | _dpfle | sn_fp_runtime | 4 (4) | native C double compare/convert |
| `100290` | _dpfgt | sn_fp_runtime | 10 (10) | native C double compare/convert |
| `1002B0` | _dpfge | sn_fp_runtime | 3 (3) | native C double compare/convert |
| `1165B0` | func_001165B0 | libm | 3 (3) | host libm |
| `116B98` | sin | libm | 3 (3) | host libm |
| `116CD0` | atanf | libm | 2 (1) | host libm |
| `116FA0` | func_00116FA0 | libm | 3 (2) | host libm |
| `117078` | fabsf | libm | 20 (15) | host libm |
| `1170A0` | func_001170A0 | libm | 2 (1) | host libm |
| `117240` | func_00117240 | libm | 4 (4) | host libm |
| `117328` | tanf | libm | 1 (1) | host libm |
| `1173A0` | func_001173A0 | libm | 2 (1) | host libm |
| `1173B8` | func_001173B8 | libm | 1 (1) | host libm |
| `1173D0` | func_001173D0 | libm | 2 (1) | host libm |
| `1173E8` | func_001173E8 | libm | 1 (1) | host libm |
| `117400` | func_00117400 | libm | 1 (1) | host libm |
| `117418` | func_00117418 | libm | 1 (1) | host libm |
| `117430` | sqrtf | libm | 2 (1) | host libm |
| `118FA8` | fptosi | libgcc_softfp | 141 (134) | native C float/double arithmetic |
| `119058` | fptodp | libgcc_softfp | 221 (219) | native C float/double arithmetic |
| `119098` | fptoui | libgcc_softfp | 32 (25) | native C float/double arithmetic |
| `119510` | dpadd | libgcc_softfp | 227 (211) | native C float/double arithmetic |
| `119568` | dpsub | libgcc_softfp | 42 (27) | native C float/double arithmetic |
| `1195D0` | dpmul | libgcc_softfp | 213 (197) | native C float/double arithmetic |
| `119858` | dpdiv | libgcc_softfp | 224 (215) | native C float/double arithmetic |
| `119B08` | litodp | libgcc_softfp | 99 (90) | native C float/double arithmetic |
| `119BC0` | dptoli | libgcc_softfp | 186 (177) | native C float/double arithmetic |
| `119C90` | dptofp | libgcc_softfp | 86 (84) | native C float/double arithmetic |
| `119CE8` | dptoul | libgcc_softfp | 2 (1) | native C float/double arithmetic |
| `119D88` | func_00119D88 | libgcc_softfp | 1 (1) | native C float/double arithmetic |
| `11D740` | memcpy | newlib | 33 (12) | host libc |
| `11D8F8` | memset | newlib | 181 (88) | host libc |
| `11EB60` | vsprintf? | newlib | 54 (1) | host libc |
| `11EBD0` | qsort | newlib | 1 (1) | host libc |
| `11F5C0` | srand | newlib | 1 (1) | host libc |
| `11F5D8` | rand | newlib | 2 (2) | host libc |
| `11F938` | sprintf | newlib | 18 (14) | host libc |
| `11FFA0` | strlen | newlib | 33 (3) | host libc |
| `122340` | vsprintf-to-buffer? | newlib | 6 (1) | host libc |

#### Boundary: c_gfx (31)

| address | name / purpose | component | callers (game) | replacement |
|---|---|---|---|---|
| `3DCFE0` | fl handle -> object (DI/EI) | capcom_fl_framework | 15 (5) | GL ES3/WebGL2 renderer (fl API) |
| `3DD040` | fl handle -> object | capcom_fl_framework | 4 (2) | GL ES3/WebGL2 renderer (fl API) |
| `3DD160` | flAllocWork? (frame work-area bump allocator; flips when full) | capcom_fl_framework | 39 (1) | GL ES3/WebGL2 renderer (fl API) |
| `3DE7E0` | fl handle op | capcom_fl_framework | 1 (1) | GL ES3/WebGL2 renderer (fl API) |
| `3DEE00` | flps triangle variant | capcom_fl_framework | 1 (1) | GL ES3/WebGL2 renderer (fl API) |
| `3DF0C0` | flpsTri3DTG (textured 3D triangle) | capcom_fl_framework | 1 (1) | GL ES3/WebGL2 renderer (fl API) |
| `3DF490` | sprite packet build in scratchpad | capcom_fl_framework | 4 (4) | GL ES3/WebGL2 renderer (fl API) |
| `3DF850` | primary primitive/sprite submit (45 game callers) | capcom_fl_framework | 47 (46) | GL ES3/WebGL2 renderer (fl API) |
| `3E8C00` | flPS2GetTextureInfoFromContext | capcom_fl_framework | 5 (4) | GL ES3/WebGL2 renderer (fl API) |
| `3E8DF0` | flPS2CreateTextureHandle | capcom_fl_framework | 5 (4) | GL ES3/WebGL2 renderer (fl API) |
| `3E8F90` | texture handle release/full check | capcom_fl_framework | 5 (4) | GL ES3/WebGL2 renderer (fl API) |
| `3E9110` | flCreatePaletteHandle (context) | capcom_fl_framework | 3 (2) | GL ES3/WebGL2 renderer (fl API) |
| `3E9250` | flPS2CreatePaletteHandle | capcom_fl_framework | 3 (2) | GL ES3/WebGL2 renderer (fl API) |
| `3E93A0` | palette handle release/full check | capcom_fl_framework | 3 (2) | GL ES3/WebGL2 renderer (fl API) |
| `3E9580` | texture lock/update (via 0x3E96A0) | capcom_fl_framework | 4 (4) | GL ES3/WebGL2 renderer (fl API) |
| `3E95E0` | texture lock/update (via 0x3E96A0) | capcom_fl_framework | 4 (3) | GL ES3/WebGL2 renderer (fl API) |
| `3EA070` | palette lock/update (via 0x3EA130) | capcom_fl_framework | 4 (4) | GL ES3/WebGL2 renderer (fl API) |
| `3EA0D0` | palette lock/update (via 0x3EA130) | capcom_fl_framework | 4 (3) | GL ES3/WebGL2 renderer (fl API) |
| `3EA660` | flReloadTexture (VRAM upload) | capcom_fl_framework | 9 (8) | GL ES3/WebGL2 renderer (fl API) |
| `3ECD00` | flFlip? (vsync wait; GS CSR field/FINISH; swap) | capcom_fl_framework | 3 (2) | GL ES3/WebGL2 renderer (fl API) |
| `3ED1C0` | fl object setup via handle (DI/EI) | capcom_fl_framework | 3 (3) | GL ES3/WebGL2 renderer (fl API) |
| `3EE6F0` | flCreateClayHandle (model) | capcom_fl_framework | 1 (1) | GL ES3/WebGL2 renderer (fl API) |
| `3F0500` | fl model/clay draw setup (DI/EI; texture reload) | capcom_fl_framework | 1 (1) | GL ES3/WebGL2 renderer (fl API) |
| `3F2A50` | plAMOCreateClayFromImage | capcom_fl_framework | 1 (1) | GL ES3/WebGL2 renderer (fl API) |
| `3F3770` | plBMPSetContextFromImage | capcom_fl_framework | 1 (1) | GL ES3/WebGL2 renderer (fl API) |
| `3F3850` | plCreateContextFromBMPImage | capcom_fl_framework | 1 (1) | GL ES3/WebGL2 renderer (fl API) |
| `411C10` | CreateSSHandle (sprite-sheet cache: SSCACHE/TEXTURE/PALETTE) | capcom_ss_sprite_cache | 1 (1) | port as-is over new fl texture API |
| `412260` | func_00412260 | capcom_ss_sprite_cache | 1 (1) | port as-is over new fl texture API |
| `41B8B0` | scratchpad packet helper | capcom_system_glue | 1 (1) | GL ES3/WebGL2 renderer |
| `420980` | scratchpad packet helper | capcom_system_glue | 1 (1) | GL ES3/WebGL2 renderer |
| `421270` | scratchpad packet helper | capcom_system_glue | 1 (1) | GL ES3/WebGL2 renderer |

#### Boundary: d_vu0 (6)

| address | name / purpose | component | callers (game) | replacement |
|---|---|---|---|---|
| `3DE160` | VU0 inline matrix multiply (4x4) | capcom_fl_framework | 36 (9) | portable C (VU0 macro ops -> float math) (fl API) |
| `3DE230` | VU0 inline matrix op | capcom_fl_framework | 14 (1) | portable C (VU0 macro ops -> float math) (fl API) |
| `3DE3D0` | VU0 inline matrix op | capcom_fl_framework | 1 (1) | portable C (VU0 macro ops -> float math) (fl API) |
| `3DE530` | VU0 inline vector transform | capcom_fl_framework | 16 (2) | portable C (VU0 macro ops -> float math) (fl API) |
| `3DE5C0` | VU0 inline vector op | capcom_fl_framework | 1 (1) | portable C (VU0 macro ops -> float math) (fl API) |
| `3DE7A0` | VU0 inline vector op | capcom_fl_framework | 1 (1) | portable C (VU0 macro ops -> float math) (fl API) |

#### Boundary: e_sif_iop (18)

| address | name / purpose | component | callers (game) | replacement |
|---|---|---|---|---|
| `3EC160` | flInitialize(640;480): IOP reboot; IRX loads; GS/DMA/VU init | capcom_fl_framework | 1 (1) | host service (no IOP) (fl API) |
| `419FE0` | sound driver entry (after IRX load) | capcom_sound_irx_load | 2 (2) | init SDL audio + host Tamsoft driver reimplementation |
| `41A040` | sound driver entry | capcom_sound_irx_load | 1 (1) | init SDL audio + host Tamsoft driver reimplementation |
| `420310` | USB/net query | capcom_usb_net_load | 1 (1) | no-op (network/USB keyboard unsupported) |
| `420340` | USB/net RPC | capcom_usb_net_load | 1 (1) | no-op (network/USB keyboard unsupported) |
| `422BE0` | Tamsoft stub (empty) | tamsoft_sound_client | 2 (2) | reimplement Tamsoft driver commands on host (SE/voice/BGM synth over SPU-ADPCM decoder + mixer) |
| `422C70` | Tamsoft lock/unlock (sema) | tamsoft_sound_client | 2 (2) | reimplement Tamsoft driver commands on host (SE/voice/BGM synth over SPU-ADPCM decoder + mixer) |
| `422EA0` | Tamsoft queue command (voice/SE?) | tamsoft_sound_client | 3 (3) | reimplement Tamsoft driver commands on host (SE/voice/BGM synth over SPU-ADPCM decoder + mixer) |
| `422FB0` | Tamsoft queue command (9 game callers) | tamsoft_sound_client | 9 (9) | reimplement Tamsoft driver commands on host (SE/voice/BGM synth over SPU-ADPCM decoder + mixer) |
| `4230B0` | Tamsoft command | tamsoft_sound_client | 1 (1) | reimplement Tamsoft driver commands on host (SE/voice/BGM synth over SPU-ADPCM decoder + mixer) |
| `4231D0` | Tamsoft command | tamsoft_sound_client | 1 (1) | reimplement Tamsoft driver commands on host (SE/voice/BGM synth over SPU-ADPCM decoder + mixer) |
| `423240` | Tamsoft command | tamsoft_sound_client | 1 (1) | reimplement Tamsoft driver commands on host (SE/voice/BGM synth over SPU-ADPCM decoder + mixer) |
| `423480` | Tamsoft command | tamsoft_sound_client | 1 (1) | reimplement Tamsoft driver commands on host (SE/voice/BGM synth over SPU-ADPCM decoder + mixer) |
| `4235D0` | Tamsoft command | tamsoft_sound_client | 1 (1) | reimplement Tamsoft driver commands on host (SE/voice/BGM synth over SPU-ADPCM decoder + mixer) |
| `423650` | Tamsoft command | tamsoft_sound_client | 1 (1) | reimplement Tamsoft driver commands on host (SE/voice/BGM synth over SPU-ADPCM decoder + mixer) |
| `4236C0` | Tamsoft command | tamsoft_sound_client | 1 (1) | reimplement Tamsoft driver commands on host (SE/voice/BGM synth over SPU-ADPCM decoder + mixer) |
| `423750` | Tamsoft flush command buffer (sceSifCallRpc) | tamsoft_sound_client | 3 (1) | reimplement Tamsoft driver commands on host (SE/voice/BGM synth over SPU-ADPCM decoder + mixer) |
| `423990` | Tamsoft sync/poll | tamsoft_sound_client | 3 (3) | reimplement Tamsoft driver commands on host (SE/voice/BGM synth over SPU-ADPCM decoder + mixer) |

#### Boundary: f_cri (17)

| address | name / purpose | component | callers (game) | replacement |
|---|---|---|---|---|
| `3FCA60` | ADXF_Open | adxf_afs | 6 (1) | AFS reader on host file (ADXF_* shim) |
| `3FCBC0` | ADXF_OpenAfs | adxf_afs | 2 (2) | AFS reader on host file (ADXF_* shim) |
| `3FCCF0` | ADXF_Close | adxf_afs | 13 (4) | AFS reader on host file (ADXF_* shim) |
| `3FD0F8` | ADXF_ReadNw | adxf_afs | 2 (2) | AFS reader on host file (ADXF_* shim) |
| `3FD450` | ADXF_GetFsizeSct | adxf_afs | 2 (2) | AFS reader on host file (ADXF_* shim) |
| `3FD530` | ADXF_GetStat | adxf_afs | 6 (2) | AFS reader on host file (ADXF_* shim) |
| `3FEAD0` | ADXM/SVM server exec? | adxt_adxm_adxstm_aixp | 2 (1) | ADXT shim: decode ADX -> SDL audio stream |
| `401868` | ADXT_Stop | adxt_adxm_adxstm_aixp | 12 (3) | ADXT shim: decode ADX -> SDL audio stream |
| `401920` | ADXT_GetStat | adxt_adxm_adxstm_aixp | 6 (2) | ADXT shim: decode ADX -> SDL audio stream |
| `4020D8` | ADXT_SetOutVol | adxt_adxm_adxstm_aixp | 3 (3) | ADXT shim: decode ADX -> SDL audio stream |
| `402498` | ADXT_ExecServer? | adxt_adxm_adxstm_aixp | 6 (1) | ADXT shim: decode ADX -> SDL audio stream |
| `4026B0` | ADXT_Pause | adxt_adxm_adxstm_aixp | 5 (4) | ADXT shim: decode ADX -> SDL audio stream |
| `402BC0` | ADXT_Init? | adxt_adxm_adxstm_aixp | 1 (1) | ADXT shim: decode ADX -> SDL audio stream |
| `402C20` | ADXT_StartAfs | adxt_adxm_adxstm_aixp | 1 (1) | ADXT shim: decode ADX -> SDL audio stream |
| `418910` | game ADX/CRI init (ADXT_Create; reload sectors) | capcom_cri_fs_init | 1 (1) | host: open AFS archives; init ADX shim |
| `418AA0` | ADX stream status wait (sceCdSync+ADXT_GetStat) | capcom_cri_fs_init | 2 (2) | host: open AFS archives; init ADX shim |
| `418B10` | ADX server tick | capcom_cri_fs_init | 3 (2) | host: open AFS archives; init ADX shim |

#### Boundary: h_pad (4)

| address | name / purpose | component | callers (game) | replacement |
|---|---|---|---|---|
| `10DF60` | scePadRead?/GetState? (pad DMA buffer read) | libpad | 2 (2) | SDL_GameController / keyboard |
| `10E020` | scePadSetActDirect (cmd 8; 6 actuator bytes) | libpad | 2 (1) | SDL_GameController / keyboard |
| `3ED300` | flPADInitialize? (scePadInit/PortOpen) | capcom_fl_framework | 1 (1) | SDL input (fl API) |
| `3ED920` | flPADGetALL? (per-frame pad read + actuator) | capcom_fl_framework | 1 (1) | SDL input (fl API) |

#### Boundary: i_memcard (11)

| address | name / purpose | component | callers (game) | replacement |
|---|---|---|---|---|
| `414CB0` | build save header (MVSC2_EEE..; RTC timestamp) | capcom_system_glue | 1 (1) | host save files |
| `418CC0` | memcard init wrapper (sceMcInit) | capcom_memcard_wrap | 4 (3) | host save files (BASLUS-20486/ dir) |
| `418D70` | memcard request/sync state machine | capcom_memcard_wrap | 9 (9) | host save files (BASLUS-20486/ dir) |
| `419310` | mc GetInfo wrapper | capcom_memcard_wrap | 2 (2) | host save files (BASLUS-20486/ dir) |
| `419520` | mc Close? wrapper | capcom_memcard_wrap | 2 (1) | host save files (BASLUS-20486/ dir) |
| `419610` | mc GetDir wrapper | capcom_memcard_wrap | 3 (2) | host save files (BASLUS-20486/ dir) |
| `419730` | mc Mkdir? wrapper | capcom_memcard_wrap | 5 (4) | host save files (BASLUS-20486/ dir) |
| `419840` | mc Open wrapper | capcom_memcard_wrap | 3 (2) | host save files (BASLUS-20486/ dir) |
| `419950` | mc Seek?/Flush? wrapper | capcom_memcard_wrap | 3 (2) | host save files (BASLUS-20486/ dir) |
| `419AC0` | mc Read wrapper | capcom_memcard_wrap | 2 (1) | host save files (BASLUS-20486/ dir) |
| `419B90` | mc Write? wrapper | capcom_memcard_wrap | 2 (1) | host save files (BASLUS-20486/ dir) |

#### Boundary: j_timer_vsync (1)

| address | name / purpose | component | callers (game) | replacement |
|---|---|---|---|---|
| `10FC98` | sceCdReadClock (RTC via IOP) | libcdvd_rtc | 3 (2) | time()/localtime() |

## Per-subsystem notes

### (a) EE kernel: syscalls, threads, semaphores, interrupts, alarms

- The 138 stubs at `1039C0-104260` and 21 more near `10C290-10D160` (kSetHook/kCopy/SetSyscall
  and TLB stubs) cover the whole syscall table. Only 58 have callers:
  `CreateThread(7) StartThread(7) ExitDeleteThread(6) ChangeThreadPriority(19) GetThreadId(11)
  ReferThreadStatus(10) Sleep/WakeupThread(4/8) Suspend/ResumeThread(2/6) CreateSema(33)
  DeleteSema(29) SignalSema(46) iSignalSema(8) WaitSema(39) PollSema(23) Add/RemoveIntcHandler,
  Add/RemoveDmacHandler, _Enable/_DisableIntc/Dmac (+i variants), SetAlarm?(0xFC, 3),
  FlushCache(13), GsGet/PutIMR, SetGsCrt, SetVSyncFlag, SifSetDma/DChain/Reg/GetReg/DmaStat,
  SetOsdConfigParam/GetOsdConfigParam, Deci2Call(10), EndOfHeap, GetMemorySize, ExecOSD,
  LoadExecPS2/ExecPS2, _InitTLB`.
  Almost every caller is inside the SDK (SIF RPC, libpad/libcdvd/libmc locking), CRI
  (SJ/SVM/SRD locking) or the Tamsoft client.
- The game core never calls a syscall. Its only kernel-flavoured leaves are `41BAD0`/`41BB30`
  (17 callers each). They wrap DMA-disable plus D-cache writeback around buffers handed to
  DMA, and become no-ops.
- Threads: the game itself is single-threaded. Threads exist inside libkernl/SIF and CRI's
  server model (SVM, ADXT server). The host shims can run CRI/sound work from the frame loop
  or an SDL audio callback, so no thread emulation is required.
- Alarms/interrupts: used by Tamsoft (`422C20` registers an alarm with handler `422BF0`), by
  `fl` (`3DC250` AddDmacHandler) and by vsync waits. Replace with per-frame callbacks.

### (b) libc / newlib / libm / soft-float

newlib 1.10-era libc (`119DA0-122670`), libm (`111588-117448`), libgcc soft-float and 64-bit
helpers (`117448-119DA0`), SN runtime float compares (`1001E0-1002D8`). The game calls
memset (88 callers), memcpy, sprintf, strlen, qsort, rand/srand, fabsf/sqrtf/sin/atanf/tanf
and the soft-double routines heavily (`dpadd/dpmul/dpdiv/fptodp/dptoli` have about 200 game
callers each). In the C sources these are compiler-generated for `double` arithmetic and
conversions, so a native build gets them for free. Watch the semantics (see the
float-determinism risk).

### (c) Graphics: GS / GIF / DMA / VIF / VU1 / scratchpad

- **SDK:** libgraph (`sceGsResetGraph?` `1002D8`, `sceGsPutDrawEnv` `100D80`, `sceGsSyncPath`
  `100F00`, `sceGsExecLoadImage` `101540`, `sceGsExecStoreImage` `1016C0`) and libdma
  (`102420-102C70`). Direct register use: GS privileged registers `0x12000000-0x120010xx`
  (PMODE/DISPFB/DISPLAY/CSR/IMR), GIF `0x10003000-0x10003C20`, VIF0/1 `0x10003800-0x10003C00`,
  DMAC channels `0x10008000-0x1000E0xx`, D_ENABLER/W `0x1000F520/0x1000F590`, timers
  `0x10000000/0x10000800`.
- **Capcom `fl` framework** (`3DB7F0-3F5F88`, 311 functions). It is the real renderer and
  owns these jobs:
  - GS packet building in scratchpad `0x70000000` (`3DBA30/3DBA90/3DBAF0`, `3DF490`, `3E00D0-3E0B50`)
  - DMA chain submit (`3DBBF0`, `3DC3C0`, `3DC720`)
  - the VRAM texture/palette allocator (`flCreateTextureHandle`, `flCreatePaletteHandle`,
    `flReloadTexture`, `flPS2StoreTexture`, "Need to call Compact function")
  - primitive submit (`3DF850` with 46 game callers, `flpsTri3DTG`)
  - model ("clay") conversion (`flCreateClayHandle`, `flPS2ConvClayData`, `plAMOCreateClayFromImage`)
  - BMP loading
  - frame flip (`3ECD00`: polls GS CSR FINISH/FIELD, uses Timer0 mode)
  - init (`flInitialize` `3EC160`, called from `main` with 640x480)
  - about 20 render-mode workers `3E1B20-3E8490` reached through a function table at `0x477A00`
- Port: re-implement the 31 `fl`-level boundary functions on GL ES3. Texture and palette
  handles map to GL textures, and PSMT8/PSMT4 palettized textures go through a palette-lookup
  shader. The work-area allocator `3DD160` stays a CPU bump allocator.
- **Capcom sprite-sheet cache** (`411C10-413C00`, `CreateSSHandle`) sits on the `fl` texture
  API. Port it unchanged once `fl` is replaced.

### (d) VU0 math

libvu0 macro-mode functions (`102C70-1039C0`, e.g. sceVu0ApplyMatrix `102C70`,
sceVu0RotTransPers `103770`, sceVu0ClipScreen `103820`) plus inline COP2 in `fl`: `3DE160`
(4x4 multiply, 36 callers), `3DE230/3DE3D0/3DE530/3DE5C0/3DE7A0`, and in the sprite cache
(`4135D0`). No VU1 microcode upload was found in game code. The `fl` packets visibly go GIF/PATH3,
but a full VIF1/MPG audit was not done. Port: plain
C float code. Bit-exactness vs VU0 (no denormals, clamping, FMAC rounding) only matters where
results feed gameplay state.

### (e) SIF RPC / IOP modules

- SIF RPC is entirely internal to the SDK, CRI and the Tamsoft client. The game never binds
  or calls RPC.
- Tamsoft sound driver client (`422BE0-423E30`): commands are queued in an EE buffer
  (`422EA0`, `422FB0`, ... at `0x633E30`) and flushed with `sceSifCallRpc` (`423750`) to
  TSNDDRV.IRX on the IOP. It binds RPC servers `0x54534400`/`0x54534401` ("TSD\0"/"TSD\1")
  and prints "Connected to TamsoftSoundDriver: Version %d.%d (C)Tamsoft". The IOP side
  (TSNDDRV + Sony MODHSYN/MODMIDI/MODMSIN + LIBSD) does the SE, voice and MIDI-sequence
  playback on SPU2. Port: a host implementation of the Tamsoft command set, which needs the
  command protocol reverse-engineered (see risks).
- USB/network (`41FFD0-420400`): loads AVETCP.IRX, USB_SRCH.IRX and USBDRV.CNF, binds RPC
  `0x01270010`, and USBKB is loaded by `flInitialize` with `keybd=1`. These are leftovers of
  the Japanese network version (`BISLPM-65047NET`, `ADX_NETW.BIN`, `ave_tcp.tm2`). Port:
  stubs that report no device.

### (f) CRI middleware

932 functions, about 112 KB, of which 274 are unreferenced. The game uses only:

- **ADXF:** `ADXF_Open` (`3FCA60`), `ADXF_OpenAfs` (`3FCBC0`), `ADXF_Close` (`3FCCF0`),
  `ADXF_ReadNw` (`3FD0F8`), `ADXF_GetFsizeSct` (`3FD450`), `ADXF_GetStat` (`3FD530`). The
  callers are the game's file loader `12DA40`/`12DF30`, which also own the 983-entry file name
  table at `0x43CDA0`.
- **ADXT:** `ADXT_StartAfs` (`402C20`), `ADXT_Stop`, `ADXT_GetStat`, `ADXT_SetOutVol`,
  `ADXT_Pause`, `ADXT_ExecServer?` (`402498`, called each frame from `12F460`),
  `ADXT_Init?` (`402BC0`). The callers are the game BGM functions `1E3F50-1E46E0`.
- **Capcom CRI init** (`418910-418C70`):
  - loads CRI_ADXI.IRX
  - sets up the HOST or CD/DVD file system (`HST:pfs0:%s`, `\ps2`, DVCI cache from `0flist.dir`)
  - loads AFS partitions `afs00.afs`..`afs03.afs` (pointer table `0x4A6A60`, used by `4189A0`)
  - creates the ADXT handle

Everything below that (cvFs, DVCI/HTCI, SRD sector reads, DTX/DTR/SJX IOP transfer, PS2RNA
IOP PCM output, SJ ring buffers, SVM servers, LSC) can be dropped. Port: a shim with the same
signatures that reads loose files and AFS entries from the extracted disc and decodes ADX
(CRI ADPCM, a documented format) to an SDL audio stream.

### (g) CD/DVD and file IO

libcdvd (`sceCdInit`, `sceCdSearchFile`, `sceCdRead`, `sceCdSync`, `sceCdDiskReady`,
callbacks) and fileio (`sceOpen/Read/Write/Close/Lseek/Ioctl` over RPC 0x80000001) are only
used by CRI (SRD/DVCI/HTCI), `fl` debug logging (`3DCBB0`/`3DCC70`, `acrout.txt`) and
`flInitialize`. **No game-core caller.** All game file access goes through ADXF. Port: host
stdio under the ADXF shim, rooted at an extracted copy of the disc.

### (h) Pad / input

libpad (`10D248-10E6D0`; `scePadInit?` `10D360` binds 0x80000100/0x80000101). The `fl` pad
layer is `3ED300` (init/port open) and `3ED920` (per-frame read and actuator). Three game
functions (`16ED00`, `16EE50`, `16EEC0`) also call libpad directly: `10DF60`
(read/state) and `scePadSetActDirect` (`10E020`) for vibration. Port: SDL_GameController
plus keyboard, filling the same 32-byte DualShock2 buffer layout (digital bits and analog
bytes) the game parses. Rumble maps to `SDL_GameControllerRumble`.

### (i) Memory card / saves

libmc 2.5.4.0 (`10FD90-111588`: sceMcInit/Open/Read/Write?/Close?/GetInfo/GetDir/Mkdir?/
Chdir/Delete/SetFileInfo/Rename/Sync). The Capcom wrapper `418C70-419EE0` loads MCMAN/MCSERV,
and `418D70` is the async request/sync state machine. Game save UI lives in
`41BBB0-41FFD0` (portable). Save data:

- directory `BASLUS-20486` (functions `38CDD0`, `38CFB0`)
- `icon.sys` and `mvsc2.ico`, plus `icon_20/21/22.ico`
- save header `MVSC2_EEE_00_0000` with an RTC timestamp (`414CB0`, which calls
  `sceCdReadClock`)

Port: implement the 10 wrapper leaves on a host directory, keep the async status protocol
(always complete immediately), and report a formatted 8 MB card.

### (j) Timers / VSync / RTC

- VSync is handled inside `fl` (`3ECD00` polls GS CSR and Timer0; libkernl `104270`/`104300`
  wait on INTC `0x1000F000`).
- The game times everything by frame count, so the platform must call the game frame once
  per 1/60 s. Use SDL vsync with a fixed-step fallback.
- RTC: `sceCdReadClock` (`10FC98`) is called from `33FE10`, `3D6B70` and the save header.
  Port: `localtime()` converted to BCD.

## IOP modules loaded

| order | path | loaded by | purpose | port |
|---|---|---|---|---|
| 1 | `cdrom0:\MODULES\IOPRP255.IMG;1` | `flInitialize` -> `sceSifRebootIop` (`rom0:UDNL`) | IOP replacement kernel image | none |
| 2 | `cdrom0:\MODULES\SIO2MAN.IRX;1` | `flInitialize` -> `3DCAD0` | SIO2 serial manager | none |
| 3 | `cdrom0:\MODULES\PADMAN.IRX;1` | `flInitialize` | pad server (libpad) | SDL input |
| 4 | `cdrom0:\MODULES\USBD.IRX;1` | `flInitialize` | USB stack | none |
| 5 | `cdrom0:\MODULES\USBMLOAD.IRX;1` | `flInitialize` | USB autoloader | none |
| 6 | `cdrom0:\MODULES\USBKB.IRX;1` (args `keybd=1`, `debug=0`) | `flInitialize` | USB keyboard | none (or SDL keyboard) |
| 7 | `cdrom0:\MODULES\CRI_ADXI.IRX;1` | `418B50` | CRI ADX IOP side (PS2RNA/SJX/DTX servers) | ADX shim |
| 8 | `cdrom0:\MODULES\MCMAN.IRX;1`, `MCSERV.IRX;1` | `418C70` | memory card | host saves |
| 9 | `cdrom0:\MODULES\LIBSD.IRX;1`, `MODHSYN.IRX;1`, `MODMIDI.IRX;1`, `MODMSIN.IRX;1`, `TSNDDRV.IRX;1` | `419EE0` | SPU2 lib, Sony hardware synth, MIDI sequencer, MIDI stream in, Tamsoft sound driver | host Tamsoft reimplementation |
| 10 | `cdrom0:\MODULES\AVETCP.IRX;1`, `USB_SRCH.IRX;1` (+ `USBDRV.CNF;1`) | `420150` | network TCP stack, USB driver search | stubs |

`rom0:ROMVER` is read by `1004E0` (region/version), and `rom0:UDNL` is used for the IOP reboot.

## SIF RPC servers bound

| RPC ID | client (bind site) | server module |
|---|---|---|
| `0x80000001` | fileio (`107BC0`) | IOP FILEIO |
| `0x80000003` | iopheap (`10AC48`) | IOP heap (sceSifAllocIopHeap) |
| `0x80000006` | loadfile (`10B198`) | LOADFILE (sceSifLoadModule) |
| `0x80000100`, `0x80000101` | libpad (`10D360`) | PADMAN |
| `0x80000400` | libmc (`10FD90`) | MCSERV |
| `0x80000592` | libcdvd init (`10F3C8`) | CDVDFSV |
| `0x80000593` | libcdvd S-cmd (`10F258`) | CDVDFSV |
| `0x80000595` | libcdvd N-cmd (`10EF40`) | CDVDFSV |
| `0x80000597` | sceCdSearchFile (`10EC08`) | CDVDFSV |
| `0x8000059A` | sceCdDiskReady (`10F6A8`) | CDVDFSV |
| `0x7D000000` (variable `0x4C2440`) | CRI DTX_Init (`4095C8`) | CRI_ADXI (DTX/SJX/PS2RNA) |
| `0x01270010` | USB/net (`420150`) | USB keyboard / network module |
| `0x54534400`, `0x54534401` | Tamsoft (`422DB0` via `422D20`) | TSNDDRV |

Also present, as SIF *command* IDs rather than RPC servers: 0x80000002/8/9/A/C (SIF
cmd/RPC system handlers in `106628`), 0x80000011/0x80000013 (`107BC0`) and 0x80000012
(libcdvd callback, `10EA40`/`10EB90`).

## Files the game opens (asset-pipeline input)

All game data loads go through one loader (`12DA40`/`12DF30`, plus `12C0D0`, `12C120`,
`12E780`). It indexes a **983-entry file name table at `0x43CDA0`** and opens either a loose
ISO9660 file by name (`ADXF_Open`, through DVCI using `sceCdSearchFile` and the
`0flist.dir` cache) or an AFS entry (`ADXF_OpenAfs`). BGM streams from AFS through
`ADXT_StartAfs`. The name families in the table (`##` = hex index 00..3A, 59 characters) are:

| family | count | probable content |
|---|---:|---|
| `PL##PAK.BIN` | 59 | per-character packed data |
| `PL##_TBL.BIN`, `PL##_##C.BIN` (`_FAC`), `PL##_WIN.BIN` | 59 / 59 / 56 | char tables, face/portrait graphics, win-quote graphics |
| `PL##_VOI.BIN` | 59 | character voice bank (SPU ADPCM for Tamsoft) |
| `HIT_##.BIN`, `HIT_FM##.BIN`, `HIT_DT##.BIN` | 59 each | hitbox data, frame and detail tables |
| `ATCK##`, `TAIKI##`, `WARI##`, `YOK##.BIN` | 59 each | attack, idle (taiki), throw-break (wari), guard (yoke?) motion data |
| `STG##TEX/POL.BIN`, `DM##TEX/POL.BIN`, `dm##tex/pol.bin`, `stg03.dat` | 17 / 23 / 4 | stage textures and polygons, demo/backgrounds |
| `GAL##.TM2` | 56 | gallery art (TIM2) |
| `font.tm2`, `font01.tm2`, `memoryfont.tm2`, `command.tm2`, `cri_adx.tm2`, `ave_tcp.tm2`, `COMING.TM2` | 7 | UI fonts/logos (TIM2) |
| `SE_COMN/SE_STAF/SE_SYUK/SE_ST##.BIN` | 4+ | sound-effect banks (Tamsoft) |
| `ADX_S000..S0B0`, `ADX_OPEN/STAF/SELC/CONT/HERE/OVER/RANK/WINS/MENU/CAPL/..PL.ADX`, `ADX_NETW.BIN` | about 25 | BGM (ADX), possibly inside AFS |
| `SEL*.BIN`, `VS4.BIN`, `ERR_MES.BIN`, `KEYBOARD.BIN`, `ASK.BIN`, `PALTEX.BIN`, `NOWLO##.BIN`, `LI###.BIN`, `S##RM##.BIN`, `SCE2#FT.BIN`, `SCE2#I2#.GF`, `ENDDCTEX.BIN`, `DEBUG.BIN` | about 80 | select screens, messages, keyboard UI, loading screens, fonts |
| `afs00.afs` .. `afs03.afs` | 4 | CRI AFS archives (ADXF partitions 0-3) |

The full list is 995 distinct names, reproducible from the ELF strings. Other paths:
`acrout.txt` and `mani.txt` (debug host files), `icon.sys`/`*.ico` and `BASLUS-20486`
(memory card). Image formats are TIM2 (`.TM2`) and, probably, raw GS-format textures in `*TEX.BIN`. `fl`
reports PSM/CLUT errors ("Not supported texture bit depth"), but the exact layouts
(PSMT4/8, CLUT order) were not verified here. The asset pipeline needs AFS extraction, TIM2
and GS-texture/CLUT decode, ADX decode, and probably SPU-ADPCM (VAG-style) decode for the
VOI/SE banks. The bank formats were not checked.

## Game functions that touch platform code directly

149 game functions call into a non-libc platform subsystem, through 90 distinct boundary
functions. Most are `fl` draw/texture calls, VU0 helpers, ADXF/ADXT, memcard wrappers and
Tamsoft commands. The direct SDK uses are only:

- libpad from `16ED00`/`16EE50`/`16EEC0` (vibration and pad state)
- `sceCdReadClock` from `33FE10`/`3D6B70`/`414CB0`

Pass `leaf=yes` and `game_callers>0` in the CSV to filter them.

## Top risks

1. **Tamsoft sound driver (highest).** SE, voices and any MIDI-sequenced audio (MODMIDI is loaded) run on
   the IOP in TSNDDRV.IRX + MODHSYN/MODMIDI (Sony hsyn/MIDI). The EE side only sends opaque
   command packets (`422EA0`..`423990`, RPC `TSD\0`/`TSD\1`). A faithful port must
   reverse-engineer the IOP driver from the disc IRX (not in this ELF): command semantics,
   voice allocation, SPU2 ADSR/reverb, and the VOI/SE bank formats. Nothing in this repo
   covers IOP code yet.
2. **`fl` renderer semantics.** Faithful output depends on GS behaviour: alpha blend equation
   `(A-B)*C>>7+D` with alpha 0x80 = 1.0, alpha test/destination alpha, PSMT4/8 CLUT lookup,
   bilinear vs point filtering, the 2048-offset XYOFFSET, interlaced field rendering at
   640x480 (`flFlip` toggles FIELD), and scissor. About 20 render-mode workers (`3E1B20-3E8490`)
   build packets directly. Re-implement at the `fl` API level; emulating GS packets is the
   fallback if the API proves too wide.
3. **Floating-point determinism.** The EE FPU is not IEEE (no denormals/NaN/Inf, clamps to
   ±max, truncating rounding). VU0 rounding also differs, and soft-double runtime calls are
   replaced by native doubles. Gameplay (positions, hit detection) may diverge from PS2
   replays and break netplay/demo sync unless critical paths are audited or a
   fixed-semantics float shim is used.
4. **32-bit pointers in data.** The game stores raw 32-bit addresses in tables. 13,009
   functions are referenced from data, and there are large pointer tables such as the
   983-entry file table and callback tables. A 64-bit desktop build needs every such table
   expressed symbolically and struct layouts with 4-byte pointers. Plan for a 32-bit-pointer
   build: wasm32 is natural; on desktop use `-m32` or a pointer-width audit.
5. **CRI coupling.** The game uses a small ADXF/ADXT surface, but the handles' state machines
   (`ADXT_GetStat` values, `ADXF_GetStat` async reads with `ADXF_ReadNw`) must be emulated
   faithfully, or loading screens and BGM transitions hang. AFS partition semantics (sector
   sizes, file IDs) must match the disc layout.
6. **Asynchronous IO assumptions.** Loads are asynchronous (ADXF read-no-wait plus status
   polling across frames) and memcard requests are polled (`418D70`). A synchronous host
   implementation must still return the expected intermediate states, or loading/save menus
   may behave differently (skipped "now loading" frames).
7. **Classification fuzziness in the glue region (`411C10-424000`).** It interleaves game code,
   draw helpers, save UI and system wrappers. Region overrides were applied by hand (see
   `component`). Inspect leaf candidates there before final API freeze.
8. **Network/USB-keyboard code paths** (JP network build leftovers) are reachable from
   `flInitialize` and menus (`KEYBOARD.BIN`). Stubs must report "no device" in the way the
   game expects.

## Caveats

- Subsystem labels of `fl`/glue functions come from heuristics. Names ending in `?` are role
  guesses. Exact names come only from strings, docs or SDK comments.
- Call counts are direct `jal`/`j` plus `%hi/%lo` function-address references inside code.
  Calls through data tables are reported separately (`dataref:N` in `evidence`).
- "Dead" means no code reference and no data pointer to the function's start. Such functions
  can be omitted from the port.
