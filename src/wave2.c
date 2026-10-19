typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_00136D00(u8 *p) {
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    if (*(s16 *)(p + 0x1C) >= 1000) *(s16 *)(p + 0x1C) = 0;
    *(s32 *)(p + 0xE0) = 0;
    *(float *)(p + 0xE4) = 0.001f * *(s16 *)(p + 0x1C);
}

extern void func_0018C510(u8 *, s32);
void func_0018C4B0(u8 *p, s32 q) {
    if (p[0x214] && p[5] < 2) {
        u32 a = *(u32 *)(p + 0x428) & 0x480;
        u32 b = *(u32 *)(p + 0x42C) & 0x2020000;
        if ((a | b) != 0) return;
    }
    func_0018C510(p, q);
}

void func_001B4C00(u8 *a, u8 *b) {
    *(s8 *)(b + 0x24) = *(s8 *)(a + 0x24);
    switch (b[0x20]) {
    case 0xD: *(s8 *)(b + 0x31) = -1; break;
    case 0xE: *(s8 *)(b + 0x31) = -3; break;
    case 0xF: *(s8 *)(b + 0x31) = -2; break;
    }
}

float func_001C3A20(u8 *p, s32 n) {
    if (*(s16 *)(p + 0x140) == 0) return *(float *)(p + 0x34) + 1.6666666f * n;
    return *(float *)(p + 0x34) - 1.6666666f * n;
}

extern void func_001E3710(u8 *, u8);
void func_001E3A40(u8 *p) {
    u8 a;
    s32 x, y;
    p = *(u8 **)(p + 0x1DC);
    x = p[0x216]; y = p[0x21B];
    if ((x & 0x80) || y >= 5) a = 0x31; else a = 0x30;
    func_001E3710(p, a);
}

extern void func_00186A60(u8 *, s32);
void func_0026ED00(u8 *p) {
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0:
    case 1: p[0x1FD] = 4; break;
    case 2: p[0x1FD] = 2; break;
    }
    p[0x1B7] = 1;
    func_00186A60(p, 0x15);
}

s32 func_00273C20(u8 *p) {
    if (p[0x20D] != 2) return 1;
    if (p[0x210] == 0) {
        if (*(s8 *)(p + 0x1E8) != 0) return 0;
        *(s8 *)(p + 0x1E8) += 1;
    }
    return 1;
}

s32 func_00254480(u8 *p) {
    if (p[0x20D] != 2) return 1;
    if (p[0x210] == 0) {
        if (*(s8 *)(p + 0x1E8) != 0) return 0;
        *(s8 *)(p + 0x1E8) += 1;
    }
    return 1;
}

void func_002809D0(u8 *p) {
    switch (p[0x452]) {
    case 0:
        p[0x471] = 1;
        p[0x452]++;
        break;
    case 1:
        if (p[0x1E4] != 0x15 && p[0x1E4] != 0x1D) p[0x451] = 1;
        break;
    }
}

void func_002B5100(u8 *p) {
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    if (*(float *)(p + 0x60) * *(float *)(p + 0x6C) > 0.0f) *(float *)(p + 0x6C) = -1.607142806053161621f;
}

void func_0031DF20(u8 *p) {
    if (*(s8 *)(p + 0x150) != 0) {
        if (*(s8 *)(p + 0x539) == 0) {
            if (((u16)(*(u16 *)(p + 0x35C) | *(u16 *)(p + 0x366)) & 0x300) != 0) {
                *(s16 *)(p + 0x1C) = 1;
                *(s16 *)(p + 0x366) = 0;
            }
        } else if (p[0x425] == 0) {
            *(s16 *)(p + 0x1C) = 1;
        }
    }
}

extern s32 func_00170E60(s32, s32, s32, s32, void *, u8 *);
extern void func_003311A0(void);
void func_00396DD0(u8 *p, u8 *q) {
    float f;
    *(float *)(p + 0x34) = *(float *)(*(u8 **)(p + 0x18) + 0x34);
    *(float *)(p + 0x38) = *(float *)(*(u8 **)(p + 0x18) + 0x38);
    f = 1.6666666f * (float)(q[6] << 5);
    if (*(s16 *)(p + 0x140) == 0) f = -f;
    *(float *)(p + 0x34) = *(float *)(p + 0x34) + f;
}

extern s32 func_00175700(u8 *);
typedef unsigned __int128 u128;
