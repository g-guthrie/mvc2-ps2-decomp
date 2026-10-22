typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

static void func_00193180(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    f32 f;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
    switch (p[0x20]) {
    case 0:
        f = 0.0f;
        break;
    case 1:
        f = 80.0f;
        break;
    case 2: {
        s16 v = *(s16 *)(p + 0x140) ^ 1;
        f = 80.0f;
        *(s16 *)(p + 0x140) = v;
        break;
    }
    }
    if (*(s16 *)(p + 0x140)) f = -f;
    *(f32 *)(p + 0x34) += f;
}

void func_00193210(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    s32 i;
    s32 *d;
    s32 *s;
    u32 t;
    t = p[4];
    p[4] = t + 1;
    d = (s32 *)(p + 0xEC);
    s = (s32 *)(*(u8 **)(p + 0x18) + 0xEC);
    i = 0x31;
    do {
        *d = *s;
        s++;
        d++;
        i--;
    } while (i > 0);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x13C] = 1;
    p[0x24] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    func_00193180(p);
    func_001757E0(p, 0x17, p[0x21] ? 0xC : 0xD);
}
