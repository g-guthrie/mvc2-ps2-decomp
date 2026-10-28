typedef int s32;
typedef unsigned int u32;
extern u32 data_u32_00450DE0[];
/* func_00218910 (0x00218914 gp_rel) picks entry [a1] (sll 2, lw), then reads
 * 16-byte rows of 16.16 fixed-point s32 (row = actor byte +0x1B7, lwc1 + cvt.s.w).
 * Both targets lie inside the still-untyped data_u32_00450DE0 (+0x70 and +0x90). */
s32 *D_004BFEE8[2] = {
    (s32 *)&data_u32_00450DE0[0x70 / 4],
    (s32 *)&data_u32_00450DE0[0x90 / 4],
};
