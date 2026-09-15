typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00175C00(u8 *, int);
extern void func_00182C30(u8 *, int);
extern void func_00182DB0(u8 *, int);
extern void func_00183D90(u8 *);
extern void func_00184540(u8 *);
extern void func_001846B0(u8 *);
extern void func_001E3240(u8 *, int);
extern void func_002F1DF0(u8 *);
extern void func_003A6DC0(u8 *, int, int);
extern void func_00398570(u8 *);
extern void func_00398D30(u8 *);

extern u8 *D_004C28D8;

typedef void (*DispatchFn)(u8 *);
extern DispatchFn jtbl_00459DA0[];

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

void func_002EBEF0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 21, 14);
    }
}

void func_002F0F20(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[827] = 0;
        p[828] = 0;
        func_002F1DF0(p);
    }
}

void func_002F92E0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        p[316] = 0;
        *(s16 *)(p + 28) = 16;
        *(s16 *)(p + 30) = 0;
    }
}

void func_002FDAC0(u8 *p)
{
    func_00175700(p);
    if (--*(s16 *)(p + 28) == 0)
        p[5]++;
}

void func_002FDEF0(u8 *p)
{
    func_00175700(p);
    if (--*(s16 *)(p + 28) == 0) {
        func_00175C00(p, 0);
        func_001846B0(p);
    }
}

void func_002ECD60(u8 *p)
{
    s16 t = *(s16 *)(p + 28);
    if ((t & 3) == 0) {
        u8 v = (u8)(t >> 2);
        func_003A6DC0(p, 0, v & 1);
    }
}

void func_002EF860(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_001E3240(p, 31);
        func_002F1DF0(p);
    }
}
