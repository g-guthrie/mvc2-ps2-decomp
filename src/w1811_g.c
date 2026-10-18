typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[6];
    u8 b6;
    u8 b7;
    u8 pad8[0x1C - 8];
    s16 s1C;
    u8 pad1E[0x34 - 0x1E];
    f32 f34;
    f32 f38;
    u8 pad3C[0x64 - 0x3C];
    f32 f64;
    u8 pad68[0x70 - 0x68];
    f32 f70;
    u8 pad74[0xD0 - 0x74];
    s32 d0;
    s32 d4;
    u8 pad_d8[0x1E4 - 0xD8];
    u8 b1E4;
    u8 pad1E5[0x1FD - 0x1E5];
    u8 b1FD;
} O;

void func_001AA6C0(O *p, O *q) {
    extern void func_001757E0(O *, s32, s32);
    extern void func_00175700(O *);
    s16 v;
    u32 t;
    if (q->b1E4 != 0x1D || q->b1FD != 4) {
        p->d0 = p->b6;
        p->d4 = p->b7;
        p->b6 = 0x10;
        p->b7 = 0;
    } else {
        p->f34 += (p->f64 - p->f34) / (f32)p->s1C;
        p->f38 += (p->f70 - p->f38) / (f32)p->s1C;
        v = p->s1C - 1;
        p->s1C = v;
        if (v == 0) {
            t = p->b7;
            p->b7 = t + 1;
            func_001757E0(p, 0x17, 0);
        }
        func_00175700(p);
    }
}
