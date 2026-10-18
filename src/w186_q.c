typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 p0[5];
    u8 b5;
    u8 p6[0x34 - 6];
    f32 f34;
    f32 f38;
    u8 p3c[0x5C - 0x3C];
    f32 f5c;
    f32 f60;
    u32 u64;
    f32 f68;
    f32 f6c;
    u8 p70[0x151 - 0x70];
    s8 b151;
} P1D3;

typedef struct {
    u8 p0[0x21];
    u8 b21;
    u8 p22[0x34 - 0x22];
    f32 f34;
    u8 p38[0x151 - 0x38];
    s8 b151;
    u8 p152[0x1E6 - 0x152];
    u8 b1E6;
} Q1D3;

void func_001D30B0(P1D3 *p, Q1D3 *q) {
    extern void func_00175700();
    extern void func_001757E0();
    f32 *s0;
    f32 *s1;
    f32 d, thr;
    switch (p->b5) {
    case 0:
        s0 = &p->f5c;
        s1 = &p->f68;
        p->f34 += p->f5c;
        p->f5c += p->f68;
        func_00175700(p);
        d = p->f34 - q->f34;
        if (d < 0.0f) d = -d;
        thr = 106.66666412353516f;
        if (d < thr) {
            u32 t = p->b5;
            p->b5 = t + 1;
            if (q->b1E6 != 0) thr = -thr;
            p->f34 = q->f34 + thr;
            *(u32 *)s0 = 0;
            p->f60 = 0;
            *(u32 *)s1 = 0;
            p->f6c = 0;
            func_001757E0(p, 0x17, 0x1D);
        }
        break;
    case 1:
        if (q->b151 == 0) {
            func_00175700();
            if (p->b151 != 0) {
                u32 t = p->b5;
                p->b5 = t + 1;
                p->b151 = 0;
                t = q->b21;
                q->b21 = t | 0x80;
            }
        }
        break;
    case 2:
        func_00175700();
        break;
    }
}
