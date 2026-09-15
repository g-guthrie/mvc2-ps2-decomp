typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern int func_00175670();
extern int func_00175700();
extern void func_001757E0(u8 *, int, int);
extern int func_00188F80(u8 *, int);
extern void func_00192B50(u8 *);
extern void func_001C8620(u8 *);
extern void func_001CF850(u8 *);
extern void func_003DAA40(u8 *);
extern void func_001801E0();
extern void func_001802A0();
extern void func_0018DDD0(u8 *);
extern void func_0018E0B0(u8 *);
extern int func_00417A40(u8 *);

void func_00180060(u8 *p) { if (--*(s16 *)(p + 28) < 0) p[6]++; }

int func_00185150(u8 *p) {
    if (*(s16 *)(p + 652)) p[7]++;
    return 0;
}

int func_00185250(u8 *p) {
    if (--*(s16 *)(p + 652) < 0) p[7]++;
    return 0;
}

int func_00189130(u8 *p) { return func_00188F80(p, 1) != 0; }

void func_0018C6B0(u8 *p, s8 amt) {
    s8 *q = *(s8 **)(p + 1056);
    s8 v = *q - amt;
    *q = v;
    if (v < 0) **(s8 **)(p + 1056) = 0;
}

void func_00186A20(u8 *p) {
    if (p[525] != 2) {
        p[525] = 2;
        p[528] = 0;
        p[488] = 0;
        p[489] = 0;
        p[490] = 17;
        p[493] = 0;
    }
}

void func_001CE030(u8 *p) {
    if (*(u16 *)(p + 208) != *(u16 *)(*(u8 **)(p + 24) + 360)) p[4] = 2;
}

void func_001B3880(u8 *p) {
    if (*(u16 *)(p + 208) != *(u16 *)(*(u8 **)(p + 24) + 360)) {
        p[5] = 0;
        p[4] = 0;
        p[316] = 0;
    }
}

int func_001B4BD0(u8 *p) {
    if (*(u16 *)(p + 208) != *(u16 *)(*(u8 **)(p + 24) + 360)) {
        p[4] = 2;
        return 1;
    }
    return 0;
}

void func_001B0ED0(u8 *p) {
    if ((s8)p[337] == 1) {
        p[5]++;
        p[337] = 0;
    }
    func_00175670(p);
}

void func_001B31F0(u8 *p) {
    if ((s8)p[339] >= 0) func_00175670(p);
}

void func_001874A0(u8 *p) {
    p[525] = 2;
    *(s32 *)(p + 96) = 0;
    *(u32 *)(p + 108) = 0xBF4DB6DBu;
    func_001757E0(p, 1, 9);
}

void func_0019E4D0(u8 *p) {
    p[5] = 0;
    *(u32 *)(p + 92) = 0x42695555u;
    *(u32 *)(p + 96) = 0x438E8000u;
    func_001757E0(p, 23, 40);
}

void func_001CF6D0(u8 *p) {
    *(s16 *)(p + 320) = (p[33] & 1) ? 0 : 1;
}

void func_001C0970(u8 *p) {
    if (p[32] == 1) {
        s8 *q = *(s8 **)(p + 24);
        q[698]--;
    }
    func_003DAA40(p);
}

void func_00185630(u8 *p) {
    ((void (*)(u8 *))(*(u32 *)(*(u32 *)(p + 1084) + 36)))(p);
}

void func_00192CE0(u8 *p) {
    s8 *q;
    p[316] = 0;
    q = *(s8 **)(p + 24);
    if (q[316]) {
        *(f32 *)(p + 52) = *(f32 *)(q + 52);
        *(f32 *)(p + 56) = *(f32 *)(*(u8 **)(p + 24) + 56);
        *(s16 *)(p + 320) = *(s16 *)(*(u8 **)(p + 24) + 320);
        func_00192B50(p);
    }
}

void func_001C87B0(u8 *p) {
    s8 *q;
    p[316] = 0;
    q = *(s8 **)(p + 24);
    if (q[316]) {
        *(f32 *)(p + 52) = *(f32 *)(q + 52);
        *(f32 *)(p + 56) = *(f32 *)(*(u8 **)(p + 24) + 56);
        *(s16 *)(p + 320) = *(s16 *)(*(u8 **)(p + 24) + 320);
        func_001C8620(p);
    }
}

void func_001CF9E0(u8 *p) {
    s8 *q;
    p[316] = 0;
    q = *(s8 **)(p + 24);
    if (q[316]) {
        *(f32 *)(p + 52) = *(f32 *)(q + 52);
        *(f32 *)(p + 56) = *(f32 *)(*(u8 **)(p + 24) + 56);
        *(s16 *)(p + 320) = *(s16 *)(*(u8 **)(p + 24) + 320);
        func_001CF850(p);
    }
}

void func_001801B0(void) { func_001801E0(); func_001802A0(); }

void func_0018DD90(u8 *p) {
    if (p[5] != 3) {
        if (!p[584]) p[584] = 0;
    }
    func_0018DDD0(p);
}

void func_0018E070(u8 *p) {
    if (p[5] != 3) {
        if (!p[584]) p[584] = 0;
    }
    func_0018E0B0(p);
}

void func_00190660(u8 *p, s16 a1, u8 a2) {
    *(s16 *)(p + 1018) = a1;
    if (a1) {
        p[1026] = a2;
        *(s16 *)(p + 1020) = 0;
        p[1027] = 0;
        *(s16 *)(p + 1024) = 0;
        p[532] = 0;
    } else {
        p[1026] = 0;
    }
}

void func_00190690(u8 *p, s16 a1, u8 a2) {
    *(s16 *)(p + 1020) = a1;
    if (a1) {
        p[1027] = a2;
        *(s16 *)(p + 1018) = 0;
        p[1026] = 0;
        *(s16 *)(p + 1024) = 0;
        p[532] = 0;
    } else {
        p[1027] = 0;
    }
}

void func_00193FD0(u8 *p) {
    if ((*(s16 *)(p + 28))-- == 0) {
        p[4]++;
        p[316] = 0;
    }
}

void func_00194410(u8 *p, u8 *q) {
    if (p[33]) {
        p[4]++;
        q[6] = 2;
    }
}

void func_001977E0(u8 *p) {
    *(s16 *)(p + 28) = (func_00417A40(p) & 7) + 7;
}

void func_0019E9B0(u8 *p) {
    if (--*(s16 *)(p + 28) == 0) p[4]++;
    func_00175700(p);
}
