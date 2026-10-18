typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C28CC;
extern s32 D_004C28C8;
extern s32 D_004C28C4;
extern s32 D_004C28C0;

void func_001E7900(u8 *p, u8 *q)
{
    extern void func_001E7A20(u8 *, u8 *, s32);
    extern void func_001E7AE0(u8 *, u8 *, s32);
    u16 *h;
    s32 n;
    D_004C28CC = 0;
    D_004C28C8 = 0;
    D_004C28C4 = 0;
    D_004C28C0 = 0;
    h = *(u16 **)(p + 0x1D4);
    n = *(s16 *)h & 0x1FFF;
    if (n != 0) {
        func_001E7A20(p, q, n);
        if (*(s8 *)(q + 0x1B3) != 0) {
            func_001E7AE0(p, q, n);
            return;
        }
        if ((s16)h[1] > 0) {
            func_001E7A20(p, q, h[1] & 0x1FFF);
            if (*(s8 *)(q + 0x1B3) != 0) {
                func_001E7AE0(p, q, h[1] & 0x1FFF);
            }
        }
    } else {
        if ((s16)h[1] > 0) {
            func_001E7A20(p, q, h[1] & 0x1FFF);
            if (*(s8 *)(q + 0x1B3) != 0) {
                func_001E7AE0(p, q, h[1] & 0x1FFF);
            }
        }
    }
}
