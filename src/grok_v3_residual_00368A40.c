typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001AD1E0(u8 *, int, int);
extern double func_00119058(f32);
extern int func_00100290(double, int);
extern void func_001E7F60(u8 *);
extern int func_001757E0(u8 *, int, int);
typedef struct { f32 x, y, z; } V3;
extern void func_0015B200(u8 *, V3 *, int, int);
extern void func_001E3710(u8 *, int);
extern u8 *D_004C2794;
extern f32 D_004F1F4C[];
extern u8 *D_004C297C;

void func_00368A40(u8 *p)
{
    s16 t;
    f32 d;
    V3 tmp;
    unsigned short z;

    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t == 0) {
        *(s16 *)(p + 0x1C) = 4;
        func_001AD1E0(p, 7, 0);
    }
    if (*(s8 *)(p + 0x1B2) == 0) {
        d = D_004F1F4C[0] + *(f32 *)(D_004C297C + 4);
        if (*(s16 *)(p + 0x140) != 0)
            d = d - *(f32 *)(p + 0x34);
        else
            d = *(f32 *)(p + 0x34) - d;
        if (func_00100290(func_00119058(d), 0)) {
            func_001E7F60(p);
            return;
        }
    }
    {
        u32 n = p[5];
        p[5] = n + 1;
        p[0x1B5] = (p[0x21] & 0x80) ? 0x4A : 0x41;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        {
            unsigned int offset = p[2] * 2;
            offset += (unsigned int)D_004C2794;
            ++*(s16 *)(offset + 0x7C);
        }
        p[0x13C] = 0;
        func_001757E0(p, 0x17, 0x15);
        tmp = *(V3 *)(p + 0x34);
        func_0015B200(p, &tmp, 1, 0xD9);
        func_001E3710(p, 0x49);
    }
}
