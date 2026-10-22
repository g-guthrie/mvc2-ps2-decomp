typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[3]; s8 b3; s8 b4; } G67;
extern G67 *D_004C2840;
extern s32 D_00442860[];
extern s32 D_00442864[];
extern f32 D_00442850[];
extern f32 D_00442854[];
extern f32 D_004427C8[];
extern f32 D_004427CC[];
extern f32 D_004427D0[];
extern f32 D_004427BC[];
extern f32 D_004427C0[];
extern f32 D_004427C4[];

void func_001467E0(u8 *p, s32 b, s32 idx)
{
    s16 h;
    u8 t;

    h = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = h;
    if (*(s16 *)(p + 0x1C) >= D_00442860[idx])
        *(s16 *)(p + 0x1C) = 0;
    h = *(s16 *)(p + 0x1E) + 1;
    *(s16 *)(p + 0x1E) = h;
    if (*(s16 *)(p + 0x1E) >= D_00442864[idx])
        *(s16 *)(p + 0x1E) = 0;
    *(s32 *)(p + 0xD0) |= 0x20000;
    if (p[0x20] == 0) {
        *(f32 *)(p + 0xE0) = -(1.0f - (f32)*(s16 *)(p + 0x1C) * D_00442850[idx]);
        *(f32 *)(p + 0xE4) = 1.0f - (f32)*(s16 *)(p + 0x1E) * D_00442854[idx];
    } else {
        *(f32 *)(p + 0xE0) = 1.0f - (f32)*(s16 *)(p + 0x1C) * D_00442850[idx];
        *(f32 *)(p + 0xE4) = -(1.0f - (f32)*(s16 *)(p + 0x1E) * D_00442854[idx]);
    }
    if (p[0x20] == 0 && p[0x21] == 1) {
        t = p[5];
        switch (t) {
        case 0:
            if (D_004C2840->b3 == 3 && D_004C2840->b4 == 1) {
                p[5] = t + 1;
                *(s32 *)(p + 0xD8) = 0x1E;
                *(f32 *)(p + 0x5C) = (D_004427C8[0] - *(f32 *)(p + 0x78)) / 30.0f;
                *(f32 *)(p + 0x60) = (D_004427CC[0] - *(f32 *)(p + 0x7C)) / 30.0f;
                *(f32 *)(p + 0x64) = (D_004427D0[0] - *(f32 *)(p + 0x80)) / 30.0f;
            }
            break;
        case 1:
        case 3:
            {
                s32 v = *(s32 *)(p + 0xD8) - 1;
                *(s32 *)(p + 0xD8) = v;
                if (v < 0) {
                    if (p[5] == 3)
                        p[5] = 0;
                    else
                        p[5] = p[5] + 1;
                } else {
                    *(f32 *)(p + 0x78) += *(f32 *)(p + 0x5C);
                    *(f32 *)(p + 0x7C) += *(f32 *)(p + 0x60);
                    *(f32 *)(p + 0x80) += *(f32 *)(p + 0x64);
                }
            }
            break;
        case 2:
            if (D_004C2840->b3 != 3 && D_004C2840->b4 != 1) {
                p[5] = t + 1;
                *(s32 *)(p + 0xD8) = 0x1E;
                *(f32 *)(p + 0x5C) = (D_004427BC[0] - *(f32 *)(p + 0x78)) / 30.0f;
                *(f32 *)(p + 0x60) = (D_004427C0[0] - *(f32 *)(p + 0x7C)) / 30.0f;
                *(f32 *)(p + 0x64) = (D_004427C4[0] - *(f32 *)(p + 0x80)) / 30.0f;
            }
            break;
        }
    }
}
