/* Complete native helper bodies preserve the original call-register usage.
 * Each helper is independently verified at its own address, with no new credit. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2704 __attribute__((section(".sdata")));
static void func_001BF550(u8 *a0) {
    if (*D_004C2704 < 11) {
        s16 t = *(s16 *)(a0 + 0x1E) - 1;
        *(s16 *)(a0 + 0x1E) = t;
        if (t <= 0) {
            u32 c;
            *(s16 *)(a0 + 0x1E) = 1;
            c = *D_004C2704;
            *D_004C2704 = c + 1;
            *(f32 *)(a0 + 0x34) += 53.333332f;
        }
    }
}

void func_001BF860(u8 *p) {
    if(*(s16*)(*(u8**)(p+0x18)+0x1c)<=0) {
        ++p[5];
        *(s16*)(p+0x1c)=10;
        *(float*)(p+0x54)=1.0f;
    }
    func_001BF550(p);
}
