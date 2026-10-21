# Scene, glyph and motion data recovery

This bank reconstructs 820 DATA bytes from native readers and their physical
storage boundaries.

| Group | Bytes | Recovered representation |
| --- | ---: | --- |
| Scene delay and position storage | 232 | Shared delay/vector storage, position vectors, velocity choices and resource selectors |
| Glyph atlas offsets | 320 | Eighty packed horizontal/row offsets consumed by texture addressing |
| Motion data | 240 | Float XY pairs, signed-halfword triples and signed-halfword pairs |
| Vertex colors | 28 | Seven packed four-channel colors used across four vertices per render pass |

The scene delay reader uses twelve logical rows of five halfwords. Its row
counter advances modulo twelve and periodically resets the state that reads
the table. The last row therefore reads into the following position vector;
this is not limited to corrupted state. One 148-byte union at `004B7EC0`
represents the actual shared bytes: a physical view with 56 halfwords and
three XYZ positions, and a twelve-by-five delay view that overlaps the first
position's x/y words. Existing native aliases at the owner base and base+112
are preserved. The union models the observed overlap without claiming it was
intentional in the original source. It neither adds a guard nor changes those
reads. The old numeric fragments labeled as jump tables are halfword data.

The other scene vectors have complete three-float readers. The four resource
selectors have four-byte stride and are truncated into an object halfword.
The C model uses signed integers; a compiler probe confirms that this ordinary
integer-array read and truncation produces the observed `lh` instruction.
The original C type is not uniquely determined by that instruction. The
existing XYZ consumer's member names now agree with the other vector views;
its complete compiled functions remain exact.

The glyph owner starts at `004B6E70`, rather than the middle of the old catalog
fragments. Native code returns each complete word, splits its low two bytes,
and feeds them into horizontal-offset and row-stride texture addressing. Its
80 entries end at the independent WINS text object. The preceding eight bytes
stay raw. Callers must supply mapped indices below 80; the mapper's fallback
does not establish that condition for arbitrary input.

Motion readers establish signed six-byte and four-byte records and six
eight-byte float pairs. The four earlier XY entries use twelve-byte stride,
but only their first eight bytes have a proven type, so the intervening lanes
remain raw. Native readers lack local bounds checks: the corresponding valid
selector ranges are four XY choices, sixteen motion records, nine records
from the interior motion view, and six float-pair choices. These are input
preconditions rather than proven global invariants.

The vertex-color field is corroborated by the renderer's packet builder and
four-byte color conversion routine. No channel order is inferred from the
hexadecimal values alone. Exactly seven table words are loaded; the following
word remains raw even though its bits also occur as an immediate elsewhere.
Existing reconstructed neighbors, unknown prefixes and stride lanes retain
their prior credit status.

The bank also adds the complete 400-byte actor callback at `00277D40`.
Its local three-float position is initialized completely before the effect
call. Signed state loads, helper order and binary32 additions remain native.
The shared `00162BA0` wrapper now has a typed actor-pointer interface, and
the `00329020` adapter forwards its second pointer, preserving the native
delay-slot move from A1 to A0. The old unprototyped call and four-argument
projection were replaced with consistent C declarations. All 641 functions
in that existing wrapper unit still verify exactly; they add no new credit.

All 26 changed DATA objects and 652 functions across the three affected CODE
units were independently compiled and verified. All 118 tests, fresh splitting,
full hybrid linkage and packed retail ELF byte identity passed. The combined
totals are 2,083,120 matching CODE bytes (63.2457%) and 262,595 reconstructed
DATA bytes (40.5199%). The next fixed CODE milestone stays 2,113,447 bytes.

## Coordinate pairs at 0x004B52F0

The complete seven-pair float table spans `[0x004B52F0,0x004B5328)`. Native `func_0016E080` loads its first two pairs directly, then reads five further pairs through the same base pointer at offsets `0x10 + 8*i` and `0x14 + 8*i`, for `i=0..4`. The following player-label string remains a separate owner. This replaces the earlier four-float fragment and 40-byte raw fragment with one 56-byte typed object. The original 16 reconstructed bytes are retained once, so new DATA progress is 40 bytes. The consumer function remains unmatched.
