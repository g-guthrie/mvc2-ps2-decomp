# Scene object and angle initialization at 001453B0

The complete 420-byte C routine allocates and initializes the scene object,
copies its three-float position, converts its three configured degree angles
to masked 16-bit phases, sets the remaining flags and movement value, and
calls its existing setup helper.

The source uses the actual separate data objects: the three-angle array at
004B33D8 and the scalar at 004B3414. The scalar's explicit `.data` placement
matches its existing catalogued section and produces the native absolute
access. The earlier scratch access through angle-array index 15 is not used.
No intervening bytes are reclassified or credited.

The catalogued angles include -90 degrees. Each double expression is therefore
converted to signed `s32`, then to unsigned for the final 0xFFFF mask. This is
defined for these angles and agrees with the actual signed conversion routine
at 00119BC0. The compiler emits `dptoli`; the constructor does not rely on the
legacy unsigned-helper alias. The real position copy and one-argument callback
interface are retained. No padding, assembly or helper clobber tricks are used.

MWCCPS2 3.0.3-020716 `-O4,p -sdatathreshold 8` reproduces the complete relocated
function in independent scratch and production builds. All 13,746 earlier
source/object pairs and 37 shared headers remain unchanged from checkpoint
`3d9b1ef5`. Four existing code/data names are exposed in the code address map;
these aliases add no matching code or data ownership.

A fresh split, production coverage (4,123 source units), catalog validation
and all 91 tests pass. The full loaded image and packed retail ELF remain
byte-exact with SHA-256 values respectively
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f` and
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Code credit is 2,033,648 / 3,293,696 bytes (61.7436%);
data remains 195,314 / 648,064 bytes (30.1381%).
