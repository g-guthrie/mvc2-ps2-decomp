# Bobbing position update at 003421E0

The recovered 212-byte routine selects a baseline and amplitude with the actor's
byte index, converts its signed frame angle from degrees to the runtime's
16-bit turn representation using double arithmetic, and calls the existing
sine lookup. It writes `baseline + amplitude * sine` to the actor's vertical
position, increments the signed halfword angle, and resets it at 360.

The amplitude and baseline loads remain separate before the multiplication
and addition, preserving the native floating-point operand order. MWCCPS2
3.0.3-020716 at `-O4,p -sdatathreshold 8` reproduces the complete function after
relocation. The sine declaration agrees with its existing unsigned word-angle
provider. No assembly, barriers, artificial padding or helper effects are used.

The table entry aliases at 004605E4 and 00460608 identify existing native
references. Their bounds remain unspecified, and no data credit is added.
All 13,730 previous source/object pairs and 37 shared headers were checked
against checkpoint `92972e3e` and remain unchanged.

Production coverage (4,107 source units), catalog validation and all 91 tests
pass. A fresh split and full hybrid link reproduce the 3,941,760-byte loaded
image (SHA-256 `c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`)
and the packed 3,942,320-byte retail ELF
(`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`).
The catalog now credits 2,030,388 / 3,293,696 code bytes (61.6447%);
reconstructed data remains 195,314 / 648,064 bytes (30.1381%).
