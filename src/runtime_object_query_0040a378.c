/* Dispatch object queries and explicitly forward the object to every native getter. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

s32 func_0040A378(void *object, s32 a1)
{
    s32 r = 0;
    extern s32 func_0040A2F8(s32 *);
    extern s32 func_0040A310(const u8 *);
    extern s32 func_0040A338(u32 *);
    extern s32 func_0040A350(const u8 *);

    if (object == 0) {
        return 0;
    }
    switch (a1) {
    case 0xC8: r = func_0040A2F8(object); break;
    case 0xC9: r = func_0040A310(object); break;
    case 0xCA: r = func_0040A338(object); break;
    case 0xCB: r = func_0040A350(object); break;
    case 0xCC: r = func_0040A338(object); break;
    case 0xCD: r = func_0040A350(object); break;
    case 0x12B: r = 1; break;
    }
    return r;
}
