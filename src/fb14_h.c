typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* 0x003F5180 static copy (real body, verified in src/align_graphics_extent_003F5180.c) */
static u32 func_003F5180(const u8 *object, u32 value)
{
    u32 alignment;

    if (object[5] == 0)
        alignment = 16;
    else
        alignment = 128;
    if (value % alignment != 0)
        value += alignment - ((value - (value / alignment) * alignment) % alignment);
    return value;
}

/* 0x003F51F0 */
u8 *func_003F51F0(u8 *q, s32 n) {
    s32 i; u8 *o; u8 *r;
    o = q;
    q += func_003F5180(o, 0x10);
    r = q;
    for (i = 0; i < n; i++) {
        if (i >= *(u16 *)(o + 6)) break;
        q += func_003F5180(o, 0x30);
        q += *(u32 *)r;
        r = q;
    }
    return r;
}
