typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00183D90(u8 *);
extern void func_001843A0(u8 *);
extern u8 *D_004C2840;

void func_002DE100(u8 *p)
{
    f32 z = 0.0f;
    f32 *vx = (f32 *)(p + 0x5C);
    f32 *ax = (f32 *)(p + 0x68);
    f32 v;

    v = *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) = *(f32 *)(p + 0x34) + v;
    v = *(f32 *)(p + 0x68);
    v = *(f32 *)(p + 0x5C) + v;
    *vx = v;
    if (!(v * *ax < z)) {
        *vx = z;
        *ax = z;
    } else if ((*(u32 *)(D_004C2840 + 0x1C)) & 1) {
        func_00183D90(p);
    }
    if ((s8)func_00175700(p) < 0) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *(u32 *)vx = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)ax = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001843A0(p);
    }
}
