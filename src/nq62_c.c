typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u32 x[8]; } B32;
typedef struct { u8 pad[0x98]; u8 *f98; } HR;
extern s8 D_004BFAF0[8];
extern s8 D_004B6C40[][4];
extern HR *D_004C2840;
extern u8 *D_004C28B8;

void func_001E6370(s32 idx) {
    u32 src;
    s32 m;
    s8 k;
    u8 *dst;
    u32 *s;
    s32 w;
    u32 *d;
    s32 j;
    s32 i;
    s8 (*tab)[4];
    for (i = 0; i < 3; i++) {
        m = i + 0x39;
        k = D_004BFAF0[idx * 3 + i];
        src = (u32)D_004C2840->f98 + ((m & 0xFC) << 15);
        dst = (u8 *)((s32)D_004C28B8 + 0x304000) + ((k & 0xFC) << 15);
        tab = D_004B6C40;
        for (j = 0; j < 4; j++) {
            s = (u32 *)((u8 *)src + (tab[j][m & 3] << 13));
            d = (u32 *)(dst + (tab[j][k & 3] << 13));
            for (w = 0; w < 0x800; w += 8) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
                d[3] = s[3];
                d[4] = s[4];
                d[5] = s[5];
                d[6] = s[6];
                d[7] = s[7];
                d += 8;
                s += 8;
            }
        }
    }
}
