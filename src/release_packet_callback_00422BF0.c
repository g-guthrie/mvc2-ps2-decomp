typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;

extern s32 func_00104C90(s32 threadId);

/* Wake the thread ID carried as alarm common data, then apply ExitHandler. */
void func_00422BF0(s32 alarmId, u16 time, void *common)
{
    func_00104C90((s32)(u32)common);
    __asm__ volatile ("sync\n\tei");
}
