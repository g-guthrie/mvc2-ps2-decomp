typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G56b;
extern G56b *D_004C2794;

void residual_002EBB80(u8 *p, u8 *q)
{
    extern void func_0018C4B0(u8 *, s32);
    extern void func_00185490(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00183D10(u8 *);
    extern void func_001757E0(u8 *, s32, u8);
    extern void func_002EBC90(u8 *, u8 *);
    unsigned int t;

    p[6]++;
    func_0018C4B0(p, 5);
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    p[0x20D] = 1;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    if (p[0x1B7] == 0) {
        q[8] = 3;
    } else {
        q[8] = 5;
    }
    p[0x1B5] = 0x44;
    t = *(volatile u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0x15, p[0x1B7] + 8);
    *(s16 *)(p + 0x1E) = *(s8 *)(p + 0x151);
    p[0x151] = 0;
    func_002EBC90(p, q);
}
