# Code publication threshold recovery, 2026-10-20

Starting at `a2638d9b`, this batch adds **7,904 verified code bytes in 26
complete functions**. Local linked code reaches **2,048,860 / 3,293,696
bytes (62.2055%)**, exceeding the fixed 2,047,573-byte publication threshold
by 1,287 bytes. Initialized-data credit is unchanged.

| Source unit or group | New functions | Bytes | Compiler recipe |
| --- | ---: | ---: | --- |
| actor_inherited_state_clones.c | 5 | 1,616 | MWCC 3.0, O4,p/G8 |
| actor_inherited_state_setups.c | 6 | 2,116 | MWCC 3.0, O4,p/G8 |
| actor_transition_bounds_001B1520.c | 1 | 452 | MWCC 3.0, O4,p/G0 |
| actor_randomized_spawn_003A1E30.c | 1 | 620 | MWCC 3.0, O4,p/G8 |
| actor_burst_spawn_003CA340.c | 1 | 1,088 | MWCC 3.0, O4,p/G8 |
| actor_launch_setup_003B4A10.c | 1 | 812 | MWCC 3.0, O4,p/G8 |
| context_dispatchers_20261020.c additions | 6 | 244 | MWCC 3.0.3, O3/G8 |
| sony29_install_kernel_handlers_0010CDB8.c and 0010D170.c | 2 | 384 | Sony EE 2.9, O2/G0 |
| sony29_cddvd_command_0010F8A0.c | 1 | 196 | Sony EE 2.9, O2/G0 |
| texture_channel_swap_00416570.c | 1 | 196 | MWCC 3.0.3, O3,p/G0 |
| cri_audio_release_00401868.c | 1 | 180 | EE GCC 2.96, O2/G0 |

The production recipes, including preprocessing, include paths, and assembly,
are recorded in `tools/compile_matching.sh`. G0/G8 denote the compiler's
small-data threshold. No generated progress graphic is part of this batch.

## Native aggregate copies and real fields

These actor routines copy the bounded state region `[0xec, 0x1b0)`.
`actor_inherited_state.h` represents its 196 bytes as an aggregate, retaining
the already established float fields at FC/100 and leaving other bytes
opaque. Structure assignment produces the native compiler copy loop.
The source uses ordinary control flow and compiler loop alignment; no manual
NOP statements or lifted assembly loops are present.

Position, velocity, palette, and timer views describe actual native fields.
Explicit local reads preserve signed narrowing and native evaluation order.
The bounds routine retains the unordered floating-point path through
`!(bound <= x)`. The four-position emission table at 0044DD50 is represented
as one array of x/y pairs rather than overlapping column-array declarations.

003CA340 contains two ordinary twenty-iteration allocation loops. Its
`i * 4` ordinal expression lets the compiler produce the native induction
variables. It returns the final allocation result. 003B4A10 uses signed
fixed-point launch presets and six switch cases; the compiler-generated
24-byte readonly section at 004B87A0 is checked in full by the unchanged
production verifier. It adds no initialized-data credit.

## ABI corrections

Native callers at 003B4780 and 003B4D08 test the return from 003B4120.
That function now returns its last allocated child pointer. The existing
284-byte body remains exact; this correction adds zero bytes. Its final
five-iteration loop always assigns the returned local, and the recovered
caller uses its actual pointer/null contract.

The new kernel patch routines install temporary copy and handler-lookup
implementations before invoking those syscall slots. Six existing syscall
primitives now declare their
parameters, and both GetSyscall wrappers capture and return V0. These are
genuine CPU syscall primitives permitted by `DECOMP.md`; their whole existing
compilation unit remains exact. Obsolete unused declarations were removed.
The copied implementation blobs remain raw and uncredited.

The CRI release routine uses the actual reset method at vtable +0x14, decoder
release calls, and mode-dependent work cleanup. Existing owner/work release
entry points now expose consistent `void *` APIs with their private views.
0040CFD8 explicitly passes its original owner to 0040D040: native A0 remains
that owner on the non-null call path. Decoder pointer declarations in the
affected units now agree with the existing pointer-based release definition.
All affected old compilation units were independently rebuilt and verified.

## Function boundaries and accounting

Two native jump-table entries, 001B8870 and 001B9030, are now represented as
separate complete functions. Their parent dispatcher entries end at their
tail jumps and delay slots. Four corrected boundaries leave 28 bytes of zero
alignment in `gaps.csv`, uncredited. Static branch, jump, and stored-address
scans found no targets in that alignment. The text denominator is unchanged.

The six new dispatcher bodies total 244 bytes; the other previously credited
functions in their shared source were rebuilt and remain exact. Their real
actor parameter declarations were corrected in existing constructors.

## Verification

Every new function and each changed existing source unit was compiled with
its production recipe and passed whole relocated-byte comparison. The
readonly switch table also passed the production comparison. Against the
preceding cached proof, 14,046 other source/object pairs and all 45 previous
headers remained unchanged; one shared actor-state header was added.

All 95 tests pass. A fresh split, complete loaded-image relink, and deterministic
ELF pack preserve retail identity:

- Loaded image: 3,941,760 bytes, SHA-256
  `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
- Packed ELF: 3,942,320 bytes, SHA-256
  `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.

This proves the independent code checkout with its existing data baseline.
The coordinator owns combined integration, reports, and publication to main.
Unmatched candidates remain excluded from credit.
