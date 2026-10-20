typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G;
extern G *D_004C2794;
extern void func_001861B0(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001E3710(u8 *, int);
extern void func_0018C4B0(u8 *, int);
extern void func_00183D90(u8 *);
extern void func_001863F0(u8 *);
extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);

void func_0024F000(u8 *p)
{
    if (p[6] == 0) {
        func_001861B0(p);
        p[6]++;
        p[0x20D] = 1;
        func_001757E0(p, 0x14, 3);
        p[0x1B5] = 0x35;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001E3710(p, 0x16);
        func_0018C4B0(p, 5);
    }
    if (p[0x213] == 3)
        func_00183D90(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    {
        f32 f = (f32)*(s8 *)(p + 0x151);
        if (f) {
            p[0x151] = 0;
            f *= p[0x1E6] != 0 ? 1.66666663f : -1.66666663f;
            *(f32 *)(p + 0x34) += f;
        }
    }
}
