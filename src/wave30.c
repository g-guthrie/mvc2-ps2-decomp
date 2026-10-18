typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_0035D340(u8 *p);
extern void (*D_004632D0[])(u8 *p);

void func_0035C9D0(u8 *a, u8 *b) {
    *(s8 *)(a + 36) = *(s8 *)(b + 36);
    if (b[361] != 22) {
        u32 t = a[4];
        a[4] = t + 1;
        func_0035D340(a);
    } else {
        D_004632D0[a[5]](a);
    }
}

void func_003B3880(u8 *a, u8 *b) {
    *(f32 *)(a + 52) = *(f32 *)(b + 52);
    *(f32 *)(a + 56) = *(f32 *)(b + 56);
    *(f32 *)(a + 60) = *(f32 *)(b + 60);
    if (*(s16 *)(a + 320) == 0) {
        *(f32 *)(a + 52) += *(f32 *)(a + 92);
    } else {
        *(f32 *)(a + 52) -= *(f32 *)(a + 92);
    }
    *(f32 *)(a + 92) -= 50.0f;
}
