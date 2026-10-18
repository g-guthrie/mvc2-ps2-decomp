typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_006207A0[];
extern u8 D_0061C7A0[];
extern s32 func_003EBA40(u8 *);
extern s32 func_003EBE70(s32);
extern s32 func_003EBA80(s32, u8 *);

s32 func_003EBD30(u32 *list, s32 n) {
    u32 w;
    s32 i;
    u8 *e;
    s32 r;
    i = 0;
    if (0 < n) do {
        w = *list++;
        if ((w & 0xFFFF) != 0) {
            e = D_006207A0 + ((w & 0xFFFF) - 1) * 64;
            if (func_003EBA40(e) == 0) {
                r = func_003EBE70(*(s16 *)(e + 0x10));
                if (r == -1) return 0;
                if (func_003EBA80(r, e) == 0) return 0;
            }
        }
        if (((w & 0xFFFF0000) >> 16) != 0) {
            w = (w & 0xFFFF0000) >> 16;
            e = D_0061C7A0 + (w - 1) * 64;
            if (func_003EBA40(e) == 0) {
                r = func_003EBE70(*(s16 *)(e + 0x10));
                if (r == -1) return 0;
                if (func_003EBA80(r, e) == 0) return 0;
            }
        }
        i++;
    } while (i < n);
    return 1;
}
