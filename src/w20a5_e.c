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
    u8 pad7[0x34 - 7];
    f32 f34;
    u8 pad38[0x5C - 0x38];
    f32 f5c;
    u8 pad60[0x68 - 0x60];
    f32 f68;
    u8 pad6c[0x151 - 0x6C];
    s8 b151;
    u8 pad152[0x1E6 - 0x152];
    u8 b1E6;
    u8 pad1E7[0x1FC - 0x1E7];
    u8 b1FC;
} P31C470;

void func_0031C470(P31C470 *p)
{
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_0019B110();
    extern void func_001E3210();
    extern void func_001E3710();
    s8 t;
    u32 *r1, *r2;
    f32 k;
    switch (p->b1FC) {
    case 0:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        }
        break;
    case 1:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        } else if (p->b151 != 0) {
            p->b151 = 0;
            func_0019B110(p, 2);
        }
        break;
    case 2:
        if (p->b6 == 0) {
            if ((p->b151 & 2) == 0) {
                p->f34 += p->f5c;
                p->f5c += p->f68;
            }
            if (func_00175700(p) < 0) {
                func_001843A0(p);
            } else if (p->b151 & 1) {
                *(u32 *)&p->f5c = 0;
                *(u32 *)&p->f68 = 0;
                func_001E3210(p, 0x20);
                func_0019B110(p, 3);
            }
        } else {
            if (func_00175700(p) < 0) {
                func_001843A0(p);
            } else {
                t = p->b151;
                if (t & 1) {
                    p->b151 = t ^ 1;
                    *(u32 *)&p->f5c = 0xC0FD5555;
                    *(u32 *)&p->f68 = 0x3E200000;
                    if (p->b1E6) {
                        p->f5c = -p->f5c;
                        p->f68 = -p->f68;
                    }
                    func_001E3710(p, 0x29);
                }
                r1 = (u32 *)&p->f5c;
                r2 = (u32 *)&p->f68;
                p->f34 += p->f5c;
                p->f5c += p->f68;
                t = p->b151;
                if (t & 2) {
                    p->b151 = t ^ 2;
                    *r1 = 0;
                    *r2 = 0;
                    k = -53.333332f;
                    if (p->b1E6) k = -k;
                    p->f34 += k;
                }
            }
        }
        break;
    }
}
