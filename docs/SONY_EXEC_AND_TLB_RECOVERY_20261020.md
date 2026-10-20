# ExecPS2 and SetTLBEntry recovery

Two complete native-derived functions add 160 matching code bytes using Sony
EE GCC 2.9 O2/G0 and the existing SN assembler.

`0010CFD8` (112 bytes) stages the supplied argv with the existing empty filename,
initializes kernel execution state, and calls ExecPS2 with the original entry,
global pointer, argc and staged vector. It returns the syscall's integer result.
The new declaration is included in the existing argument-staging header.

`0010C3F0` (48 bytes) rejects TLB indices outside 13 through 47, then forwards
all five arguments: index, page mask, EntryHi, EntryLo0 and EntryLo1. Unsigned
subtraction expresses the native range check without signed overflow.

The ABI identification is corroborated by the [PS2SDK syscall-number table](https://github.com/ps2dev/ps2sdk/blob/329e2bb43287e16af16c4dde1c614e2662c24468/ee/kernel/include/syscallnr.h)
(ExecPS2 is 0x07 and _SetTLBEntry is 0x56), the [ExecPS2 declaration](https://github.com/ps2dev/ps2sdk/blob/329e2bb43287e16af16c4dde1c614e2662c24468/ee/kernel/include/kernel.h),
and the [five-argument TLB declaration](https://github.com/ps2dev/ps2sdk/blob/master/ee/kernel/include/kernel.h).
These are interface evidence; the function bodies were derived from retail.

Both existing syscall primitives now expose their actual arguments and explicitly
capture the integer result from v0. All 156 functions in that source unit remain
exact. The execution initializer's tail adapter now takes no arguments and calls
the existing integer-returning selector; all 629 functions sharing its source
unit remain exact. A stale unused declaration was removed from p3.c; all ten
functions there remain exact. Both other consumers of the updated argv header
were recompiled and all three existing functions remain exact.

All new functions pass whole-function relocated comparison. Fresh splitting,
full hybrid-image linkage, packed ELF comparison and all 91 tests pass.
