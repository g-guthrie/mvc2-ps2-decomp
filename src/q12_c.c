typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;
extern s32 func_00175700(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);

void func_001734F0(u8 *p)
{
    s8 i;
    s8 c;
    p[0x4D2] = 5;
    *(s16 *)(p + 0x4D4) = 0x78;
    *(s16 *)(p + 0x4D6) = 0x28;
    *(s16 *)(p + 0x4DA) = 1;
    for (i = 0; i < 3; i++) {
        c = p[0x544 + i];
        if (c == 0x2B || c == 0x2D || (*(s8 *)(p + 0x520) & (1 << i)) == 0) {
            p[0x544 + i] = 0x2A;
        }
    }
    p[0x547] = 0x2A;
}

extern u8 D_0045CB50[];
extern void func_00186A60(void *p, s32 a);
extern s32 func_00189310(void *p, void *q, void *r);
extern void func_00186A60(void *p, s32 a);
s32 func_00304E00(u8 *p)
{
    u8 *q = p + 0x2B8;
    if (func_00189310(p, D_0045CB50, p + 0x3A0) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    if (q[5] != 0) return 0;
    q[6] = 0;
    q[7] = 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 6;
    func_00186A60(p, 0x1D);
    return 1;
}

extern void func_0034B040(void *p);
extern void func_00198170(void *p, s32 a);
void func_0034A9F0(u8 *p)
{
    u32 c;
    func_0034B040(p);
    if ((s8)func_00175700(p) < 0) {
        c = p[5];
        p[5] = c + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x42092492;
        *(u32 *)(p + 0x6C) = 0xBF092492;
        func_001757E0(p, 0x16, 0xD);
    } else {
        s32 t; t = *(s8 *)(p + 0x151); if (t != 0) { if ((s8)t == 0x3E) { func_00198170(p, 1); p[0x151] = 0; } p[0x151] = 0; }
    }
}

extern u8 D_00454AD0[];
extern s32 func_00273C20(void *p);
extern void func_0018A990();
s32 func_00273A90(u8 *p)
{
    if (func_00189310(p, D_00454AD0, p + 0x3A0) == 0) return 0;
    if (func_00273C20(p) == 0) return 0;
    if (*(u32 *)(p + 0x2CC) != 0) return 0;
    func_0018A990(p, p + 0x3A0);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 6;
    func_00186A60(p, 0x15);
    *(u32 *)(p + 0x2C4) = *(u16 *)(p + 0x354);
    *(u32 *)(p + 0x2C4) = *(u32 *)(p + 0x2C4) & 0x60;
    *(u32 *)(p + 0x2C8) = 0;
    return 1;
}
