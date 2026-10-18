typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct O {
    u8 pad0[6];
    u8 b6;
    u8 pad7[0x34 - 7];
    f32 f34;
    f32 f38;
    u8 pad3C[0x5C - 0x3C];
    f32 f5C;
    f32 f60;
    u8 pad64[0x68 - 0x64];
    f32 f68;
    f32 f6C;
    u8 pad70[0x1B2 - 0x70];
    s8 b1B2;
    u8 pad1B3[0x1E6 - 0x1B3];
    u8 b1E6;
} O;

void func_002BA310(O *p) {
    extern void func_00175700(O *);
    extern void func_002BA590(O *);
    extern void func_001757E0(O *, s32, s32);
    f32 *a3, *t0;
    u32 t;
    func_00175700(p);
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    a3 = &p->f5C;
    t0 = &p->f68;
    if ((p->b1E6 == 0 && p->f5C > 0.0f) || (p->b1E6 != 0 && p->f5C < 0.0f)) {
        *a3 = 0.0f;
        *t0 = 0.0f;
    }
    if (p->b1B2 != 0) {
        func_002BA590(p);
        return;
    }
    if (p->f60 <= 0.0f) {
        t = p->b6;
        p->b6 = t + 1;
        *a3 = 0.0f;
        *t0 = 0.0f;
        func_001757E0(p, 0x15, 3);
    }
}
