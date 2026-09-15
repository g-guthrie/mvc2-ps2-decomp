typedef unsigned char u8;

extern int func_001820A0(u8 *);
extern int func_00182300(u8 *);
extern int func_001864A0(u8 *);
extern void func_001865B0(u8 *);
extern u8 *D_004C25D4;
extern void func_00125A80(int);
extern void func_00125C20(int);
extern void func_00125AF0(int);
extern void func_00125C90(int);
extern void func_001EA6A0(u8 *);
extern void func_001EA5C0(u8 *);
extern void func_00211990(u8 *);
extern void func_00211950(u8 *);
extern void func_0021E5E0(u8 *);
extern void func_0021E5A0(u8 *);
extern void func_00223F00(u8 *);
extern void func_00223E40(u8 *);
extern void func_0022DD30(u8 *);
extern void func_0022DCF0(u8 *);
extern void func_0023B2D0(u8 *);
extern void func_0023B190(u8 *);
extern void func_00249BF0(u8 *);
extern void func_00249BB0(u8 *);
extern void func_0024EFC0(u8 *);
extern void func_0024EF80(u8 *);
extern void func_0025D8A0(u8 *);
extern void func_0025D860(u8 *);
extern void func_00263D70(u8 *);
extern void func_00263C40(u8 *);
extern void func_0026C300(u8 *);
extern void func_0026C2C0(u8 *);
extern void func_002701A0(u8 *);
extern void func_00270160(u8 *);
extern void func_00274D60(u8 *);
extern void func_00274CB0(u8 *);
extern void func_00282970(u8 *);
extern void func_00282930(u8 *);
extern void func_00287AB0(u8 *);
extern void func_00287A30(u8 *);
extern void func_0028F250(u8 *);
extern void func_0028F210(u8 *);
extern void func_00296880(u8 *);
extern void func_00296840(u8 *);
extern void func_0029CBA0(u8 *);
extern void func_0029CAC0(u8 *);
extern void func_002A22F0(u8 *);
extern void func_002A2210(u8 *);
extern void func_002A8700(u8 *);
extern void func_002A86C0(u8 *);
extern void func_002B3D60(u8 *);
extern void func_002B3D20(u8 *);
extern void func_002B9780(u8 *);
extern void func_002B9740(u8 *);
extern void func_002CD150(u8 *);
extern void func_002CD110(u8 *);
extern void func_002D2710(u8 *);
extern void func_002D26D0(u8 *);
extern void func_002F34A0(u8 *);
extern void func_002F3410(u8 *);
extern void func_002F82F0(u8 *);
extern void func_002F8290(u8 *);
extern void func_002FD510(u8 *);
extern void func_002FD4D0(u8 *);
extern void func_00306440(u8 *);
extern void func_00306400(u8 *);
extern void func_0030A0E0(u8 *);
extern void func_0030A010(u8 *);
extern void func_003113C0(u8 *);
extern void func_00311380(u8 *);

#define SEQ530(then_fn, else_fn) \
    do { \
        func_001820A0(p); \
        func_00182300(p); \
        if (p[530] == 1) \
            then_fn(p); \
        else \
            else_fn(p); \
        if (func_001864A0(p)) \
            func_001865B0(p); \
    } while (0)

void func_001EA550(u8 *p) { SEQ530(func_001EA6A0, func_001EA5C0); }
void func_002118E0(u8 *p) { SEQ530(func_00211990, func_00211950); }
void func_0021E530(u8 *p) { SEQ530(func_0021E5E0, func_0021E5A0); }
void func_00223DD0(u8 *p) { SEQ530(func_00223F00, func_00223E40); }
void func_0022DD70(u8 *p) { SEQ530(func_0022DD30, func_0022DCF0); }
void func_0023B120(u8 *p) { SEQ530(func_0023B2D0, func_0023B190); }
void func_00249B40(u8 *p) { SEQ530(func_00249BF0, func_00249BB0); }
void func_0024EF10(u8 *p) { SEQ530(func_0024EFC0, func_0024EF80); }
void func_0025D7F0(u8 *p) { SEQ530(func_0025D8A0, func_0025D860); }
void func_00263BD0(u8 *p) { SEQ530(func_00263D70, func_00263C40); }
void func_0026C250(u8 *p) { SEQ530(func_0026C300, func_0026C2C0); }
void func_002700F0(u8 *p) { SEQ530(func_002701A0, func_00270160); }
void func_00274C40(u8 *p) { SEQ530(func_00274D60, func_00274CB0); }
void func_002828C0(u8 *p) { SEQ530(func_00282970, func_00282930); }
void func_002879C0(u8 *p) { SEQ530(func_00287AB0, func_00287A30); }
void func_0028F1A0(u8 *p) { SEQ530(func_0028F250, func_0028F210); }
void func_002967D0(u8 *p) { SEQ530(func_00296880, func_00296840); }
void func_0029CA50(u8 *p) { SEQ530(func_0029CBA0, func_0029CAC0); }
void func_002A21A0(u8 *p) { SEQ530(func_002A22F0, func_002A2210); }
void func_002A8650(u8 *p) { SEQ530(func_002A8700, func_002A86C0); }
void func_002B3CB0(u8 *p) { SEQ530(func_002B3D60, func_002B3D20); }
void func_002B96D0(u8 *p) { SEQ530(func_002B9780, func_002B9740); }
void func_002CD0A0(u8 *p) { SEQ530(func_002CD150, func_002CD110); }
void func_002D2660(u8 *p) { SEQ530(func_002D2710, func_002D26D0); }
void func_002F33A0(u8 *p) { SEQ530(func_002F34A0, func_002F3410); }
void func_002F8220(u8 *p) { SEQ530(func_002F82F0, func_002F8290); }
void func_002FD460(u8 *p) { SEQ530(func_002FD510, func_002FD4D0); }
void func_00306390(u8 *p) { SEQ530(func_00306440, func_00306400); }
void func_00309FA0(u8 *p) { SEQ530(func_0030A0E0, func_0030A010); }
void func_00311310(u8 *p) { SEQ530(func_003113C0, func_00311380); }

void func_00125940(void)
{
    if (D_004C25D4[5] == 2)
        func_00125A80(16);
    else
        func_00125C20(16);
}

void func_00125980(void)
{
    if (D_004C25D4[5] == 2)
        func_00125AF0(4);
    else
        func_00125C90(4);
}

void func_00125E70(void)
{
    if (D_004C25D4[5] == 3)
        func_00125A80(16);
    else
        func_00125C20(16);
}

void func_00125EB0(void)
{
    if (D_004C25D4[5] == 3)
        func_00125AF0(4);
    else
        func_00125C90(4);
}

void func_00125F80(void)
{
    if (D_004C25D4[1] == 26)
        func_00125A80(2);
    else
        func_00125C20(2);
}

void func_00125FC0(void)
{
    if (D_004C25D4[1] == 26)
        func_00125AF0(2);
    else
        func_00125C90(2);
}
