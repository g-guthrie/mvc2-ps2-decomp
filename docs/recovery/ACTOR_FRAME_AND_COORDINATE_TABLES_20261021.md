# Actor setup and frame-table recovery

This bank adds two complete actor setup functions (864 CODE bytes) and 784 reconstructed DATA bytes. Changed/new objects were compiled with the registered production recipes and verified against the private retail image. Unchanged source/object and header hashes are retained as cached proof; full-image linkage is checked separately.

`func_001B1D20` and `func_001B1EE0` preserve the native 196-byte inherited-state copy, repeated position/flag stores, signed direction test, BSS float inputs, and exact distance/acceleration constants. Both pass the parent to `func_00176160` and the child to `func_001754A0`; only the first invokes `func_0015E630` and sets the child's active byte. The shared inherited-state layout remains unchanged.

| DATA owner | Bytes | Native role / valid input |
| --- | ---: | --- |
| `004B3200..004B3350` | 336 | Fourteen pairs of XYZ endpoints; creator calls explicitly select 0–13 and the callback interpolates the pair. |
| `004B3350..004B3368` | 24 | Two XYZ parameter triples, selected by whether that selector is below seven. |
| `004B33F0..004B3414` | 36 | Nine scalar samples selected by a signed context halfword; the table branch requires index 0–8. |
| `004B3AF0..004B3B70` | 128 | Sixteen float coordinate pairs; `0015B160` uses `field1C - 1`, requires `field1C` 1–16, and skips the read at zero. |
| `004B3ED0..004B3EF4` | 36 | Three XYZ basis vectors used by the native modulo-three selectors. |
| `004B3F00..004B3F80` | 128 | Sixteen float coordinate pairs; callback requires index 0–15 and the associated state update cycles a valid index modulo sixteen. |
| `004B4060..004B40A0` | 64 | Sixteen float frame parameters, read into child field `+0x74`. |
| `004B40A0..004B40C0` | 32 | Sixteen signed-halfword frame delays, read into countdown field `+0x1E`. |

The two coordinate grids are complete physical arrays replacing fragmented placeholder rows. In particular, all six old fragments at `3AF0..3B70` were already catalogued placeholders; there was no uncatalogued twelve-byte tail there. The frame-delay array at `40A0` was missing from the DATA inventory and had been printed as instructions by the disassembler. Its signed-halfword loads and countdown use establish its data role; it has no CODE credit. Neither progress denominator changes.

The two frame arrays share native index `8*mode + frame`, which must be in `[0,16)`. The fresh-child producer obtains mode 0 or 1 from the byte-valued RNG modulo two, and the frame update advances/clamps the frame at seven. This supports the normal producer path, without claiming arbitrary external field writes are excluded.

The nine-sample scalar access is unchecked. Another native path sets its context selector to nine; the relation between that state and the table-reading branch remains unproven. The source records the physical nine-float owner and its valid-index precondition, without asserting universal runtime bounds. The vector selector using `(context & 15) - 1` likewise requires a nonnegative resulting table index when taking that path.

The 8-byte prefix before `3200`, the 12-byte prefix before `33F0`, and the three unreferenced 1.0 floats at `3EF4` remain placeholders. No opaque bytes or near-match functions receive reconstructed progress. Existing consumer C sources retain their native address aliases; this bank does not claim recovery of the original global source types or global alias closure.
