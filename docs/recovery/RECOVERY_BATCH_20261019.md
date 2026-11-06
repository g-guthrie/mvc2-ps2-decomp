# Exact dispatch, runtime, and effect-record recovery

This batch adds 53 compiler-exact functions (10,300 bytes) and 525 reconstructed
data bytes. The reconstructed functions have whole-span instruction and
relocation proofs and are included in the byte-exact hybrid image.

The dispatch recovery adds 44 functions /2,004 bytes. Every original inventory
span remains fully covered by verified C entries or uncredited assembly
residuals. Native alignment bytes and unknown callback bodies remain
uncredited. Owner-context arguments follow the actual callback interfaces.

Five payload callbacks add 1,848 bytes: 001D01D0, 001D9780, 001DE8D0, 001A7560,
and 001C55A0. The owner dispatches DEB00/EE40, A7880/B460, and D9A70/E860 now
carry their real second argument. The existing eight-byte 001D04F0 release
wrapper moves from a generic four-integer tail to its actual unary object
release interface; its credit does not increase.

Four pinned Newlib/fdlibm units add 6,448 bytes. Their original notices,
compiler profiles, aliases, and strict readonly section checks are documented
in [the runtime receipt](sdk-receipts-20261019.md). Compiler constant pools
receive no reconstructed-data credit.

This product includes software developed by the University of California,
Berkeley and its contributors.

The placement table at 0044C3C0 contains sixteen six-byte records ending at
the independent callback table 0044C420. Coalescing its old fragments restores
two previously unknown records, adding 12 bytes to the previous 84-byte credit.
The launch family 0044C530–0044C76A contains 57 ten-byte records. The exact
001C0A90 consumer reads three header bytes, two signed velocity halfwords, and
two animation bytes per record. Its unread alignment byte stays a placeholder.
The 513 meaningful bytes are reconstructed; all 57 pad bytes and the six-byte
tail before callback table 0044C770 remain placeholders. The physical ownership
and record grammar establish the array extent; no universal runtime selector
bound is claimed.

Root validation rebuilt and checked 51 new or changed code translation units,
including the complete existing units affected by interface repairs, and 176
data objects, including every changed pad/tail and the neighboring boundaries.
Unchanged source/object/header hashes were checked against the previous full
build manifest. The loaded image and packed retail ELF reproduce their pinned
SHA-256 hashes exactly. This establishes hybrid-image identity while raw
regions retain zero reconstruction credit.
