typedef unsigned int u32;
extern int func_0010CA20(void);
extern void func_0010CA68(void);
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

typedef unsigned long long u64;
extern void func_00104150(volatile u32 *flag, volatile u64 *value);
u64 func_00104300(void)
{
    volatile u32 flag = 0;
    volatile u64 value;
    int interrupts_enabled;
    func_00104150(&flag, &value);
    interrupts_enabled = func_0010CA20();
    I_STAT = 4;
    __asm__ volatile("sync" ::: "memory");
    if (interrupts_enabled)
        func_0010CA68();
    while ((I_STAT & 4) == 0 && flag == 0) {
    }
    interrupts_enabled = func_0010CA20();
    I_STAT = 4;
    __asm__ volatile("sync" ::: "memory");
    if (interrupts_enabled)
        func_0010CA68();
    return value;
}
