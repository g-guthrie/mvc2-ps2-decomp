typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004CAE64[];
extern u8 D_00443E90[];
extern u32 *D_004CAD50[];
extern u8 *D_004CAE34[];
extern u8 *D_004CAE38[];
extern u8 *D_004CAE3C[];
extern u8 *D_004CAE40[];
extern u8 *D_004CAE44[];
extern u32 D_004C27FC[1];
extern u8 *D_004C2840;

static void func_0014AB60(u8 *p, s32 dir) {
    s32 i;
    s32 t;
    u32 *q;
    i = 0;
    do {
        if (dir != 0) {
            { u32 c = p[5]; p[5] = c - 1; }
            if (p[5] == 0xFF) p[5] = 0x37;
        } else {
            { u32 c = p[5]; p[5] = c + 1; }
            if (p[5] == 0x38) p[5] = 0;
        }
        t = D_00443E90[p[5]];
        if (t >= 0x20) {
            t -= 0x20;
            q = (u32*)(D_004C2840 + 0x34);
        } else {
            q = (u32*)(D_004C2840 + 0x30);
        }
        if (*q & (1 << t)) return;
        i++;
    } while (i < 0x38);
    p[5] = p[6];
}

void func_0014AC30(u8 *p) {
    extern s32 func_0012ABC0(s32, s32);
    extern void func_001E3CE0(s32);
    s32 k;
    u8 *h;
    s32 j;
    u32 **pp;
    s32 s0;
    f32 one;
    u16 s1;
    u8 *o2;
    s32 v;
    u16 f;
    u8 *o;
    s32 i;
    u8 *g;

    f = func_0012ABC0(3, 0);
    g = D_004CAE64[0];
    h = *(u8 **)(g + 0xD8);
    if (g[0x23] != 0) {
        if (g[5] != 0) {
            h[0x13C] = 0;
            return;
        }
    } else {
        if (g[5] == 7) {
            h[0x13C] = 0;
            return;
        }
    }
    h[0x13C] = 1;
    if (p[4] == 0) {
        p[4] = 1;
        p[5] = 0;
        p[6] = 1;
    } else {
        p[6] = p[5];
        s1 = f;
        s0 = (s1 & 0x40) ? 10 : 1;
        if ((s1 & 0x400) != 0) {
            for (i = 0; i < s0; i++) func_0014AB60(p, 0);
            func_001E3CE0(1);
        }
        if ((s1 & 0x800) != 0) {
            for (i = 0; i < s0; i++) func_0014AB60(p, 1);
            func_001E3CE0(1);
        }
    }
    if (p[5] != p[6]) {
        i = D_00443E90[p[5]];
        if (i >= 0x18) i -= 3;
        k = 1;
        j = D_00443E90[p[6]];
        if (j >= 0x18) j -= 3;
        pp = &D_004CAD50[i];
        o = (u8 *)*pp;
        o[5] = k;
        o[4] = k;
        *(u32 *)(o + 0x80) = 0x3F800000;
        *(u32 *)(o + 0x7C) = 0x3F800000;
        *(u32 *)(o + 0x78) = 0x3F800000;
        *(u32 *)(o + 0x3C) = 0xC14D999A;
        *(u32 *)(o + 0x50) = *(u32 *)(o + 0x54) = 0x3FA66666;
        o2 = *(u8 **)((u8 *)*pp + 0xD8);
        if (o2 != 0) {
            *(u32 *)(o2 + 0x3C) = 0xC14D851F;
            *(u32 *)(o2 + 0x54) = 0x3FB33333;
            *(u32 *)(o2 + 0x50) = 0x3FB33333;
        }
        o = (u8 *)D_004CAD50[j];
        one = 1.0f;
        o[4] = 0;
        *(u32 *)(o + 0x80) = 0x3F4CCCCD;
        *(u32 *)(o + 0x7C) = 0x3F4CCCCD;
        *(u32 *)(o + 0x78) = 0x3F4CCCCD;
        *(u32 *)(o + 0x3C) = 0xC14E147B;
        *(f32 *)(o + 0x54) = one;
        *(f32 *)(o + 0x50) = one;
        o2 = *(u8 **)((u8 *)D_004CAD50[j] + 0xD8);
        if (o2 != 0) {
            *(u32 *)(o2 + 0x3C) = 0xC14DC28F;
            *(f32 *)(o2 + 0x54) = one;
            *(f32 *)(o2 + 0x50) = one;
        }
        *(s16 *)(D_004CAE38[0] + 0xCC) = i + 0x3A;
        *(u32 *)(D_004CAE38[0] + 0x84) = D_004C27FC[0];
        *(s16 *)(D_004CAE3C[0] + 0xCC) = i + 0xCB;
        *(u32 *)(D_004CAE3C[0] + 0x84) = D_004C27FC[0];
        *(s16 *)(D_004CAE40[0] + 0xCC) = (p[5] + 1) % 10 + 0x25;
        *(u32 *)(D_004CAE40[0] + 0x84) = D_004C27FC[0];
        *(s16 *)(D_004CAE44[0] + 0xCC) = (p[5] + 1) / 10 + 0x25;
        *(u32 *)(D_004CAE44[0] + 0x84) = D_004C27FC[0];
        if (i >= 0x18) i += 3;
        if (i >= 0x20) {
            i -= 0x20;
            o = (u8 *)D_004C2840 + 0x3C;
        } else {
            o = (u8 *)D_004C2840 + 0x38;
        }
        if ((*(u32 *)o & (1 << i)) != 0) D_004CAE34[0][0x13C] = 1;
        else D_004CAE34[0][0x13C] = 0;
    }
}
