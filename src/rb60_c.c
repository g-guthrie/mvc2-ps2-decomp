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
static u8 *func_003F51F0(u8 *q, s32 n) {
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

typedef struct { s32 *a[7]; } A5270;
extern A5270 D_0062C7C0;

s32 func_003F5270(u8 *p, s32 unused, s32 n) {
    A5270 loc = D_0062C7C0;
    s32 i;
    s32 len;
    s32 pos;
    u8 *q;
    s32 sum;
    s32 t;
    pos = (s32)func_003F51F0(p, 0);
    q = (u8 *)pos;
    len = func_003F5180(p, 0x30);
    pos += len;
    if (q[0x11] > 1) {
        for (i = 0; i < 7 || i < q[0x11]; i++) {
            loc.a[i] = (s32 *)(pos + ((u32)i << 2) + 0x10);
        }
        t = func_003F5180(p, (q[0x11] < 5) ? 0x20 : 0x30);
        pos += t;
        len += t;
    }
    if (len < *(u16 *)(q + 0xC)) {
        pos += func_003F5180(p, 0x10);
    }
    if (q[0x11] > 1) {
        sum = 0;
        for (i = 0; i < n; i++) sum += *loc.a[i];
        pos += sum;
    }
    return pos;
}
