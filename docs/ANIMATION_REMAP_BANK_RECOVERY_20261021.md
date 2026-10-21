# Complete character animation remap bank

The native renderer at `0x001E24E0` uses the character selector at actor `+1`
to index the pointer directory at `0x0044F0D0`. It then reads a byte from the
selected animation map. `0xFE` suppresses drawing, `0xFF` preserves the input
animation, and other values replace that animation ID. The fixed readers at
`0x001E3430` and `0x001E3520` use directory slots 4 and 25 respectively.

The complete physical bank contains 59 contiguous maps of 64 bytes:
`[0x004B5B70, 0x004B6A30)`, totaling 3,776 bytes. The source models this format
as a two-dimensional byte array. All 59 directory entries are symbolic pointers
to its rows, with actual `R_MIPS_32` relocations and addends `0, 64, ..., 3712`.
The 236-byte directory occupies `[0x0044F0D0, 0x0044F1BC)`.

The documented valid-input domains are character selector 0–58 and per-map
animation index 0–63. The local native selector does not check bounds. Physical
format recovery does not prove every selector is reachable or establish behavior
for every unchecked index. The source does not invent a 256-byte capacity from
the consumer's eight-bit index.

This replaces 78 fragmented placeholder bank units (3,760 bytes) and absorbs
16 previously unowned bytes that lie inside the proven maps. The directory's
236 bytes were also placeholders. The net reconstructed-data increase is
4,012 bytes relative to the published baseline. The previously proposed 64-byte
map at `0x004B61B0` is row 25 and is included once in the complete bank.

The zero word at `[0x0044F1BC, 0x0044F1C0)` remains unowned: native code does
not demonstrate a terminator or a real 60th entry. The eight-byte gap before
`0x004B5B70` also remains unowned, and the existing reconstructed owner beginning
at `0x004B6A30` is preserved. Both complete compiled data objects match retail;
950 instruction words from the three native consumers were independently pinned
to the private executable during recovery.
