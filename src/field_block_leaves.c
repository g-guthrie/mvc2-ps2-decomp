typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;

void func_002FFB00(u8 *unused, u8 *p) {
    p[12] = 8;
    p[13] = 1;
    p[11] = 0;
    p[14] = 0;
    p[15] = 0;
    p[16] = 0;
}

void func_001398D0(s32 *p) { p[16] += 256; p[17] += 384; p[18] += 128; }

void func_00353650(u8 *a, u8 *b, u8 *c) { b[3] = 255; b[4] = 0; c[7] = 6; }

void func_00353670(u8 *a, u8 *b, u8 *c) { a[434] = 0; b[3] = 255; b[4] = 0; c[7] = 6; }

void func_0034A680(u8 *p, s8 *q) { p[4]++; p[316] = 0; q[717]--; }

void func_0030C470(u8 *p) {
    *(s8 *)(p + 702) = -1;
    p[700]++;
    p[701] = 0;
    p[698] = 0;
    p[699] = 0;
}

void func_002F8D80(u8 *p) {
    p[718] = 0;
    p[709] = 0;
    *(u16 *)(p + 710) = 0;
    p[716] = 0;
    p[717] = 0;
    p[532] = 0;
    *(u16 *)(p + 1024) = 0;
    *(u16 *)(p + 1018) = 0;
    p[1026] = 0;
}

void func_003AEE70(u8 *p) { *(u16 *)(p + 320) = 0; p[4]++; }

void func_002D3D00(u8 *p) { p[337] = 0; *(s32 *)(p + 92) = 0; *(s32 *)(p + 104) = 0; }

void func_001740A0(u8 *p) {
    p[1232] = 2;
    p[1233] = 0;
    *(u16 *)(p + 1236) = 10;
    *(u16 *)(p + 1238) = 120;
}
