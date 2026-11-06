# The player structure

Every character on screen is one of these. The game keeps six, one per team
slot, and most of the code below 0x0c1e9000 reads or writes them, so a unit that
gets a member's **width** wrong compiles to different instructions and never
matches. Offsets here are byte offsets from the start of the structure.

These offsets come from
[mountainmanjed/marvelous2](https://github.com/mountainmanjed/marvelous2), a
disassembly of the NTSC-U Dreamcast release, whose `memory/pl_mem.asm` records
what its author worked out about this structure. The Dreamcast and NAOMI
releases are the same game code built for the same CPU, so **structure offsets
carry over unchanged**; the absolute addresses in that repository (0x8c......)
are Dreamcast ones and do not.

Treat a row as a lead, not as proof. What settles a member is the retail bytes:
if a unit matches with a different width, the width in the unit is right and
this table is wrong. Rows our own units have since confirmed are marked.

| Offset | Width | Name | Notes |
| ---: | ---: | --- | --- |
| 0x0000 | 1 | `active` | 00-7f |
| 0x0001 | 1 | `charid0` |  |
| 0x0005 | 1 | `unnamed_state` |  |
| 0x0006 | 1 | `Special_Move_State` |  |
| 0x001c | 2 | `mash_timer` | used for many mash moves as well as sent's dash |
| 0x001e | 2 | `mash_counter` | used for ruby heart balls count, tron drill mash, psylocke psyblade |
| 0x0022 | 1 | `airdash_direction` | airdash direction(?) |
| 0x0034 | 4 | `x_pos` | absolute to world/stage **(confirmed here)** |
| 0x0038 | 4 | `y_pos` | **(confirmed here)** |
| 0x0040 | 2 | `char_pal_effect` |  |
| 0x0050 | 4 | `x_sprite_scale` |  |
| 0x0054 | 4 | `y_sprite_scale` |  |
| 0x0058 | 4 | `z_sprite_scale` |  |
| 0x005c | 4 | `x_velocity` | **(confirmed here)** |
| 0x0060 | 4 | `y_velocity` | **(confirmed here)** |
| 0x0068 | 4 | `JumpUNK` | **(confirmed here)** |
| 0x006c | 4 | `y_drag` | **(confirmed here)** |
| 0x00e0 | 4 | `x_pos_screenspace` |  |
| 0x00e4 | 4 | `y_pos_screenspace` |  |
| 0x0110 | 1 | `xflip_copy_2` |  |
| 0x012c | 1 | `unk_012c` | flag accessed as a byte in exact NAOMI units; Dreamcast notes say it is often 1 |
| 0x0130 | 2 | `xflip_copy` | exact NAOMI units read and write a 16-bit field here; name from Dreamcast notes |
| 0x0142 | 2 | `frame_count` |  |
| 0x0144 | 2 | `sprite_id` |  |
| 0x014a | 1 | `anim_flags` | if == 128 then opponent can preblock also seems to control whether special cancels are allowed 64 seems to directly inherit from 0x10 of animation structs in pldat files definitely flags |
| 0x0154 | 4 | `current_cell_data` |  |
| 0x0158 | 1 | `anim_group` |  |
| 0x0158 | 1 | `anim_id` |  |
| 0x015c | 4 | `Dat_GFX1` | Dat File Pointers |
| 0x0160 | 4 | `Dat_GFX2` |  |
| 0x0164 | 4 | `Dat_Pal` |  |
| 0x0168 | 4 | `animations` |  |
| 0x016c | 4 | `hitbox_pattern_table` |  |
| 0x0170 | 4 | `hitbox_data` |  |
| 0x0174 | 4 | `attack_data` |  |
| 0x0178 | 4 | `Sprite_Extras` |  |
| 0x017c | 4 | `Dat_FilePointer` |  |
| 0x0184 | 4 | `FAC_ptr` |  |
| 0x01a1 | 1 | `attack_data_index` | **(confirmed here)** |
| 0x01a3 | 1 | `sp_move_strength` | **(confirmed here)** |
| 0x01c0 | 1 | `hitbox_group_index` |  |
| 0x01d0 | 1 | `unk_01d0` | seems to control what animation/move to play **(confirmed here)** |
| 0x01d2 | 1 | `xflip` | **(confirmed here)** |
| 0x01d3 | 1 | `unk_01d3` | 0 when walking forward, 1 when walking backward, 0xFF when not walking |
| 0x01d4 | 1 | `special_move_jump_limiter` | if != 0, can't do normal jump specials. also prevents some SJ specials like ruby heart ball and lightning attack |
| 0x01d5 | 1 | `airdash_counter` |  |
| 0x01d6 | 1 | `normal_jump_action_counter` | unfly glitch is based on this value |
| 0x01d9 | 1 | `double_jump_counter` |  |
| 0x01e1 | 1 | `undizzy` |  |
| 0x01e1 | 1 | `undizzy_reset_timer` | counts down, when reaches 0, sets plmem[0x1e1] = 0 |
| 0x01e8 | 1 | `chain_strength` |  |
| 0x01e9 | 1 | `sp_move_id` |  |
| 0x01eb | 1 | `throw_immunity` | invincible to throws when > 0 timer, counts down, set when getting up |
| 0x01ed | 1 | `attack_immunity` | invincible to attack when > 0 timer, counts down, set when tagged out |
| 0x01f2 | 1 | `disable_special_move_counter` | counts down. when > 0x00, prevents special/super moves, airdash, tag |
| 0x01f3 | 1 | `disable_all_move_counter` | counts down. when > 0x00, prevents all moves set during fly screen dash |
| 0x01f4 | 1 | `unk_1f4` | ?? loaded as byte by loc_8c0500ac |
| 0x01f9 | 1 | `stance` | **(confirmed here)** |
| 0x01fc | 1 | `superjump_state` | 00 = not superjumping 01 = superjump rising 02 = superjump falling |
| 0x01fd | 1 | `corner_touching` | 00 = no corner 01 = right corner 02 = left corner |
| 0x01fe | 1 | `limb_choice` | 00 if doing a punch attack 01 if doing a kick attack **(confirmed here)** |
| 0x01ff | 1 | `in_air_normal` | 00 ground 01 normal jump 02 super jump |
| 0x0200 | 1 | `Buff_Speed` | Buffs |
| 0x0201 | 1 | `Flight_Flag` |  |
| 0x0202 | 1 | `Buff_HyperArmor` |  |
| 0x0203 | 1 | `Buff_Unk_03` | for magneto at least this toggles his idle floating anim |
| 0x0204 | 1 | `Buff_Unk_04` |  |
| 0x0205 | 1 | `Buff_Damage` |  |
| 0x0206 | 1 | `Buff_Defense` |  |
| 0x0207 | 1 | `landing_screen_shake_strength` | how hard the screen shakes when you land |
| 0x0208 | 1 | `Buff_Unk_08` |  |
| 0x0209 | 1 | `Buff_Unk_09` |  |
| 0x020a | 1 | `Buff_Unk_0a` |  |
| 0x020b | 1 | `Buff_Unk_0b` |  |
| 0x020c | 4 | `EnemyPointer` | pointer to opponent's currently active character's plmem struct **(confirmed here)** |
| 0x0210 | 1 | `has_blocked_this_jump` | 00 normally, 01 once you block in the current jump causes guard breaks if normal jumping ([0x1fc] == 00) |
| 0x0235 | 1 | `flying_screen_camera_follows` | if 1, camera follows this character (used for fs dummy) opponent can leave edge of screen, and will be forced to fs-dash in |
| 0x0239 | 1 | `air_hitstun_counter` |  |
| 0x023a | 1 | `airthrow_protection_counter` | if >= 2, you can't be airthrown. incremented when you get thrown set to 0 when you press an attack, or when you land |
| 0x0244 | 4 | `unk244` | loaded by loc_8c0500ac as a float |
| 0x0258 | 1 | `dhc_move_id` |  |
| 0x0259 | 1 | `unk259` | starts out as 0 set to 1 when you call assist when you do a team super, it gets set to 3 if you have 3 chars, 2 if you have 2, 1 if you have 1 decrements when your assist chars leave screen if it's greater than > 1 while thcing, you cant move |
| 0x0270 | ? | `unk270` | Used in Damage Calc |
| 0x0275 | 1 | `unk275` |  |
| 0x0298 | 4 | `x_opponent_distance` |  |
| 0x029e | ? | `unk29e` |  |
| 0x02a0 | 2 | `snapout_disable_timer` |  |
| 0x034e | 2 | `unk_034e` | compared using tst 0x0400 in omega red char programming, which indicates it might be bit flags? |
| 0x0411 | 1 | `unk_0411` | in damage_calc |
| 0x041c | 4 | `unk_041c_float` | loaded around loc_8c0518c6 and compared to y position **(confirmed here)** |
| 0x0420 | 2 | `health` |  |
| 0x0424 | 2 | `health2` | might be red health?? |
| 0x0440 | 2 | `UnkCpuData440` |  |
| 0x04c9 | 1 | `assist_type` |  |
| 0x0525 | 1 | `is_cpu` | Control_ID 0x524 if != 0, controlled by cpu **(confirmed here)** |
| 0x052d | 1 | `pal_id` |  |
| 0x0540 | 1 | `num_wins` | Char A & B Only |
| 0x0541 | 1 | `num_lose` |  |
| 0x0542 | 1 | `num_draw` |  |
| 0x0543 | 1 | `handicap_level` |  |

## Constants that show up in the pools

The game scales CPS2 coordinates, 384 by 224, to the 640 by 480 display, so two
ratios appear throughout the float pools and in values derived from them.

| Bits | Value | Exact | Meaning |
| --- | ---: | --- | --- |
| `0x3fd55555` | 1.6666666 | 5/3 | horizontal scale, 640/384 |
| `0x40092492` | 2.1428571 | 15/7 | vertical scale, 480/224 |

A pool float whose mantissa ends in `92492` is almost always one of these times
a power of two or a small multiple, so read it that way before assuming it is an
arbitrary constant. `tools/float_literal.py` gives the spelling that compiles to
exactly those bits.
