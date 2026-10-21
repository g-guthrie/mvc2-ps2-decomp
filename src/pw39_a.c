typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long u64;

/* EE GCC 2.96: ./tryee.sh src/pw39_a.c sn */
typedef struct { s32 a; s32 b; s32 c[10]; } T;

extern void func_003F81C8(s32 a);
void func_00400020(s32 *p) { func_003F81C8(p[1]); }

s32 func_0040F1E0(s32 *p, s32 n) {
    if (n == 1) return p[3];
    if (n != 0) {
        void (*f)(s32, s32) = (void (*)(s32, s32))p[7];
        if (f != 0) {
            f(p[8], -3);
            return 0;
        }
    }
    return 0;
}

extern u8 D_00488ED0[];
extern s32 func_0040AAB8(s32, T *);
extern void func_0040A440(s32, u8 *);
extern void func_0010F148(s32);
extern s32 func_004098D8(T *, u8 *);
s32 func_00409B58(s32 a) {
    T t;
    s32 r = 0;
    if (a != 0) {
        func_0040AAB8(a, &t);
        if (t.b == 0) {
            func_0040A440(a, D_00488ED0);
            func_0010F148(0);
            if (func_004098D8(&t, D_00488ED0) == 0) return r;
        }
        r = 1;
    }
    return r;
}

extern u8 D_004BE2F8[];
extern void func_0040D5A0(u8 *);
extern void func_0040D040(void *);
void func_0040CFD8(s8 *p) {
    if (p == 0) {
        func_0040D5A0(D_004BE2F8);
        return;
    }
    if (p[1] != 0) func_0040D040(p);
    if (*(s32 *)((u8 *)p + 0x24) > 0) p[1] = 2; else p[1] = 1;
}

extern u8 D_004BE2D8[];
extern s32 func_00400528(s32, s32);
extern s32 func_00400BE0(s32, s32);
extern void func_004005F8(u8 *);
extern s32 func_0040CE38(s32 *, s32, s32, s32, s32);
s32 func_0040CD78(s32 *a, s32 b) {
    s32 r = func_00400528(b, a[2]);
    s32 n;
    if (r == 0) {
        func_0040D5A0(D_004BE2D8);
        return -1;
    }
    n = (func_00400BE0(r, b) + 0x7FF) / 2048;
    func_004005F8((u8 *)r);
    return func_0040CE38(a, b, 0, 0, n);
}
