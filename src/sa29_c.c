typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[4];
    u8 b4;
    u8 b5;
    u8 b6;
    u8 pad7[0x1D];
    s8 b24;
    u8 pad25[0xB];
    s8 b30;
    u8 b31;
    u8 pad32[6];
    f32 f38;
    u8 pad3C[0xD0 - 0x3C];
    s8 d[8];
} TA;

extern void (*D_00472B58[])(TA *, TA *);

void func_003A25E0(TA *p, TA *q) {
    extern void func_003A2AE0(void);
    extern int func_00174470(const void *);
    extern void func_003DAA40(TA *);
    extern void func_001757E0(TA *, s32, s32);
    s8 *d;
    s8 *r;
    s8 *e;
    s8 *r2;
    s8 t;
    if (p->b4 == 0) {
        func_003A2AE0();
        p->d[4] = 11;
        p->d[5] = 0;
        *(f32 *)((u8 *)p + 0xD0) = p->f38 - 17.14285659790039f;
        p->b6 = 1;
        if (func_00174470(p) == 0) {
            func_003DAA40(p);
            return;
        }
        func_001757E0(p, 0x16, 3);
        *(s8 *)((u8 *)p + 0x31) = -8;
    }
    d = p->d;
    r = d + 4;
    t = d[4] - 1;
    d[4] = t;
    if (t < 0) *r = 11;
    e = p->d;
    r2 = e + 5;
    t = e[5];
    if (t != 0) *r2 = t - 1;
    p->b24 = q->b24;
    D_00472B58[p->b5](p, q);
}
