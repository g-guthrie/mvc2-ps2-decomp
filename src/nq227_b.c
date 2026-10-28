typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef void (*DispatchFn)(u8 *);

extern s8 D_004D18DC[];
extern s8 D_004D18DB[];
extern DispatchFn jtbl_00472810[];

void residual_0039E580(u8 *p) {
    p[0x96] = D_004D18DC[0] & (1 << D_004D18DB[0]);
    jtbl_00472810[p[4]](p);
}
