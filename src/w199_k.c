typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern s8 D_004ACD08[];
typedef struct { s16 x, y; u8 z, w; } W199E;
extern W199E D_0044C0E0[];

void func_001BCF60(u8 *p, u8 *q) {
    extern u32 func_00174170();
    extern void func_00175580();
    extern void func_001BCCE0();
    u32 t;
    u32 r;
    u32 s;
    W199E *e;
    W199E *f;
    t = p[5];
    p[5] = t + 1;
    p[0x31] = 1;
    *(s8 *)(p + 0x13D) = -1;
    *(s16 *)(p + 0x13E) = D_004ACD08[q[0x1B8]];
    r = func_00174170();
    *(s16 *)(p + 0x1C) = (r & 0x1F) + 0x3C;
    *(u32 *)(p + 0x118) = 0;
    *(u32 *)(p + 0x64) = 0x3C4CCCCD;
    f = &D_0044C0E0[p[0x20]];
    *(f32 *)(p + 0x5C) = 1.666666627f * (f32)f->x;
    *(f32 *)(p + 0x60) = 2.142857075f * (f32)f->y;
    e = &D_0044C0E0[p[0x20]];
    r = func_00174170();
    s = r % 3;
    s = (u8)(e->w + s);
    r = func_00174170();
    func_00175580(p, 0x1B, s, r % 10);
    func_001BCCE0(p, q);
}
