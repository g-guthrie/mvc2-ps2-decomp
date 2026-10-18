typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 func_00175700();
extern void func_001E3240(void *p, s32 a);
extern void func_003891D0();
extern void *D_004C1D90[2];
void func_00388A80(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (q[0x1E4] != 0x1D) {
        func_001E3240(p, 0x1E);
        {
            u32 t = p[4]; p[4] = t + 1;
        }
        p[0x13C] = 0;
    } else {
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        func_003891D0(p, q);
        ((void (*)(u8 *, u8 *))D_004C1D90[p[5]])(p, q);
    }
}
