typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 b21;
    u8 pad22[0x15B - 0x22];
    u8 b15B;
    u8 pad15C[0x1E4 - 0x15C];
    u8 b1E4;
    u8 pad1E5[0x33A - 0x1E5];
    u8 b33A;
} P2DD;

void func_002DDCE0(P2DD *p)
{
    extern s32 func_003D92F0(P2DD *);
    extern void func_001843A0(P2DD *);
    extern void func_00175700(P2DD *);
    extern void func_001E3210(P2DD *, s32);
    extern void func_001757E0(P2DD *, s32, s32);
    s32 s;
    s32 t;

    if (p->b1E4 == 0x16 && func_003D92F0(p) != 0) {
        func_001843A0(p);
        return;
    }
    switch (p->b20) {
    case 0:
        if ((p->b21 & 0x7F) != 2) {
            p->b33A = 0xFF;
        }
        if ((p->b21 & 0x7F) == 1) {
            func_00175700(p);
            if ((p->b21 & 0x80) != 0) {
                p->b21 = 3;
                func_001E3210(p, 0x11);
                func_001757E0(p, 0x13, 2);
            }
        } else {
            if (p->b15B != 0) {
                p->b15B = 0;
                t = p->b21;
                if (t != 0) {
                    s = 0xF;
                }
                if ((u8)t == 2) {
                    s = 0x10;
                }
                func_001E3210(p, (u8)s);
            }
            func_00175700(p);
        }
        break;
    case 2:
    case 1:
    case 3:
    case 4:
        func_00175700(p);
        break;
    default:
        break;
    }
}
