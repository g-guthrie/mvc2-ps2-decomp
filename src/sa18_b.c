typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_0045ED80[];
extern s32 D_0045ED20[][3];
extern s32 D_004C283C;

void func_0033C6E0(u8 *p) {
    s32 t;
    s16 v;
    t = D_0045ED80[*(s16 *)(p + 0x1C)];
    if (D_0045ED20[t][p[0x20]] != 0) {
        *(s16 *)(p + 0xCC) = p[0x20] + 0x1F;
        *(s32 *)(p + 0x84) = D_004C283C;
    } else {
        *(s16 *)(p + 0xCC) = p[0x20] + 0x22;
        *(s32 *)(p + 0x84) = D_004C283C;
    }
    v = *(s16 *)(p + 0x1E) + 1;
    *(s16 *)(p + 0x1E) = v;
    if (v >= 10) {
        *(s16 *)(p + 0x1E) = 0;
        v = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = v;
        if ((u32)v >= 0x14) {
            *(s16 *)(p + 0x1C) = 0;
        }
    }
}
