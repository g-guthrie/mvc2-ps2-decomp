# Scene tables and callback recovery

The actor and scene callback batch reconstructs 14 complete functions, totaling
5,024 code bytes. Each production object reproduces its full registered native
instructions and relocations. The changes to 17 existing compilation units
preserve their entire object bytes; signature repairs add no matching credit.

The inherited-state dispatch region contains distinct callable entries at
00197920 (44 bytes), 00197950 (236 bytes), and 0019E750 (56 bytes).
The first two dispatch through the real owner/context tables; 0019E750 is a timer
callback. The adjacent 0019E670 body remains unmatched at 224 bytes. Four bytes
of native alignment between the first two entries stay uncredited. These splits
clarify callable ownership without changing the conservative text denominator.

Scene lifecycle, position, signed animation cycling, launch, colour, resource
stream, owner signalling and lifetime callbacks account for the other 4,688
bytes. Actual descriptor types, signed command bytes, inherited facing, integer
duration conversions, and animation helper contracts are preserved. The resource
callbacks transport native 32-bit resource addresses explicitly and require live
handles and valid allocated stream storage. Their return contracts agree with
the owned providers. The allocation chain also returns an actual integer handle through F0C60,
F0C50, DB9B0, DCFE0 and DE7E0. The retry routine preserves the native ignored
second caller hint. A handle becomes a pointer only after the real DD030 address
lookup; the old void and pointer return declarations are corrected without
changing the compiled objects. The empty renderer stub retains its actual resource and
four floating inputs, as supplied by both native callers. Native quirks and
unmatched candidates are retained rather than counted as recovered code.

## Typed data and boundaries

The scene/effect table changes add 160 reconstructed bytes after preserving one
previously reconstructed scalar byte exactly once. Their owners comprise two
endpoint vectors, a 13-entry signed animation cycle, two eight-float height
tables, two eight-short timer tables, and a seven-entry unary callback directory.
The former directory mistakenly began at packed timer words. Its actual start
is 00462330. The 34E290 dispatcher base is 004622A0, with the relevant interior
callback view at 004622B0. Both mode paths construct eight selectors. The signed
animation cycle uses timer values 0 through 25 divided by two, then wraps at 26.
Three remaining bytes after the animation cycle remain raw and uncredited.

A separate 200-byte window at 004B82E8 contains four typed owners totalling
82 bytes and 118 opaque bytes. The typed owners are a three-float spawn vector,
four launch records, six rise heights, and six signed animation codes. The
launch records have four signed halfwords followed by animation and event bytes:
the native stride is ten, not twelve. Data, indexed caller and initializer use
compatible tagged `LaunchRecord` definitions and the actual helper signature.
The complete caller object remains byte-identical.

The launch-record read requires `p[0x1B7] + 2*p[0x20] < 4`. The height/code read
requires `p[0x22] < 6`, with ordinary live actor and owner storage. These are
explicit valid-input contracts, not claims that every global scheduler path
has been closed. Resetting the selector after reading it is not an input guard.
The real float and signed-byte providers permit exact reconstruction of the
304-byte 0034C1E0 callback without incompatible word-array aliases.

The eight islands replace the old 192-byte raw word unit and absorb an eight-byte
unowned prefix. Only 82 bytes receive new source credit. Their four opaque
islands, 118 bytes in total, remain placeholders; other adjacent gaps and owners
are unchanged. Combined net new table DATA is 242 bytes. No raw fill, guessed
capacity, alignment or instruction lift earns source credit.
