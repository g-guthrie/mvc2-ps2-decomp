# Inherited actor and motion recovery

Nine complete native functions add 3,976 matching C bytes:

| Address | Bytes | Role |
| --- | ---: | --- |
| `0x001B2090` | 424 | Parent-state setup and signed motion offsets |
| `0x001B73B0` | 304 | Linked actor phase dispatch |
| `0x001BB140` | 368 | Context-aware child setup |
| `0x0019CE30` | 536 | Inherited child state and effect creation |
| `0x0019D050` | 536 | Inherited child motion and state transitions |
| `0x002D0B30` | 404 | Motion and animation state callback |
| `0x002E2F30` | 420 | Motion integration and animation transition |
| `0x001B6B60` | 572 | Parent-relative position cycle |
| `0x001CAF00` | 412 | Owner-state callback dispatch |

The inherited-state copies reuse the existing 196-byte `ActorState` definition,
matching the native 49-word loop. Parent and callback context pointers follow
the actual callers. The cleanup wrapper at `0x001B7650`, the declaration of
`0x001B73B0`, and the context signature of `0x001BB2B0` now carry their actual
argument contracts. Previously corrected unrelated wrappers remain intact.
All 783 functions in the eight affected existing compilation units recompile
exactly; the corrections add no credit for those existing bodies.

The motion callbacks preserve native store order, floating-point operations,
status narrowing and field clearing. In particular, `0x002D0B30` clears the
float field at `+0x6C` before its animation call. Compiler profiles remain explicit
in the production build script. No shared headers or data capacities change.

All nine new functions and the affected existing objects passed independent
whole-object verification. Separate source/native reviews cover their helper
contracts and storage views. The position-cycle dispatcher selects modes 3–7 through its actual interior
table base, so the offset reads use indices 0–4 of the existing six-pair float
owner at `0x004B5800`. An earlier mode interpretation incorrectly suggested an
overlap with a neighboring byte table; that hypothesis is superseded without
changing DATA ownership. The owner dispatcher retains its actual signed state
cache and a common child/owner callback protocol. Private near matches and an
exact candidate requiring an unproven alignment annotation remain outside the
matching catalog. Full-image linkage is checked separately
before promoting this batch to complete.
