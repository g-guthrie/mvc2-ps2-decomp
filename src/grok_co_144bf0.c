typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern signed char *D_004C2840;
extern void func_003DAA40(u8 *);
extern void func_001448E0(u8 *);

void func_00144BF0(u8 *p)
{
    if (D_004C2840[2] != 5) {
        func_003DAA40(p);
    } else if (*(s16 *)(p + 0x1C) != 0x5A) {
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
        func_001448E0(p);
    } else {
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 1;
        if (*(s16 *)(p + 0x1E) >= 0xC8)
            *(s16 *)(p + 0x1E) = 0;
        *(u32 *)(p + 0xD0) |= 0x20000;
        *(u32 *)(p + 0xE0) = 0;
        *(f32 *)(p + 0xE4) = 1.0f - 0.004999999888241291f * (f32)*(s16 *)(p + 0x1E);
    }
}
