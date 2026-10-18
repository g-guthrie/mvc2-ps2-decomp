typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x5B8]; } E;
extern u8 D_00583B90[];
extern u8 D_00583BE2[];
extern E D_004F20B0[];
extern s8 D_004F7F3F[];
extern u8 *D_004C2840;

void func_0032B690(u8 *p) {
    s16 c;
    u8 *g;
    extern void func_0032BEF0();
    extern void func_0013A070();
    if (D_00583B90[*(s8 *)(p + 0x538)] != 3) {
        return;
    }
    p[5] = 0;
    p[6] = 0;
    c = *(s16 *)(p + 0x1E);
    *(s16 *)(p + 0x1E) = c + 1;
    if (c >= 2) {
        *(E **)(p + 0x18) = &D_004F20B0[*(s8 *)(p + 0x538) + *(s16 *)(p + 0x1E) * 2];
        g = D_004C2840;
        if (*(s8 *)(g + 0x49) != 0) {
            p[4] = 0xB;
            g = D_004C2840;
            *(s8 *)(g + 0x8D) = *(s8 *)(g + 0x49);
            D_00583BE2[*(s8 *)(p + 0x538)] = 1;
            g = D_004C2840;
            if (*(s8 *)(g + 0xAA) != 0 || *(s8 *)(g + 0x4C) == 5 || *(s8 *)(g + 0x4C) == 7) {
                func_0032BEF0();
                return;
            }
            p[4] = 7;
            D_00583BE2[*(s8 *)(p + 0x538)] = 0;
            func_0013A070(p, 1);
        } else {
            if (D_004F7F3F[0] != 0) {
                if (*(s8 *)(g + 0x90) == *(s8 *)(p + 0x4DC)) {
                    p[4] = 0xB;
                    return;
                }
            }
            p[4] = 7;
            D_00583BE2[*(s8 *)(p + 0x538)] = 0;
            func_0013A070(p, 1);
        }
    } else {
        p[4] = 3;
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    }
}
