typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y, z; } Float3;

extern u8 *func_003DA750(void *, int, int);
extern void func_00157290(u8 *);
extern u32 D_004C2838;
extern Float3 D_00444C70[];

void func_00157330(Float3 *pos, int idx)
{
    u8 *p = func_003DA750(0, 9, 1);
    if (p) {
        Float3 off;
        p[0x13C] = 1;
        *(void (**)(u8 *))(p + 0x10) = func_00157290;
        *(s16 *)(p + 0xCC) = (s16)(idx + 0x2C);
        *(u32 *)(p + 0x84) = D_004C2838;
        *(u32 *)(p + 0xD0) = 0x800401;
        off = D_00444C70[idx];
        *(f32 *)(p + 0x34) = pos->x + off.x;
        *(f32 *)(p + 0x38) = pos->y + off.y;
        *(f32 *)(p + 0x3C) = pos->z + off.z;
        *(f32 *)(p + 0x5C) = -off.x / 15.0f;
        *(f32 *)(p + 0x60) = -off.y / 15.0f;
        *(f32 *)(p + 0x64) = -off.z / 15.0f;
        *(f32 *)(p + 0x50) = 1.0f;
        *(f32 *)(p + 0x54) = 1.0f;
        *(f32 *)(p + 0x58) = 1.0f;
        *(f32 *)(p + 0x78) = 1.0f;
        *(f32 *)(p + 0x7C) = 1.0f;
        *(f32 *)(p + 0x80) = 1.0f;
    }
}
