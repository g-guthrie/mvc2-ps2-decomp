typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct PA {
    u8 _p0[6];
    u8 b6;
    u8 _p1[0x1C - 7];
    s16 h1c;
    u8 _p2[0x34 - 0x1E];
    f32 f34;
    u8 _p3[0x5C - 0x38];
    f32 f5c;
    u8 _p4[0x68 - 0x60];
    f32 f68;
    u8 _p5[0x151 - 0x6C];
    s8 b151;
    u8 _p6[0x1B2 - 0x152];
    s8 b1b2;
    u8 _p7[0x1B7 - 0x1B3];
    u8 b1b7;
    u8 _p8[0x1E6 - 0x1B8];
    u8 b1e6;
    u8 _p9[0x209 - 0x1E7];
    u8 b209;
} PA;

extern f32 D_0045AB70[];
extern f32 D_0045AB74[];

void func_002DDF40(PA *p)
{
    extern void func_001D1EB0(PA *);
    extern void func_001D20B0(PA *, s32, s32);
    extern void func_00175700(PA *);
    extern void func_001757E0(PA *, s32, u8);
    s16 h;
    u32 t;
    s32 c;

    p->b209 = 2;
    if (p->b151 != 0) {
        p->b151 = 0;
        p->f5c = *(f32 *)((u8 *)D_0045AB70 + (p->b1b7 << 3));
        p->f68 = *(f32 *)((u8 *)D_0045AB74 + (p->b1b7 << 3));
        if (p->b1e6 != 0) {
            p->f5c = -p->f5c;
            p->f68 = -p->f68;
        }
        func_001D1EB0(p);
        func_001D20B0(p, 1, 0);
        func_001D20B0(p, 1, 1);
    }
    if (p->b1b2 != 0) {
        if (((s8)p->b1b2 & 1) != 0) {
            p->h1c = 1;
        }
    }
    func_00175700(p);
    h = p->h1c - 1;
    p->h1c = h;
    if (h == 0) {
        t = p->b6;
        p->b6 = t + 1;
        p->b209 = 0;
        if (p->b1b2 != 0 && ((s8)p->b1b2 & 1) == 0) {
            *(u32 *)&p->f5c = 0xC1055555;
            *(u32 *)&p->f68 = 0x3E555555;
            c = 3;
        } else {
            *(u32 *)&p->f5c = 0xC0A00000;
            *(u32 *)&p->f68 = 0x3E555555;
            c = 4;
        }
        if (p->b1e6 != 0) {
            p->f5c = -p->f5c;
            p->f68 = -p->f68;
        }
        func_001757E0(p, 0x15, c);
    }
    p->f34 += p->f5c;
    p->f5c += p->f68;
}
