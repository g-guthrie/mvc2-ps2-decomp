typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2794;
extern u8 *D_004C2840;
extern u8 D_004B93E8[];
extern u8 D_004B93F8[];
extern u8 D_004B9400[];
extern u8 D_004B9408[];
extern u8 D_004B9410[];
extern u8 D_004B9420[];
extern u8 D_004F259C[];
extern u8 D_004F2598[];
extern u8 D_004F261C[];
extern u8 D_004F20B1[];
extern u32 *D_00477830[];
extern u32 *D_00477834[];

void func_003D94B0(void) {
    extern s32 func_0016D130();
    extern void func_0011F938();
    extern void func_003D7350();
    u8 buf[16];
    s32 s0;
    s32 s1;
    s32 v;
    u32 w;
    u8 *g;
    if (*D_004C2794 == 9) return;
    if (func_0016D130() != 0) return;
    g = D_004C2840;
    if (*(s8 *)(g + 0x4C) == 2) return;
    if (*(s8 *)(g + 0x8F) == 0) {
        s1 = (*(s8 *)(g + 0x88) & 1) ? 0 : 1;
        v = *(s8 *)(s1 + (u32)D_004C2794 + 0x9C);
        if (v != 0) {
            func_0011F938(buf, D_004B93E8, (s8)v);
            func_003D7350((u8)((s1 * 27 + 3) * 3), D_004C2840[0xB6], 0x13, buf);
        }
        s0 = (u8)((s1 * 27 + 0xF) * 3);
        if (*(u32 *)(D_004F259C + s1 * 0x5B8) != 0) {
            func_0011F938(buf, D_004B93F8, *(u32 *)(D_004F2598 + s1 * 0x5B8));
            func_003D7350(s0, D_004C2840[0xB6], 0x15, buf);
            func_0011F938(buf, D_004B9400, *(u32 *)(D_004F259C + s1 * 0x5B8));
            func_003D7350((u8)((u8)s0 - 9), D_004C2840[0xB6], 0x15, buf);
        } else {
            func_0011F938(buf, D_004B9408, *(u32 *)(D_004F2598 + s1 * 0x5B8));
            func_003D7350(s0, D_004C2840[0xB6], 0x15, buf);
        }
        if (*(s8 *)(D_004C2840 + 0x4C) != 7) return;
        s0 = (u8)(((1 - s1) * 27 + 0xF) * 3);
        w = *(u32 *)(D_004F261C + s1 * 0x5B8);
        if (w >= 0x57E40) {
            func_0011F938(buf, D_004B9410, 99, 59, 99);
        } else {
            func_0011F938(buf, D_004B9410, w / 3600, (w / 60) % 60, ((w % 60) * 100) / 60);
        }
        func_003D7350(s0, D_004C2840[0xB6], 0x15, buf);
        return;
    }
    v = *(s8 *)(D_004C2794 + 0x9C);
    if (v == 0) {
        if (D_004C2794[0x46] == 0 && D_004C2794[0] < 5) {
            func_0011F938(buf, D_004B9420);
            func_003D7350(0x2A, D_004C2840[0xB6], 0x13, buf);
        }
    } else {
        func_0011F938(buf, D_004B93E8, (s8)v);
        func_003D7350(0x2D, D_004C2840[0xB6], 0x13, buf);
    }
    v = *(s8 *)(D_004C2794 + 0x9D);
    if (v == 0) {
        if (D_004C2794[0x46] == 0 && D_004C2794[0] < 5) {
            func_0011F938(buf, D_004B9420);
            func_003D7350(0x5D, D_004C2840[0xB6], 0x13, buf);
        }
    } else {
        func_0011F938(buf, D_004B93E8, (s8)v);
        func_003D7350(0x60, D_004C2840[0xB6], 0x13, buf);
    }
    g = D_004C2840;
    if (*(s8 *)(g + 0x58) != 0) {
        s32 t = (*(s8 *)(g + 0x29) != 0) ? 2 : 0;
        func_003D7350(6, (u8)(*(s8 *)(g + 0xB6) + 0x19), 0x37,
                      D_00477830[t][D_004F20B1[D_004C2794[0x8A] * 0x5B8]]);
        func_003D7350(0x69, (u8)(*(s8 *)(D_004C2840 + 0xB6) + 0x19), 0x37,
                      D_00477834[t][D_004F20B1[D_004C2794[0x8B] * 0x5B8]]);
    }
}
