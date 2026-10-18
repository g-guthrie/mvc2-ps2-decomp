typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;

extern void func_0021C330(void *p, void *q);
extern void func_001757E0(void *p, s32 a, u8 b);
extern s32 func_00175700(void *p);
extern void func_00175C00(void *p, s32 a);
extern void func_00184540(void *p);
extern void func_001843A0(void *p);
extern s32 func_0024D670(void *p);
extern void func_00126400();

void func_0021C2D0(u8 *p, u8 *q) {
    *(s8 *)(p + 0x151) = 12;
    *(f32 *)(p + 0x5C) = (*(f32 *)(q + 0x34) - *(f32 *)(p + 0x34)) / 32.0f;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x41092492;
    *(u32 *)(p + 0x6C) = 0xBF092492;
    *(f32 *)(p + 0x34) -= 4.0f * *(f32 *)(p + 0x5C);
    func_0021C330(p, q);
}

void func_002A3D00(u8 *p) {
    u32 t = p[6];
    p[6] = t + 1;
    p[0x1B5] = (p[0x1B7] != 0) ? 0x3B : 0x3A;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    {
        s16 *q = (s16 *)((p[2] << 1) + (u32)D_004C2794);
        q[0x3E] = q[0x3E] + 1;
    }
    func_001757E0(p, 0x15, (p[0x1B7] != 0) ? 0xB : 0xA);
}

void func_002C8660(u8 *p, u8 *q) {
    s8 r;
    if (*(s8 *)(p + 0x161) != 0) q[4] = 1;
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_00175C00(p, 0);
    }
    r = func_00175700(p);
    if (r < 0) {
        if (p[0x20D] == 2) {
            func_00184540(p);
        } else {
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
            func_001843A0(p);
        }
    }
}
