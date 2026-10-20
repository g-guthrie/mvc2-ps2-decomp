/* Preserve interrupt state while operating on 64-byte cache lines. */
typedef unsigned int u32;
extern int func_0010CA20(void);
extern int func_0010CA68(void);
extern void func_00104630(void *,void *);
extern void func_00104770(void *,void *);
void func_001046D8(void *start,void *end)
{
    u32 status;
    __asm__ volatile("mfc0 %0,$12" : "=r"(status));
    status &= 0x10000u;
    if (status) func_0010CA20();
    func_00104630((void *)((u32)start & ~63u), (void *)((u32)end & ~63u));
    if (status) func_0010CA68();
}
void func_00104818(void *start,void *end)
{
    u32 status;
    __asm__ volatile("mfc0 %0,$12" : "=r"(status));
    status &= 0x10000u;
    if (status) func_0010CA20();
    func_00104770((void *)((u32)start & ~63u), (void *)((u32)end & ~63u));
    if (status) func_0010CA68();
}
