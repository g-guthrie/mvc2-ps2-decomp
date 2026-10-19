typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

extern void func_001741D0(u8 *, f32 *);
extern s32 func_00118FA8(f32);
extern void func_001E3D20(s32, s32, s32, s32);
extern s8 *D_004C2840;
extern u8 *D_0044F134;
extern u8 D_004F20B0[];

void func_001E3520(u8 *p, s32 id)
{
    f32 t[1];
    s32 v;
    s32 i;
    s32 s;
    u8 r;
    u8 *e;
    func_001741D0(p + 0x34, t);
    v = func_00118FA8(t[0] / 40.0f);
    if (v < 0)
        v = 0;
    if (v >= 0x10)
        v = 0xF;
    if (D_004C2840[0x45]) {
        r = D_0044F134[id & 0xFF];
        if (r == 0xFE)
            return;
        if (r != 0xFF)
            id = r;
    }
    i = 0;
    e = D_004F20B0;
    do {
        if (e[1] == 0x19)
            s = e[0x1B8];
        i = i + 1;
        e = e + 0x5B8;
    } while (i < 6);
    func_001E3D20(s & 0xFF, id & 0xFF, v, -1);
}
