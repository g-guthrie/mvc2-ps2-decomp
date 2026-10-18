typedef signed int s32;
extern void func_001191F0(void *, void *);
extern long long func_001192B0(void *, void *, void *);
extern long long func_00119118(long long);
long long func_00119510(long long a, long long b) {
    s32 x[8], y[8], z[8];
    func_001191F0(&a, x);
    func_001191F0(&b, y);
    return func_00119118(func_001192B0(x, y, z));
}
