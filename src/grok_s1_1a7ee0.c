typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern u8 *func_003DA750(u8 *, int, int);
extern f32 func_001A8CB0(u8 *);
extern void func_001A7FA0(u8 *, u8 *);
extern void func_001A7990(void);

void residual_001A7EE0(u8 *p, u8 *q)
{
    u8 *n;
    p[5]++;
    *(s16 *)(p + 0x1E) = 10;
    n = func_003DA750(p, 3, 2);
    if (n != 0) {
        *(void **)(n + 0x10) = (void *)func_001A7990;
        *(u8 **)(n + 0x18) = q;
        *(s16 *)(n + 0x1E) = *(s16 *)(p + 0x1E) - 1;
        n[0x20] = (func_001A8CB0(p) < 80.0f) ? 6 : 5;
    }
    func_001A7FA0(p, q);
}
