typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_00338100(int);
extern void func_003384F0(int);
extern void func_00338BF0(int);
extern void func_003394A0(int);
extern void func_00339690(int);
extern void func_00339820(int);
extern void func_0033A0B0(int);
extern void func_0033A240(int);
extern void func_00339AC0(int);

void func_0033A320(void) {
    func_00338100(8);
    func_003384F0(9);
    func_00338BF0(13);
    func_003394A0(15);
    func_00339690(16);
    func_00339820(17);
    func_0033A0B0(18);
    func_0033A240(19);
    func_00339AC0(11);
}

extern void func_00185490(int);
s32 func_0036EAE0(u8 *a0, u8 *a1, u8 *a2) {
    s32 r = *(s32*)(a2+4);
    if (r != 0) {
        s32 x = *(s32*)(a1+0x220);
        if (*(u8**)(*(u8**)(a0+0x1E0)+0x1E0) != a0) {
            func_00185490(x);
            { u32 t = a0[4]; a0[4] = t + 1; }
            a0[0x13C] = 0;
            r = 0;
        }
    }
    return r;
}

extern void func_00186A60(void *, int);
void func_002229B0(u8 *a0) {
    a0[5] = 0;
    a0[7] = 0;
    a0[6] = 0;
    switch (*(s8*)(a0+0x4DD)) {
    case 1:
        a0[0x1FD] = 0;
        break;
    case 0:
    case 2:
        a0[0x1FD] = 1;
        *(s16*)(a0+0x2DA) = 1;
        break;
    }
    a0[0x1B7] = 1;
    func_00186A60(a0, 0x15);
}

typedef float f32;
extern f32 func_00117400(f32);
extern s32 func_00118FA8(f32);
s32 func_001E1FF0(s32 a0) {
    s32 r;
    if (a0 != 0) {
        r = func_00118FA8(200.0f * func_00117400((f32)a0 / 127.0f));
    } else {
        r = -999;
    }
    return r;
}

extern void func_0016B0C0(void *, void *, int);
extern int func_00166C80(void *, void *, int);
int func_00168250(u8 *a0, void *a1) {
    func_0016B0C0(a0, a1, 0);
    func_0016B0C0(a0, a1, 1);
    return func_00166C80(a0, a1, a0[0x2B8] == *(s32*)(a0+0x4C8));
}

extern void func_001266A0(void *, int, int);
extern void func_0018C6E0(void *);
extern void func_0015D010(void *, s32 *);
extern void func_001757E0(void *, int, int);
void func_00272DD0(u8 *a0) {
    s32 v[3];
    func_001266A0(a0, 6, 6);
    func_0018C6E0(a0);
    a0[0x1B4] = 10;
    v[0] = 0; v[1] = 0; v[2] = 0;
    func_0015D010(a0, v);
    func_001757E0(a0, 15, 2);
}

extern int func_00175700(u8 *);
void func_0036D8B0(u8 *a0) {
    if (*(u8*)(*(u8**)(a0+0x18)+5) != 0) {
        a0[5] = 2;
        *(s16*)(a0+0x1C) = 10;
    } else {
        func_00175700(a0);
        if (*(s8*)(a0+0x153) < 0) {
            u32 t = a0[4]; a0[4] = t + 1;
            a0[0x13C] = 0;
        }
    }
}

void func_0034DA60(u8 *a0) {
    *(f32*)(a0+0x34) += *(f32*)(a0+0x5C);
    *(f32*)(a0+0x5C) += *(f32*)(a0+0x68);
    *(f32*)(a0+0x38) += *(f32*)(a0+0x60);
    *(f32*)(a0+0x60) += *(f32*)(a0+0x6C);
    if (*(f32*)(a0+0x38) < *(f32*)(*(u8**)(a0+0x18)+0x430)) {
        u32 t = a0[5]; a0[5] = t + 1;
        *(f32*)(a0+0x38) = *(f32*)(*(u8**)(a0+0x18)+0x430);
    }
}

void func_00238F40(u8 *a0) {
    a0[5] = 0;
    a0[6] = 0;
    a0[7] = 0;
    switch (*(s8*)(a0+0x4DD)) {
    case 0:
        a0[0x1FD] = 1;
        a0[0x1B7] = 1;
        break;
    case 1:
        a0[0x1FD] = 2;
        a0[0x1B7] = 1;
        break;
    case 2:
        a0[0x1FD] = 0;
        a0[0x1B7] = 1;
        break;
    }
    func_00186A60(a0, 0x15);
}

extern void func_001843A0(void *);
extern void func_001843A0(void *);
extern s32 func_003D92F0();
extern void *func_001BC660(void *, int);
void func_00279170(u8 *a0) {
    if (func_003D92F0(a0)) {
        func_001843A0(a0);
    } else {
        func_00175700(a0);
        if (*(s8*)(a0+0x150) > 0) {
            u32 t = a0[7]; a0[7] = t + 1;
            func_001BC660(a0, 0x10);
        }
    }
}

extern u8 D_004F1F45[];
extern u8 D_004F1F46[];
void func_002D81A0(u8 *a0) {
    s32 r = (s8)func_00175700(a0);
    if (r < 0) {
        func_001843A0(a0);
    } else {
        if (*(s8*)(a0+0x150) != 0) {
            a0[0x150] = 0;
            *D_004F1F45 = 1;
            *D_004F1F46 = 1;
        }
    }
}

void func_00217780(u8 *a0) {
    func_00175700(a0);
    if (*(s8*)(a0+0x151) != 0) {
        u32 t = a0[6]; a0[6] = t + 1;
        a0[0x151] = 0;
        *(u32*)(a0+0x60) = 0xC1AB6DB6;
        *(u32*)(a0+0x6C) = 0;
        if (a0[0x210] != 0) {
            *(u32*)(a0+0x60) = 0xC1DEDB6D;
        }
        *(u32*)(a0+0x5C) = 0;
        *(u32*)(a0+0x68) = 0;
    }
}

void func_001D50D0(u8 *a0, u8 *a1) {
    if (a1[5] != 0 || a1[0x1E4] != 0x1D) {
        a0[4] = 2;
        a0[0x13C] = 0;
    } else {
        s16 v = *(s16*)(a0+0x1C) - 1;
        *(s16*)(a0+0x1C) = v;
        if (v == 0) {
            a0[4] = 2;
            a0[0x13C] = 0;
        } else {
            func_00175700(a1);
        }
    }
}



extern u8 D_0044AFC0[];
extern void func_001A16D0(void *, void *);
extern void func_001A09B0(void *);
extern int func_001A0880(void *, void *);
extern void func_001A17C0(void *, void *, int);
extern void func_001A1910(void *, void *);
extern void func_001A1860(void *, void *);
void func_001A1440(u8 *a0, u8 *a1) {
    func_001A16D0(a0, a1);
    { u32 t = a0[4]; a0[4] = t + 1; }
    *(u8**)(a0+0x1C4) = D_0044AFC0;
    func_001A09B0(a0);
    func_001A0880(a0, a1);
    func_001A17C0(a0, a1, 0);
    func_001A1910(a0, a1);
    func_001A1860(a0, a1);
}

extern u8 *func_003DA750(int, int, int);
extern void func_001CDEC0();
void func_001CDE40(u8 *a0, u8 a1, u8 a2) {
    u8 *p = func_003DA750(0, 3, 0);
    if (p != 0) {
        *(void**)(p+0x10) = (void*)func_001CDEC0;
        *(u8**)(p+0x18) = a0;
        p[0x20] = a1;
        p[0x21] = a2;
        *(s16*)(p+0x26) = 0x2300;
        p[1] = a0[1];
        *(u16*)(p+0xD0) = *(u16*)(a0+0x168);
    }
}
