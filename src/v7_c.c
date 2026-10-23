typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void (*D_004BF7E0[16])(u8 *, u8 *) __attribute__((section(".sdata")));

void func_001A9D20(u8 *p, u8 *q) {
    D_004BF7E0[p[7]](p, q);
    if (q[0x1E4] == 0x1D) {
        switch (q[0x1FD]) {
        case 5:
            *(u32 *)(p + 0xD0) = p[6];
            *(u32 *)(p + 0xD4) = p[7];
            p[6] = 0xF;
            p[7] = 0;
            return;
        case 4:
            *(u32 *)(p + 0xD0) = p[6];
            *(u32 *)(p + 0xD4) = p[7];
            p[6] = 0x11;
            p[7] = 0;
            return;
        }
        return;
    }
}
