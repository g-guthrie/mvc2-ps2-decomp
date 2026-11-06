# Tokyo Bus Guide findings applied to MVC2

Reference reviewed: [lhsazevedo/tbg-decomp](https://github.com/lhsazevedo/tbg-decomp/tree/a81e38746c4fa7f37d841c166ebc818c54864bae),
commit `a81e38746c4fa7f37d841c166ebc818c54864bae` (2026-10-04 review).
The source material is its `docs/lessons_learned.md`, `docs/delinker_boundaries.md`,
`build/shc_matching.sub`, and `Makefile.matching`. These are research leads,
not evidence that MVC2 used the same compiler revision. TBG's matching target
still assembles many functions; its behavioral C tests do not imply exact C.
No TBG ROM is required for these compiler experiments.

## Findings reproduced with the pinned compiler

The probe (`workbench/tbg-learnings-20261004/probe.py`) and its retained C,
assembly listings and JSON hashes are in the history of the original
[mvc2-naomi-decomp](https://github.com/g-guthrie/mvc2-naomi-decomp) repository. It uses
our game flags in a temporary compiler directory; it never changes accepted
options, source registration, or verifier behavior.

- Adding `-size`, `-round=nearest`, or both produces identical instruction/data
  listings for this probe. This is a bounded result, not equivalence for all C.
  There is no evidence here to change `config/compiler.json`.
- `return 2.0f` still loads `0x40000000` from a pool. Neither extra option
  resolves the known `fldi1; fadd` constant-materialization mismatch.
- Mentioning a string in both `sizeof` and its array initializer emits an
  additional pooled copy; the single-mention control has no duplicate.
- A table of mutable pointers to const characters lands in D; making the
  pointers const moves the table into C. Const qualification is layout-relevant.
- A zero-initialized local 32-byte array emits a 32-byte constant template and
  a runtime copy (`__slow_mvn` here). Do not introduce aggregate initialization
  when retail instead clears storage through a loop.
- `3.05f` and `3.0500001907348633f` emit `40433333` and `40433334` respectively.
  Preserve retail bits using our `tools/float_literal.py`; decimal prettiness
  and host round-trip conversion alone are not sufficient evidence for SHC.

## Use while recovering C

The following are TBG observations to test against MVC2 native instructions,
not automatically established MVC2 facts:

- Nested conditions, break/continue placement, and strength-reduced loops can
  affect redundant branches and dead bytes. Preserve the retail shape when
  matching; do not delete unreachable emitted instructions just for coverage.
- Trace memory writes and calls in native order. A conditional refinement may
  compute in a local and store once; writing a global before and after the
  condition introduces an extra observable store. Ghidra can reorder writes.
- Check floating comparisons at the instruction level: `FCMP/GT Fm,Fn`
  compares Fn against Fm. Trace the following branch and delay slot too.
- Recover imported callee prototypes before trusting caller parameters.
  Missing SDK prototypes can hide FR4 arguments or cause phantom caller
  arguments. Confirm register and stack arguments at multiple native callers.
- Runtime struct-copy helpers can use special registers rather than the usual
  function ABI. TBG reports `_quick_odd_mvn` with destination R1, source R2,
  and length R0. Verify each MVC2 helper against `config/runtime.json` and
  native code, then express the struct assignment in C, not a helper call.
- Ghidra SSA names may combine distinct values. Follow reaching definitions;
  retain separate source values when the native lifetimes require them.
- An apparent global may be a field, an address alias, or an offset folded
  from another symbol. Follow the caller's actual base load and displacement.
  Account for direct displacement, immediate R0 offsets and word-pool offsets.
  Generated labels and BSS declarations do not prove object boundaries.
  A gapless access union is evidence of extent, not by itself proof of an
  original C object or of the exact boundary at the next loaded base.
- Do not infer field meaning from an offset suffix shared by unrelated structs.
  Scope renames by actual type and sweep declarations, callers, data references
  and tools. Verify the full dependency graph after public-symbol changes.

## Use while recovering units and data

- Recover internal functions as well as exports. Same-unit calls and literal
  reachability are boundary evidence; a symbol list alone can omit statics.
- Distinguish string pools from separately authored arrays. First-use order,
  deduplication and alignment can reveal compiler ownership. Confirm against
  MVC2 before replacing declarations; don't add padding arrays to hide a gap.
- A named static float can introduce a new constant object absent from retail.
  Prefer the native-supported literal expression and check every data section.
- Disassembly archives can fold section alignment into apparent data or emit
  empty sections. Compare real section content, linking and final bytes before
  changing ownership. Never remove retail bytes to make an extent pass.
- Do not split BSS or move data based only on reconstructed labels. Preserve
  relocations, alignment and all references when a native-supported boundary
  changes. Raw Ghidra exports need independent type/size/ownership review.

## Behavioral test lessons, if a simulator is introduced

We do not use TBG's PHP sh4objtest harness. Its API-specific fixes are not new
MVC2 dependencies or reasons to modify our exact comparison gate.

- Check the simulator's opcode support and signed arithmetic before blaming C.
  TBG encountered MULS.W, EXTS.W and postincrement MOV.W support gaps, plus an
  unsigned mock for signed division. Include negative/boundary cases.
- Explicitly initialize relevant memory; do not assume VM memory or registers
  start at zero. An indeterminate native read is not a license to invent a value.
- Understand whether named same-unit calls execute or are mocked. Assert all
  register/stack arguments, return values and observable writes; export/static
  visibility and stale objects can invalidate symbol-based expectations.
- Preserve real adjacency/aliases when assigning mock addresses. Independently
  allocated globals can break an original base-plus-offset reference. Discover
  stack locals per compiled object rather than assuming identical frames.
- Test that deleting a function's effects causes failure. An early return can
  be a misleading mutation if the framework still discovers dead code.
  Reach the paths containing copies and stores; happy-path tests can miss them.
- Coverage exclusions or force-stop hooks diagnose harness limits; they cannot
  establish equivalence or earn exact-match credit. Keep native proof separate.

TBG-specific lint invocation, archive exports, debug-symbol switches and naming
refresh commands remain upstream workflow details. For MVC2 use our build cache,
unit extent diagnostics, type contracts and full linked comparison. Do not add
another harness solely to reproduce those maintenance procedures.
