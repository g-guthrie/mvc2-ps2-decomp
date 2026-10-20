typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_0016A930(u8 *, u8 *, u32);
typedef struct { u8 pad[0x10]; u8 p, q; u8 pad2[10]; } E;
extern s32 func_0028A530(u8 *p, u8 *q);
extern s32 func_0028B0B0();
static s32 func_0028A490(u8 *p) {
    u8 state = p[0x1E6];
    u8 *owner = *(u8 **)(p + 0x220);
    if ((state == 0 && *(f32 *)(p + 0x34) < *(f32 *)(owner + 0x34)) ||
        (state != 0 && *(f32 *)(p + 0x34) > *(f32 *)(owner + 0x34))) {
        return 1;
    }
    return 0;
}
s32 func_0028A4F0(u8 *a, u8 *b) {
    if (func_0028A490(a)) {
        a[7] = 6;
        b[0x18] = 0;
        return func_0028A530(a, b);
    } else {
        return func_0028B0B0();
    }
}
