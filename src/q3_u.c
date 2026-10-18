typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

void func_001AFF40(u8 *p) {
    extern void func_001E3210();
    extern void func_001754A0();
    u8 *o;
    s32 n; u32 *d; u32 *s;
    u32 t;
    t = p[4];
    p[4] = t + 1;
    o = *(u8 **)(p + 0x18);
    d = (u32 *)(p + 0xEC);
    s = (u32 *)(o + 0xEC);
    n = 0x31;
    do {
        *d = *s;
        n--;
        s++;
        d++;
    } while (n > 0);
    p[0x13C] = 1;
    p[2] = o[2];
    p[1] = o[1];
    *(f32 *)(p + 0x50) = *(f32 *)(o + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(o + 0x54);
    p[0x1B7] = o[0x1B7];
    p[0x1B8] = o[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(o + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(o + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(o + 0x24);
    p[0x13C] = 1;
    p[0x24] = 0xE;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    *(f32 *)(p + 0x60) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(s16 *)(p + 0x1C) = 0x78;
    func_001E3210(*(u8 **)(p + 0x18), 0x26);
    func_001754A0(p, 0x1B, 9);
}
