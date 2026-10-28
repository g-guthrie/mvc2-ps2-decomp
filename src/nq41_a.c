typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern s32 D_004D17CC;
extern char D_004BF140[];
extern u8 D_004A9360[], D_004A96B0[];
extern u16 D_006336FE[];
extern u8 D_006336FD[], D_006336FC[], D_006336FB[], D_006336FA[];
extern int func_004220B0(float scale, void *data, s32 zero, s32 mode);
extern s32 func_0011F938();
extern unsigned int func_0011FFA0(const char *text);
extern void func_00422740(char *text, s32 width, s32 mode, s32 arg3,
                          s32 arg4, s32 arg5, s32 arg6);

void func_00421520(void)
{
    char buffer[200];
    u16 v;
    func_004220B0(0.090000003576278687f, D_004A9360, 0, 2);
    v = *(u16 *)((u8 *)D_006336FE + D_004D17CC * 8);
    switch (v) { case 0: case 0xFFFF: return; }
    func_0011F938((s32)buffer, D_004BF140, D_006336FD[D_004D17CC * 8], D_006336FC[D_004D17CC * 8], v, D_006336FB[D_004D17CC * 8], D_006336FA[D_004D17CC * 8]);
    func_00422740(buffer, 0x140 - func_0011FFA0(buffer) * 9, 0x18C, 0, -1, 0x200, 0x200);
}

void func_00421730(void)
{
    char buffer[200];
    u16 v;
    func_004220B0(0.090000003576278687f, D_004A96B0, 0, 2);
    v = *(u16 *)((u8 *)D_006336FE + D_004D17CC * 8);
    switch (v) { case 0: case 0xFFFF: return; }
    func_0011F938((s32)buffer, D_004BF140, D_006336FD[D_004D17CC * 8], D_006336FC[D_004D17CC * 8], v, D_006336FB[D_004D17CC * 8], D_006336FA[D_004D17CC * 8]);
    func_00422740(buffer, 0x140 - func_0011FFA0(buffer) * 9, 0x18C, 0, -1, 0x200, 0x200);
}

