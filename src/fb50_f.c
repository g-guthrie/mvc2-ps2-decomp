typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_0061BEA0[16];
extern s32 D_0062BC00[];
extern f32 D_0062BC30[];
extern s32 D_004C2AE4;
extern s32 D_004C2AE0;
extern f32 D_004C2A80;
extern f32 D_004C2A84;
extern f32 D_004C2A88;
extern f32 D_004C2A8C;
extern f32 D_004C2A90;
extern f32 D_004C2A94;
extern f32 D_004C2A98;
extern f32 D_004C2A9C;
extern s32 fptosi(f32);
extern void func_003DD260(f32 *m);
extern void func_003DD930(s32 a, s32 b, s32 c, s32 d, f32 e, f32 g);

void func_003DD5D0(f32 *m, s32 a1, s32 a2, s32 a3, s32 a4, f32 fa, f32 fb)
{
    s32 s0;
    f32 f24, f20, f21;

    s0 = a3 / 2;
    f24 = (f32)s0;
    f20 = (f32)(a4 / 2);
    func_003DD260(D_0061BEA0);
    D_0061BEA0[0] = f24;
    D_0061BEA0[5] = -f20;
    f21 = fb - fa;
    D_0061BEA0[14] = fa;
    D_0061BEA0[10] = f21;
    D_0061BEA0[15] = 1.0f;
    D_0061BEA0[12] = (f32)a1 + f24;
    D_0061BEA0[13] = (f32)a2 + f20;
    D_0061BEA0[0] = D_0061BEA0[0] / 1.3300000429153442f;
    if (D_0062BC00[0] == 0) {
        a2 = a2 / 2;
        a4 = a4 / 2;
    }
    f24 = (f32)s0;
    f20 = (f32)(a4 / 2);
    func_003DD260(m);
    m[0] = f24;
    m[5] = -f20;
    m[10] = f21;
    m[12] = (f32)a1 + f24;
    m[13] = (f32)a2 + f20;
    m[14] = fa;
    m[15] = 1.0f;
    m[10] = m[10] * (0.5f * -D_0062BC30[0]);
    m[12] = (f32)(0x800 - (D_004C2AE4 >> 1)) + m[12];
    m[13] = (f32)(0x800 - (D_004C2AE0 >> 1)) + m[13];
    m[14] = 0.5f * D_0062BC30[0];
    m[0] = m[0] / 1.3333330154418945f;
    D_004C2A8C = m[12];
    D_004C2A88 = m[13];
    D_004C2A9C = (f32)a1;
    D_004C2A98 = (f32)a2;
    D_004C2A94 = (f32)a3;
    D_004C2A90 = (f32)a4;
    D_004C2A84 = 2048.0f - D_004C2A8C;
    if (D_004C2A84 < 0.0f) D_004C2A84 *= -1.0f;
    D_004C2A84 = 2048.0f - D_004C2A84;
    D_004C2A80 = 2048.0f - D_004C2A88;
    if (D_004C2A80 < 0.0f) D_004C2A80 *= -1.0f;
    D_004C2A80 = 2048.0f - D_004C2A80;
    s0 = fptosi(D_004C2A84);
    func_003DD930(0, 0, s0, fptosi(D_004C2A80), fa, fb);
}
