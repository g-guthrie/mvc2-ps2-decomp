typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct G { u8 pad[0x1C]; s32 f1C; } G;

extern G *D_004C2840;
extern int func_00175700(u8 *);

void func_0036E520(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 0x54) += 0.2f;
    if (!(*(f32 *)(p + 0x54) < 1.0f))
        p[0x24] = 0xB;
    if (!(*(f32 *)(p + 0x54) < 2.0f)) {
        *(u32 *)(p + 0x54) = 0;
        p[0x24] = 0xA;
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 1;
        if (*(s16 *)(p + 0x1E) == 0)
            p[5]++;
    }
    *(f32 *)(p + 0x50) = 1.0f;
    if ((D_004C2840->f1C & 1) == 0)
        *(f32 *)(p + 0x50) = 0.8f;
}
