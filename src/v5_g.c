typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C29C4;
static void func_0038E610(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    *(f32 *)(p + 52) = *(f32 *)(q + 52);
    q = *(u8 **)(p + 24);
    *(f32 *)(p + 56) = *(f32 *)(q + 56);
    *(f32 *)(p + 52) += *(f32 *)(D_004C29C4 + 8);
    *(f32 *)(p + 56) += *(f32 *)(D_004C29C4 + 12);
}

extern void (*D_004C1DF0[16])(u8 *);
void func_0038E8F0(u8 *p) {
    func_0038E610(p);
    D_004C1DF0[p[5]](p);
}
