/* MWCC 3.0 -O3 -sdatathreshold 0 (try30.sh src/p1e.c). */
typedef signed int s32;
typedef float f32;

extern f32 D_00632750, D_00632754, D_00632758, D_00632760, D_00632764;
extern void func_003DD260(void *m);
extern void func_003DF850(s32 n, void *m);
extern void func_003DE680(f32 *a, f32 *b);

void func_00417DA0(f32 *src, f32 *dst) {
    f32 m[16];
    func_003DD260(m);
    func_003DF850(25, m);
    D_00632750 = src[0];
    D_00632754 = src[1];
    D_00632758 = src[2];
    func_003DE680(&D_00632760, &D_00632750);
    dst[0] = D_00632760;
    dst[1] = D_00632764;
}
