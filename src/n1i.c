typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;
extern s16 D_00449250[];

void func_00191B60(u32 *a, u32 *b) {
    u8 t;
    s16 v;
    *a = 0;
    *b = 0;
    t = *(s8 *)(D_004C2794 + 0x40) / 10;
    if (t > 9) t = 9;
    v = D_00449250[t];
    *b = v;
    if (v != 0) {
        *a = *b >> 8;
        *b = *b << 24;
    }
}
