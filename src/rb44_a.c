typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x34];
    f32 f34;
    u8 pad38[0x5C - 0x38];
    f32 f5C;
    u8 pad60[0x68 - 0x60];
    f32 f68;
    u8 pad6C[0x140 - 0x6C];
    s16 h140;
    u8 pad142[0x151 - 0x142];
    s8 b151;
    u8 pad152[0x1FC - 0x152];
    u8 b1FC;
} PA;

void func_00310950(PA *p) {
    extern s32 func_00175700(PA *);
    extern void func_001843A0(PA *);
    extern void func_00183D90(PA *);
    extern void func_001DD8A0(PA *, s32, s32);
    f32 z;
    s32 t;
    switch (p->b1FC) {
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        }
        break;
    case 2:
        func_00183D90(p);
        if ((s8)func_00175700(p) < 0) {
            if (p->h140 == 0) {
                p->f34 += -66.66666412353516f;
            } else {
                p->f34 += 66.66666412353516f;
            }
            func_001843A0(p);
        } else {
            t = p->b151;
            if (t & 1) {
                p->b151 = t & ~1;
                p->f5C = -16.66666603088379f;
                p->f68 = 0.8333587646484375f;
                if (p->h140 != 0) {
                    p->f5C = -p->f5C;
                    p->f68 = -p->f68;
                }
            }
            t = p->b151;
            if (t & 2) {
                p->b151 = t & ~2;
                func_001DD8A0(p, 9, 2);
            }
            z = 0.0f;
            if (p->f5C * p->f68 > z) {
                p->f5C = z;
                p->f68 = z;
            }
        }
        break;
    }
}
