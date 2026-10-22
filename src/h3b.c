typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C29A4;
void func_00381A60(u8 *p)
{
    s16 v;
    f32 x;
    D_004C29A4[3] = 0xFF;
    x = *(f32 *)(p + 0x54);
    *(f32 *)(p + 0x54) += -x / (f32)*(s16 *)(p + 0x1C);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}

extern u8 *D_004C2840;
extern s32 D_004C265C;
extern void func_003DAA40(s32);
extern void func_0016CB50(void);
extern void func_0016CCA0(void);
extern void func_003298B0(u32, s32, s32);
void func_0016BD50(void)
{
    s16 v = *(s16 *)(D_004C2840 + 8) - 1;
    *(s16 *)(D_004C2840 + 8) = v;
    if (v == 0) {
        func_003DAA40(D_004C265C);
        D_004C2840[5] = 6;
        *(s16 *)(D_004C2840 + 8) = 0xF0;
        func_0016CB50();
        func_0016CCA0();
        func_003298B0(0xFF000000, 2, 0);
    }
}

extern u32 D_004C2794;
extern s8 func_00175700(u8 *);
extern void func_001843A0(u8 *);
void func_0025D8E0(u8 *p)
{
    s16 *a;
    if (func_00175700(p) < 0) {
        func_001843A0(p);
    }
    if (*(s8 *)(p + 0x151) == 1) {
        p[0x151] = 0;
        p[0x1B5] = 0x19;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        a = (s16 *)((p[2] << 1) + D_004C2794);
        a[0x3E] = a[0x3E] + 1;
    }
}

extern void func_003DA410(void);
extern void func_00170160(int);
extern void func_00122840(u32);
extern void func_001E40E0(void);
extern void func_001E4140(void);
extern void func_001E4150(void);
void func_0016BE80(void)
{
    D_004C2840[2] = 5;
    D_004C2840[3] = 0;
    D_004C2840[4] = 0;
    D_004C2840[5] = 0;
    D_004C2840[6] = 0;
    *(s16 *)(D_004C2840 + 8) = 0;
    *(s16 *)(D_004C2840 + 0xA) = 0;
    *(s16 *)(D_004C2840 + 0xC) = 0;
    *(s16 *)(D_004C2840 + 0xE) = 0;
    func_003DA410();
    func_00170160(0xF);
    func_00122840(0xFF000000);
    func_001E40E0();
    func_001E4140();
    func_001E4150();
}
