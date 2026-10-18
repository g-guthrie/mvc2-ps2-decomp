typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct P {
    u8 pad0[6];
    u8 state;
    u8 pad1[0x34 - 7];
    f32 f34;
    f32 f38;
    u8 pad2[0x50 - 0x3C];
    f32 f50;
    u8 pad3[0x1E6 - 0x54];
    u8 b1E6;
    u8 pad4[0x430 - 0x1E7];
    f32 f430;
} P;

extern f32 D_004F1F4C[];
extern s32 func_00174470(P *);
extern void func_00185490(P *);
extern void func_001757E0(P *, s32, s32);

void func_0027EDE0(P *p) {
    extern s8 func_00175700(P *);
    f32 v;
    u32 t;
    u32 sw = p->state;
    switch (sw) {
    case 0:
        if (func_00174470(p) != 0) {
            p->state = 2;
        } else {
            p->state = 1;
            func_00185490(p);
            v = 106.66666412353516f * p->f50;
            if (p->b1E6 != 0) {
                v = -v;
            }
            p->f34 = D_004F1F4C[0] + v;
            p->f38 = p->f430;
            func_001757E0(p, 0, 4);
        }
        break;
    case 1:
        if (func_00175700(p) < 0) {
            t = p->state;
            p->state = t + 1;
        }
        break;
    case 2:
        p->state = sw + 1;
        func_001757E0(p, 0x13, 0);
        break;
    case 3:
        func_00175700(p);
        break;
    }
}
