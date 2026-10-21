# Memory-card icon file recovery

`src/data/data_icon_file_00465260.c` reconstructs the complete 50,968-byte
`mvsc2.ico` file at `[0x00465260,0x00471978)`. This is a bounded PS2 memory-card
icon with typed geometry, animation and texture records. Its extent follows the
native file writer and the parsed format, rather than a repeated fill pattern.

Native state 0x17 of 0038B2E0 selects file index 1. State 0x18 constructs
`/BASLUS-20486SYS/mvsc2.ico` through 0038D010 and opens it. State 0x19 obtains the
buffer from 0038D290(type=1), its exact length `0xC718` from 0038D310(type=1),
and writes it through 00419B90 to 001105D0. The last helper issues memory-card
RPC operation 6, the write operation; the adjacent read wrapper uses operation
5. The source is aligned, so no unaligned-head staging changes the buffer span.
The existing address getter now declares the actual tagged icon type and takes
its address; its complete compilation unit remains byte-identical.

| File section | Address | Size | Typed contents |
| --- | --- | --- | --- |
| Header | 00465260 | 20 | Version 0x10000, one shape, attributes 7, backface 3.0, 756 vertices |
| Model | 00465274 | 18,144 | 756 vertices, each 24 bytes |
| Animation | 00469954 | 36 | One sequence, one shape frame, one key |
| Texture | 00469978 | 32,768 | 128 by 128 PSMCT16 pixels |

Each vertex stores three Q6.10 position components and its explicit padding
halfword, three Q4.12 normal components and their padding halfword, two Q4.12 UV
coordinates, and RGBA bytes. Both padding fields are defined by the file format
and preserved as such. They are not unexplained inferred gaps. The animation
sequence has length one, speed 1.0, offset zero and one shape; frame zero has
one key at frame 0.0 with weight 1.0. Attributes 7 enables texture storage while
leaving the RLE flag clear, so the final 32,768 bytes are raw 16-bit pixels.

The field layout and raw-texture interpretation were checked against the primary
[HDLGameInstaller format declarations](https://github.com/ps2homebrew/HDLGameInstaller/blob/main/IconLoader.h)
and [loader implementation](https://github.com/ps2homebrew/HDLGameInstaller/blob/main/IconLoader.c).
No implementation code from those sources is included. Native bytes, file
selection and compiler output independently establish this particular owner.
The original 7,168-byte all-ones investigation window begins eight bytes into
this texture; its role follows from the complete file parse.

The owner replaces 377 raw units covering 49,640 bytes and absorbs 1,328
previously unowned internal bytes. None of the old units had reconstructed
source credit, so the net addition is 50,968 DATA bytes. Adjacent owners beginning
at 00471978 are excluded. The exact source was independently compiled with
MWCCPS2 3.0.3, `-O3 -sdatathreshold 0`, and checked over the full file span by
`tools/verify_data_object.py`. The object, ROM, toolchain and native evidence stay
private; only the typed C source and documentation are published. This does not
claim recovery of other icon files or emulator/runtime acceptance.
