typedef signed char s8;
typedef unsigned short u16;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
/* 28-byte record, same layout as data_rec_00442B50: func_00147B70 indexes list + p[0x20]*28 and reads
   lwc1 0/4/8 (position -> p+0x34), lwc1 0xC/0x10/0x14 (-> p+0x78..0x80), lhu 0x18 (-> p+0xCC) and
   lb 0x1B (index into D_004435C8); func_00147920 tests lb 0x1A & 0x80 in the sibling lists. */
typedef struct { V3 pos; V3 col; u16 id; s8 flags; s8 slot; } LightListRec;
typedef char LightListRec_size[(sizeof(LightListRec) == 28) ? 1 : -1];
/* Target of jtbl_00443984[9]. */
LightListRec data_rec_004438D0[5] = {
    { { -9.14f, 6.5f, -13.0f }, { 1.0f, 1.0f, 1.0f }, 0x007F, 0, 1 },
    { { -9.14f, 6.5f, -13.01f }, { 1.0f, 1.0f, 1.0f }, 0x0080, 0, 1 },
    { { 0.0f, 0.0f, 0.0f }, { 1.0f, 0.1f, 0.1f }, 0x0051, 0, 0 },
    { { 0.0f, 0.0f, 0.0f }, { 0.8f, 0.0f, 0.0f }, 0x0052, 0, 0 },
    { { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f }, 0x0124, 0, 0 },
};
