extern void func_00104C90(int);
void func_00110748(int a, int b, int c) {
    func_00104C90(c);
    __asm__ volatile("sync\n\tei");
}
