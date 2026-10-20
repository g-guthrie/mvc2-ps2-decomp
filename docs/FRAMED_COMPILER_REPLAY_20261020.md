# Framed candidate replay and uncredited launch corrections

Baseline: `70769fd909a35e9a47c0a53901bf15d4851a5645`.
This audit adds **no matching code or data credit**. It does not establish
that the remaining functions need another compiler: candidate source and
ABI mistakes remain possible.

The compiler sweeps used the preserved Grok C candidates, current numeric
catalog and function spans, private one-row verification catalogs, and the
unchanged whole-function object verifier. They did not modify production
sources or the verifier. Each compiler used small-data threshold 8.

| Scope | Profiles | Replay results |
| --- | --- | --- |
| 25 candidate tuples, >=400 bytes and below 003E0000 | MWCC 3.0.3 O2/O3; MWCC 3.0.1-020123 O4/Op | 69 mismatches; 6 missing-definition rows; no exact receipt |
| 250 smaller candidate tuples | MWCC 3.0.3 and 3.0-011126 O3 | 471 mismatches; 24 verification failures; 5 unresolved local relocations; no exact receipt |
| 244 smaller definition/source variants, 234 unique spans | MWCC 3.0.3 O2; MWCC 3.0.1-020123 O4/Op | 445 size mismatches; 30 same-size mismatches; 13 unresolved relocations; no exact receipt |

Some candidate-list rows incorrectly associate an extern declaration with
the source containing it. Those are not function definitions and cannot
receive credit. In the O3 sweep, all 16 missing-definition failures are
calls/declarations of 00174470 in eight unrelated source units. Its actual
source definition was checked separately and remains nonmatching. The
other eight verification failures are GP-relative displacements outside
the signed 16-bit range; they require a supported addressing/profile check,
not a relaxed relocation verifier.

The follow-up used G0 for 00346610, 0038EC30, both 002803A0 source variants,
and 0037F7C0, retaining `.sdata` only where native GP accesses prove it.
MWCC 3.0.3/3.0 O3 and 3.0.1 O4/Op then resolved the GP displacements,
but every candidate still had a size mismatch. The closest revised
0037F7C0 form was 224 bytes versus the native 220. No addressing check
was weakened and no new matching credit resulted.

The O3 unresolved cases include writable compiler `.lit4` constants at
00141130 and 0020C2F0 and a complete 32-byte switch table at 0012BA70.
An unresolved relocation is not proof of a nonmatch. Native instruction
review nevertheless rules out the tested literal-pool forms: their GP
loads differ from the native immediate/register-relative instructions.
0012BA70's compiled frame is 0x30 bytes versus native 0x40 before any table
relocation is applied. Removing the redundant outer switch guard or using
an output record did not reproduce its complete native function. No
readonly mapping or credit was added for those cases.

## Concrete correction for uncredited 003BF2E0

Retail instructions establish the following algorithm details that the
preserved sketch got wrong:

- The random byte is multiplied by three, shifted right by **two**, then
  narrowed as a **signed halfword** before subtracting 0x60. The old sketch
  shifted by eight and narrowed as a signed byte.
- The owner pointer comes from **the second argument plus 0x18**, rather
  than the child/first argument.
- Horizontal velocity is `(target_x - child_x) / 12.0f`; the owner's ground
  coordinate belongs in the vertical calculation, not the horizontal one.
- The owner's ground coordinate is read before writing child velocity.
  Retaining that snapshot preserves the observed memory ordering.
- The three position floats are copied from the second argument before
  the first random-state call.

The corrected candidate preserves ordinary float motion fields and the
actual integer animation-helper return. Its two tested forms still have
240/244-byte code-generation differences against the native 240-byte
span. It therefore remains an **uncredited candidate**, not a recovered
matching function. No padding, barriers or fabricated helper effects were
introduced to force a match.

## Private replay receipts

Private ledgers were retained under `private/compiler-replay-20261020`.
They contain source/object hashes, span checks and individual outcomes.
No retail executable, compiler binary, object or large probe log is part
of this document. Ledger SHA-256 values:

- `large-results.json`: `e9f3e62f6786a42a15c84965fdb5dbae5775f7dba6ec8e6452effa733f2fdb77`
- `small-o3-ledger.json`: `f4f96ef665fdea7721fd7e6f9c8964aed3afb0d387a55c9cbd84d1463403c33c`
- `small-other-profiles.csv`: `2f92deccb1acf04ab722373035f80425ba8f147eaeb8dd99338e0e6441691b8c`

These negative results apply to the recorded source/profile combinations;
they do not rule out a faithful source reconstruction under those compilers.
