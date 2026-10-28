typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 b0; u8 pad1; s16 h2; u8 pad4[6]; s16 hA; u8 padC[6]; s16 h12; u8 pad14[0xC]; } E46;
extern E46 D_004429B0[];
extern s32 D_004F7FD8[];
extern f32 D_004F7FD0[];
extern f32 D_004F7FD4[];

/* MW 3.0.3: ./try.sh src/nq80_b.c "-O3,p -sdatathreshold 0" */
void func_00146F50(u8 *p) {
    extern s32 fptosi(f32);
    E46 *e;
    u32 k;
    s32 v;
    k = p[0x20];
    e = &D_004429B0[k];
    if (k == 2) {
        v = 100 - D_004F7FD8[0];
        if (v / 100 != 0) e->b0 = 1; else e->b0 = 0;
        v = v % 100;
    } else {
        if (k == 0) v = fptosi(D_004F7FD0[0]);
        else v = fptosi(D_004F7FD4[0]);
        if (v < 0) {
            e->h2 = (k != 0) ? 0x41 : 0x42;
            v = -v;
        } else {
            { s32 h; if (k != 0) h = (v > 0) ? 0x42 : 0x41; else h = 0x41; e->h2 = h; }
        }
    }
    e->hA = v / 10 + 0x37;
    e->h12 = v % 10 + 0x37;
}
