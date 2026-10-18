typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_0016A930(u8 *, u8 *, u32);
typedef struct { u8 pad[0x10]; u8 p, q; u8 pad2[10]; } E;
extern s32 func_0028A530();
extern s32 func_0028B0B0();
static s32 func_0028A490() { return 1; }
s32 func_0028A4F0(u8 *a, u8 *b) {
    if (func_0028A490(a, b)) {
        a[7] = 6;
        b[0x18] = 0;
        return func_0028A530();
    } else {
        return func_0028B0B0();
    }
}
