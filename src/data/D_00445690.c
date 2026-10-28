typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* func_00160F90 (src/g2g.c) bounds field 0x1C to < 0x16 and loads
 * D_00445690[i].id (lh, stride 4 at 0x00160FB8..C4). The second halfword of
 * each entry is not read. */
typedef struct { s16 id; s16 unused; } IdEntry;
typedef char IdEntry_size_check[(sizeof(IdEntry) == 4) ? 1 : -1];
IdEntry D_00445690[22] = {
    { 222, 0 },
    { 222, 0 },
    { 222, 0 },
    { 223, 0 },
    { 223, 0 },
    { 223, 0 },
    { 224, 0 },
    { 224, 0 },
    { 225, 0 },
    { 225, 0 },
    { 226, 0 },
    { 226, 0 },
    { 227, 0 },
    { 228, 0 },
    { 229, 0 },
    { 230, 0 },
    { 231, 0 },
    { 232, 0 },
    { 233, 0 },
    { 234, 0 },
    { 235, 0 },
    { 236, 0 }
};
