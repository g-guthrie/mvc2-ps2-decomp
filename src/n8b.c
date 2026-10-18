typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 *D_004C2840;
extern void func_00172B50();
extern void func_001757E0(void *p, s32 b, s32 c);
extern void func_00175C00(void *p, s32 b);
extern u32 func_00174170(void *p);
extern u8 D_004F20B0[];
extern u8 D_004F2668[];

void func_00172B00(void)
{
    D_004C2840[0x8E] = 0;
    if (D_004C2840[0x2A] != 0) return;
    if (D_004C2840[0x4C] != 2) {
        func_00172B50((void*)D_004F20B0);
        func_00172B50(D_004F2668);
    }
}


void func_002FDB10(u8 *p)
{
    u8 *q = p + 0x2B8;
    u32 t;
    if ((func_00174170(p) & 1) == 0) {
        p[0x168] = 0;
    } else {
        p[0x168] = 1;
    }

    func_001757E0(p, 0x13, p[0x168]);
    p[0x216] = 0;
    *(s16 *)(q + 4) = 0;
    func_00175C00(p, 0);
    t = p[6];
    p[6] = t + 1;
}

extern u8 D_00455C00[];
extern s32 func_0018A160(u8 *p, u8 *a, u8 *b);
extern void func_00186A60(u8 *p, s32 b);

s32 func_002863A0(u8 *p)
{
    if (func_0018A160(p, D_00455C00, p + 0x378) == 0) {
        return 0;
    }
    if (p[0x20D] == 2 && p[0x210] == 0) {
        if (*(s8 *)(p + 0x1E8) != 0) {
            return 0;
        }
        p[0x1E8] = *(s8 *)(p + 0x1E8) + 1;
    }
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

extern u8 D_004C1380[4];
extern void func_001E3710(void *p, s32 b);

void func_002FA0B0(u8 *p)
{
    switch (p[0x1FC]) {
    case 0:
    case 1:
        p[0x168] = 3;
        *(void **)(p + 0x408) = D_004C1380;
        func_001E3710(p, 0x14);
        break;
    case 2:
        p[0x168] = 4;
        *(void **)(p + 0x408) = D_004C1380;
        func_001E3710(p, 0x16);
        break;
    default:
        break;
    }
    func_001757E0(p, 0x16, p[0x168]);
}
