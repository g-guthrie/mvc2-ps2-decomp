typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

static void func_0034CF30(u8 *p, u8 *q) { p[0x40] = 0; }
extern void func_0034D080(u8 *);
void func_0034D200(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    func_0034CF30(p, q);
    if (q[0x22] != 0xFF) {
        u32 t = p[5];
        p[5] = t + 1;
        p[0x22] = 0;
        func_0034D080(p);
    }
}

#define P(t,o) (*(t*)(p+(o)))
#define Q(t,o) (*(t*)(*(u8**)(p+0x18)+(o)))

extern s32 func_00175700();
extern void func_003CAB20(u8 *, s32, s32);
void func_003CC820(u8 *p, s32 b) {
    func_00175700(p, b);
    {
        s16 v = P(s16,0x1C) - 1;
        P(s16,0x1C) = v;
        if (v <= 0) func_003CAB20(p, b, 0xB);
    }
}

static s32 func_0024C590(u8 *p) { P(u8,0x80) = 0; return 0; }
extern void func_00126400();
void func_0024C4F0(u8 *p) {
    P(u8,0x40C) = 2;
    P(u8,0x33C) = 5;
    if (P(s8,0x151)) func_00175700(p);
    if (func_0024C590(p) < 0) {
        u32 t = P(u8,6);
        P(u8,6) = t + 1;
        func_00126400(p);
    }
}

extern void func_00158220(V3 *);
void func_001581C0(u8 *p, f32 *q) {
    V3 v;
    if (P(s16,0x140)) v.x = P(f32,0x34) - q[0];
    else v.x = P(f32,0x34) + q[0];
    v.y = P(f32,0x38) + q[1];
    *(s32 *)&v.z = 0;
    func_00158220(&v);
}

extern u8 D_0062BC00[];
extern s32 func_003DCFE0(s32, s32);
extern void func_003DD0D0(void);
void func_003DD070(void) {
    s32 i = 0;
    s32 off = 0;
    do {
        s32 r = func_003DCFE0(0x80000, 1);
        i++;
        *(s32 *)(D_0062BC00 + off + 0x3E8) = r;
        off += 4;
    } while (i < 2);
    func_003DD0D0();
}

void func_001DAE90(u8 *p, u8 *q) {
    if (P(s16,0x1C) != *(u16 *)(q + 0x168)) {
        u32 t = P(u8,4);
        P(u8,4) = t + 1;
        P(u8,0x13C) = 0;
    } else {
        P(s8,0x24) = *(s8 *)(q + 0x24);
        P(f32,0x34) = *(f32 *)(q + 0x34) + P(f32,0x5C);
        P(f32,0x38) = *(f32 *)(q + 0x38) + P(f32,0x60);
        func_00175700(p);
    }
}


extern u8 D_00583B90[];
extern u8 D_00583BC6;
void func_00138880(u8 *p) {
    if (P(u8,0x22) == 7) {
        D_00583B90[P(u8,0x20)] = 3;
        P(u8,4) = 4;
        if (P(u8,0x20)) D_00583BC6 &= 0xD;
        else D_00583BC6 &= 0xE;
    }
}

extern s32 func_00184540(u8 *);
extern void func_001DD8A0(u8 *, s32, s32);
void func_00311420(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_00184540(p);
    } else {
        s8 f = P(s8,0x151);
        if (f & 2) {
            P(s8,0x151) = f & ~2;
            func_001DD8A0(p, 9, 5);
        }
    }
}


extern void func_003AAE20();
void func_003AADA0(u8 *p, u8 *q) {
    u8 *s = *(u8 **)(p + 0x18);
    func_00126400(p, q);
    *(s16 *)(s + 0x366) = 0;
    P(u8,5) = 2;
    *(s8 *)(q + 9) = *(s8 *)(q + 0xF);
    q[8] = 0;
    *(s16 *)(q + 0xA) = P(u8,0x22);
    {
        u8 *t = *(u8 **)(q + 0x28);
        if (t) {
            t[4] = 2;
            *(u32 *)(q + 0x28) = 0;
        }
    }
    func_003AAE20(p, q);
}

extern void func_001E3210();
extern void func_001266A0();
extern void func_001843A0();
void func_00261100(u8 *p) {
    if (P(s8,0x151)) {
        P(s8,0x151) = 0;
        if (P(u8,0x21) == 4) func_001E3210(p, 0xF);
        else func_001E3210(p, 0xC);
    }
    if (P(s8,0x153) < 0) {
        P(u8,0x40D) = 0;
        P(u8,0x40C) = 0;
        P(u8,0x33B) = 0;
        P(u8,0x33C) = 0;
        func_001266A0(p, 0, 0xD);
        func_001843A0(p);
    } else {
        func_00175700(p);
    }
}

extern void func_003DAA40(void);
extern void (*D_0044DAE0[])(u8 *, u8 *);
void func_001CBD00(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (P(u8,4) >= 2) {
        func_003DAA40();
    } else {
        D_0044DAE0[P(u8,0x20)](p, q);
    }
    P(s8,0x24) = *(s8 *)(q + 0x24) + P(s8,0x31);
    if (P(s8,0x24) > 7) P(s8,0x24) = 7;
    if (P(s8,0x24) < 0) P(s8,0x24) = 0;
}

extern void func_00183920();
void func_0020EF50(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    } else {
        u32 f = P(u8,0x15B);
        if (f & 1) {
            u32 v[3];
            P(u8,0x15B) = 0;
            v[0] = 0xC1AD5555;
            v[1] = 0x43452492;
            v[2] = 0;
            func_00183920(p, v);
        } else if (f & 2) {
            P(u8,0x15B) = 0;
            func_001E3210(p, 0x1E);
        }
    }
}


extern void func_001E3710();
extern void func_00176160();
extern void func_001A78D0();
extern void func_0024BA20();
void func_0024B150(u8 *p) {
    func_00175700(p);
    if (P(s8,0x151)) {
        u32 t = P(u8,7);
        P(u8,7) = t + 1;
        P(u32,0x5C) = 0;
        if (P(s16,0x140) == 0) P(u32,0x68) = 0xC0555555;
        else P(u32,0x68) = 0x40555555;
        func_001E3710(p, 0x4B);
        func_00176160(p, 5, 4, 1);
        func_001A78D0(p, 0xE);
    }
    func_0024BA20(p);
}

extern void func_002746F0();
void func_00274650(u8 *p) {
    u32 k = P(u8,0x1FC);
    switch (k) {
    case 0:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    case 1:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    case 2:
        func_002746F0(p);
        break;
    }
}

extern void func_001757E0();
void func_00252090(u8 *p) {
    func_00175700();
    P(f32,0x34) += P(f32,0x5C);
    P(f32,0x5C) += P(f32,0x68);
    P(f32,0x38) += P(f32,0x60);
    P(f32,0x60) += P(f32,0x6C);
    if (P(f32,0x38) <= P(f32,0x430)) {
        u32 t = P(u8,6);
        P(u8,6) = t + 1;
        P(f32,0x38) = P(f32,0x430);
        func_001757E0(p, 0x16, 8);
    }
}


extern void func_002BD610();
s32 func_002BD4E0(u8 *p, u8 *q) {
    if (P(u8,0x22) == 0x10) return 0;
    if (!(P(s8,0x211) & 2)) return 0;
    P(u8,7) = 4;
    func_002BD610();
    *(u32 *)(q + 4) = 0x43A00000;
    {
        s16 v = P(u8,0x1E6) ^ 1;
        P(s16,0x140) = v;
        P(u8,0x1E6) = v;
    }
    func_001757E0(p, 0x16, 2);
    return 1;
}

extern s32 D_004493E0[];
extern void func_001937E0();
extern void func_00193870();
extern void func_00175670();
void func_00193A80(u8 *p, u8 *q) {
    if (q[0x15B]) {
        u32 t = P(u8,4);
        P(u8,4) = t + 1;
        P(u8,0x13C) = 0;
    } else {
        func_00176160(q, 2, *(s8 *)(q + 0x150) + D_004493E0[q[0x25]], 1);
        func_001937E0(p, q);
        func_00193870(p, q);
        func_00175670(p);
    }
}
