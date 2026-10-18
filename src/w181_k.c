typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 b[0x14];
    s32 f14;
} G_k;

extern G_k *D_004C2840;
extern s32 D_004C2850;

void func_0012FA40(s32 flag)
{
    extern void func_0012FB90(void);
    extern void func_0012FC40(void);
    extern void func_003D6AC0(void);
    extern void func_00122840(s32);
    extern void func_003D7300(void);
    extern void func_001E4150(void);
    extern void func_001E40E0(void);
    extern void func_001E4140(void);
    extern void func_001E4480(s32, s32);
    extern void func_001E4340(s32);
    extern void func_0012E6B0(void);
    extern void func_0012E720(void);
    extern void func_0016EE50(void);
    if (D_004C2840->f14 == 0x60)
        func_0012FB90();
    if (flag != 0)
        func_0012FC40();
    D_004C2850 = 0x1E;
    D_004C2840->f14 = 0x40;
    ((u8 *)D_004C2840)[0] = 1;
    ((u8 *)D_004C2840)[1] = 0;
    ((u8 *)D_004C2840)[2] = 0;
    ((u8 *)D_004C2840)[3] = 0;
    ((u8 *)D_004C2840)[4] = 0;
    ((u8 *)D_004C2840)[5] = 0;
    ((u8 *)D_004C2840)[6] = 0;
    ((u8 *)D_004C2840)[7] = 0;
    ((u8 *)D_004C2840)[0x5D] = 0;
    ((u8 *)D_004C2840)[0x5E] = 0;
    ((u8 *)D_004C2840)[0x4C] = 0;
    ((u8 *)D_004C2840)[0x91] = 1;
    ((u8 *)D_004C2840)[0x4E] = 7;
    ((s8 *)D_004C2840)[0x59] = -1;
    *(s16 *)((u8 *)D_004C2840 + 0x106) = 0;
    *(s16 *)((u8 *)D_004C2840 + 0x108) = 0;
    func_003D6AC0();
    func_00122840(0);
    if (flag != 0)
        func_003D7300();
    func_001E4150();
    func_001E40E0();
    func_001E4140();
    func_001E4480(6, 1);
    func_001E4340(1);
    func_0012E6B0();
    func_0012E720();
    func_0016EE50();
}
