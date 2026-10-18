typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct P {
    u8 pad0[6]; u8 b6; u8 pad7[0x1C - 7]; s16 h1C; u8 pad1E[0x34 - 0x1E]; f32 f34; f32 f38; u8 pad3C[0x5C - 0x3C];
    f32 f5C; f32 f60; u8 pad64[4]; f32 f68; f32 f6C; u8 pad70[0x1B7 - 0x70]; u8 b1B7; u8 pad1B8[0x1E6 - 0x1B8]; u8 b1E6;
    u8 pad1E7[0x20D - 0x1E7]; u8 b20D; u8 pad20E[0x430 - 0x20E]; f32 f430;
} P;
extern void func_00175700(P *);
extern void func_00183d50(P *);
extern void func_001757E0(P *, s32, s32);

void func_002A4420(P *p)
{
    f32 z = 0.0f;
    s16 h;
    func_00175700(p);
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    if ((p->b1E6 == 0 && p->f5C > z) || (p->b1E6 != 0 && p->f5C < z)) {
        *(u32 *)&p->f68 = 0;
        *(u32 *)&p->f5C = 0;
    }
    if ((p->f60 < z && p->f38 <= p->f430) || (p->b1B7 == 0 && (h = p->h1C - 1, p->h1C = h, h == 0))) {
        p->b6++;
        p->f38 = p->f430;
        p->b20D = 0;
        func_00183d50(p);
        func_001757E0(p, 0x15, (u8)(p->b1B7 + 0x15));
    }
}
