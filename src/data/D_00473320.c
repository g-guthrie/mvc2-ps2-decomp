typedef unsigned short u16;
/* 0x20-byte record: func_003AA4D0, func_003AAE20, func_003AB950, func_003ABB40 and
 * func_003ACEB0 store its address in actor +0x164 and then read the u16 at +0x12 through it
 * (lhu, scaled by 16 into actor +0x1D4). The next object, data_u8_00473340, has its own
 * reader, so the record ends there. */
typedef struct { u16 h[16]; } Rec_00473320;
Rec_00473320 D_00473320 = { {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x002E, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
} };
