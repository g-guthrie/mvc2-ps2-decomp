typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_004C1F60[8];

void func_003AFE10(u8 *o, u8 *q) {
    extern s32 fptosi(f32);
    extern void func_00175700();
    extern void func_00174910(u8 *, s32);
    extern void func_001E3210(u8 *, s32);
    u8 *t;
    s16 *s;
    u8 *e;
    u32 c;
    u8 *f;

    t = q + 0x2B8;
    s = (s16 *)(o + 0xD0);
    if (t[o[0x21]] == 0) {
        o[4] = 3;
        return;
    }
    switch (q[5]) {
    case 0:
        break;
    default:
        o[4] = 2;
        o[6] = 1;
        o[7] = 0;
        t[o[0x21]] = 0;
        return;
    }
    func_00175700();
    if (*(s16 *)(o + 0x140) != *(s16 *)(q + 0x140)) {
        *(s16 *)(o + 0x140) = *(s16 *)(q + 0x140);
        o[0x22] = D_004C1F60[o[0x21]];
        if (*(s16 *)(q + 0x140) != 0) {
            o[0x22] = 0x20 - *(s8 *)(o + 0x22);
            o[0x22] &= 0x1F;
        }
    }
    s[0] = fptosi(*(f32 *)(q + 0x34));
    s[1] = fptosi(137.14285278320312f + *(f32 *)(q + 0x38));
    *(f32 *)(o + 0x34) = s[0];
    *(f32 *)(o + 0x38) = s[1];
    *(u32 *)(o + 0x5C) = 0;
    *(u32 *)(o + 0x60) = 0;
    *(u32 *)(o + 0x68) = 0;
    *(u32 *)(o + 0x6C) = 0;
    func_00174910(o, 0x1900);
    e = (u8 *)(o[0x21] + (u32)t);
    f = e + 6;
    if (e[6] != 0) {
        *f = 0;
        t[o[0x21]] = 0;
        c = o[5];
        o[5] = c + 1;
        o[6] = 0;
        o[7] = 0;
        func_001E3210(q, 0x21);
        return;
    }
    if (t[0xC] == 0)
        return;
    e[0] = 0;
    o[0x1B7] = q[0x1B7];
    switch (o[0x1B7]) {
    case 0:
        o[6] = 1;
        break;
    case 1:
        o[6] = 1;
        break;
    case 2:
        o[6] = 2;
        break;
    default:
        o[6] = 3;
        break;
    }
    c = o[5];
    o[5] = c + 1;
    o[7] = 0;
    func_001E3210(q, 0x21);
}
