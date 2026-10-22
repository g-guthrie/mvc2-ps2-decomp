typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 a, b; u8 c, d; } R;
extern s8 data_s8_004ACD08[];
extern R D_0044C0E0[];

void func_001BCB60(u8 *p, u8 *q) {
    extern s32 func_00174170(void);
    extern void func_00175580(u8 *, s32, s32, s32);
    extern void func_001BCCE0(u8 *, u8 *);
    R *e;
    u32 t;
    t = p[5];
    p[5] = t + 1;
    p[0x13D] = 1;
    *(s16 *)(p + 0x13E) = data_s8_004ACD08[q[0x1B8]];
    *(s16 *)(p + 0x1C) = (func_00174170() & 0x1F) + 0x3C;
    *(s32 *)(p + 0x118) = 0;
    *(u32 *)(p + 0x64) = 0x3C4CCCCD;
    e = &D_0044C0E0[p[0x20]];
    *(f32 *)(p + 0x5C) = 1.6666666269302368f * (f32)(e->a + (s16)(func_00174170() & 0x3F));
    *(f32 *)(p + 0x60) = 2.142857074737549f * (f32)(e->b + (s16)(func_00174170() & 0x3F));
    e = &D_0044C0E0[p[0x20]];
    t = (u8)(e->d + (u32)func_00174170() % 3);
    func_00175580(p, 0x1B, t, (u32)func_00174170() % 10);
    func_001BCCE0(p, q);
}
