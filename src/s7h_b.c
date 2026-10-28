typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 t[0x40]; } HM1G;
extern HM1G *D_004C2794;

void func_002BCA80(u8 *p, u8 *q)
{
    extern void func_00175700(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern s32 func_002BCF40(u8 *, u8 *);
    extern void func_002BD190(u8 *, u8 *);
    extern void func_002BCBE0(u8 *, u8 *);
    s32 t;
    u8 a;
    s32 b;
    u8 x;

    p[0x40C] = 2;
    p[0x33C] = 5;
    { u32 c6 = p[6]; p[6] = c6 + 1; }
    func_00175700(p);
    func_001266A0(p, 1, 8);
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    p[0x22] = 0xFF;
    func_002BCF40(p, q);
    a = (t = (p[0x1E6] != 0) ? 5 : 0x15) & 0xFF;
    p[0x22] -= a;
    x = p[0x22];
    if ((s8)x < 0) {
        p[0x22] = 0;
    } else if (x > 6) {
        p[0x22] = 6;
    }
    a += p[0x22];
    if (*(s8 *)(p + 0x539) == 0 && (*(u16 *)(p + 0x354) & 0x3000) != 0) {
        t = (p[0x1E6] != 0) ? 0xB : 0x15;
        a = t & 0xFF;
    }
    p[0x22] = a;
    func_002BD190(p, q);
    p[0x1B5] = 0x5C;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->t[p[2]]++;
    func_002BCBE0(p, q);
}
