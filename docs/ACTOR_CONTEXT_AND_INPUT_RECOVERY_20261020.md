# Actor context and input recovery

Five whole functions add 2,544 code bytes:

| Function | Bytes | Source |
| --- | ---: | --- |
| 001DC460 | 412 | actor_emission_cycles_001CCF60.c |
| 001D1C10 | 508 | actor_emission_cycles_001CCF60.c |
| 003A3050 | 740 | actor_lifecycle_003A3050.c |
| 003AABB0 | 484 | actor_input_motion_003AABB0.c |
| 003AB270 | 400 | actor_input_motion_003AABB0.c |

The two native callback rows previously labeled as residuals are renamed without changing extents or gaps. `001DC460` receives actual parent context. Its constructor and two dispatcher heads now explicitly forward that context through the existing `ContextDispatchFn`, adding no callback typedef. All 1,446 existing functions in those two source units remain exact. A separate DATA-owner proposal describes the existing 48-byte callback span at 0044EC30 and its three native 16-byte groups; CODE makes no DATA edit or claim that a physical split is necessary.

The owner-relative initializer at `001D1C10` reads one real four-entry signed-halfword offset-pair table and one four-word integer motion descriptor. Native integer-to-float conversions establish the descriptor's type. Floating-point operation order is retained, and offset negation is performed after integer promotion.

`003A3050` implements the actor lifecycle using the shared inherited-state aggregate, the actual timer and palette fields, four bounded position-offset records and the established two-player counter array. It uses the current unsigned-word declaration of the callback table and converts selected native code addresses at the call site. Native lifecycle states select only the four real callbacks. The existing DATA table's fifth word is the first signed-halfword XY point of the adjacent twelve-point path, not a fifth callback. A precise ownership proposal is preserved separately for the DATA coordinator; it requires splitting existing owners and re-proving the remaining tail, rather than adding overlapping data.

The two input/motion callbacks share one source unit. Partial typed views expose only the observed input mask, timer, count, divisor and position fields. The delta helper writes exactly two floats, so its local output is two floats. Actual callback and child/owner arguments are preserved, including a four-argument call. No unused locals, fabricated field extents or forced registers are used.

The new actor sources use legacy MWCCPS2 3.0 `-O4,p`, threshold eight. Existing constructor and dispatcher units retain modern MWCCPS2 3.0.3 `-O3` with their respective threshold eight and zero. All 1,467 whole functions across five complete units pass relocated verification. No new readonly section, DATA source or initialized-data credit changes. Frozen private receipts record the retail-image, packed-executable and 95-test gates separately from compilation.
