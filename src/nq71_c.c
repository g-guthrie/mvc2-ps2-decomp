typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x44]; union { s16 h; s32 w; } u; u8 pad2[4]; } E4C;
extern s32 D_004C28A0;
extern u8 D_0056EE70[];
extern s8 D_0057ED70[];
extern s32 D_0057FB70[];
s32 func_00415320(u8 *dst, s32 *src, s32 sel)
{
    extern s32 func_003F1AB0();
    extern void func_003F1C10();
    s32 i;
    s32 k;
    s32 base;
    s16 cnt;
    s32 h;
    u8 *e;
    h = *src;
    cnt = func_003F1AB0(h);
    if (D_004C28A0 + cnt >= 0x340) return -1;
    base = D_004C28A0;
    *(s16 *)(dst + 2) = base;
    *(s16 *)(dst + 0) = cnt;
    e = D_0056EE70 + base * 0x4C;
    *(u8 **)(dst + 4) = e;
    D_004C28A0 += cnt;
    for (i = 0; i < cnt; i++) {
        func_003F1C10(h, i, e);
        k = D_0057ED70[*(s16 *)(e + 0x44) + sel];
        if (k != -1) ((E4C *)e)->u.w = D_0057FB70[k];
        else ((E4C *)e)->u.w = 0;
        e += 0x4C;
    }
    return 0;
}
