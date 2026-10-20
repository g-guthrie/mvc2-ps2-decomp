# Actor setup and random launch recovery

Two complete C functions add 780 exact code bytes using MWCCPS2 3.0.3
with `-O4 -Op -sdatathreshold 8`:

| Entry | Bytes | Source |
| --- | ---: | --- |
| 00187840 | 352 | `actor_setup_00187840.c` |
| 00396030 | 428 | `random_launch_00396030.c` |

The actor setup routine uses ordinary float literals for its position
threshold, motion and acceleration fields. The threshold literal removes
the sketch's integer-to-float pointer punning; the remaining literal
assignments retain every native store and constant bit pattern. Its
animation helper declaration matches the existing int-return definition.

The random launch routine also uses ordinary float constants and the
established manager counter view at offset 0x7C. It accesses the actor's
counter index directly instead of introducing an additional byte-pointer
local. Its facing branch negates velocity before negating the local
position offset, reproducing the native floating-point register allocation
and instruction order. Its random helper declaration agrees with the
existing int-return definition. There are no fabricated helper effects,
barriers, padding, assembly bodies or data-ownership claims.

Both entire relocated function spans match retail. All 13,724 preceding
source/object pairs and all 37 shared headers remain unchanged. Build
coverage, catalog validation and all 89 tests pass.

The loaded ROM remains exactly 3,941,760 bytes, SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
The packed ELF remains exactly 3,942,320 bytes, SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Raw fallback regions remain uncredited.
