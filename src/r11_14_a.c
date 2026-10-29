typedef signed int s32;

/* Both are busy-wait delays: the nop runs are the original inline-asm
   timing delays, the surrounding control flow is C. */

extern s32 func_003FEAD0(void);
extern s32 func_003FEBD8(void);

void func_00418B10(void)
{
    __asm__("nop;nop;nop;nop;nop;nop");
    func_003FEAD0();
    func_003FEBD8();
}

void func_0041BAD0(void)
{
    extern s32 func_00104990(s32);
    s32 s0;
    while (((s0 = func_00104990(2)) | func_00104990(1)) != 0) {
        __asm__("nop;nop;nop;nop;nop;nop");
    }
}
