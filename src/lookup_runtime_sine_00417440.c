typedef unsigned int u32;
typedef float f32;

/* Interior entry point into the existing floating-point table. */
extern f32 D_00496A50[];

f32 func_00417440(u32 angle)
{
    u32 quadrant = angle & 0xC000;

    switch (quadrant)
    {
    case 0:
        return D_00496A50[angle & 0xFFFF];
    case 0x4000:
        return D_00496A50[0x8000 - (angle & 0xFFFF)];
    case 0x8000:
        return -D_00496A50[angle & 0x3FFF];
    case 0xC000:
        return -D_00496A50[0x10000 - (angle & 0xFFFF)];
    default:
        return 0.0f;
    }
}
