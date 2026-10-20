# Input direction motion at 001F0980

The recovered 260-byte function advances horizontal position and velocity,
checks the animation result, and selects zero or a signed 2.5-unit velocity
from its input state. A negative animation result invokes the existing finish
helper. A zero signed state byte stops motion. Other paths distinguish the
embedded pad word from the regular input word and retain the native priority
of the 0x800 direction bit over 0x400.

Expressing the regular-input path as a positive 0xC00 mask guard with nested
direction tests preserves the native branch order. Ordinary floating-point
literals express the velocity stores directly. The initial helper's void
result declaration agrees with its complete existing source provider.
MWCCPS2 3.0-011126 `-O4,p -sdatathreshold 8` reproduces all 260 relocated bytes;
no assembly, barriers, instruction patching or artificial padding is used.

Combined validation with the three newly recovered Sony mode setters passes
all 91 tests, catalog validation and production coverage (4,112 source units).
The full loaded image and packed retail ELF remain byte-exact with SHA-256
values `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f` and
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Code credit is 2,031,768 / 3,293,696 bytes (61.6866%); data remains
195,314 / 648,064 bytes (30.1381%).
