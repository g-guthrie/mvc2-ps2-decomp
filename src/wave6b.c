typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2794;
extern u8 *D_004C2840;
extern u8 *D_004C2940;
extern u8 *D_004C299C;
extern u8 D_004C262C;
extern u8 D_004C2630;
extern u8 D_004C00C0[8];
extern u8 *D_004C25D4;
extern u8 *D_004C25D0;
extern void (*D_004BFAAC[2])(u8 *, u8 *);
extern u8 D_00462210[];
extern void func_00175910(u8 *, s32, s32, s32);
extern void func_0037F440(u8 *);
extern void func_00136DA0(s32);
extern void func_00186A60(u8 *, s32);
extern void func_001639A0(u8 *);
extern void func_00163B70(u8 *);
extern void func_00125AF0(s32);
extern void func_00125C90(s32);





void func_0037F3A0(void) {
    u8 *p = D_004C299C;
    if (p[2] < 10) {
        if (--p[3] <= 0) {
            D_004C299C[3] = 1;
            D_004C299C[2]++;
        }
    }
}

void func_0034DC30(u8 *p) {
    u32 v = *(u8 *)(p + 0x22);
    if (*(u8 *)(D_004C2940 + 8) != 0) {
        v ^= 0x1F;
        v &= 0x1F;
        v += 1;
        v &= 0x1F;
    }
    func_00175910(p, 0x17, 6, *(s32 *)(D_00462210 + v * 4));
}

void func_0022C780(u8 *p) {
    u8 v;
    s32 st;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    st = *(s32 *)(p + 0x2BC);
    v = D_004C00C0[*(s8 *)(p + 0x4DD)];
    if (st == 0x27) v = 0x1C;
    if (st == 7) v = 0x1B;
    p[0x1FD] = v;
    func_00186A60(p, 0x1D);
}

void func_00163D70(u8 *p) {
    func_001639A0(p);
    func_00163B70(p);
    if (*(u8 *)(p + 0x249) != 0) {
        s8 v = *(s8 *)(p + 0x211);
        if (v != 0) {
            D_004C2794[0x61] = v;
        }
    }
}

void func_00125A20(void) {
    if (D_004C25D4[5] == 1 || D_004C25D0[5] == 2) {
        func_00125AF0(4);
    } else {
        func_00125C90(4);
    }
}

void func_001D9700(u8 *p, u8 *q) {
    u16 x;
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    x = *(u16 *)(q + 0x168);
    if (x != *(u16 *)(p + 0xD0)) {
        p[4]++;
    } else {
        D_004BFAAC[p[5]](p, q);
    }
}

extern void func_003DA6F0(s32);
extern void func_003D7310(void (*)(void));
extern void func_001526A0(void);
extern void (*D_00446290[])(void);

void func_0016B3E0(void) {
    func_003DA6F0(0xD);
    func_003DA6F0(7);
    func_003D7310(func_001526A0);
    D_00446290[*(s8 *)(D_004C2840 + 4)]();
}

extern void func_001CABF0(u8 *);
void func_001CA7E0(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        p[5]++;
    }
    if (*(s16 *)(p + 0x1C) > 0x49) {
        func_001CABF0(p);
    }
}

extern void func_00294B20(u8 *, s32);


extern void func_003DAA40(u8 *);
void func_00329750(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (q[5] != 0 || q[0x1FD] != 1 || q[0x1E4] != 0x15 || q[0x169] != 0x15) {
        func_003DAA40(p);
    }
}

extern void func_00174910(u8 *, s32);
void func_003B90B0(u8 *p) {
    u32 v;
    s8 t;
    func_00174910(p, 0x190);
    v = (u8)(p[0x22] + 1);
    p[0x22] = v;
    t = v;
    p[0x22] = t & 0x1F;
}
