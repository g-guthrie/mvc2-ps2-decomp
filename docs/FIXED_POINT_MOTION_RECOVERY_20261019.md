# Fixed-point motion callback and native helper recovery

Function 003486B0 adds 328 bytes of whole-function matching C. It initializes
actor state, converts signed 16.16 motion pairs using the native 5/3 and 15/7
coordinate scales, mirrors horizontal motion by direction, and adds position
from the incoming context argument. The complete modern Metrowerks O4,p / G0
object reproduces its native instructions and relocations. Slot 004C19A4
contains this entry address. The callback uses actor A0 and context A1; the
outer 00348800 dispatcher indexes 004C19A0 by actor offset 0x20 and preserves
the incoming context. Tracing that incoming argument further remains separate
from this whole-function compiler proof.

The existing sixteen-byte 00461EF0 motion input retains its placeholder status;
this code recovery alone does not claim a universal selector bound.

The static helpers at 00345EE0, 0037F440, and 0038E500 now implement their genuine
actor-position, timer/counter, and animation-scale behavior. Their complete
88-, 56-, and 104-byte bodies verify independently, as do all credited callers
in m15d, wave30b, and q3_a. The q3_a production recipe now includes Op so its
helper also matches exactly. These repairs add no helper credit.

Two adjacent fixed-field triplets at 004382F8 and 00438304 add 24 reconstructed
data bytes. Each word has a fixed native load/store, and the following owner
at 00438310 is independently loaded at 00107E10/00107E20. The source uses three
neutral u32 fields per unit rather than inventing a selector range or array.
Root verification covers both objects and the next physical 752-byte unit.

Root checks all ten credited functions in the four new/changed code units,
the three helper bodies, fresh splitting with alias annotations, and the full
hybrid ROM and packed retail ELF. Both final images reproduce the pinned
SHA-256 hashes exactly. All 57 tests, catalog validation, build coverage, shell
syntax, and staged whitespace checks pass.
