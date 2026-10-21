typedef unsigned int u32;
typedef struct PatchEntry { int syscall_number; void *handler; } PatchEntry;
extern PatchEntry D_00439140[];
extern unsigned char D_00438998[];
extern int func_0010CD50(void);
extern void func_0010CCE8(int, void *);
extern void func_0010CCF8(void *, const void *, u32);
extern void *func_0010CD40(int);
extern void func_00104060(int);
void func_0010CDB8(void)
{
    unsigned int i;
    PatchEntry *entry;
    if (!func_0010CD50()) return;
    entry = D_00439140;
    func_0010CCE8(entry[0].syscall_number, entry[0].handler);
    func_0010CCF8((void *)0x80074000, D_00438998, 0x7a8);
    func_00104060(0);
    func_00104060(2);
    func_0010CCE8(entry[1].syscall_number, entry[1].handler);
    for(i = 2; i < 3; ++i) {
        void *handler = func_0010CD40(entry[i].syscall_number);
        func_0010CCE8(entry[i].syscall_number, handler);
    }
}
