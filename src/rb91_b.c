typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x1A]; s8 b1A; u8 pad1B[0x24 - 0x1B]; s32 w24; u8 pad28[0x91 - 0x28]; s8 b91; } G91b;
typedef struct { s32 w0; s32 w4; s32 w8; s32 wC; u16 d[16]; } Pal91;

extern G91b *D_004C2840;
extern f32 D_004C26C4;
extern s32 D_004C26C8;
extern s32 D_004C26C0;
extern s32 D_004C26BC;
extern s32 D_004C26B4;
extern s32 D_004C26B8;
extern f32 D_004F1C20[];
extern f32 D_004F1C24[];
extern f32 D_004F1C28[];
extern f32 D_004F1C2C[];
extern f32 D_004F1C30[];
extern f32 D_004F1C34[];
extern f32 D_004F1C38[];
extern f32 D_004F1C3C[];
extern f32 D_004F1C00[];
extern f32 D_004F1C04[];
extern f32 D_004F1C08[];
extern f32 D_004F1C0C[];
extern f32 D_004F1C10[];
extern f32 D_004F1C14[];
extern f32 D_004F1C18[];
extern f32 D_004F1C1C[];
extern f32 D_004ACD10[];
extern f32 D_004ACD14[];
extern f32 D_004ACD18[];
extern f32 D_004ACD1C[];
extern f32 D_004ACD20[];
extern f32 D_004ACD24[];
extern f32 D_004ACD28[];
extern f32 D_004ACD2C[];
extern u8 D_004CB280[];
extern Pal91 D_004F54D0[];
extern u16 D_004F44D0[];

void func_00174BC0(void) {
    extern void func_00417FE0(s32);
    extern void func_00176360(s32, u16 *, s32);
    G91b *g;
    s8 *pb;
    s32 i;
    Pal91 *e;
    s32 off;
    s32 j;
    g = D_004C2840;
    pb = &g->b1A;
    if (g->b1A == 0 && g->b91 == 0) {
        f32 f;
        f = (D_004C26C4 += 0.01f);
        D_004C26C8 += 1;
        if (f > 1.0f) {
            D_004C26C4 = 0.5f;
        }
    }
    if (((D_004C26C8 + *pb) & 1) != 0) {
        D_004C26C0 = 0x190;
        D_004C26BC = 0x10;
    } else {
        D_004C26C0 = 0x10;
        D_004C26BC = 0x190;
    }
    g->w24 = 0;
    D_004F1C20[0] = 10.0f;
    D_004F1C24[0] = 11.0f;
    D_004F1C28[0] = 12.0f;
    D_004F1C2C[0] = 13.0f;
    D_004F1C30[0] = 30.0f;
    D_004F1C34[0] = 31.0f;
    D_004F1C38[0] = 32.0f;
    D_004F1C3C[0] = 33.0f;
    D_004C26B4 = (s32)D_004CB280;
    D_004C26B8 = 0;
    D_004F1C00[0] = D_004ACD10[0];
    D_004F1C04[0] = D_004ACD14[0];
    D_004F1C08[0] = D_004ACD18[0];
    D_004F1C0C[0] = D_004ACD1C[0];
    D_004F1C10[0] = D_004ACD20[0];
    D_004F1C14[0] = D_004ACD24[0];
    D_004F1C18[0] = D_004ACD28[0];
    D_004F1C1C[0] = D_004ACD2C[0];
    func_00417FE0(0);
    e = D_004F54D0;
    for (i = 0, off = 0; i < 0x80; i++, e++, off += 0x20) {
        if (e->w8 != 0) {
            u16 *src = e->d;
            u16 *dst = (u16 *)((u8 *)D_004F44D0 + off);
            u16 *base = dst;
            j = 0;
            do {
                if (e->w8 & 1) {
                    *dst = *src;
                    src++;
                    dst++;
                } else if (e->w8 & 2) {
                    s32 x = *src;
                    s32 c1, c2, c3, c4;
                    src++;
                    c1 = (s16)(x & 0xF000);
                    c2 = (s16)(((x & 0xF00) >> 1) & 0xF00);
                    c3 = (s16)(((x & 0xF0) >> 1) & 0xF0);
                    c4 = (s16)((x & 0xF) >> 1);
                    c1 |= c2; c1 = c3 | c1; c1 = c4 | c1;
                    *dst = c1;
                    dst++;
                }
                j++;
            } while (j < 16);
            e->w8 = 0;
            func_00176360(e->w0, base, (u32)e->w4);
        }
    }
}
