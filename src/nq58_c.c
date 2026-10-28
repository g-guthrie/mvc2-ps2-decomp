typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void (*D_0044CC20[])(u8 *);
typedef struct { u8 pad[0x1C]; s16 t; } T1C_nq58;

void func_001C4B00(u8 *p)
{
    extern void func_00175670(u8 *);
    u8 *o = *(u8 **)(p + 0x18);
    s16 v = *(s16 *)(p + 0x1C) - 1;
    s16 h;
    u32 k;

    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    h = ((T1C_nq58 *)p)->t;
    if (h > 0x3C) {
        if (p[1] != o[1] || o[4] >= 2) {
            p[4] = 2;
            p[5] = 0;
            p[0x13C] = 0;
            return;
        }
    }
    if (h > 0x14 && o[0x1E4] == 0x15) {
        k = o[0x1FD];
        if (k == 7 || k - 4 <= 1 || k == 0xD) {
            p[5] = 5;
            *(s16 *)(p + 0x1C) = 0x14;
            return;
        }
    }
    D_0044CC20[p[5]](p);
    func_00175670(p);
}
