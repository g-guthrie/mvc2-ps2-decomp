/* EE GCC 2.96: ./tryee.sh src/s6b_a.c sn 8 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;

/* RIFF WAVE "fmt " chunk body */
typedef struct {
    s16 format;
    u16 channels;
    s32 rate;
    s32 bytes_per_sec;
    u16 block_align;
    u16 bits;
} WavFmt;

extern u8 *D_004C2260; /* "fmt " */
extern u8 *D_004C2270; /* "data" */
extern s32 func_0011D6A8(u8 *, u8 *, s32);

s32 func_003F8D90(u8 *buf, s32 n, s16 *oh, s8 *oa, s8 *ob, s8 *oc, s8 *od,
                  s32 *oe, s32 *of, s32 *og, s16 *oi) {
    s32 i;
    WavFmt *e;
    s32 q;
    u8 c;
    i = 0;
    while (i < n && func_0011D6A8(buf + i, D_004C2260, 4) != 0) i++;
    if (i == n) return -1;
    if ((i & 3) != 0) return -1;
    e = (WavFmt *)(buf + i + 8);
    if (e->format >= 2) return -1;
    i = 0;
    while (i < n && func_0011D6A8(buf + i, D_004C2270, 4) != 0) i++;
    if (i == n) return -1;
    *oh = i + 8;
    q = *(s32 *)(buf + i + 4);
    *oa = -1;
    *oe = e->rate;
    *od = e->channels;
    *ob = e->bits;
    c = e->block_align;
    *oc = c;
    *of = q / (s8)c;
    *og = 1;
    if (*ob == 0x10) {
        *oi = 0;
    } else if (*ob == 8) {
        *oi = 1;
    } else if (*ob == 4) {
        *oc = (s8)*od * 2;
        *og = 4;
        *of = (q / 2) / *od;
        *ob = 0x10;
        *oi = 2;
    }
    if ((u8)*ob == 0) return -1;
    if (*oc == 0) return -1;
    if ((u32)(*(u8 *)od - 1) >= 2) return -1;
    if (*oe == 0) return -1;
    return 0;
}
