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

## EE GCC 2.96 branch-likely residue

About twenty EE GCC functions differ from retail by a single delay slot: our
`2.96-ee-001003-1` cc1 emits a branch-likely (`bnel`/`bnezl`) where retail
has a plain branch with an instruction stolen from the target, because retail's
compiler treated the stolen register as dead on a fall-through path that ends in
a call. A sweep of every option in this cc1, Sony 2.9 and SN 2.95.2 found no
flag that reproduces it, so these are left unmatched rather than hand-written.
The reverse case (retail `bgtzl`) in func_00406CE0 is reproduced per object by
`-fasynchronous-exceptions`; that flag breaks other EE objects and is never set
globally.
