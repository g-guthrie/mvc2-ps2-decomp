typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


typedef struct { u8 pad0[0x22]; u8 b22; u8 pad23[0x15]; f32 f38; u8 pad3c[0x17B]; u8 b1b7; u8 pad1b8[0x56]; u16 h20e; u8 pad210[2]; u8 b212; } S6;
u8 *func_002BE610(u8 *actor) {
    S6 *p = (S6 *)actor;
    extern u8 *func_001E7FD0(u8 *);
    u8 a;
    s32 v = (p->h20e & 0xC00) >> 10;
    p->b22 = v;
    if ((u8)v != 0) {
        a = p->b212;
        if (a == 0) {
            if (p->b1b7 == 1 && !(p->f38 <= 137.14285278320312f)) {
                u8 *r;
                { u32 t = *(u8 *)((u8 *)p + 0x22); p->b22 = t ^ 3; }
                if ((r = func_001E7FD0((u8 *)p)) != 0) {
                    *(u8 *)((u8 *)p + 0x20B) = 2;
                    return r;
                }
                goto done;
            }
        }
        if (a == 1) {
            if (p->b1b7 == 1 && !(p->f38 <= 137.14285278320312f)) {
                u8 *r;
                if ((r = func_001E7FD0((u8 *)p)) != 0) {
                    *(u8 *)((u8 *)p + 0x20B) = 1;
                    return r;
                }
            }
        }
    }
done:
    return 0;
}

typedef struct { u8 pad0[6]; u8 b6; u8 pad7[0x15]; s16 h1c; u8 pad1e[0x16]; f32 f34, f38; u8 pad3c[0x20]; f32 f5c, f60, pad64, f68, f6c; u8 pad70[0x176]; u8 b1e6; } S7;
void func_0025E6A0(u8 *p) {
    extern void func_00176160();
    extern void func_001757E0();
    extern void func_00186A20();
    extern void func_001E3710();
    extern void func_0036BFF0();
    extern void func_00175700();
    f32 c;
    p[0x1E8] = 1;
    if (*(s8 *)(p + 0x153) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_00176160(p, 0, 1, 1);
        func_001757E0(p, 0x15, 3);
        p[7] = 0;
        if (p[0x20D] != 2) {
            func_00186A20(p);
            *(f32 *)(p + 0x38) = 21.42856979370117f + *(f32 *)(p + 0x430);
            if (p[0x1B7] != 0) {
                func_001757E0(p, 0x15, 6);
                p[7] = 3;
                if (*(s16 *)(p + 0x140) != 0) c = 133.33332824707031f; else c = -133.33332824707031f;
                *(f32 *)(p + 0x34) += c;
            }
        }
        *(s16 *)(p + 0x366) = 0;
        func_001E3710(p, 0x4B);
        func_0036BFF0(p, 10, 0x13, 10);
        func_0036BFF0(p, 9, 0x13, 9);
        func_0036BFF0(p, 0xB, 0x13, 0xB);
    }
    func_00175700(p);
}
