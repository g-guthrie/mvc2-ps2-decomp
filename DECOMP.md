# Decompilation rules

- Target only the NTSC-U PS2 executable `SLUS_204.86` documented in the README.
- At the owner's explicit request, the checksum-pinned executable/compiler
  build bundle is NOT distributed; you supply it yourself. Extracted
  working inputs remain under ignored `private/`. Keep other game assets,
  generated assembly, and SDK files out of Git.
- A function counts as matching C only after its verified compiler and
  assembler recipe reproduces its whole instructions and relocations exactly.
- Required CPU operations (syscalls, barriers, interrupt control) may use short
  inline assembly blocks. Algorithmic control flow and memory operations must
  be reconstructed in C; instruction-stream lifts remain uncredited.
- Assembly placeholders and mechanically translated output count as zero.
- Empty asm barriers used solely to force matching code generation, and unused
  fixed-register locals, remain uncredited until the C matches without them.
- Whole-image linkage and target-hash verification remain the final gate.
- The deterministic ELF packer now reconstructs the complete retail
  `SLUS_204.86` container byte-for-byte from the exact hybrid loaded image.
- The current hybrid relink is byte-exact for the complete loaded image. Raw
  `.word` placeholders still count as zero matching source.
- Progress separately reports the conservative 3,293,696-byte text span and
  648,064-byte initialized-data span. Neither gaps nor mixed data count as C.
  decomp.dev "decompiled" is `matched_*`; "fully linked" is `complete_*`
  (hybrid-placed matching C). Overlapping catalog ranges are a hard error.
  See docs/PROGRESS.md.

## Current unknowns

- The embedded component string is `MW MIPS C Compiler (2.4.1.01)`. Exact
  compiler-in-the-loop evidence now includes MWCCPS2 3.0/3.0.3, Sony EE GCC
  2.9-991111, SN Systems GCC 2.95.2, and EE GCC 2.96; each source unit records and verifies its compiler
  and flags.
- The original translation-unit map was stripped; the current function
  inventory is an explicit-size spimdisasm baseline, not recovered source-file
  ownership.
- The disc includes multiple IOP modules; this initial project reports only the
  main Emotion Engine executable.

## Exact C checkpoint

The current sources contain exact address getters, simple/straight leaves,
direct tails, absolute and GP-relative dispatchers, signed-result/reset/call
handlers, and 2,077 verified dispatcher heads split from oversized assembly
ranges. Current totals are generated in the [progress graphic](assets/progress.svg)
and published on [decomp.dev](https://decomp.dev/g-guthrie/mvc2-ps2-decomp).
`make match` is the private relocated-object verification gate; the full
compiler pass and hybrid link remain separate from catalog/report validation.
The initial Sony SDK recovery passes whole-object checks and isolated batch
linkage into the retail image. Reconstructed-data totals follow the catalog's
bounded ownership rules. Raw arrays, untyped fills, and numeric-address tables remain
uncredited placeholders even when physically included by the hybrid linker.
See [progress rules](docs/PROGRESS.md) for the catalog policy. The split
residual spans remain assembly and count as zero.

## Metrowerks compiler-process state (soft-float warm-up)

mwccps2 3.0 and 3.0.3 keep one piece of state for the life of the compiler
process. The first time the backend lowers a C double-arithmetic operation
(add, sub, mul, div or compare under `-fp off`) into a runtime call, it stops
handing out `$a0`/`$a1` as temporaries, and every function compiled later in
the same invocation uses `$a2`/`$a3`/`$t0` instead. No declaration, pragma or
option reproduces it; only compiling such an operation does. Retail built many
functions in a compiler run that had already compiled one.

A stanza may reproduce that by compiling, in the same invocation and before the
subject, the credited project source that contains the nearest preceding
retail function with double arithmetic, then keeping only the subject's object
(see the `build/warm/` stanzas in tools/compile_matching.sh). Nothing extra is
placed in the subject's own source. Enabling the warm-up globally is wrong: it
breaks functions in 0x3A0000-0x3C8000 that retail compiled in the default
state.

The state only changes functions that themselves contain C double arithmetic;
a function without any is compiled identically warm or cold.

What counts as double arithmetic, as measured: a double add, subtract,
multiply or divide (retail calls `dpadd`/`dpsub`/`dpmul`/`dpdiv`). A function
that only converts (`fptodp`/`dptofp`, or a double constant narrowed to float)
does not change the state, and neither does C that calls the helpers
explicitly; the compiler has to lower the operation itself. A float-to-int cast
that 3.0 lowers to an `fptosi` call under `-fp off` makes the *subject* a
soft-float function, so it is affected by the state. To find the warm source for
a subject, take the nearest preceding retail function that calls one of the
four arithmetic helpers and use the credited source that contains it, written
with native C double expressions.

## EE GCC 2.96 branch-likely residue: define the callee first

Where our `2.96-ee-001003-1` cc1 emitted a branch-likely (`bnel`/`bnezl`) and
retail has a plain branch with an instruction stolen from the target, the
cause is file order, not a flag. `reorg` fills a plain branch only if the
stolen register is dead on the other path, and `resource.c`
(`find_dead_or_set_registers`) stops its liveness scan at any insn for which
`can_throw()` is true. A call can throw unless it carries a `REG_EH_REGION`
note of 0 or less. That note is added when the callee is `TREE_NOTHROW`, and
with exceptions off `nothrow_function_p()` sets `TREE_NOTHROW` on every
function cc1 has already compiled in the same translation unit. So:

- Define the called function earlier in the same `.c` file (retail address
  order), as in src/newlib_mprec_balloc.c, src/hb9_a.c and src/s0b.c.
- A callee compiled with different flags cannot share the unit. Find a form
  that matches with the caller's flags (func_00407BC0 keeps its `jal` with
  sibling calls on when its body is a `do { } while (0)` statement).
- The cvFs device wrappers (src/cvfs_device_calls.c) also need the full
  `if (device->fn != 0) { result = device->fn(name); } else { error; return
  -1; } return result;` shape with `-fno-optimize-sibling-calls`.
- Sony 2.9 objects (func_0010E770) do not have this mechanism.

The reverse case (retail `bgtzl`) used to need `-fasynchronous-exceptions`;
func_00406CE0 now matches without it, from the same callee-first file.

## Metrowerks 3.0 build 22 (mwcps2-3.0b22-020926)

A fourth Metrowerks build, "Version 3.0 build 22" dated 2002-09-26, is part of
the toolchain (`MWCCPS2_30B22`). It is a separate code line from 3.0-011126,
3.0.1-020123 and 3.0.3-020716 and reproduces register allocation those builds
do not (func_00200BD0, where 3.0/3.0.3 swap $s0/$s1). It does not replace 3.0
or 3.0.3 in general: rebuilding every credited 3.0 source with it reproduces
119 of 1718 functions. Use it per object only. 3.0.1-020123, 2.3.3 and 2.3 were
also tested against every known wall and matched nothing new; 2.3/2.3.3 save
$ra with `sq` like 2.4, so they are not the missing "2.4 scheduling with `sd
$ra`" build either. Build 22, like 3.0b38, b50 and b52, never emits the
hazard `nop` between `c.cond.s` and `bc1t`/`bc1f`, so a retail function with
`c.xx.s; nop; bc1x` is not from these builds.
