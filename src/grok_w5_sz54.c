typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))

void func_00173F90(u8 *p) {
    p[0x543] = 0;
    p[0x53B] = 0;
    p[0x542] = 0;
    p[0x4DE] = 1;
    *(s32 *)(p + 0x548) = 0;
    *(s32 *)(p + 0x54C) = 0;
    p[0x551] = 0x14;
    p[0x552] = 0x14;
    *(s32 *)(p + 0x558) = 0;
    *(s32 *)(p + 0x55C) = 0;
    *(s32 *)(p + 0x560) = 0;
    *(s32 *)(p + 0x564) = 0;
    *(s32 *)(p + 0x518) = 0;
    *(s32 *)(p + 0x51C) = 0;
    *(s32 *)(p + 0x56C) = 0;
    p[0x554] = 0;
    p[0x555] = 0;
    p[0x556] = 0;
}

void func_00182BD0(u8 *p) {
    p[0x207] = 2;
    *(u16 *)(p + 0x354) &= 0x3F0;
    *(u16 *)(p + 0x35C) &= 0x3F0;
    *(u16 *)(p + 0x356) &= 0x3F0;
    *(u16 *)(p + 0x35E) &= 0x3F0;
    *(u16 *)(p + 0x362) &= 0x3F0;
    *(u16 *)(p + 0x360) &= 0x3F0;
}

void func_0015EDB0(u8 *p) {
    if ((s16)(--*(s16 *)(p + 30)) == 0) {
        p[4] = 0;
        if ((s16)(++*(s16 *)(p + 28)) >= 8) {
            p[4] = 2;
            *(s16 *)(p + 28) = 7;
        }
    }
}

void func_002F8DE0(u8 *p) {
    if (p[0x20D] == 2) {
        F(p, 0x5C) /= 8.0f;
        F(p, 0x68) /= 8.0f;
        F(p, 0x60) /= 8.0f;
        F(p, 0x6C) /= 8.0f;
    }
}

int func_00189730(u8 *a0, u8 *a1, u8 *a2) {
    s8 n = (s8)(a2[1] - 1);
    a2[1] = (u8)n;
    if (n > 0) {
        if ((*(u16 *)(a0 + 0x35E) & *(u16 *)(a1 + 8)) == 0) {
            a2[0] = 0;
        }
        return 0;
    }
    a2[0]++;
    return 0;
}
