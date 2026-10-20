typedef unsigned int u32;
extern int func_0010CA20(void);
extern int func_0010CA68(void);
#define I_STAT (*(volatile u32 *)0x1000F000)

void func_00104270(void)
{
    int interruptsEnabled;

    interruptsEnabled = func_0010CA20();
    I_STAT = 4;
    __asm__ volatile ("sync" ::: "memory");
    if (interruptsEnabled != 0)
        func_0010CA68();

    while ((I_STAT & 4) == 0) {
    }

    interruptsEnabled = func_0010CA20();
    I_STAT = 4;
    __asm__ volatile ("sync" ::: "memory");
    if (interruptsEnabled != 0)
        func_0010CA68();
}
