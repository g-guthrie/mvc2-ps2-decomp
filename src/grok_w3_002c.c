typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00175910(u8 *, s32, s32, s32);
extern void func_00174910(u8 *, s32);
extern void func_00183D90(u8 *);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern void func_00182C30(u8 *, s32);
extern void func_00182DB0(u8 *, s32);
extern void func_0018C6E0(u8 *);
extern void func_00398570(u8 *);
extern void func_00398D30(u8 *);

extern u8 *D_004C28D8;

typedef void (*DispatchFn)(u8 *);
extern DispatchFn jtbl_00459DA0[];
extern DispatchFn jtbl_0045A590[];

void func_002C29D0(u8 *p)
{
    if (D_004C28D8[2])
        p[6]++;
}

void func_002C2BA0(u8 *p)
{
    if (D_004C28D8[2])
        p[6]++;
}

void func_002C40D0(u8 *p)
{
    p[533] = 0;
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 108) = 0xBF4DB6DBu;
    func_00184540(p);
}

void func_002CAFA0(u8 *p)
{
    p[533] = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 108) = 0xBF4DB6DBu;
    func_00184540(p);
}

void func_002C2980(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[6]++;
        p[337] = 0;
        D_004C28D8[2] = 0;
        func_00398570(p);
    }
}

void func_002C2B50(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[6]++;
        p[337] = 0;
        D_004C28D8[2] = 0;
        func_00398D30(p);
    }
}

void func_002C6F60(u8 *p)
{
    func_00183D90(p);
    jtbl_00459DA0[p[6]](p);
}

void func_002D0900(u8 *p)
{
    p[6]++;
    func_00182C30(*(u8 **)(p + 476), 30);
    func_00182DB0(p, 3);
    *(s16 *)(p + 28) = 64;
}

void func_002C7960(u8 *p)
{
    p[826] = 0xff;
    if (--*(s16 *)(p + 30) == 0) {
        *(s16 *)(p + 30) = 16;
        *(f32 *)(p + 96) = -*(f32 *)(p + 96);
    }
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
}

void func_002D7210(u8 *p)
{
    func_00175700(p);
    if (*(s16 *)(p + 28) == 0)
        p[5]++;
    else
        --*(s16 *)(p + 28);
}

void func_002D7F10(u8 *p)
{
    func_00175700(p);
    if (--*(s8 *)(p + 698) == 0)
        func_001843A0(p);
}

void func_002DB0E0(u8 *p)
{
    func_00174910(p, 1400);
    *(f32 *)(p + 52) -= *(f32 *)(p + 92);
    *(f32 *)(p + 56) -= *(f32 *)(p + 96);
}

void func_002D5540(u8 *p)
{
    func_0018C6E0(p);
    jtbl_0045A590[p[523] & 0x3f](p);
}

void func_002DEAC0(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    p[7]++;
    func_00175910(p, 22, 0, 7);
}

void func_002DF510(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    p[7]++;
    func_00175910(p, 22, 11, 7);
}

void func_002DEAF0(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    p[6]++;
    p[7] = 0;
    *(s16 *)(p + 28) = 20;
    *(s16 *)(p + 30) = 0;
    func_001757E0(p, 22, 1);
}
