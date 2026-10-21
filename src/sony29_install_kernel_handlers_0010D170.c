typedef unsigned int u32;
typedef struct PatchEntry { int syscall_number; void *handler; } PatchEntry;
extern PatchEntry D_004398C8[];
extern unsigned char D_00439160[];
extern unsigned char D_004398A0[];
extern void func_0010D108(int, void *);
extern void func_0010D118(void *, const void *, u32);
extern void *func_0010D160(int);
extern void func_00104060(int);
void func_0010D170(void)
{
    unsigned int i;
    PatchEntry *entry;
    if (*(volatile u32 *)0x10001810 & 0x100) return;
    entry = D_004398C8;
    func_0010D108(entry[0].syscall_number, entry[0].handler);
    func_0010D118((void *)0x80076000, D_00439160, 0x740);
    func_0010D118((void *)0x82000, D_004398A0, 0x28);
    func_00104060(0);
    func_00104060(2);
    func_0010D108(entry[1].syscall_number, entry[1].handler);
    for(i = 2; i < 8; ++i) {
        void *handler = func_0010D160(entry[i].syscall_number);
        func_0010D108(entry[i].syscall_number, handler);
    }
}
