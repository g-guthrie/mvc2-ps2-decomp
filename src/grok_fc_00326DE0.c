/* ./try.sh src/grok_fc_00326DE0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FC8;
extern f32 D_004F1FCC;
extern void func_00185490(u8 *);
extern void func_00186A60(u8 *, s32);
extern int func_001757E0(u8 *, int, int);
extern void func_00175C00(u8 *, int);

void func_00326DE0(u8 *p)
{
    u8 *q;

    p[0x425] = 0;
    p[0x13C] = 1;
    p[0] = 1;
    p[0x269] = 2;
    q = *(u8 **)(p + 0x220);
    if (q[0x1E6])
        *(f32 *)(p + 0x34) = 133.3333282470703125f + D_004F1FCC;
    else
        *(f32 *)(p + 0x34) = D_004F1FC8 - 133.3333282470703125f;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    func_00185490(p);
    *(f32 *)(p + 0x38) += 411.428558349609375f;
    *(u32 *)(p + 0x60) = 0xC1092492u;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DBu;
    *(u32 *)(p + 0x5C) = 0x41555555u;
    if (p[0x1E6] == 0)
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    *(u32 *)(p + 0x68) = 0;
    p[4] = 1;
    p[5] = 0;
    func_00186A60(p, 3);
    p[6] = 1;
    p[7] = 1;
    p[0x1EA] = 0x11;
    p[0x1E8] = 0;
    p[0x1E9] = 1;
    p[0x1ED] = 4;
    p[0x20D] = 2;
    p[0x208] = 0x12;
    p[0x206] = 0x16;
    p[0x1FF] = 0x1E;
    p[0x1E7] = 0;
    func_001757E0(p, 1, 0xA);
    func_00175C00(p, 1);
}
