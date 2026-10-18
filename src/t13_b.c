typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00282B70(u8 *p) {
    extern s32 func_00175700(void *);
    extern void func_00186A60(void *, s32);
    extern void func_001757E0(void *, s32, s32);
    s8 r = func_00175700(p);
    if (r < 0) {
        p[0x1EA] = 0x11;
        p[0x1E8] = 0;
        func_00186A60(p, 3);
        switch (*(s8 *)(p + 0x1E7)) {
        case 0:
            func_001757E0(p, 1, 0xE);
            break;
        case 1:
            func_001757E0(p, 1, 0xF);
            break;
        case -1:
            func_001757E0(p, 1, 0xD);
            break;
        }
    }
}

extern u8 D_004567A0[];

void func_00288770(u8 *p) {
    extern s32 func_00175700(void *);
    extern s32 func_00174170();
    extern void func_001757E0(void *, s32, s32);
    s8 r = func_00175700(p);
    if (r < 0) {
        u32 t = p[7];
        u32 b;
        p[7] = t + 1;
        b = *(u16 *)(p + 0x4F0);
        if (b & 0x2000) {
            p[0x168] = 0xA;
        } else if (b & 0x800) {
            p[0x168] = 9;
        } else if (b & 0x400) {
            p[0x168] = 0xB;
        } else {
            p[0x168] = D_004567A0[func_00174170() & 0x1F];
        }
        func_001757E0(p, 0x13, p[0x168]);
    }
}

extern void (*D_00463FE0[])(void *, void *);
extern void (*D_00463FD0[])(void *, void *);

void func_00376C80(u8 *p, u8 *q) {
    extern s32 func_00174470(void *);
    extern void func_00377860(void *, void *);
    if (func_00174470(p) == 0) {
        p[4] = 2;
        p[5] = 4;
        func_00377860(p, q);
        return;
    }
    if (p[0x20] != 0) {
        D_00463FE0[p[5]](p, q);
    } else {
        D_00463FD0[p[5]](p, q);
    }
}

void func_001784A0(u8 *p) {
    extern void func_0018F320(void *);
    extern void func_00175700(void *);
    extern s32 func_001864a0(void *);
    extern void func_00191210(void *);
    func_0018F320(p);
    func_00175700(p);
    if (func_001864a0(p) != 0) {
        u32 t = p[6];
        u8 *q;
        u32 v;
        p[6] = t + 1;
        p[0x20D] = 0;
        if ((p[0x245] & 7) == 5) {
            *(s16 *)(p + 0x1F8) = 2;
            func_00191210(p);
            return;
        }
        q = *(u8 **)(p + 0x1CC);
        v = q[1];
        if (v == 9 || v == 0x2C) {
            p[0x1F7] = 1;
            *(s16 *)(p + 0x1F8) = 0x30;
        } else {
            p[0x1F7] = 0x3C;
            *(s16 *)(p + 0x1F8) = 0x78;
        }
        func_00191210(p);
    }
}

void func_001E3A70(u8 *p) {
    extern void func_001E24E0(void *, s32);
    extern void func_001E3710(void *, u8);
    u32 t = p[1];
    u8 x;
    if (t == 0x2A) {
        return;
    }
    if ((p[0x216] & 0x80) != 0 || p[0x21B] >= 5) {
        x = 0x35;
    } else {
        x = 0x34;
    }
    if (t == 0x10) {
        func_001E24E0(p, 0x20);
        func_001E24E0(p, 0x2B);
    } else if (t == 0x34) {
        func_001E24E0(p, 0x1F);
    } else {
        func_001E3710(p, x);
        func_001E24E0(p, 0x2B);
    }
}
