typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);

void func_001AA4E0(u8 *a, u8 *b) {
    u8 *q = b + 0x2B8;
    func_00175700(a);
    if (b[0x1E4] == 0x1D && b[0x1FD] == 5 && *(s16 *)(a + 0x1E) < q[7]) {
        return;
    }
    {
        u32 t = a[7];
        a[7] = t + 1;
        func_001757E0(a, 0x17, 0x42);
    }
}
