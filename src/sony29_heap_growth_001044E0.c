typedef unsigned int u32;
struct Runtime;
extern struct Runtime *func_0011B370(void);
extern void *func_00103DC0(void);
extern void *D_00438254;
void *func_001044E0(int increment)
{
    u32 enabled,status,next;
    void *old;
    __asm__ volatile("mfc0 %0,$12" : "=r"(enabled));
    enabled &= 0x10000u;
    if(enabled) {
        do {
            __asm__ volatile("di" : : : "memory");
            __asm__ volatile("sync.p" : : : "memory");
            __asm__ volatile("mfc0 %0,$12" : "=r"(status));
        } while(status&0x10000u);
    }
    next=(u32)D_00438254+(u32)increment;
    if((u32)func_00103DC0()<next) {
        *(int *)(void *)func_0011B370()=12;
        if(enabled)__asm__ volatile("ei" : : : "memory");
        return (void *)-1;
    }
    old=D_00438254;
    D_00438254=(void *)next;
    if(enabled)__asm__ volatile("ei" : : : "memory");
    return old;
}
