# Camera tangent return contract, 2026-10-20

The existing camera caller 00123120 consumes F0 from 004175C0. That helper
scales a sixteen-bit angle to radians and forwards it to 003DE7D0, whose
native tail jump targets the already recovered float-to-float tangent
implementation 00117328. Both wrappers must return `float`.

The source now expresses that complete chain. The generic four-integer,
void-return declaration of 003DE7D0 is replaced by its actual float parameter
and result, and 004175C0 returns the result. The existing caller now declares
the actual unsigned-short input. An unused stale declaration is removed
from `k4.c`. The camera height offset 004F1FB8 is declared as the float used
by other native camera routines; its existing zero store remains unchanged.

This is a zero-byte progress correction. All 661 existing functions across
the four affected compilation units remain whole relocated matches:

- `tail_leaves.c`: MWCC 3.0.3, O3/G0; 641 functions, 5,680 bytes.
- `p0m.c`: MWCC 3.0.3, O3/Op, fp off, G0; two functions, 140 bytes.
- `w171_b.c`: MWCC 3.0.3, O3/Op/G0; one function, 220 bytes.
- `k4.c`: EE GCC 2.96, O2/G0, empty extra flags; 17 functions, 1,068 bytes.

No registers, assembly, qualifiers, padding, or instructions were added to
force the match. Full loaded-image and packed-ELF retail identity checks and
the 95-test suite pass. Verified code remains 2,053,084 bytes (62.3337%).

The coordinator independently rebuilt all four units and reverified all661
functions, then repeated the combined image and95-test gates successfully.
