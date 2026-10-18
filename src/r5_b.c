typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

/* EE GCC 2.96: ./tryee.sh src/r5_b.c sn */

extern s32 func_0011D6A8(void *, void *, s32);
extern char D_004C2250[];
extern char D_004BC5B8[];
extern void func_003FB128(void *);
extern s32 func_003FFEC8(s32);

s32 func_003F8D68(void *a) { return func_0011D6A8(a, D_004C2250, 4) == 0; }

s32 func_00402908(s32 *a) {
    if (a == 0) { func_003FB128(D_004BC5B8); return -1; }
    return func_003FFEC8(a[1]);
}

void func_003F8320(u8 *p, s32 a, s32 b) {
    s32 q;
    if (*(s16 *)(p + 0x98) == 0) {
        *(s32 *)(p + 0x48) = a;
        q = b / *(s8 *)(p + 0xF);
        *(s32 *)(p + 0x74) = 0;
        *(s32 *)(p + 0x94) = 0;
        *(s32 *)(p + 0x90) = 0;
        *(s32 *)(p + 0x4C) = q;
    } else {
        s32 d = (*(s8 *)(p + 0xD) / 8) * *(s8 *)(p + 0xE);
        *(s32 *)(p + 0x48) = a;
        q = b / d;
        *(s32 *)(p + 0x94) = 0;
        *(s32 *)(p + 0x74) = 0;
        *(s32 *)(p + 0x90) = 0;
        *(s32 *)(p + 0x4C) = q;
    }
}

typedef struct { u8 b0; u8 b1; u16 h2; s32 w4; s32 w8; s32 wC; } E3FB;
extern s32 D_0047C5A8;
extern u16 D_0047C588[];
extern E3FB D_0047B588[];
void func_003FB510(s32 idx, s32 flag, s32 a2, s32 a3, s32 a4) {
    E3FB *e;
    D_0047C5A8 = D_0047C5A8 % 256;
    e = &D_0047B588[D_0047C5A8];
    if (flag == 0) D_0047C588[idx]++;
    D_0047C5A8++;
    e->b0 = idx;
    e->b1 = flag;
    e->h2 = D_0047C588[idx];
    e->w4 = a2;
    e->w8 = a3;
    e->wC = a4;
}
