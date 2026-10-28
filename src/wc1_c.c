typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3c;
typedef struct { u8 pad[7]; s8 b7; } Gc;
typedef struct { u8 pad[0x1C]; s16 h1c; u8 pad2[0x16]; f32 f34; } Pc;

extern V3c D_0043F490[];
extern V3c D_0043F498[];
extern u8 D_00583B90[];
extern Gc *D_004C2840;

void func_0013CDE0(u8 *p)
{
    extern void func_003DAA40(void);
    u32 st;
    s32 i;
    u8 j;
    u8 c;
    V3c *e;
    st = p[4];
    switch (st) {
    case 0:
        *(f32 *)(p + 0x50) = 1.0f;
        *(f32 *)(p + 0x54) = 1.0f;
        *(f32 *)(p + 0x58) = 1.0f;
        *(f32 *)(p + 0x3C) = (f32)(0.5 + (double)(D_0043F498[p[0x21]].x));
        *(f32 *)(p + 0x34) = D_0043F490[p[0x21]].x;
        if (D_004C2840->b7 != 0) {
            p[4]++;
            p[0x13C] = 0;
            return;
        }
        *(s16 *)(p + 0x1C) += 1;
        if (*(s16 *)(p + 0x1C) >= 500) ((Pc *)p)->h1c = 0;
        *(u32 *)(p + 0xD0) |= 0x20000;
        *(u32 *)(p + 0xE0) = 0;
        *(f32 *)(p + 0xE4) = 0.0020000000949949026f * (f32)*(s16 *)(p + 0x1C);
        for (i = 0; (s16)i < 2; i = (s16)(i + 1)) {
            c = D_00583B90[(s16)i + 0x30];
            if (c != 0 && (j = (s8)c - 1, p[0x21] == j)) {
                if (i != 0) {
                    *(f32 *)(p + 0x50) = 1.149999976158142f;
                    *(f32 *)(p + 0x54) = 1.149999976158142f;
                    *(f32 *)(p + 0x58) = 1.149999976158142f;
                    e = &D_0043F490[j];
                    *(f32 *)(p + 0x3C) = (f32)(0.5 + (6.0 + (double)(e->z)));
                    if (*(f32 *)(p + 0x34) < 0.0f) {
                        ((Pc *)p)->f34 = e->x - 2.0f;
                    } else {
                        ((Pc *)p)->f34 = 2.0f + e->x;
                    }
                } else {
                    *(f32 *)(p + 0x50) = 1.2000000476837158f;
                    *(f32 *)(p + 0x54) = 1.2000000476837158f;
                    *(f32 *)(p + 0x58) = 1.2000000476837158f;
                    e = &D_0043F490[j];
                    *(f32 *)(p + 0x3C) = (f32)(0.5 + (double)(8.0f + e->z));
                    if (*(f32 *)(p + 0x34) < 0.0f) {
                        ((Pc *)p)->f34 = e->x - 2.0f;
                    } else {
                        ((Pc *)p)->f34 = 2.0f + e->x;
                    }
                }
            }
        }
        break;
    case 1:
        func_003DAA40();
        break;
    }
}
