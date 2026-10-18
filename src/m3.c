typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef long long s64;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s32 func_00175700(u8 *);
extern s32 func_00175670(u8 *);
extern void func_001843A0(u8 *);
extern void func_001E31D0(u8 *, s32);
extern void func_002CFA20(u8 *);
extern void func_00186A20(u8 *);
extern void func_001B50B0(u8 *, u8 *);
extern void func_002579D0(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);
extern void func_003B9310(u8 *, s32, s32);
extern void func_00390BE0(u8 *, s32);
extern u8 D_004D18A0;
extern s32 func_00189310(u8 *, u8 *, u8 *);
extern s32 func_003DA750(s32, s32, s32);
extern void func_0035E7C0();
extern u8 D_0045DDA0[];
extern void (*D_004649D0[])(u8 *);

void func_0035E760(s32 a, s32 b) {
    u8 *r = (u8 *)func_003DA750(0, 1, 1);
    if (r) {
        *(s16 *)(r + 0x26) = 0xE00;
        *(u32 *)(r + 0x10) = (u32)func_0035E7C0;
        *(s32 *)(r + 0x14) = a;
        *(s32 *)(r + 0x18) = b;
    }
}

void func_0017B3B0(u8 *p) {
    p[0x201] = 1;
    p[0x1B1] = 0;
    p[0x1FF] = 4;
    p[0x20D] = 0;
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        func_001E31D0(p, 0x2B);
    }
}

void func_001B5040(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (*(u16 *)(p + 0xD0) != *(u16 *)(q + 0x168)) {
        p[4] = 2;
    } else {
        if ((s8)func_00175670(p) < 0) p[4] = 2;
        func_001B50B0(q, p);
    }
}

void func_002FE150(u8 *p, u8 *q) {
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[0x151] = 0;
        {
            u32 t = p[6];
            p[6] = t + 1;
        }
        q[0xA] = 1;
        *(s16 *)(p + 0x1E) = 0;
        if (p[0x21] == 1) func_00186A20(p);
    }
}

void func_001C0320(u8 *p) {
    if ((s8)func_00175670(p) < 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        *(V3 *)(p + 0x34) = *(V3 *)(*(u8 **)(p + 0x18) + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
    }
}

void func_00387C90(u8 *p) {
    D_004649D0[p[0x20]](p);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24) + *(s8 *)(p + 0x31);
    if (*(s8 *)(p + 0x24) > 7) *(s8 *)(p + 0x24) = 7;
    if (*(s8 *)(p + 0x24) < 0) *(s8 *)(p + 0x24) = 0;
}

void func_00257370(u8 *p) {
    switch (p[0x1FC]) {
    case 2:
        func_002579D0(p);
        break;
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}

void func_003AD320(u8 *p, u8 *q) {
    u16 k;
    s8 *t = (s8 *)(*(u8 **)(p + 0x1DC) + 0x24E);
    if (*t <= 0 && (*(u16 *)(p + 0x35E) & 0x3C00)) {
        u16 x = *(u16 *)(p + 0x362);
        if (x & 0x300) k = 0;
        else if (x & 0x60) k = 1;
        else return;
        *t += 2;
        *(u16 *)(q + 0x16) = k;
        *(u16 *)(q + 0x14) = *(u16 *)(p + 0x35E);
        *(u16 *)(q + 0x12) = 1;
    }
}

void func_002885B0(u8 *p) {
    if (*(s16 *)(p + 0x1C) == 0) {
        p[7] = 4;
        func_001757E0(p, 0x13, 1);
    } else if ((s8)func_00175700(p) < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        func_001757E0(p, 0, 0);
    }
}

void func_003B9D80(u8 *p) {
    if ((*(u8 **)(p + 0x14))[5] == 0) {
        func_00175700(p);
        if ((s8)p[0x151] != 0) {
            u32 t = p[5];
            p[5] = t + 1;
            p[0x151] = 0;
            func_003B9310(p, 2, 0);
        }
    } else {
        u32 t = p[4];
        p[4] = t + 1;
        p[5] = 0;
        p[0x13C] = 0;
    }
}

void func_0030DBE0(u8 *p) {
    u32 t = p[6];
    if (t == 0) {
        if (D_004D18A0 < 2) {
            p[0x13C] = 0;
        } else {
            p[6] = t + 1;
            p[0x13C] = 1;
            func_001757E0(p, 0x12, 0);
        }
    } else if ((s8)func_00175700(p) < 0) {
        u32 u = p[5];
        p[5] = u + 1;
    }
}

void func_0029F3A0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < 0) {
            p[6] = 6;
            func_001757E0(p, 0x16, 0x12);
            return;
        }
    }
    if (*(s8 *)(p + 0x151) & 1) {
        p[0x151] = 0;
        func_00390BE0(p, 1);
    }
}

void func_0023AFE0(u8 *p) {
    switch (p[0x1FC]) {
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    case 2:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}
