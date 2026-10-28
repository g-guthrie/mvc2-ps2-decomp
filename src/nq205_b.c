typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3c;
typedef struct { s16 x, y; } P2;
typedef struct { s16 x, y, f; u8 a; u8 pad; } E8;
extern G3c *D_004C2794;
extern P2 D_004728C0[];
extern E8 D_004728E0[][4];
typedef struct { u8 pad0[0x34]; f32 f34, f38; u8 pad3c[0x104]; s16 f140; } SA;

void func_0039FDC0(u8 *o, u8 *a) {
    extern s32 func_00174170(void);
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_00174470(u8 *);
    extern s32 func_001745B0(u8 *);
    extern void func_003A00F0(u8 *, u8 *);
    extern void func_001E7F60(u8 *);
    u32 t;
    SA *sa = (SA *)o;
    u8 *q;
    E8 *e;
    s16 x, y;
    t = o[4];
    o[4] = t + 1;
    *(B3c *)(o + 0xEC) = *(B3c *)(a + 0xEC);
    q = o + 2;
    o[0x13C] = 1;
    *q = a[2];
    o[1] = a[1];
    *(f32 *)(o + 0x50) = *(f32 *)(a + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(a + 0x54);
    o[0x1B7] = a[0x1B7];
    o[0x1B8] = a[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(a + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(a + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(a + 0x24);
    o[0x24] = 0;
    o[0x1B0] = 0x40;
    o[0x1B1] = 0;
    o[0x1B5] = (func_00174170() & 1) + 0x5D;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = *q; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    *(s32 *)(o + 0xD0) = func_00174170() & 3;
    if (o[7] == 0) {
        x = D_004728C0[o[0x20]].x;
        y = D_004728C0[o[0x20]].y;
        if (sa->f140 != 0) x = -x;
        sa->f34 += 1.6666666269302368f * (f32)x;
        sa->f38 += 2.142857074737549f * (f32)y;
    }
    e = &D_004728E0[o[0x20]][*(s32 *)(o + 0xD0)];
    x = e->x;
    y = e->y;
    if (sa->f140 != 0) x = -x;
    sa->f34 += 1.6666666269302368f * (f32)x;
    sa->f38 += 2.142857074737549f * (f32)y;
    sa->f140 ^= e->f;
    func_001757E0(o, 0x15, e->a);
    o[0x14F] = 0x40;
    o[0x14E] = 0x40;
    o[0x14D] = 0x40;
    o[0x14C] = 0x40;
    if (func_00174470(o) == 0 || func_001745B0(o) == 0) {
        func_003A00F0(o, a);
    } else {
        func_001E7F60(o);
    }
}
