typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

extern void func_00176160(u8 *, s32, s32, s32);
extern void func_001BEDE0(u8 *, s32);
extern void func_002F4390(u8 *, u8 *, s32);
extern void func_002F4A50(u8 *, u8 *, s32);
extern void (*D_0043CC70[])(s32);
extern s32 D_004BEDC0[];

void func_0012AC90(s32 a0, s32 a1) { D_0043CC70[a0](a1); }

s32 func_00416770(u8 *p, s32 a1) { return (D_004BEDC0[*(s32 *)(p + 0x14)] * a1) >> 3; }

s32 func_00420B00(u8 *p) {
    **(u64 **)p = ((u64)0x10000000 << 32) | *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = 0;
    return 1;
}

void func_001BEDB0(u8 *p, s32 a1) {
    p[5]++;
    *(s16 *)(p + 0x1C) = 10;
    *(s32 *)(p + 0x118) = 0x3F800000;
    *(s32 *)(p + 0x54) = 0x3F800000;
    *(s32 *)(p + 0x50) = 0x3F800000;
    func_001BEDE0(p, a1);
}

void func_002EE450(u8 *p, s32 a1) {
    s32 t;
    s32 i = (p[0x25] << 3) + a1;
    t = *(s32 *)(p + 0x2FC);
    *(s32 *)(p + 0x2FC) = t + 1;
    func_00176160(p, 0, t + i, 1);
}

void func_002F4360(u8 *p, u8 *q) {
    *(u16 *)(p + 0x35E) = *(u16 *)(q + 0x14);
    p[0x1E6] ^= q[0x11];
    *(u16 *)(p + 0x140) = p[0x1E6];
    func_002F4390(p, q, q[0x16]);
}

void func_002F4A20(u8 *p, u8 *q) {
    *(u16 *)(p + 0x35E) = *(u16 *)(q + 0x14);
    p[0x1E6] ^= q[0x11];
    *(u16 *)(p + 0x140) = p[0x1E6];
    func_002F4A50(p, q, q[0x16]);
}

u32 func_0035AEA0(u8 *p, u8 a1, u8 a2) {
    if (p[0xE] != 0) return p[0xE];
    p[0xE] = a1;
    p[0xF] = a2;
    return 0;
}
