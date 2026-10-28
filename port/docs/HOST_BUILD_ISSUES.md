# Host build (Port A): status, rewrites, remaining issues

Snapshot date: 2026-10-28, on `origin/main` (ff-merged, includes the `sLb1_*` sources).
The matching build and `src/` are untouched. All host-only glue lives under `port/`.

## Targets

| Target | Triple / toolchain | Role | Result |
|---|---|---|---|
| **Emscripten (primary)** | `wasm32-unknown-emscripten`, emsdk clang 24 / emcc 6.0.13 | browser + PWA (iPhone, Android, desktop) | **16,477 / 16,477 TUs compile**; `emcmake` + Ninja builds `build/port-em/libmvc2_game.a` |
| i386 (desktop debug) | `i386-linux-gnu -m32 -malign-double`, Ubuntu clang 18 | fast native debugging | **16,477 / 16,477**; CMake builds `build/port-i386/libmvc2_game.a` (20 MB) |
| bare wasm32 | `wasm32-unknown-unknown`, clang 18 | data-model check with no emsdk | 16,477 / 16,477 |

The TUs are 6,383 credited game/SDK C sources plus 10,094 data-only C sources.

Every target is viable because the game TUs are **freestanding**: no
`#include <...>` is live (the newlib-derived files include system headers only
under dead `#if` branches). So no 32-bit libc headers are needed and the
planned `port/include/libc` was dropped. Clang's resource headers
(`stdarg.h`, `stddef.h`) are all that is used.

Commands:
```
source /home/user/emsdk/emsdk_env.sh
emcmake cmake -S port -B build/port-em -G Ninja && ninja -C build/port-em mvc2_game
cmake -S port -B build/port-i386 -G Ninja -DCMAKE_TOOLCHAIN_FILE=$PWD/port/cmake/i386-clang.cmake
ninja -C build/port-i386 mvc2_game
python3 port/tools/probe_host_build.py --target emscripten|i386|wasm32 [--resume]   # per-TU results.csv
python3 port/tools/host_link_check.py build/port_probe/emscripten/obj --csv undefined.csv
```
The probe runs the emsdk clang directly (the command emcc runs for each TU)
and skips emcc's per-file Python start-up. A full probe takes about 2 to 3
minutes on 4 cores. `--resume` reuses up-to-date objects, and `results.csv` is
rewritten every `--chunk` TUs so the run survives a container restart.

## How the sources are made host-compilable

There are two parts: `port/include/ps2_compat.h` is force-included
(`-include`), and `port/tools/hostify.py` writes a filtered copy of each TU into
the build tree. `#line` directives keep diagnostics pointing at `src/`. The
header handles everything a macro can: it refuses LP64 targets, maps
`__int128` to TI mode on i386, and declares `ps2_asm_stmt`, the `FN()` stub and
`__builtin_args_info`. The rest needs token-level rewriting:

| Rule | EE/MW-ism | Rewrite | Sites |
|---|---|---|---|
| R1 | `long` is 64-bit under MWCC/EE GCC | `long` → `long long`; `long double` → `double` | all TUs |
| R2 | MW lexes `0x1E-0x...` as 3 tokens | space before the sign | – |
| R3 | `register T x __asm__("$17")` pins | pin dropped | 11 in 10 files |
| R4 | GNU statement asm | outputs zeroed + `ps2_asm_stmt(file,line,tmpl)`; `nop` → `((void)0)`; `mult/multu` → C | 238 hook sites in 26 files, 36 nops |
| R5 | MW `asm { }` blocks | nop → empty; `add.s/sub.s/mul.s/div.s` on C operands → C; else hook | 11 nop, 6 FPU-as-C |
| R6 | file-scope asm, `FN(name, body)` whole-function asm | dropped (`PS2_TOPLEVEL_ASM_DROPPED`) | 13 files |
| R7 | MW scopes block `extern` prototypes per block (one TU, several prototypes) | block-local const function pointer to an asm-label alias | 783 in 156 files |
| R8 | TU-local `static` copies of functions that headers declare extern | renamed `name__hs` in that TU | 270 files |
| R9 | the credited copy itself is `static` (incl. K&R heads, `_PARAMS` prototypes, `#define name func_X`) | `static` dropped in the owning TU (per `matches.csv`), so the one credited copy is the global definition | 25 |
| R10 | constructs no rule can carry | exact per-file replacements in `port/tools/host_overrides.py` (raises if stale) | 1 file |

The brace-depth and statement scanner is preprocessor-aware (the `Braces` and
`file_scope_heads` helpers). Every `#if` branch restarts from the state at its
`#if`. Prototypes in mutually exclusive branches are never compared, and K&R
heads are recognised. This fixed `newlib_heap_core.c`, where R7 had misfired on
`#if __STD_C` prototype pairs.

R10, the only override, is in `src/fb86_b.c`. `struct P` puts a 0xC4-byte
`C cEC` at 0xEC, but its next field sits at 0x13C. The gap is written as the
negative pad `u8 p1B0[0x13C - 0xEC - sizeof(C)]`. MWCC and i386 clang wrap that
size mod 2^32, so the offsets come out right. Emscripten clang rejects the
4 GB struct. The host form is a 0x50-byte head plus an explicit 0xC4-byte
`memmove` for the one struct copy, with identical layout and behaviour. A real
fix (a union) belongs in `src/` whenever someone touches that file.

## Remaining failures

**None at compile level on any target.** The history of failures is logged at
the end of this file.

The build uses `-w` with the hard C99 errors downgraded
(`-Wno-error=implicit-function-declaration,int-conversion,incompatible-pointer-types,implicit-int,return-type`),
so "compiles" does not mean "correct". A warnings survey on i386 (all 16,477
TUs, selected `-W` flags) found these semantic hazards to fix before running:

| Warning | Count | Files | Why it matters on the host |
|---|---:|---:|---|
| `deprecated-non-prototype` / `strict-prototypes` | 7,146 / 7,095 | 1,007 / 1,306 | **wasm-critical.** Wasm calls need exact signatures, and a call through an unprototyped or mismatched declaration gets a wasm-ld "signature mismatch" stub that traps (`call_indirect` traps likewise). MIPS tolerates this. |
| `implicit-function-declaration` | 60 | 41 | same wasm signature hazard (e.g. `hk3_a.c`, `motion_speed_transition.c`, `g7.c`) |
| `return-type` (non-void function without a return) | 64 | 48 | MIPS returns whatever is in `$v0`; on the host the value is undefined |
| `uninitialized` / `sometimes-uninitialized` | 20 / 25 | 18 | decomp relies on register contents |
| `array-bounds` | 4 | 3 | trailing-array `[1]` idioms; check them |
| `incompatible-(function-)pointer-types` | 5 | 3 | function-pointer table casts |

The next step for wasm is a signature audit. Link with
`-Wl,--fatal-warnings`, then generate one real prototype per symbol from the
credited definitions into a force-included header.

## Link level (nm over all objects; `port/tools/host_link_check.py`)

- **Duplicate strong definitions: 0** on both i386 and Emscripten. There are
  30,153 global definitions. Static copies are private (R8) and the credited
  copy is exported (R9).
- **Credited C functions with no global definition: 3.** These are the
  `FN()`-asm kernel helpers `func_001048B0`, `func_0010CA68` and
  `func_0010CA20`. The platform layer must supply them.
- **Undefined everywhere: 8,824 symbols** (Emscripten), grouped by where their
  EE address falls:

| Class | Symbols | What the link step needs |
|---|---:|---|
| data inside a credited data unit | 5,751 | `D_xxxxxxxx` references into a unit. The matching build resolves them by absolute address (`config/symbol_addrs.txt`); the host needs generated `unit + offset` aliases. On ELF, use `.set` or `--defsym`. On wasm, which has no symbol+offset aliases, use a generated header of `#define D_x (*(T *)((u8 *)&unit + off))`, or define the units at those names. |
| bss | 1,700 | the 0x171E00-byte BSS (`0x004C2580..0x00634380`) has no C definitions. Generate a zeroed host array (or per-symbol definitions) from `symbol_addrs.txt`. |
| text: other name of a credited function | 434 | e.g. callers say `func_00133BC0` and the catalog credits `residual_00133BC0` (same address). Generated aliases resolve these. |
| text: label/table inside code | 635 | `lbl_`/`D_` addresses in the text range: mid-function code addresses taken as data, callback tables and switch targets. Each one must map to a host function or handle. |
| data with no data unit | 178 | data addresses not covered by any credited unit |
| text: C-less function | 95 | calls to the unmatched spans in C_COVERAGE.md (plus `func_00000000` null and a few constant addresses) |
| text: placeholder function | 17 | callable once the placeholder C (which already compiles) is linked |
| text: credited in `.S` | 8 | the semaphore and DECI2 syscall stubs, which belong in the platform layer |
| host runtime | 3–4 | `ps2_asm_stmt`, `__builtin_next_arg` (10 EE varargs files, see C_COVERAGE.md); also `memset` and `_GLOBAL_OFFSET_TABLE_` on i386 |
| outside image | 2 | `D_00634380` (end-of-BSS marker), `gMvc2Scratchpad_70000000` (16 KB EE scratchpad, which becomes a host array) |

The address model: data tables take addresses symbolically (`&func_X`,
`&D_x`), so they relocate. On a 32-bit target a `u32` field holds a real host
pointer losslessly. Literal EE addresses in code and the 635 code-label
references need per-case mapping. Every other class above can be generated
mechanically from the catalogs.

Other ABI items to verify once it links:

- MW/EE bitfield order. EE is little-endian, LSB-first like x86 and wasm;
  spot-check it.
- `-malign-double` on i386, needed because EE aligns 8-byte types to 8 (wasm
  already does).
- `char` is signed (`-fsigned-char`), matching EE.
- TI-mode quadword arithmetic needs compiler-rt (`__multi3` etc.).

## 64-bit plan (future work)

This is deferred by the scope change: the browser build (wasm32, 32-bit
pointers) runs on iPhone as a PWA, so no native 64-bit target is needed now.
If one is ever wanted (native arm64 iOS, x86-64), there are two routes. The
first is to put all game memory (data, BSS, heaps) in an arena below 4 GB, via
an `mmap` hint or `MAP_32BIT` on Linux. That still leaves the function
pointers, string literals and static addresses stored in `u32` fields. They
would need either the image linked low (a custom linker script on ELF; not
practical on Mach-O/iOS, where the 64-bit `__PAGEZERO` covers the low 4 GB by
default) or a handle table. The second route is a base-relative pointer
scheme. Either way, every pointer→`u32` store needs auditing first. R1 and the
freestanding setup carry over unchanged.

## Files

- `port/CMakeLists.txt`, `port/cmake/{i386,wasm32}-clang.cmake`: CMake build (Emscripten via `emcmake`)
- `port/include/ps2_compat.h`: force-included compat header
- `port/tools/hostify.py`, `hostify_tree.py`, `host_overrides.py`: source filter (R1–R10)
- `port/tools/host_sources.py`: credited source lists for CMake
- `port/tools/host_flags.py`, `probe_host_build.py`: per-TU probe with failure classes and resume
- `port/tools/host_link_check.py`: nm duplicate and undefined-symbol classification
- `port/tools/list_c_less.py`: spans with no honest C (C_COVERAGE.md)

## Progress log (restart-safe notes)

- run 1, killed by a container restart: CMakeLists, toolchains,
  `ps2_compat.h`, hostify R1–R8 and the probe written. wasm32 probe:
  16,473/16,474 OK.
- run 2:
  - ff-merged `origin/main`.
  - i386 probe: 16,476/16,477 OK. The failure was `newlib_heap_core.c`, where
    R7 misfired on `#if __STD_C` prototype pairs. Fixed with the pp-aware
    `Braces` helper and branch paths.
  - nm found 20 credited statics with no global definition. Fixed by adding
    R9 (extended to K&R heads, `_PARAMS` and `#define` aliases), which left 3
    (the `FN()` asm functions).
  - Scope change: Emscripten is now primary. Added probe target `emscripten`.
    `fb86_b.c` (>4 GB struct) was fixed with R10.
  - All three targets now compile 16,477/16,477. The CMake builds for i386 and
    for emcmake both complete.
  - Ran the warnings survey and the link classification.
