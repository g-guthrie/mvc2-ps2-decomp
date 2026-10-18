typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18A6;
extern u8 D_004D18A0[];

void func_00327FB0(u8 *p)
{
    extern void func_00183AD0();
    s32 i;
    u8 *o;
    s16 h;
    u32 t;
    if (D_004D18A6 == 0) {
        t = p[4];
        p[4] = t + 1;
    } else if (p[5] == 0) {
        if (*(u8 *)(*(u8 **)(p + 0x18) + 0x404) == 0) {
            p[5] = p[5] + 1;
        }
    } else {
        h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h < 0) {
            t = p[4];
            p[4] = t + 1;
            for (i = 0; i < 3; i++) {
                o = *(u8 **)(D_004D18A0 + p[2] * 12 + i * 4 + 0x18);
                if (o[0] != 0 && o[5] != 2) {
                    o[0x1B4] = 1;
                }
            }
            for (i = 0; i < 3; i++) {
                o = *(u8 **)(D_004D18A0 + (p[2] ^ 1) * 12 + i * 4 + 0x18);
                if (o[0] != 0 && o[5] == 3) {
                    o[0x1B4] = 10;
                }
            }
            *(u8 *)(*(u8 **)(p + 0x18) + 0x1FF) = 0xC;
            *(u8 *)(*(u8 **)(p + 0x18) + 0x201) = 0xC;
            *(u8 *)(*(u8 **)(p + 0x18) + 0x1B1) = 0;
            func_00183AD0(*(u8 **)(p + 0x18));
        }
    }
}

