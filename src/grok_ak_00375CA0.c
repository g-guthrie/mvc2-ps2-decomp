typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern f32 func_00417500(void *);
extern f32 func_00417440(void *);
/* 0x004B84C8 */

void func_00375CA0(u8 *owner, u8 *p)
{
    u8 *s = *(u8 **)(p + 0x14);
    void *m = *(void **)(s + 0x48);
    f32 sc = (f32)((s16 *)0x004B84C8)[p[0x20]];
    f32 f20, f22, f1;
    f32 n;
    u32 sb = 0x80000000;
    n = *(f32 *)&sb;
    f20 = sc * func_00417500(m);
    f22 = f20 + n * func_00417440(m);
    f20 = sc * func_00417440(m);
    f1 = f20 + n * func_00417500(m);
    *(f32 *)(p + 0x34) = *(f32 *)(s + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(s + 0x38);
    if (owner[0x1E6])
        f22 = -f22;
    *(f32 *)(p + 0x34) += f22;
    *(f32 *)(p + 0x38) += f1;
}
