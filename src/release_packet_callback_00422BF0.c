typedef signed int s32;
typedef unsigned short u16;

extern s32 func_00104C90(void *common);

/* Forward the alarm's thread-ID userdata and apply the EE ExitHandler workaround. */
void func_00422BF0(s32 alarmId, u16 time, void *common)
{
    func_00104C90(common);
    __asm__ volatile ("sync\n\tei");
}
