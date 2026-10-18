typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void (*D_004C1C98[2])(void *);
extern s32 func_00372260(void *p);

s32 func_0036E220(u8 *p) {
    D_004C1C98[p[5]](p);
    if (p[1] != (*(u8 **)(p + 0x18))[1]) {
        return func_00372260(p);
    }
}
