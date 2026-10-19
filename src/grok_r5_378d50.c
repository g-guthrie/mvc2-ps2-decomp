typedef unsigned char u8;
typedef float f32;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00464110[];

void residual_00378D50(u8 *p)
{
    jtbl_00464110[p[0x20]](p);
    *(f32 *)(p + 0x54) += 0.015625f;
}
