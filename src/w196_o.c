typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u32 w0;
    s8 f4;
    u8 b5;
    u8 pad6[2];
    u32 w8;
    u32 wC;
    s32 w10;
    u8 pad14[0x14];
    u32 w28;
    u32 w2C;
} E40;

extern E40 D_00494DD8[];
extern u8 D_00494DA8[];
extern u8 D_004BEA20[];
extern u8 D_0040FD18[];

E40 *func_0040FDC0(s32 a, u32 b, s32 c)
{
    extern void func_0040FEF8(E40 *);
    s32 i;
    E40 *e;
    for (i = 0; i < 0x40; i++) {
        if (D_00494DD8[i].f4 == 0) break;
    }
    if (i == 0x40) return 0;
    e = &D_00494DD8[i];
    e->f4 = 1;
    e->w0 = (u32)D_00494DA8;
    e->b5 = a;
    e->w8 = (u32)D_004BEA20;
    e->wC = b;
    e->w10 = c / 16;
    e->w28 = (u32)D_0040FD18;
    e->w2C = (u32)e;
    func_0040FEF8(e);
    return e;
}
