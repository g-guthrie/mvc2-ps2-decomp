# Owner countdown and contact-state recovery

Two native-first C functions match with MWCCPS2 3.0-011126,
`-O4,p -sdatathreshold 8`, adding 916 code bytes and no data credit.

| Function | Bytes | Recovered behavior |
| --- | ---: | --- |
| 00379A60 | 516 | Owner countdown, contact-byte and animation-state update |
| 003BD4C0 | 400 | Contact-state filter returning zero or minus one |

The countdown routine initializes the owner's countdown to eight when the
actor's signed byte at 0x1B2 is nonzero, and decrements a nonzero countdown
when byte 0x23 is zero. Its two paths retain their distinct contact-byte
writes and select animation IDs from owner byte 0x1B7 and the signed
integer expression `(actor[0x23] / 2) % 2`. The byte animation local retains
the native narrowing at assignment. Both paths clear the native halfword,
byte and word fields in order and increment the existing per-index signed
halfword counter at `D_004C2794 + 0x7C`. The typed owner view places its
countdown at 0x2DC. The counter view has a flexible array: it asserts no
invented array bound and earns no data credit.

The filter preserves the special 0x15/2/3 case, the owner/status comparison,
the two cached previous-state bytes and conditional reset, and each of the
six 7-through-12 state tests. Its integer locals hold the values after the
native unsigned-byte loads, avoiding extra byte-narrowing operations when
comparing the cached values. Existing callers already declare an integer
result and pass the actor pointer; no caller or helper ABI is changed.

Root independently recompiled both canonical source files with the exact
production recipes and verified all 129 and 100 words respectively against
retail. Both source units are compiled and verified in the production script.
No assembly, padding, compiler barriers, volatile access or fabricated helper
is used.

The full hybrid ROM remains exactly 3,941,760 bytes with SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
The packed retail ELF remains exactly 3,942,320 bytes with SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Unreconstructed raw regions remain uncredited.
