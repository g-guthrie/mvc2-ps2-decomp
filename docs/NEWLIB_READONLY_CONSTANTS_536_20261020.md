# Newlib readonly constants

Recover 536 additional initialized-data bytes from six exact Newlib owners.
The coordinator checked the packet's 124 hashes, native instruction words,
and each cached source object's symbol size, section offset, and retail bytes.
Original arrays retain their complete extents. Named scalars keep their
original types; unnamed literal-pool scalars require direct native loads.

| Owner | Newly recovered bytes |
| --- | ---: |
| k_sin | 112 |
| k_rem_pio2f | 72 |
| k_tanf | 64 |
| atan | 168 |
| scalbn | 48 |
| atanf | 72 |

The atanf high and low tables are complete float[4] arrays at 0x004AC290
and 0x004AC2A0. They replace earlier fragments that split one array or
crossed their boundary. The 12 previously credited bytes remain within
those whole arrays, so their inclusion adds no duplicate credit. Across
the packet, 548 typed bytes replace 12 already credited bytes: net 536.

The four preserved raw spans total 20 bytes: alignment at 0x004AC114 and
0x004AC164, an unsymbolized tail at 0x004AC248, and bytes after the atanf
owner at 0x004AC2E4. Inter-owner gaps also remain uncredited. Exact constant
pool placement does not establish a typed owner for padding or neighboring
bytes.

Forty-four standalone data units, including the four raw spans, are rebuilt
with MWCCPS2 3.0.3, O3/G0. The six unchanged code owners and their complete
anchored readonly sections are reverified against retail. No code credit
is added; data linkage and whole-image identity are separate final gates.

The coordinator combined link places every recovered object. All95 tests
pass; the loaded image and packed ELF retain the retail SHA-256 hashes
c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f
and48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7.
Linked initialized data reaches242,520/648,064 bytes (37.4222%).
