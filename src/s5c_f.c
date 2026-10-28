/* MW 3.0, compiled in the same mwccps2 invocation after src/e080_b.c (soft-float warm): -O3 -Op -fp off -sdatathreshold 8 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840; typedef struct { u8 pad[0x340]; s16 h340; u8 pad2[0xF6]; s16 h438; } S4;

void func_0018F8C0(u8 *p, s16 *q)
{
    s32 n;
    f32 r;
    s16 v;
    s32 h;

    n = *q;
    if (n == 0) {
        return;
    }
    if (*(s8 *)(D_004C2840 + 0x57) != 0) {
        r = n;
    } else {
        switch (*(s8 *)(D_004C2840 + 0x55)) {
        case 0:
            if (p[0x425] != 0) {
                return;
            }
            r = (f32)((s16)n * 3) / 4.0f;
            if (r < 1.0f) {
                r = 1.0f;
            }
            break;
        case 1:
            return;
        case 2:
            r = n;
            break;
        }
    }
    h = *(s16 *)(p + 0x438);
    v = h - (s32)r;
    ((S4 *)p)->h438 = v;
    if (v < 0) {
        *(s16 *)(p + 0x438) = 0;
    }
    ((S4 *)p)->h340 = (s16)r;
}
