typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

extern void func_001741D0(u8 *, f32 *);
extern s32 func_00118FA8(f32);
extern void func_001E3D20(s32, s32, s32, s32);
extern s8 *D_004C2840;
typedef struct { u8 *p; u8 pad[16]; } FarPtr;
extern FarPtr D_0044F0E0;
extern u8 D_004CD183[];

void func_001E3430(u8 *p, u8 *q, s32 id)
{
    f32 t[2];
    s32 v;
    u8 r;
    func_001741D0(p + 0x34, &t[0]);
    v = func_00118FA8(t[0] / 40.0f);
    if (v <= -1)
        v = 0;
    if (v >= 0x10)
        v = 0xF;
    if (D_004C2840[0x45]) {
        r = D_0044F0E0.p[id & 0xFF];
        if (r == 0xFE)
            return;
        if (r != 0xFF)
            id = r;
    }
    func_001E3D20(D_004CD183[q[0x1B8] * 20], id & 0xFF, v, -1);
}
