typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G_o;
extern G_o *D_004C2794;

void func_00397BA0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q = p + 0xD0;
    s32 v;
    s16 h;
    u32 t;
    p[0x24] = 0;
    v = *(s8 *)(p + 0x1B4);
    if (v != 0) {
        p[0x1B4] = v - 1;
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(s8 *)(p + 0x1B2) != 0) {
        p[0x1B4] = 4;
        { u32 x = q[3]; q[3] = x - 1; }
        if ((s32)q[3] <= 0) goto fail;
        p[0x1B5] = 0x3F;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
    if (*(s8 *)(p + 0x1B3) != 0) {
        p[0x1B3] = 0;
        { u32 x = q[2]; q[2] = x - 1; }
        if ((s32)q[2] <= 0) goto fail;
    }
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (*(s16 *)(p + 0x1C) <= 0) goto fail;
    func_00175700(p);
    func_001E7F60(p);
    return;
fail:
    t = p[5];
    p[5] = t + 1;
    func_001757E0(p, 0x17, 4);
}
