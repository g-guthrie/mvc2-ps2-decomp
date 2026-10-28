typedef signed char s8;
typedef unsigned short u16;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
/* 28-byte record, same layout as data_rec_00442B50: func_00147B70 indexes list + p[0x20]*28 and reads
   lwc1 0/4/8 (position -> p+0x34), lwc1 0xC/0x10/0x14 (-> p+0x78..0x80), lhu 0x18 (-> p+0xCC) and
   lb 0x1B (index into D_004435C8); func_00147920 tests lb 0x1A & 0x80 in the sibling lists. */
typedef struct { V3 pos; V3 col; u16 id; s8 flags; s8 slot; } LightListRec;
typedef char LightListRec_size[(sizeof(LightListRec) == 28) ? 1 : -1];
/* Target of jtbl_00443984[7,8]. */
LightListRec data_rec_00443840[5] = {
    { { -9.0f, 6.52f, -13.1f }, { 1.0f, 1.0f, 1.0f }, 0x0002, 0, 1 },
    { { -9.0f, 6.52f, -13.09f }, { 1.0f, 1.0f, 1.0f }, 0x0003, 0, 1 },
    { { 0.0f, 6.55f, -13.11f }, { 1.0f, 1.0f, 1.0f }, 0x0000, 0, 0 },
    { { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f }, 0x0001, 0, 0 },
    { { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f }, 0x0026, 0, 0 },
};
