typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

struct S40BD;

s32 func_0040BDC8(void *object, s32 a1)
{
    s32 r = 0;
    extern s32 func_0040BD48(struct S40BD *);
    extern s32 func_0040BD68(u8 *);
    extern s32 func_0040BD98(u32 *);
    extern s32 func_0040BDB0(u32 *);

    if (object == 0) {
        return 0;
    }
    switch (a1) {
    case 0xC8: r = func_0040BD48(object); break;
    case 0xC9: r = func_0040BD68(object); break;
    case 0xCA: r = func_0040BD98(object); break;
    case 0xCB: r = func_0040BDB0(object); break;
    case 0xCC: r = func_0040BD98(object); break;
    case 0xCD: r = func_0040BDB0(object); break;
    case 0x12B: r = 1; break;
    }
    return r;
}
