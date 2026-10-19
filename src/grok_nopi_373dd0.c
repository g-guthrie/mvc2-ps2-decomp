/* Metrowerks 3.0: ./try.sh src/grok_nopi_373dd0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);

void residual_00373DD0(u8 *p)
{
    if (--*(s16 *)(p + 28) <= 0)
        p[6]++;
    *(f32 *)(p + 80) += 0.00800000037997961f;
    *(f32 *)(p + 84) += 0.00800000037997961f;
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    func_00175700(p);
    func_001E7F60(p);
}
