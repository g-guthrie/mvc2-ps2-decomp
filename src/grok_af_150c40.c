typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y, z; } Float3;

extern u8 *func_003DA750(void *, int, int);
extern void func_00150D70(u8 *);
extern u32 D_004C27FC;
extern Float3 D_00444370[];

void func_00150C40(u8 owner)
{
    int i;
    for (i = 0; i < 2; i++) {
        u8 *p = func_003DA750(0, 13, 1);
        if (!p)
            break;
        p[0x13C] = 1;
        *(void (**)(u8 *))(p + 0x10) = func_00150D70;
        *(s16 *)(p + 0xCC) = 0x24;
        *(u32 *)(p + 0x84) = D_004C27FC;
        *(u32 *)(p + 0xD0) = 9;
        *(Float3 *)(p + 0x34) = D_00444370[i];
        *(u32 *)(p + 0x48) = (u16)(65536.0 * (double)(i * 0xB4) / 360.0 + 0.5);
        p[0x20] = (u8)i;
        *(s16 *)(p + 0x1C) = 0;
        p[0x21] = owner;
    }
}
