typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s8 D_004405A0[];
extern V3 D_00440550[][3];
extern u32 D_004C2830;
extern u8 *D_004C2840;
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_0013D300(void);

void func_0013D0F0(u8 *p) {
    u8 *o;
    if (p[0x21] == D_004405A0[((s8 *)*(u8 **)(p + 0x14))[0x540]]) {
        if ((o = func_003DA750(0, 6, 1)) != 0) {
            o[0x13C] = 1;
            *(u32 *)(o + 0x18) = *(u32 *)(p + 0x18);
            *(u8 **)(o + 0xC8) = p + 0x88;
            *(u32 *)(o + 0x14) = *(u32 *)(p + 0x14);
            o[0x20] = p[0x20];
            o[0x21] = p[0x21];
            *(s16 *)(o + 0xCC) = 0xB3;
            *(u32 *)(o + 0x84) = D_004C2830;
            *(void **)(o + 0x10) = (void *)func_0013D300;
            *(V3 *)(o + 0x34) = D_00440550[o[0x20]][o[0x21]];
            if (o[0x20]) {
                *(u32 *)(o + 0x40) = 0x2000;
                *(u32 *)(o + 0x44) = 0x8000;
            } else {
                *(u32 *)(o + 0x40) = 0xE001;
                *(u32 *)(o + 0x44) = 0;
            }
            *(u32 *)(o + 0xD0) = 0x807;
            if ((o = func_003DA750(0, 6, 1)) != 0) {
                o[0x13C] = 1;
                *(u32 *)(o + 0x18) = *(u32 *)(p + 0x18);
                *(u8 **)(o + 0xC8) = p + 0x88;
                *(u32 *)(o + 0x14) = *(u32 *)(p + 0x14);
                o[0x20] = p[0x20];
                o[0x21] = p[0x21];
                if (((s8 *)D_004C2840)[0x29]) {
                    *(s16 *)(o + 0xCC) = 0xAE;
                    *(u32 *)(o + 0x84) = D_004C2830;
                } else {
                    *(s16 *)(o + 0xCC) = 0xB4;
                    *(u32 *)(o + 0x84) = D_004C2830;
                }
                *(void **)(o + 0x10) = (void *)func_0013D300;
                *(V3 *)(o + 0x34) = D_00440550[o[0x20]][o[0x21]];
                *(f32 *)(o + 0x3C) += 0.1f;
                *(u32 *)(o + 0x40) = 0xE001;
                *(u32 *)(o + 0xD0) = 0x803;
            }
        }
    }
}
