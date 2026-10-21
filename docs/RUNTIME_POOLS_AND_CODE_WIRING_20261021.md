# Runtime pool recovery and clean-build ordering

This checkpoint adds 176 exact matching code bytes and 4,540 reconstructed
data bytes. Code is 2,065,128 / 3,293,696 (62.6994%); data is
248,736 / 648,064 (38.3814%). All newly matching entries are complete after
fresh linkage and retail-image verification.

## Code and build wiring

The signed-button motion handler at 00267D70 clears actor motion state,
selects the button word, and computes horizontal speed and facing. It is
176 whole bytes under legacy MWCCPS2 3.0-011126, -O3 -Op, threshold zero.
The public signature retains the opaque actor pointer used by its caller;
the implementation uses the native field view locally. The caller's two
arguments are now declared explicitly. Both production units reproduce all
18 registered functions. The production compile/verify stanza is included.

The existing build-coverage checker exposed a separate ordering defect:
27 code compilations followed the data build. The single data invocation
now runs after the final code compilation, ensuring code-owned switch tables
have fresh code objects available. No compiler flags or instruction bytes
were changed by moving it. `make progress-check` now runs that existing
checker before the catalog validator, and the report workflow invokes this
same target. Existing negative fixtures already exercise the ordering rule;
the pre-fix script failed it and the corrected script passes. Coverage now
reports 4,177 wired code sources and no unregistered bodies.

## Data recovered

| Objects | New bytes | Independent extent evidence |
| --- | ---: | --- |
| Effect offsets and two fixed vectors | 40 | Eight fixed selector calls; complete three-float loads |
| Scene vector table | 36 | Sole caller loops over three complete V3 records |
| Renderer matrices | 128 | Two rows; RNG mask proves signed remainder columns 0..3 |
| Htci file requests | 624 | Thirteen 48-byte records with native field and scan evidence |
| SJRM instances | 3,072 | Sixty-four 48-byte records; independent lifecycle clear of 0xC00 |
| Runtime request slots | 640 | Thirty-two 20-byte records; independent per-record clear and two bounded scans |

The file-request pool reuses HtciFileRequest rather than introducing a second
layout. Its formerly opaque words are identified as block counts, buffer
pointer, and completed blocks. Five bytes retain an explicit opaque view.
The block counters use 2048-byte units; they are not byte counts. The root
rebuilt all six dependent units and verified 39 current registered functions;
the worker's older baseline receipt covered 38. Current SDK repairs in the
shared s3w9e unit were preserved.

The SJRM pool reuses RuntimeQueryContext. The existing type's unknown prefix
is now the interface pointer, active/mode bytes, two alignment bytes and UUID
pointer, followed by the already established node pool, capacity, moved list,
four indexed lists and error callback/context. The constructor and lifecycle
sources use this shared pool declaration. Its constructor retains the true
interface/UUID object address contracts. The known two-argument error
callback remains an external native function alias; its C body gains no code
credit in this checkpoint.

Every field has constructor or method evidence, and the pool's 64-record scan
and full lifecycle clear agree on its complete 3072-byte extent. The next
string at 4959D8 and following raw owners are unchanged. The root rebuilt the
complete recursive include closure: ten code units with 15 existing functions
and 33 data objects. No local duplicate record type or new type header remains.

Runtime slots at 495BB8 contain an active byte, one opaque byte, the observed
halfword at +2, a callback-object pointer, two command arguments and the
returned runtime handle. Both consumers scan exactly 32 slots. Release clears
the active byte; reuse clears the entire 20-byte record. The following 0xA18
zero tail stays raw. No interpretation of the external command payload beyond
its observed fields is credited.

For the renderer matrices, the existing random routine's native 7FFFFFFF
mask proves its output nonnegative. Signed remainder by four therefore gives
columns 0..3; the caller supplies only rows 0 and 1. This establishes both
complete 2x4 arrays. The coordinator verified 384 instruction words across
nine relevant function spans and all eight fixed-selector callsites for the
other lookup. The runtime-slot audit separately checked 264 native words;
its two unreconstructed consumer bodies remain uncredited code.

## Verification

The coordinator independently rebuilt 18 changed code units, covering 72
whole functions, and 48 data objects. The latter include existing data owners
affected by shared headers and retained raw neighbors. Seven old data units
retire; only nine newly proven typed objects contribute the 4,540-byte gain.

Before linkage, 15,127 unchanged source/object pairs and 45 unchanged headers
were checked against the preceding proof manifest. The two changed shared
headers' recursive include closures cover 50 units; each was rebuilt and
verified. Catalog rows and sources were imported by scoped immutable deltas,
preserving unrelated canonical changes.

All 95 tests, coverage and catalog checks pass. Fresh split and linkage
produce the exact 3,941,760-byte retail loaded image; executable packing
produces the exact 3,942,320-byte retail ELF. Their SHA-256 values remain
c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f and
48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.
The fixed next code-publication threshold remains 2,080,510 bytes, with
15,382 more verified code bytes required.
