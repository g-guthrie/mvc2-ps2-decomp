typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[4]; u8 b4; u8 b5; } G2c;
extern G2c *D_004C28D8;
extern u8 D_00459B60[];

void func_002C3200(u8 *p)
{
    extern void func_00175700(u8 *);
    extern s32 func_00399240(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 r;
    s32 t;
    t = D_004C28D8->b4 + 1;
    D_004C28D8->b4 = t;
    r = ((u8)t + 4) % 4;
    D_004C28D8->b4 = r;
    if (r == 0) {
        if (func_00399240(p, D_00459B60[p[0x22]], D_004C28D8->b5) != 0) {
            t = D_004C28D8->b5 + 1;
            D_004C28D8->b5 = t;
            D_004C28D8->b5 = (s8)(u8)t & 3;
        }
    }
    func_00175700(p);
    t = p[0x20] - 1;
    p[0x20] = t;
    if ((u8)t == 0) {
        t = p[6];
        p[6] = t + 1;
        if (p[0x20D] != 2) func_001757E0(p, 0x16, 2);
        else func_001757E0(p, 0x16, 5);
    }
}
