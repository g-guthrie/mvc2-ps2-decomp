typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 a, b, c; } T6_e;
typedef struct { u8 pad[0x30]; u32 f30, f34, f38, f3c; } K_e;
extern K_e *D_004C2840;

void func_0012BC00(u8 *p, s32 q)
{
    extern s32 func_00417A40();
    u32 m;
    s32 i, r, c, k;
    u32 *a, *b, *x, *y;
    K_e *d;

    *(s16 *)(p + 0x10) = 1;
    c = 0;
    r = func_00417A40() % 0x3B;
    for (i = 0; i < 0x3B; i++) {
        if (r >= 0x18 && r < 0x1B) {
            r++;
        } else {
            if (r >= 0x20) {
                a = &D_004C2840->f34;
                b = &D_004C2840->f3c;
            } else {
                a = &D_004C2840->f30;
                b = &D_004C2840->f38;
            }
            if ((*a & (1 << r)) != 0 && (*b & (1 << r)) == 0) break;
            r++;
            if (r >= 0x3B) r = 0;
        }
    }
    if (i != 0x3B) {
        *(s16 *)((q << 1) + (u32)p + 0x14) = r;
        x = &D_004C2840->f30;
        y = &D_004C2840->f38;
        for (k = 0; k <= 0x3A; k++) {
            if (k == 0x20) {
                x++;
                y++;
            }
            if (k < 0x18 || k > 0x1A) {
                m = 1 << k;
                if ((*x & m) != 0 && (*y & m) != 0) c++;
            }
        }
        ((T6_e *)(p + 0x1C))[q].a = (c + 1) * 100;
    } else {
        *(s16 *)((q << 1) + (u32)p + 0x14) = -1;
    }
}
