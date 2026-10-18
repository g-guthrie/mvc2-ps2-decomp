typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_001891F0(u8 *, s32);
extern void func_00186A60(u8 *, s32);
extern s32 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_0025D8E0(void);
extern void func_003266E0(u8 *);



void func_00349700(u8 *p, u8 *q) {
    if (q[0x1E4] == 0x1D) {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + *(f32 *)(p + 0x60);
    }
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}

void func_00323AF0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_003266E0(p);
    } else if (p[0x15B]) {
        f32 v = -6.666666508f;
        if (*(s16 *)(p + 0x140) != 0) v = -v;
        *(f32 *)(p + 0x34) += v;
    }
}

extern void func_0030C470(void);
extern void func_003BA230(u8 *, s32, u8);
extern s32 func_00309310(u8 *);

s32 func_00309E80(u8 *p) {
    u8 i;
    if (p[0x1FC] == 2 && *(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_0030C470();
        for (i = 0; i < 6; i++) func_003BA230(p, 3, i);
    }
    return func_00309310(p);
}
