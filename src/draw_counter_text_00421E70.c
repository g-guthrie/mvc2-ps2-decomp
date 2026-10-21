typedef signed int s32;
typedef unsigned char u8;

extern s32 D_004D17F8;
extern char D_004BF158[];
extern u8 D_004AA7B0[];
extern void func_004220B0(float scale, void *data, s32 zero, s32 mode);
extern s32 func_0011F938(char *destination, const char *format, ...);
extern unsigned int func_0011FFA0(const char *text);
extern void func_00422740(char *text, s32 width, s32 mode, s32 arg3,
                          s32 arg4, s32 arg5, s32 arg6);

void func_00421E70(void)
{
    char buffer[200];

    func_004220B0(0.090000003576278687f, D_004AA7B0, 0, 2);
    func_0011F938(buffer, D_004BF158, D_004D17F8);
    func_00422740(buffer, 0x140 - func_0011FFA0(buffer) * 9,
                  0x184, 0, -1, 0x200, 0x200);
}
