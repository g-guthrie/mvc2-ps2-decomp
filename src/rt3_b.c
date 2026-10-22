typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct Q19E {
    u8 pad0[4];
    u8 b4;
    u8 pad5[0x20 - 5];
    u8 b20, b21;
    u8 pad22[0x34 - 0x22];
    f32 f34, f38;
    u8 pad3c[0x168 - 0x3C];
    u16 h168;
} Q19E;

typedef struct P19E {
    u8 pad0[4];
    u8 b4;
    u8 pad5[0x14 - 5];
    Q19E *q;
    u8 pad18[0x21 - 0x18];
    u8 b21;
    u8 pad22[0x31 - 0x22];
    s8 b31;
    u8 pad32[0x34 - 0x32];
    f32 f34, f38;
    u8 pad3c[0x13C - 0x3C];
    u8 b13C;
} P19E;

void func_0019EE00(P19E *p, s32 r) {
    extern void func_0019EDD0();
    extern void func_00175700(P19E *);
    extern void func_0019F3A0(P19E *, s32);
    Q19E *q = p->q;
    u32 t;
    p->b13C = 0;
    if (q->b4 != 1) {
        t = p->b4;
        p->b4 = t + 1;
        return;
    }
    if (p->b21 == 0) {
        if (q->b20 != 1 || q->b21 != 0) {
            t = p->b4;
            p->b4 = t + 1;
            return;
        }
        if (q->h168 != 0x1718) {
            t = p->b4;
            p->b4 = t + 1;
            return;
        }
        func_0019EDD0(p, r);
    } else {
        p->b31 = -1;
        p->f34 = q->f34;
        p->f38 = 21.428569793701172f + q->f38;
    }
    func_00175700(p);
    func_0019F3A0(p, r);
}
