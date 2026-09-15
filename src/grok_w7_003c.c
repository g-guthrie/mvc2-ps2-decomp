typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern s32 D_004C2A5C;
extern s32 D_0058C800[];
extern s16 D_004C27A4;
extern s8 *D_004C2840;
extern s8 D_004C2A40;

extern s32 func_003DA780(void);
extern void func_003D7190(s8 *);
extern void func_003D7030(void);
extern void func_00174BC0(void);

s32 func_003DA750(void)
{
    if (D_004C27A4 <= 0)
        return 0;
    return func_003DA780();
}

void func_003D7310(s32 p)
{
    if (D_004C2A5C != 16) {
        D_0058C800[D_004C2A5C] = p;
        D_004C2A5C++;
    }
}

void func_003D6FF0(void)
{
    func_003D7190(&D_004C2A40);
    if (D_004C2840[0x1A] == 0)
        func_003D7030();
    D_004C2840[0x1A] = 0;
    func_00174BC0();
}

void func_003DB890(s32 *p, s32 a1)
{
    s32 old = p[2];
    p[3] = old;
    p[2] = a1;
    p[4] = p[2] & (p[3] ^ p[2]);
    p[5] = p[3] & (p[3] ^ p[2]);
    p[6] = p[4] | p[5];
}
