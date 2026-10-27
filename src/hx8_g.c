typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F1FD0[];
extern u8 D_004F1F45, D_004F1F46;

extern int func_00175700(u8 *);
extern int func_00174470(const void *);
extern u8 *func_003CA900(u8 *, unsigned int);
extern void func_003CAB20(u8 *, u8 *, unsigned int);
extern void func_001E7F60();
extern void func_001757E0(u8 *, s32, s32);
extern void func_001E3710(u8 *, s32);

void func_003CC9C0(u8 *p, u8 *q) {
    u8 *r;
    s16 v;
    if (p[0x6] != 0) goto L3CCBA8;
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v != 0) goto L3CCAA4;
    if (q[0x5] != 0) goto L3CCAA4;
    if (func_00174470(p) == 0) goto L3CCAA4;
    if (*(s16 *)(q + 0x1E) <= 0) goto L3CCAA4;
    r = func_003CA900(q, 0x12);
    if (r == 0) goto L3CCAA4;
    *(s16 *)(r + 0x140) = *(s16 *)(p + 0x140);
    {
        f32 f2 = -65.0f;
        if (*(s16 *)(p + 0x140) != 0) f2 = -f2;
        *(f32 *)(r + 0x34) = *(f32 *)(p + 0x34) + f2;
    }
    *(f32 *)(r + 0x38) = 137.142852783f + *(f32 *)D_004F1FD0;
L3CCAA4:
    if (*(f32 *)(p + 0x38) < *(f32 *)(q + 0x430)) {
        u32 t = p[0x6];
        p[0x6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        if (func_00174470(p) != 0) {
            D_004F1F45 = 1;
            D_004F1F46 = 1;
        }
        func_001757E0(p, 1, 3);
        func_001E3710(p, 0x35);
    }
    if (*(s8 *)(p + 0x1B3) == 0) goto L3CCB50;
    {
        f32 f0 = -6.66666651f;
        if (*(s16 *)(p + 0x140) != 0) f0 = -f0;
        *(f32 *)(p + 0x5C) = f0;
    }
    func_003CAB20(p, q, 9);
    return;
L3CCB50:
    if (((s8)p[0x1B2] & 0x11) == 0) goto L3CCB98;
    {
        f32 f0 = -13.3333330f;
        if (*(s16 *)(p + 0x140) != 0) f0 = -f0;
        *(f32 *)(p + 0x5C) = f0;
    }
    func_003CAB20(p, q, 0xD);
    return;
L3CCB98:
    func_001E7F60(p);
    return;
L3CCBA8:
    v = (s8)func_00175700(p);
    if ((s8)v >= 0) return;
    func_003CAB20(p, q, p[0x7]);
}
