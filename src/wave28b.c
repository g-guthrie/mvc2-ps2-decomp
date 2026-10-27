typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_0037DC50(u8 *a, u8 *b);
extern void func_0037D9F0(u8 *a, u8 *b);
extern int func_00175700(u8 *);

void func_0037DBC0(u8 *p, u8 *q) {
    if (p[1] != q[1]) {
        func_0037DC50(p, q);
    } else {
        func_0037D9F0(p, q);
        if ((s8)func_00175700(p) < 0) {
            p[4] = 2;
            p[316] = 0;
        }
    }
}

extern void func_00176160(u8 *a, s32 b, s32 c, s32 d);
extern void func_003DAA40(void *a);

void func_00329810(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    if (*(s32 *)(q + 716) > 0) {
        *(s32 *)(q + 720) = *(s32 *)(q + 720) + 1;
        *(s32 *)(q + 720) = *(s32 *)(q + 720) % 6;
        func_00176160(q, 4, *(s32 *)(q + 720) + 16, 1);
    } else {
        func_003DAA40(p);
    }
}

extern void func_002C6AF0(u8 *p);
extern void func_001843A0(u8 *p);

void func_002C6A70(u8 *p) {
    switch (p[0x1fc]) {
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        }
        break;
    case 2:
        func_002C6AF0(p);
        break;
    }
}

extern void func_0016B0C0(u8 *p, u8 *q, s32 z);
extern s32 func_00174170(void);


extern s32 func_001864A0(u8 *p);
extern void func_001865B0(u8 *p);

void func_00202710(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5c);
    *(f32 *)(p + 0x5c) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6c);
    func_00175700(p);
    if (func_001864A0(p)) {
        func_001865B0(p);
    }
}

extern void func_0019B110(u8 *p, s32 a);

void func_003206B0(u8 *p) {
    p[1036] = 2;
    p[828] = 5;
    if ((s8)func_00175700(p) >= 0) {
        if (*(s8 *)(p + 337) & 2) {
            func_0019B110(p, 7);
        }
    } else {
        p[1037] = 0;
        p[1036] = 0;
        p[827] = 0;
        p[828] = 0;
        func_001843A0(p);
    }
}

extern void func_001E3210(u8 *p, s32 a);
extern void func_001A78D0(u8 *p, s32 a);
extern void func_00363BD0(u8 *p, s32 a);

void func_0024BC80(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 337) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[337] = 0;
        func_001E3210(p, 47);
        if (p[439] == 0) {
            func_001A78D0(p, 2);
        } else {
            func_001A78D0(p, 3);
        }
        func_00363BD0(p, 0);
    }
}

extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_003B7AB0(void);

void func_003B7A20(u8 *p) {
    u8 *v = func_003DA750(0, 1, 0);
    if (v != 0) {
        *(void **)(v + 16) = (void *)func_003B7AB0;
        *(f32 *)(v + 52) = *(f32 *)(p + 52);
        *(f32 *)(v + 56) = *(f32 *)(p + 56);
        *(u32 *)(v + 24) = *(u32 *)(p + 24);
        *(u8 **)(v + 20) = p;
        v[1] = p[1];
        *(s16 *)(v + 38) = 13569;
        v[32] = 255;
        *(s16 *)(v + 28) = *(s16 *)(p + 28);
        *(s16 *)(v + 30) = *(s16 *)(p + 30);
    }
}

extern void func_001757E0(u8 *p, s32 a, s32 b);
extern void func_00375DA0(u8 *p, s32 a);

void func_0026D7E0(u8 *p) {
    u32 t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        func_001757E0(p, 21, 14);
    } else {
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        } else if (*(s8 *)(p + 337) != 0) {
            p[337] = 0;
            func_00375DA0(p, 0);
        }
    }
}

extern void func_00183D50(u8 *p);

void func_0020A4E0(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    if (*(f32 *)(p + 56) < *(f32 *)(p + 1072)) {
        u32 t = p[7];
        p[7] = t + 1;
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        func_00183D50(p);
        func_001757E0(p, 1, 3);
    }
}

void func_001F9140(u8 *p) {
    if (*(s8 *)(p + 337) != 0) {
        *(f32 *)(p + 52) += *(f32 *)(p + 92);
        *(f32 *)(p + 92) += *(f32 *)(p + 104);
        *(f32 *)(p + 56) += *(f32 *)(p + 96);
        *(f32 *)(p + 96) += *(f32 *)(p + 108);
    }
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    }
}




extern s32 func_0019B710(u8 *p, s32 a);
extern void func_0019B740(u8 *p);
extern s32 func_00175670();

void func_0019B2C0(u8 *p) {
    if (p[5] == 0) {
        if (func_0019B710(p, 7) == 0 && func_0019B710(p, 20) == 0 && func_0019B710(p, 21) == 0) {
            func_0019B740(p);
            return;
        }
    }
    if ((s8)func_00175670(p) < 0) {
        func_0019B740(p);
    }
}
