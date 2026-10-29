# Link notes (Port G)

Status 2026-10-29, on `d2eef6225` (origin/main).  `src/` and the matching
build are untouched; everything is under `port/`.

## Result

| | Emscripten (primary) | i386 (desktop debug) |
|---|---|---|
| build | `emcmake cmake -S port -B build/port-em -G Ninja && ninja -C build/port-em mvc2_host` | `cmake -S port -B build/port-i386 -G Ninja -DCMAKE_TOOLCHAIN_FILE=$PWD/port/cmake/i386-clang.cmake && ninja -C build/port-i386 mvc2_host` |
| link | `mvc2_host.js` + `mvc2_host.wasm` (5.4 MB), **0 undefined**, `-Wl,--fatal-warnings` clean (**0 signature mismatches**) | `mvc2_host` (6 MB), **0 undefined** |
| run | `node mvc2_host.js [--frames N]` | `./mvc2_host [--frames N] [--timeout S]` |
| stops at | game init: `func_0012F4C0` → `func_00414CB0` gets no heap and the game spins in `for (;;)` | same (the watchdog reports the step after 10 s) |
| full build time (4 cores) | 2.5 min from scratch (signature pass included) | 3.5 min |

Prerequisite for i386: `apt-get install gcc-multilib` (32-bit crt files,
libgcc and libc headers; this container only had the libc6-i386 runtime).

### Where the boot stops, and why

`host_main.c` runs `main` (`func_00170C30`, src/z2_b.c) step by step:
`func_003EC160(640, 480)` (platform init, C-less: a logging stub that returns
0; the PS2 main retries it forever, the host goes on), then `func_0012F4C0`.
Its first call, `func_00414CB0(0x200000)` (src/hk11_a.c), allocates the game
heaps with `func_003DCF70` = `func_003F09C0(D_0062C020, size, 0)`, an arena
that `func_003EC160` builds over a 22 MB `malloc` (ENGINE_MAP §2.2 step 2,
`func_003F0940`, plus the 6 MB handle pool `D_005BF280`).  With no arena the
allocation fails and `func_0012F4C0` hangs in its `for (;;) {}`.  Stubs hit
on the way: `func_003EC160`, `func_0010E9A8` (libcdvd, from the
`sceCdReadClock` in `func_00414CB0`) and one `ps2_asm_stmt` (syscall 0x45 in
src/grok_tiny_leaves.c:505).  **The first missing platform piece is the arena
/ handle-pool part of `func_003EC160`.**  Nothing in the link is missing for
the steps after it; they will hit stubs as listed in `glue/stubs.csv`.

## What is faked (generated table)

Every faked symbol is in `glue/mvc2_fakes[]` (compiled into the binary;
`mvc2_stub_report()` prints the ones that were hit) and in `glue/stubs.csv`.
1,006 rows on both targets:

| Kind | Count | Host behaviour | Source |
|---|---:|---|---|
| code label taken as data | 603 | a distinct 4-byte slot in `mvc2_ee_code_labels` (`mvc2_ee_code_label_addr[]` maps it back to the EE address); they are MWCC switch tables that host `switch` code never reads | generated |
| data with no C | 178 | zero bytes, one blob per gap between credited units (real values unknown on the host; e.g. `D_004C0198` ints in deferred_move_setup.c) | generated |
| non-C data unit | 74 | zero stand-in for the 10 VU1 microcode units (`src/vu/*.vsm`) and 5 EE kernel-patch blobs (`src/data_asm/*.s`), with the names inside them | generated |
| C-less function | 81 | logs, returns 0 (75 code spans, 5 residuals, 1 padding) | generated |
| code label taken as a function | 38 | logs, returns 0 | generated |
| placeholder (`FN()` asm) | 8 | logs, returns 0 (VU0 helpers, `func_00105540`, ...) | generated |
| libc forward | 12 | `memchr memcmp memcpy memmove memset strcat strcmp strcpy strlen strncat strncmp strncpy` (newlib MMI assembly, identified by link order and callers) | port/stubs/ee_libc.c |
| syscall | 6 | CreateSema/DeleteSema/SignalSema/iSignalSema/WaitSema as counters (a wait never blocks), Deci2Call returns -1 | port/stubs/ps2_kernel.c |
| kernel helper | 3 | the `FN()` COP0 helpers: Status.IE probe returns 0, DI/EI wrappers keep an EIE flag | port/stubs/ps2_kernel.c |
| asm hook | 1 | `ps2_asm_stmt`: logs each site once, does nothing | port/stubs/ps2_asm_stmt.c |
| scratchpad, end-of-BSS | 2 | 16 KB `mvc2_ee_scratchpad`; alias at the end of the BSS blob | generated |

Not faked but generated: the EE BSS (one zero blob `mvc2_ee_bss`,
`0x004C2580..0x00634380`, 1,697 aliases with `.size` from the neighbouring
catalog addresses), and the R11 aliases.

## Design choices

**Data aliases on wasm (5,751 symbols).**  wasm objects cannot define a
symbol as another object's symbol plus an offset, and there is no
`--defsym` in wasm-ld.  A force-included `#define D_x (*(T *)((u8 *)&unit + off))`
breaks every declaration of `D_x` and needs a type per use.  But a wasm data
symbol *can* sit at an offset inside a segment of its own object, and LLVM's
wasm writer turns a file-scope `.set D_x, unit+0x10` into exactly that
(tested with emcc 6.0.13: `.weak` works too).  So hostify R11 emits the
aliases into the TU that owns the unit (`PS2_DATA_ALIAS`, ELF gets `.type` and
`.size` as well).  The unit keeps its single contiguous layout, references
need no rewriting, and the same mechanism serves i386.  The aliases are weak,
so a strong definition elsewhere would win instead of colliding (none today).
Function aliases cannot use `.set` on wasm (the alias is not exported), so
they are `__attribute__((weak, alias))` in the owning TU.

**BSS.**  One blob rather than 1,700 separate arrays: the game clears ranges
that span symbols (e.g. the 0x420-byte render globals at `D_0062BC00`), the
end-of-BSS marker needs a place, and host address = blob + (EE − 0x004C2580)
helps debugging.

**Signatures (wasm-critical).**  The raw wasm objects showed 9,465 call sites
whose import signature differs from the definition (K&R `void f();`,
`extern void f(void);` in callback tables, per-block prototypes, implicit
declarations).  `host_sigs.json` gives each function one canonical prototype
from its definition (typedefs resolved, pointers as `void *`, widths and
signedness kept; host libc names from the Emscripten archive + sysroot
headers; stubs from their callers).  hostify R12 replaces the disagreeing
declarations and fixes the calls; nothing is suppressed, and wasm-ld runs with
`--fatal-warnings`.  The call fix follows the EE EABI: integer and float
arguments go to separate register files, so when a caller's float/int order
differs from the callee's (e.g. `func_004220B0(p, 0.09f, D, 2)` against a
`(void *, int, int, float)` definition) the host call passes ints in order to
int parameters and floats to float parameters, which is what the PS2 did.
Missing arguments become 0 (the PS2 passed whatever was in the register);
extra ones are evaluated and dropped.

**Indirect calls.**  Direct calls are exact.  Calls through callback tables
use the table's element type, which often differs from the callee's; a wasm
`call_indirect` with another type traps.  The Emscripten link therefore uses
`-sEMULATE_FUNCTION_POINTER_CASTS=1` (CMake `MVC2_EMULATE_FPCASTS`, default
ON).  Auditing those tables would allow turning it off.

## Known approximations

- R15: `sony29_varargs_forwarder_00105E48.c` / `_handler_00105E80.c` hand
  `func_00105858` a pointer to the first variadic argument; the EE code
  pointed 7 register slots earlier and reads 64-bit slots.  The printf-style
  walkers are exact (the game's vfprintf reads with `__builtin_va_arg`).
- R14: 48 functions that fell off the end and 16 `return;` in non-void
  functions return 0 (MIPS returned `$v0`).  Sites are in `host_sigs.json`
  (`noreturn`, `bare_return`).
- Generated stubs return 0, including `func_003EC160` (platform init) and
  `func_003ECD00` (flip): the platform layer replaces them.
- 178 gap data words and the non-C units are zero.

## Files

- `port/tools/link_catalog.py`: catalog view (addresses, units, unit
  aliases, alternate function names, host runtime names).
- `port/tools/gen_link_glue.py`: `sigs` and `glue` (see its docstring).
- `port/tools/host_sigs.py`, `port/tools/wasm_obj.py`: canonical
  prototypes; wasm object/archive symbol reader.
- `port/tools/hostify.py`: R11–R16 (R7 fix: skips statics, keeps line
  numbers), `hostify_tree.py --sigs`, `probe_host_build.py --diag --sigs`.
- `port/include/ps2_compat.h`: `PS2_DATA_ALIAS`, `PS2_TEXT_ALIAS`,
  `PS2_VA_START_HERE`, `PS2_TO_PTR/F32/F64`.
- `port/stubs/`: `mvc2_stubs.h`, `stub_runtime.c`, `ps2_asm_stmt.c`,
  `ps2_kernel.c`, `ee_libc.c`, `host_main.c`.
- `port/CMakeLists.txt`: signature step, glue step, `mvc2_host`;
  `port/cmake/emcc-direct.sh`.

Generated per build tree (`build/<tree>/`): `host_sigs.json`, `sigs_raw/`
(raw build + diag.csv), `glue/` (`mvc2_glue_*.c`, `stubs.csv`,
`link_glue.csv`, `summary.txt`).

Probe-only flow (no CMake), as used while developing:
```
python3 port/tools/probe_host_build.py --target emscripten --diag --out build/port_probe/em-raw
emcc -O1 -Iport/stubs -c port/stubs/X.c -o build/port_probe/em-raw/stubobj/X.o   # each stub
python3 port/tools/gen_link_glue.py sigs --out build/port_probe/em-raw/host_sigs.json \
        --stub-objs build/port_probe/em-raw/stubobj build/port_probe/em-raw/obj
python3 port/tools/probe_host_build.py --target emscripten --sigs build/port_probe/em-raw/host_sigs.json --out build/port_probe/em
python3 port/tools/gen_link_glue.py glue --target emscripten --sigs ... --out build/port_probe/em/glue build/port_probe/em/obj
```

## Log


- step 0: read HOST_BUILD_ISSUES / C_COVERAGE / PLATFORM_SURFACE / ENGINE_MAP.
  Experiments (build/exp): on wasm, file-scope asm `.set D_x, unit+16` in the
  unit's own TU gives a real data symbol at an offset (also `.weak`); a function
  alias needs `__attribute__((alias))` in the defining TU (asm `.set` of a
  function does not export on wasm).
- step 1 (i386): `apt-get install gcc-multilib` (32-bit crt/libgcc/libc
  headers; the container had only the libc6-i386 runtime).  New:
  port/tools/link_catalog.py, gen_link_glue.py, wasm_obj.py; hostify R11
  (catalog aliases in owner TUs), R15 (varargs), R16 (weak null);
  port/stubs/*.c.  probe build + `gen_link_glue.py glue --target i386` +
  link (`clang -m32 -no-pie hostobj/*.o libmvc2_game.a $(cat glue/link_extra.rsp) -lm`)
  -> build/port_probe/i386/mvc2_host links with 0 undefined.
- step 2 (wasm): raw em build with `--diag` -> `gen_link_glue.py sigs`
  (host_sigs.json) -> em build with `--sigs` (hostify R12 canonical
  prototypes + call fixes, R13 data-declared code addresses, R14 returns).
  9,465 mismatching imports in the raw build -> 0.  Host libc names get
  their prototype from the Emscripten archive + sysroot header.
  `emcc ... -Wl,--fatal-warnings` links build/port_probe/em/mvc2_host.js.
- step 3 (CMake): `ninja mvc2_host` works on both trees (build/port-i386,
  build/port-em).  Emscripten game TUs now compile through
  port/cmake/emcc-direct.sh (emsdk clang directly): 1m19s instead of ~48 min.
  Both stop in func_0012F4C0 -> func_00414CB0 heap allocation (platform init
  func_003EC160 is a stub, so the 22 MB arena / handle pool does not exist).
- step 4: R14 extended to `return;` in non-void functions (16, via
  `-Wreturn-mismatch` in the diag build); the diag build of the final sources
  reports 0 implicit declarations, 0 missing returns, and the wasm scan 0
  mismatching imports and 0 data/function symbol-kind conflicts.
  EMULATE_FUNCTION_POINTER_CASTS added (option, default ON); links and runs.
