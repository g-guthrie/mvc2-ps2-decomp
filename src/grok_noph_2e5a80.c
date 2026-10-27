/* Metrowerks 3.0: ./try.sh src/grok_noph_2e5a80.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern void func_001E3210(u8 *, int);
extern u8 *func_001D45D0(u8 *, u8);

void func_002E5A80(u8 *p)
{
    f32 y;

    p[6]++;
    p[0x2B8] = 0;
    func_001E3210(p, 30);
    func_001D45D0(p, 0);
    y = 160.0f;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x5C) = 0x40DC0000;
    if (p[0x1E6]) {
        y = -y;
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
    *(f32 *)(p + 0x34) += y;
    *(u32 *)(p + 0x68) = 0;
}
