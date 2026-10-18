extern void func_00104210(int, void *);

void func_00104F08(int a0, int a1, int a2) {
    struct {
        int f0, f4, f8;
    } buf;

    buf.f4 = a1;
    buf.f8 = a2 & 0xFFFF;
    buf.f0 = a0;
    func_00104210(-5, &buf);
}
