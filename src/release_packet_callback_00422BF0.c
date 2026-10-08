typedef signed int s32;

extern s32 func_00104C90(s32 token);

/* Release the registered packet token and restore EE interrupt delivery. */
void func_00422BF0(s32 context, s32 ignored, s32 token)
{
    func_00104C90(token);
    __asm__ volatile ("sync\n\tei");
}
