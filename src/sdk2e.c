extern void func_00104C90(int);
void func_00110748(int a, int b, int c) {
    func_00104C90(c);
    __asm__ volatile("sync\n\tei");
}

void func_00102EA8(void *dst, void *a, void *b) {
    __asm__ volatile(
        "lqc2 $vf4, 0($5)\n\t"
        "lqc2 $vf5, 0($6)\n\t"
        "vsub.xyzw $vf6, $vf4, $vf5\n\t"
        "sqc2 $vf6, 0($4)");
}
