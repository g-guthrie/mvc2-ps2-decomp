typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern int *D_004C8928;
extern int *D_004C892C;
extern int *D_004C8930;
typedef char *va_list;
extern void func_00120A30(void *, s32, char *, va_list);
extern u8 D_004C83D0[];
extern s32 func_0010E0F8(s32);
extern void func_0040EE28(void);
extern void func_0011EB60();
extern u8 D_004BE860[];
extern void func_00103BA0(void);
extern s32 func_00104990(s32);
extern s32 func_00103B10(s32, s32);
extern s32 D_004C3AD4;
extern s32 D_00438268;
extern s32 func_0010C3E0(void);
extern void func_0011D8F8(void *, s32, s32);
extern u8 D_00490DA8[];
extern s32 D_004C24D8;

void func_003FF288(void) { func_0040EE28(); }

void func_0040ED00(void) { func_0011EB60(D_004BE860); }

void func_00104AA0(void) { func_00103BA0(); __asm__ volatile("sync"); }

void func_001061D8(void) {
    func_00104990(5);
    func_00103B10(5, D_004C3AD4);
    D_00438268 = 0;
}

void func_00110898(void *argument) {
    int *p = (int *)((u32)argument | 0x20000000);
    if (D_004C8928) *D_004C8928 = p[0];
    if (D_004C892C) *D_004C892C = p[1];
    if (D_004C8930) *D_004C8930 = p[36];
}

void func_0011EB00(s32 *obj, char *fmt, ...) {
    va_list ap;
    ap = (va_list)__builtin_next_arg(fmt) - 48;
    func_00120A30(obj, obj[2], fmt, ap);
}

typedef struct { s32 f0, f4, f8, fC, f10; } S400E40;
extern void func_0040ADF0(s32, s32, s32, s32);
extern void func_0040AE10(s32);

void func_00400E40(S400E40 *p) {
    if (p) {
        func_0040ADF0(p->f8, p->fC, p->f10, p->f4);
        func_0040AE10(p->f0);
    } else {
        func_0040ADF0(0, 0, 0, 0);
        func_0040AE10(0);
    }
}

extern s32 func_004064E8(s32, s32, s32);
extern s32 func_004001A8(s32, s32, s32, s32);
extern void func_003FB178(void *, s32);
extern void func_00400658(s32, s32);
extern u8 D_004BBEE0[];

s32 func_004003C8(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 v = func_004064E8(a, b, 0);
    s32 r;
    if (v == 0) {
        func_003FB178(D_004BBEE0, a);
        return 0;
    }
    r = func_004001A8(v, c, d << 11, e);
    if (r != 0) func_00400658(r, 0);
    return r;
}

extern void func_004067B8(s8 *);
extern void func_00407B08(s8 *, s32);
extern s32 func_00406128(s8 *);
extern void func_0011FE88(s32, s32);

s32 func_00406440(s8 *p, s32 q, s32 r) {
    s32 v;
    if (*p == 0) {
        func_004067B8(p);
        if (*p == 0) return 0;
    }
    func_00407B08(p, q);
    v = func_00406128(p);
    if (v == 0) {
        func_004067B8(p);
        v = func_00406128(p);
        if (v == 0) return v;
        func_0011FE88(q, r);
    }
    return v;
}

extern void func_0040BBB8(void);
extern void func_0040B098(void);
extern void func_00408698(void);
extern s32 func_00108118(s32);
extern void func_004086B8(void);
extern void func_0040B6E0(u8 *);
extern s32 D_004895D4;
extern u8 D_004BE068[];

void func_0040B8A8(u8 *p) {
    s32 r;
    if (p != 0) {
        if (p[2] >= 2) func_0040BBB8();
        if (*(s8 *)(p + 1) == 0) {
            func_0040B098();
            func_00408698();
            r = func_00108118(*(s32 *)(p + 0x18));
            func_004086B8();
            if (r < 0 && D_004895D4 != 2) func_0011EB60(D_004BE068);
        }
        p[0] = 0;
        func_0040B6E0(p);
    }
}

extern s32 func_001089F0(s32, s32, s32 *);
extern u8 D_004BDDD8[];
extern u8 D_004BDDB0[];

