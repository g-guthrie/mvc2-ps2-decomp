# Sony runtime address modes at 00102A50 and 00102AD0

Two adjacent C functions reproduce complete retail spans with Sony EE GCC
2.9-991111 `-O2 -G0 -ffunction-sections` and the existing SN assembler:

| Function | Bytes | Resulting mode bits |
| --- | ---: | --- |
| 00102A50 | 124 | Clear bits 0, 2 and 3; set bit 8 |
| 00102AD0 | 128 | Clear bits 0 and 2; set bits 3 and 8 |

Both first remap their address argument with the existing 00102520 provider,
call the reset helper, replace the address field at +0x10 unless its current
value is the unsigned all-ones sentinel, and write the supplied value at +0x20.
Their shared structure describes only these native fields and the intervening
unknown bytes; no unused tail padding is required. The address and mapping
result use unsigned 32-bit values consistent with the existing provider.

The compiler directly emits the native 64-bit register saves at 16-byte
spacing. No assembly or object output is rewritten. Both functions were
independently compiled and verified in scratch, then recompiled and verified
from their production source. The previous 13,733 source/object pairs and
37 shared headers remain unchanged from checkpoint `3b96ec40`.

All 91 tests, catalog validation and production coverage (4,110 sources) pass.
The complete loaded image (3,941,760 bytes) and retail ELF (3,942,320 bytes)
remain byte-exact, with SHA-256 values respectively
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f` and
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Code credit is now 2,030,948 / 3,293,696 bytes (61.6617%);
data remains 195,314 / 648,064 bytes (30.1381%).
