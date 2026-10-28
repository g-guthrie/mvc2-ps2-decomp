typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* func_0016A210 (src/luna_a_mask_lookup.c) returns
 * D_004461C0[object->type] & (1 << index) (lhu, stride 2, type = lbu 0x1E4).
 * No reader bounds the index; sized to the zero block at 0x004461E0. */
u16 D_004461C0[16] = {
    0x803Fu, 0x803Fu, 0x001Au, 0x809Eu, 0x803Fu, 0x803Fu, 0x803Fu, 0x803Fu,
    0x803Fu, 0x803Fu, 0x803Fu, 0x003Du, 0x0000u, 0x001Au, 0x809Eu, 0x8012u
};
