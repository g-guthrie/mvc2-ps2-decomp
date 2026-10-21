typedef unsigned int u32;
struct SyscallPatch { int number; void *handler; };
extern struct SyscallPatch D_00438980[2];
extern void *D_00438978;
extern int func_0010CAD8(u32 *, const u32 *, u32);
extern u32 *func_0010CB10(u32 *, u32 *, u32);
extern u32 *func_0010CB50(u32 *, u32 *, u32);
extern void func_0010CC98(int, void *);
void func_0010CB98(void)
{
    u32 first, second, first_base, second_base;
    func_0010CC98(D_00438980[0].number, D_00438980[0].handler);
    func_0010CC98(D_00438980[1].number, D_00438980[1].handler);
    first = (u32)func_0010CB50((u32 *)0x80000000u, (u32 *)0x80080000u, (u32)func_0010CB10);
    second = (u32)func_0010CB50((u32 *)0x80000000u, (u32 *)0x80080000u, (u32)func_0010CAD8);
    first_base = first - 0x20c;
    second_base = second - 0x168;
    while (first_base != second_base) {
        if (first_base < second_base) {
            first = (u32)func_0010CB50((u32 *)(first + 4), (u32 *)0x80080000u, (u32)func_0010CB10);
            first_base = first - 0x20c;
        } else {
            second = (u32)func_0010CB50((u32 *)(second + 4), (u32 *)0x80080000u, (u32)func_0010CAD8);
            second_base = second - 0x168;
        }
    }
    D_00438978 = (void *)first_base;
}
