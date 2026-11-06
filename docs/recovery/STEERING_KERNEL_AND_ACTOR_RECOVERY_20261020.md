# Steering, kernel and actor recovery

Four whole functions add 1,812 code bytes:

| Function | Bytes | Source |
| --- | ---: | --- |
| 003BE040 | 344 | actor_steering_003BE040.c |
| 0010CB98 | 252 | sony29_kernel_table_discovery_0010CB98.c |
| 001DF7F0 | 736 | actor_emission_cycles_001CCF60.c |
| 001C4920 | 480 | actor_emission_cycles_001CCF60.c |

The steering callback integrates motion, advances rotation and chooses a direction in a 32-bin ring. Its native target position is a real 12-byte vector. Angle masking occurs in an integer before conversion to a direction byte. Owner context is explicitly forwarded through `003BE2C0` to `003BE240`, which consumes it. The existing dispatcher, wrapper and two other callers now preserve that context in their C contracts; all 1,474 existing functions in those four source units remain exact.

The callback dispatcher uses the repository's existing generic actor/context convention. The new steering callback and the directly repaired callers use that convention explicitly. This packet does not claim identical ISO C function types for every legacy callback in the table. The corresponding 52-byte callback-table type proposal is reserved for the DATA coordinator; no DATA source is changed here. The cohort audit distinguishes seven context consumers from four callbacks that ignore incoming context.

The kernel routine installs two syscall handlers and searches for their words in kernel memory to find the shared table base. It uses unsigned integer address arithmetic for candidate comparison and index subtraction. The two existing syscall primitives now expose their real arguments and the search pointer result; only actual CPU syscall operations use inline assembly. Their complete 156-function unit remains exact. The two-entry patch table is an external typed view with no new data credit.

The landing callback uses a real 12-byte configuration record and a single count/code pair array. Its native NaN-sensitive landing comparison and explicit unsigned-halfword wrapping are preserved. The initialization callback at `001C4920` is already named in a reconstructed callback table and has a complete native entry and epilogue. Its existing 480-byte residual inventory row is renamed without changing its extent or adding a row. No alignment bytes are counted.

Legacy MWCCPS2 3.0 `-O4,p`, threshold eight, builds the steering and lifecycle sources. The kernel routine uses Sony EE GCC 2.9, `-O2 -G0 -ffunction-sections`, with the existing preprocessor and assembler. Existing caller units retain their original modern MWCC recipes. Eight complete source units, 1,645 functions in total, pass relocated-object verification. Final frozen receipts separately record full-image placement, retail executable reconstruction and the 95 tool tests.

## Separate actor-argument follow-up

The cohort review also found two old-style calls in `003BE4E0` that omitted the actor argument even though the native callees consume A0. They now call `003BE5C0(p)` and `00175670(p)` with their existing definitions' actual void and integer return contracts. This changes only `w1710_b.c`, adds no source credit, and does not change the incoming-context protocol. Its 224-byte complete function remains exact under the existing `-O3 -Op -sdatathreshold 8` recipe. The entire object file is byte-identical to the object already used by this packet's passing full-image and executable gates, so those binary results remain applicable without another unchanged link/test run.
