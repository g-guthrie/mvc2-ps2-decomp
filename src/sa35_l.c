typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[7]; u8 b7; u8 pad8[0x38 - 8]; f32 f38; u8 pad3C[0x5C - 0x3C];
    f32 f5C; f32 f60; u8 pad64[4]; f32 f68; f32 f6C; u8 pad70[0x151 - 0x70];
    s8 b151; u8 pad152[0x1B2 - 0x152]; s8 b1B2; u8 pad1B3[0x1E6 - 0x1B3];
    u8 b1E6; u8 b1E7; u8 pad1E8[0x20D - 0x1E8]; u8 b20D; u8 pad20E[2]; u8 b210;
    u8 pad211[0x430 - 0x211]; f32 f430;
} P;

void func_001FD950(P *p)
{
    extern s8 func_00175700();
    extern void func_00183d50(P *);
    extern void func_001757E0(P *, s32, s32);
    extern void func_00184570(P *);
    extern void func_001843A0(P *);
    s8 r;
    u32 t;
    switch (p->b7) {
    case 0:
        func_00175700(p);
        if (p->b151 & 1) {
            p->b151 = p->b151 & ~1;
            t = p->b7;
            p->b7 = t + 1;
            if (p->b210 == 0) *(u32 *)&p->f60 = 0xC1CDB6DB;
            else *(u32 *)&p->f60 = 0xC2009249;
        }
        break;
    case 1:
        func_00175700(p);
        if (p->b1B2 == 0) {
            if (p->f430 <= p->f38) return;
            t = p->b7;
            p->b7 = t + 1;
            p->f38 = p->f430;
            p->b20D = 0;
            *(u32 *)&p->f5C = 0;
            *(u32 *)&p->f60 = 0;
            *(u32 *)&p->f68 = 0;
            *(u32 *)&p->f6C = 0;
            func_00183d50(p);
            func_001757E0(p, 1, 3);
        } else {
            *(u32 *)&p->f5C = 0x40BAAAAA;
            if (p->b1E6 != 0) p->f5C = -p->f5C;
            *(u32 *)&p->f68 = 0;
            *(u32 *)&p->f60 = 0x41700000;
            *(u32 *)&p->f6C = 0xBF892492;
            p->b1E7 = 1;
            func_00184570(p);
        }
        break;
    case 2:
        r = func_00175700(p);
        if (r < 0) func_001843A0(p);
        break;
    }
}
