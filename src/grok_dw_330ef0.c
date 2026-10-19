/* Metrowerks 3.0: ./try.sh src/grok_dw_330ef0.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C283C;
extern f32 func_00417F60(void);
extern void func_00170E60(
    void *, void *, void *, void *, void (*)(u8 *, u8 *, s32), s32);
extern void func_00331350(u8 *, u8 *, s32);

void func_00330EF0(u8 *p)
{
    f32 z;
    f32 c;
    f32 k;
    u8 *s;
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 2;
    if (*(s16 *)(p + 0x1C) >= 0x168)
        *(s16 *)(p + 0x1C) = 0;
    *(f32 *)(p + 0x68) += *(f32 *)(p + 0x6C);
    z = 0.0f;
    if (*(f32 *)(p + 0x6C) > z) {
        c = -4.999999987376214e-07f;
        *(f32 *)(p + 0x6C) = *(f32 *)(p + 0x6C) + c;
    }
    k = 4.999999873689376e-06f;
    if (*(f32 *)(p + 0x68) <= k) {
        *(f32 *)(p + 0x68) = 0.0f;
        *(f32 *)(p + 0x6C) = 1.9999999494757503e-05f * func_00417F60();
    }
    s = *(u8 **)(p + 0x84);
    func_00170E60(
        *(u8 **)(D_004C283C + 0x14),
        (void *)*(u32 *)(*(u8 **)(s + 0x1C) + 0x18),
        (void *)*(u32 *)(s + 0x14),
        (void *)*(u32 *)((s32)*(u8 **)(s + 0x1C) + *(s16 *)(p + 0xCC) * 4),
        func_00331350,
        (s32)p);
}
