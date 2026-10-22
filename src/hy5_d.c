typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 x[6]; } S24;
typedef struct {
    u8 b0;
    s8 b1;
    s8 b2;
    u8 pad3[5];
    s16 h8;
    u8 padA[0x4F];
    s8 b59;
    u8 pad5A[0xAC];
    s16 h106;
    s16 h108;
} G;
extern S24 D_004F8020;
extern G *D_004C2840;
extern u8 D_0041DBA0[];
extern u8 D_0043CC58[];

void func_00128AE0(void)
{
    extern void func_003DF850(s32, void *);
    extern void func_0012ACC0();
    extern void func_00129060(s32, void *);
    extern void func_0012D4A0();
    extern void func_003D6D50();
    extern void func_003D6E20();
    extern void func_00170160(int);
    extern void func_003DA410();
    extern void func_00122DA0();
    extern void func_00329890();
    extern void func_00122840(s32);
    extern void func_0016F090(void *);
    extern void func_0016F0C0(f32);
    extern void func_00146BF0();
    extern void func_00146C80(s32);
    extern void func_003298B0(u32, s32, s32);
    extern void func_001E3F50(s32);
    extern void func_001E4340(s32);
    extern void func_001E3FE0();
    S24 buf;
    G *g;
    s8 a;
    s32 t;
    s8 *pp;
    buf = D_004F8020;
    buf.x[1] = -16;
    func_003DF850(0x18, &buf);
    D_004C2840->h108 = 0;
    D_004C2840->h106 = 0;
    g = D_004C2840;
    t = g->b2;
    pp = (s8 *)((u8 *)g + 2);
    if (t == 0) {
        *pp = t + 1;
        func_0012ACC0(0);
        func_00129060(8, (void *)func_0012D4A0);
        func_00129060(5, D_0041DBA0);
        func_003D6D50();
        func_003D6E20();
        func_00170160(0x10);
        func_00170160(0x1C);
        func_003DA410();
        func_00122DA0();
        func_00329890();
        func_00122840(0);
        func_0016F090(D_0043CC58);
        func_0016F0C0(1.0f);
        D_004C2840->h8 = 0;
        func_00146BF0();
        func_00146C80(0);
        func_003298B0(0xFF000000, 0x19, 0);
        return;
    }
    a = g->b59;
    if (a >= 0) {
        if ((u32)a <= 2 || a == 7 || a == 5) {
            func_001E3F50(0x1C);
            func_001E4340(1);
            func_001E3FE0();
            D_004C2840->b1 = D_004C2840->b1 + 1;
            D_004C2840->b2 = 0;
        } else {
            g->b1 = g->b1 + 1;
            D_004C2840->b2 = 0;
        }
    } else {
        g->b1 = g->b1 + 1;
        D_004C2840->b2 = 0;
        func_001E3F50(0x1C);
        func_001E4340(1);
        func_001E3FE0();
    }
}
