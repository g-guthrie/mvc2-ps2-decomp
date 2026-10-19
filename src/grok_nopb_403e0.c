/* Metrowerks 3.0: ./try.sh src/grok_nopb_403e0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);

void func_002403E0(u8 *p)
{
    func_00175700(p);
    if ((signed char)p[337] == 0) {
        p[6]++;
        *(u32 *)(p + 92) = 0xC17D5555;
        *(u32 *)(p + 104) = 0x3EA00000;
        *(s16 *)(p + 30) = 24;
        if (p[486]) {
            *(f32 *)(p + 92) = -*(f32 *)(p + 92);
            *(f32 *)(p + 104) = -*(f32 *)(p + 104);
        }
        *(u32 *)(p + 96) = 0;
        *(u32 *)(p + 108) = 0;
    }
}
