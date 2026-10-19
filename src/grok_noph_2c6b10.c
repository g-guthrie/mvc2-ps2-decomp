/* Metrowerks 3.0: ./try.sh src/grok_noph_2c6b10.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);

void residual_002C6B10(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x161)) {
        p[6]++;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? 14.1666660309f : -14.1666660309f;
        *(f32 *)(p + 0x68) = p[0x1E6] ? -0.7291666269302368f : 0.7291666269302368f;
    }
}
