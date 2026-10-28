typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004BAC60[];

static unsigned int *func_003F1F00(void *file) { return file; }

s32 func_003F2A50(u8 *a, s32 b, u32 c)
{
    extern void func_003ED0D0(u8 *);
    extern u32 *func_003F1F10(s32, s32);
    extern u8 *func_003F19B0(s32, u32);
    extern s16 func_003F1E10(s32, u32);
    extern s32 func_003F2B70(u8 *, u8 *);
    u32 *t;
    u8 *o;

    if ((*func_003F1F00((void *)b) & 1) == 0) {
        func_003ED0D0(D_004BAC60);
        return 0;
    }
    if ((t = func_003F1F10(b, 1)) == 0) {
        return 0;
    }
    if (t[1] <= c) {
        return 0;
    }
    if ((o = func_003F19B0(b, c)) == 0) {
        return 0;
    }
    switch (*o) {
    case 1: case 3: case 4: case 5:
        return 0;
    case 2:
        *(s16 *)(a + 0x20) = func_003F1E10(b, c);
        return func_003F2B70(a, o);
    }
    return 0;
}
