typedef signed short s16;
typedef signed int s32;
typedef float f32;

/* Effect data block for the task family at 0x00159xxx-0x0015Axxx. Every member
 * is reached through its own address (D_00444EF0, D_00444F10, D_00444F20,
 * D_00444F40, D_00444F60, D_00444F80, D_00444F90, D_00444FB0, D_00444FC0,
 * D_00444FE0); nothing addresses the unit start. Members and reader widths:
 *
 * offset[2] (D_00444EF0): func_00159F50 (0x00159F50, lui/addiu 0x00159FAC-FB4)
 * selects entry s0 with s0 * 12 (sll/addu 0x00159FA8-FB8) and copies three f32
 * (lwc1 +0/+4/+8, 0x00159FEC-FF4) to the task's 0x5C/0x60/0x64 vector.
 * ScaleKey tables (keys[] of {s32 frame, f32 value}, 8 bytes): D_00444F10,
 * D_00444F20 (func_00159EA0, 0x00159ECC-F18), D_00444F40, D_00444F60
 * (0x0015A04C-A098), D_00444F80, D_00444F90 (0x0015A1EC-A254) and D_00444FB0,
 * D_00444FC0 (0x0015A35C-A3C4) are each passed as the first argument of
 * func_00154710 (the keyframe interpolator in src/frame_scale_updates.c, which
 * reads lw +0, lwc1 +4, lw +8, lwc1 +0xC of the current and next key). Key
 * counts follow the next referenced address.
 * sprite[4] (D_00444FE0): func_0015A720 (0x0015A720) loads it with lh +0 at a
 * byte offset advancing by 4 (addu 0x0015A810, lh 0x0015A834, addiu s3 += 4 at
 * 0x0015A914); the high halfword of each word is never read and is zero.
 * The 8-byte zero members pad_* are alignment gaps between tables (the next
 * table starts 16-byte aligned); no reader touches them. */
typedef struct {
    s32 frame;
    f32 value;
} DataScaleKey;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} DataVec3;
typedef struct {
    s16 id;
    s16 unread_02;
} DataSpriteId;
typedef struct {
    DataVec3 offset[2];       /* 0x00444EF0 */
    s32 pad_18[2];            /* 0x00444F08 */
    DataScaleKey key_10[2];   /* 0x00444F10 */
    DataScaleKey key_20[3];   /* 0x00444F20 */
    s32 pad_38[2];            /* 0x00444F38 */
    DataScaleKey key_40[3];   /* 0x00444F40 */
    s32 pad_58[2];            /* 0x00444F58 */
    DataScaleKey key_60[3];   /* 0x00444F60 */
    s32 pad_78[2];            /* 0x00444F78 */
    DataScaleKey key_80[2];   /* 0x00444F80 */
    DataScaleKey key_90[3];   /* 0x00444F90 */
    s32 pad_A8[2];            /* 0x00444FA8 */
    DataScaleKey key_B0[2];   /* 0x00444FB0 */
    DataScaleKey key_C0[3];   /* 0x00444FC0 */
    s32 pad_D8[2];            /* 0x00444FD8 */
    DataSpriteId sprite[4];   /* 0x00444FE0 */
} Data00444EF0;
typedef char data_rec_00444EF0_size_check[(sizeof(Data00444EF0) == 0x100) ? 1 : -1];

Data00444EF0 data_rec_00444EF0 = {
    { { -4.33f, 0.0f, 2.5f }, { 4.33f, 0.0f, 2.5f } },
    { 0 },
    { { 0, 1.0f }, { 20, 0.0f } },
    { { 0, 1.0f }, { 8, 1.0f }, { 13, 0.0f } },
    { 0 },
    { { 0, 0.0f }, { 8, 2.0f }, { 20, 8.0f } },
    { 0 },
    { { 0, 1.0f }, { 8, 1.0f }, { 13, 0.0f } },
    { 0 },
    { { 0, 0.0f }, { 20, 240.0f } },
    { { 0, 1.0f }, { 8, 1.0f }, { 13, 0.0f } },
    { 0 },
    { { 0, 0.0f }, { 20, -240.0f } },
    { { 0, 1.0f }, { 8, 1.0f }, { 13, 0.0f } },
    { 0 },
    { { 96, 0 }, { 97, 0 }, { 98, 0 }, { 100, 0 } }
};
