typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;

extern s8 D_004F7F3F;
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern u16 D_004F25B8;
extern u16 D_004F2B70;
extern u16 D_004F25B4;
extern u16 D_004F2B6C;
extern u16 D_004C291E __attribute__((section(".sdata")));
extern u16 D_004C291C __attribute__((section(".sdata")));
extern u16 D_004C291A __attribute__((section(".sdata")));
extern u16 D_004C2918 __attribute__((section(".sdata")));
typedef void (*DispatchFn)(void);
extern const u32 jtbl_0045E240[];

void func_003299F0(void)
{
    s32 idx;
    u16 *a;
    u16 *b;
    u16 v;

    if (D_004F7F3F != 0 && ((s8 *)D_004C2840)[0x90] != 0) {
        idx = (s8)((s8 *)D_004C2840)[0x90];
        idx = (s8)((idx - 1) ^ 1);
        a = (u16 *)((u32)&D_004F25B8 + idx * 0x5B8);
        b = (u16 *)((u32)&D_004F25B4 + idx * 0x5B8);
        v = a[0];
        D_004C291E = v;
        D_004C291C = v;
        v = b[0];
        D_004C291A = v;
        D_004C2918 = v;
    } else {
        D_004C291C = D_004F25B8;
        D_004C291E = D_004F2B70;
        D_004C2918 = D_004F25B4;
        D_004C291A = D_004F2B6C;
    }
    ((DispatchFn)jtbl_0045E240[(s8)((s8 *)D_004C2840)[3]])();
}
