typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

static void func_0018D6F0(u8 *a0, u8 *a1, u8 *a2) {
    a2[0] = 0;
}

void func_0018D9A0(u8 *a0) {
    u8 *a1 = *(u8 **)(a0 + 0x1C8);
    u8 *s0;
    u8 buf[16];
    u32 a3;
    if (a1 == 0) {
        return;
    }
    if (a1[3] != 0) {
        if (a1[3] != 1) {
            return;
        }
    }
    a3 = a0[0x1B6] & 0x7F;
    *(u8 **)(a0 + 0x1D0) = *(u8 **)(a1 + 0x184) + a3 * 28;
    s0 = *(u8 **)(a0 + 0x1D0);
    if (s0 == 0) {
        return;
    }
    if (*(s8 *)(s0 + 0xB) < 0) {
        return;
    }
    func_0018D6F0(a0, a1, buf);
    a3 = s0[8];
    if (a0[0x1BA] != 0) {
        a3 = (0x20 - (s8)a3) & 0x1F;
    }
    {
        extern void func_00154790(u8 *, s16, u8, u32);
        extern void func_00156E80(u8 *, u32);
        func_00154790(buf, *(s16 *)(a0 + 0x140), s0[0xB], a3);
        if (s0[0x12] & 0x40) {
            func_00156E80(buf, 0);
        }
    }
}
