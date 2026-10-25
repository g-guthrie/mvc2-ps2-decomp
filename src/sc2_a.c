typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *,void *);

extern const DispatchFn jtbl_004761D0[];

void func_003C81C0(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    q[0x2BF] = 2;
    q[0x205] = 2;
    jtbl_004761D0[p[4]](p,q);
}

typedef unsigned int u32x;
typedef float f32;
extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);

void func_002AE030(u8 *p)
{
    f32 a, b;
    u32x t;
    t = p[6]; p[6] = t + 1;
    func_00185490(p);
    func_0018C4B0(p, 2);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    *(short *)(p + 0x1C) = 0;
    *(int *)(p + 0x60) = 0;
    *(int *)(p + 0x6C) = 0;
    if (p[0x1FD] == 0x10) {
        a = p[0x212] ? 16.66666603088379f : 25.0f;
        b = p[0x212] ? -0.6770833134651184f : -0.78125f;
    } else {
        a = p[0x212] ? -16.66666603088379f : -23.333332061767578f;
        b = p[0x212] ? 0.6770833134651184f : 0.78125f;
    }
    if (p[0x1E6] != 0) *(f32 *)(p + 0x5C) = a; else { a = -a; *(f32 *)(p + 0x5C) = a; }
    if (p[0x1E6] != 0) *(f32 *)(p + 0x68) = b; else { b = -b; *(f32 *)(p + 0x68) = b; }
    func_001757E0(p, 0x15, 0x2B);
}
