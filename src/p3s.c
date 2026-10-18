typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 a, b; } P2;
extern P2 *D_004C3AE4;
extern P2 *D_004C3AEC;

void func_00106240(s32 i, s32 x, s32 y) {
    s32 off = i * 8;
    if (i < 0) i = (s32)D_004C3AE4; else i = (s32)D_004C3AEC;
    off += i;
    *(s32 *)(off + 4) = y;
    *(s32 *)off = x;
}
