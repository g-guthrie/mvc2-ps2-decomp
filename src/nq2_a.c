typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
typedef float f32;

/* 6-byte entries; the s16 at +2 is read. */
typedef struct { s16 x; s16 y; s16 z; } T3;
extern T3 D_00464930[];

/* jtbl_004649C0[0]: case body reached from func_00387A80's dispatch. */
void residual_00387AA0(u8 *a, u8 *b) {
    extern void func_00387AF0(u8 *, u8 *);
    u32 t;
    s16 *q;
    t = a[5];
    a[5] = t + 1;
    q = (s16 *)((u8 *)D_00464930 + a[0x20] * 6);
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) + (f32)q[1];
    func_00387AF0(a, b);
}
