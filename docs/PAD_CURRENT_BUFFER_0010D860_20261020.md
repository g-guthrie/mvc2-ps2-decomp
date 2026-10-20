# Current pad buffer at 0010D860

The complete 96-byte routine loads a buffer pointer from the existing
28-byte BufferSlot layout, synchronizes its 256-byte range with the native
cache helper, and compares the signed sequence words at offsets 0x58 and
0xD8. It returns the first 128-byte buffer unless the second sequence is
greater, in which case it returns the second buffer.

The source uses an ordinary conditional offset variable. This is the verified
variant: the initially reported Boolean-shift version differs by six words
and receives no credit. Both use the same target and verifier; independent
recompilation identified the correct source/object pair before integration.

Sony EE GCC 2.9-991111 at `-O2 -G0 -ffunction-sections` and SNAS reproduce
the complete relocated function from scratch and production source. The
existing BufferSlot stride and the two-pointer cache-helper interface agree
with other native pad routines. The cache-helper body itself remains outside
this recovery. No volatile workaround, assembly, padding or output editing
is used; no data is credited.

The previous 13,745 source/object pairs and 37 shared headers remain unchanged
from checkpoint `705009cf`.

Production coverage (4,122 source units), catalog validation and all 91 tests
pass. The complete loaded image and packed retail ELF remain byte-exact with
SHA-256 values `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`
and `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Code credit is 2,033,228 / 3,293,696 bytes (61.7309%);
data remains 195,314 / 648,064 bytes (30.1381%).
