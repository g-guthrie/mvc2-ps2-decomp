# Pad request-state label at 0010DAF8

The complete 52-byte C routine selects an entry from the native request-state
string table for indices below four and passes the selected string to the
existing copy helper. Other indices write the native fallback byte (zero).
The table includes the request labels `COMPLETE`, `FAILED` and `BUSY`.

The source preserves the unsigned word-sized selector and the two-pointer
copy-helper interface. Sony EE GCC 2.9-991111 at
`-O2 -G0 -ffunction-sections`, followed by SNAS, reproduces every relocated
function byte. Both the scratch reconstruction and the production source
were independently compiled and checked against the canonical ROM.
No compiler output, assembly or object bytes are edited; no data is credited.

All 13,744 previous source/object pairs and 37 shared headers remain unchanged
from checkpoint `71a63e18`.

Production coverage (4,121 source units), catalog validation and all 91 tests
pass. The full loaded image and packed retail ELF remain byte-exact with
SHA-256 values `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`
and `48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Code credit is 2,033,132 / 3,293,696 bytes (61.7280%);
data remains 195,314 / 648,064 bytes (30.1381%).
