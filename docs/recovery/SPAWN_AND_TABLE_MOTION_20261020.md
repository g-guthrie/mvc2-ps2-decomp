# Counted spawning and table motion

Three complete functions add 892 exact C code bytes, compiled with
MWCCPS2 3.0.3 using `-O4 -Op -sdatathreshold 8`:

| Entry | Bytes | Source |
| --- | ---: | --- |
| 00357700 | 188 | `spawn_counted_00357700.c` |
| 001F1070 | 320 | `motion_table_update_001f1070.c` |
| 001FB250 | 384 | `motion_landing_001fb250.c` |

The spawn loop writes the current signed-byte count into each allocated
object and decrements that count after initializing the object's fields.
Its constructor declaration matches the existing allocator, and its typed
callback agrees with the complete one-argument state dispatcher at
00357C40. The old sketch's `padloop` pragma is removed; the compiler emits
all native instructions without explicit padding.

The table update uses an ordinary float zero assignment for acceleration
at offset 0x68. This aligns the field's type with its motion role and
reproduces the native constant and floating-point register allocation.
Its animation helper declarations agree with their existing definitions,
including explicit signed-byte narrowing of the integer result. The
original NaN-sensitive comparison behavior is retained.

The landing routine also uses float zero assignments for its motion fields.
An ordered negative-velocity comparison retains the native comparison sense;
combined with the field types it reproduces every floating-point operand.
Its callback allocation and signed-result helper interfaces agree with their
existing definitions.

Four address aliases identify existing table entry points at 0044F7D0,
0044F7D4 and 0044F7D8, plus the existing 001F9CB0 helper. These award no data ownership, bounds or data credit.
All three full relocated function spans verify against retail. All 13,726
preceding source/object pairs and 37 shared headers remain unchanged.

A fresh executable split, build coverage, catalog validation and all 89
tests pass. The loaded ROM remains 3,941,760 bytes, SHA-256
`c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f`.
The packed ELF remains 3,942,320 bytes, SHA-256
`48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7`.
Raw fallback regions remain uncredited.
