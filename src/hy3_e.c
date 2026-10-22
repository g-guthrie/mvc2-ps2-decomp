typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern V3 D_0045F168;
extern V3 D_0045F138;
extern V3 D_0045F148;
extern V3 D_0045F158;
extern s32 D_004C283C;

void func_0033E380(u8 *p)
{
    extern s32 func_00417A40();
    extern void func_0033E560(u8 *);
    extern void func_0032E690(u8 *);
    u32 t = p[4];
    switch (t) {
    case 0:
        p[4] = t + 1;
        *(s16 *)(p + 0xCC) = func_00417A40() % 2 + 3;
        *(s32 *)(p + 0x84) = D_004C283C;
        *(V3 *)(p + 0x34) = D_0045F168;
        *(f32 *)(p + 0x34) += (f32)(func_00417A40() % 2000 - 1000);
        *(f32 *)(p + 0x38) += (f32)(func_00417A40() % 200);
        *(f32 *)(p + 0x3C) += (f32)(func_00417A40() % 2000 - 1000);
        *(V3 *)(p + 0x5C) = D_0045F138;
        *(V3 *)(p + 0x68) = D_0045F148;
        *(V3 *)(p + 0x50) = D_0045F158;
        break;
    case 1: {
        f32 c = -63.599998f;
        if (*(f32 *)(p + 0x38) <= c) {
            p[4] = 0;
            *(f32 *)(p + 0x38) = c;
            func_0033E560(p + 0x34);
        }
        *(f32 *)(p + 0x54) -= 0.05f;
        func_0032E690(p);
        break;
    }
    }
}
