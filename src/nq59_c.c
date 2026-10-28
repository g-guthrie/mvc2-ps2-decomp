typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C28A8;
extern s32 D_004C28A4;
extern s8 D_0057ED70[];
extern s32 D_0057FB70[];
extern s32 D_0057E570[];
extern s32 D_0057E574[];

s32 func_00415140(s32 idx, u8 *r) {
    extern s32 func_00415250(u8 *);
    s8 *e = &D_0057ED70[idx];
    if (*e != -1) return -1;
    if (D_004C28A8 == 0x1000) return -1;
    D_0057FB70[D_004C28A8] = func_00415250(r);
    if (*(s32 *)(r + 4) & 0xF0) {
        s32 k = D_004C28A4;
        if (k == 0x100) return -1;
        if (D_0057E570[k * 2] != -1) return -1;
        D_0057E570[k * 2] = D_0057FB70[D_004C28A8];
        D_0057E574[k * 2] = *(s32 *)(r + 0xC) >> 16;
        D_004C28A4++;
    }
    *e = D_004C28A8;
    D_004C28A8++;
    return 0;
}
