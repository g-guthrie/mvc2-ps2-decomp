typedef unsigned int u32;
typedef signed int s32;

struct MenuNoticeData
{
    u32 words[8];
};

extern s32 D_004C2B5C;
extern s32 D_004C2B60;
extern s32 D_004C2B64;
extern s32 D_004C2B68;
extern signed char D_004C27C4;
extern signed char D_004C27C0;
extern float D_004C2530;
extern s32 func_0012E560(struct MenuNoticeData *data);
extern s32 func_003299D0(void);
extern void func_003DA650(s32 value);
extern void func_00146C80(s32 mode);
extern void func_003298B0(s32 color, s32 duration, s32 mode);
extern void func_0012ACC0(s32 callback);
extern void func_0041CA40(void);
extern void func_0041C550(void);

void func_0041C4B0(struct MenuNoticeData *data)
{
    if (func_0012E560(data) == 0)
        return;
    if (func_003299D0() != 0)
        return;

    D_004C2530 = 1.0f;
    D_004C2B5C = 0;
    D_004C27C4 = 1;
    D_004C2B60 = 0;
    D_004C27C0 = 30;
    D_004C2B64 = 0;
    D_004C2B68 = 0;
    func_003DA650(13);
    func_00146C80(5);
    func_003298B0(-16777216, 10, 0);
    func_0012ACC0((s32)func_0041CA40);
    *(void (**)(void))0x0043CD0C = func_0041C550;
}
