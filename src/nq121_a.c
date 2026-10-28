typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3sa1j;
extern V3sa1j D_0043FA10[][3][3];
extern u8 D_00583BC3;
extern u8 D_00583BC6;

void func_001391E0(u8 *p)
{
    extern void func_0032D450(u8 *, s32, s32, f32);
    u8 t;
    u32 x;
    s16 h;
    if (D_00583BC6 != 0) return;
    t = p[6];
    switch (t) {
    case 0:
        x = (s8)D_00583BC3; x = (u8)((u32)*(s8 *)(p + 0xDC) ^ x);
        if (x == 0) break;
        p[6] = t + 1;
        *(s16 *)(p + 0x1E) = 0x1E;
        if (D_00583BC3 == 3) {
            func_0032D450(p, *(s16 *)(p + 0x1E), 0, D_0043FA10[p[0x20]][0][*(s32 *)(p + 0xD4)].x);
        } else {
            func_0032D450(p, *(s16 *)(p + 0x1E), 0, D_0043FA10[p[0x20]][(u8)x][*(s32 *)(p + 0xD4)].x);
        }
        *(s32 *)(p + 0xDC) |= (u8)x;
        break;
    case 1:
        h = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = h;
        if (*(s16 *)(p + 0x1E) <= 0) {
            p[5] = 0;
            p[6] = 0;
        } else {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        }
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        break;
    }
}
