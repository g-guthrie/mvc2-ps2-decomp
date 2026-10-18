typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


typedef struct { u8 p0[5]; u8 b5; u8 p1[0xD0-6]; s32 d0; s32 d4; s32 d8; } S1;

void func_001D7380(S1 *p, u8 *q) {
    s32 v;
    extern void func_001D70C0();
    extern void func_001D7500();
    extern void func_001E3710();
    if (p->b5 == 0) {
        if (*(s8 *)(q + 0x1B3) != 0) {
            p->d8 = 0xFF;
            goto call;
        }
        v = p->d0 - 1;
        p->d0 = v;
        if (v >= 0) return;
        if (p->d4 == 8) {
            u32 t = p->b5;
            p->b5 = t + 1;
            p->d0 = 3;
            p->d8 = 0xFF;
            return;
        }
        func_001D70C0(p);
        p->d0 = 3;
        v = p->d4 + 1;
        p->d4 = v;
        if ((v & 1) == 0) return;
        func_001E3710(p, 0x50);
        return;
    }
    v = p->d0 - 1;
    p->d0 = v;
    if (v >= 0) return;
call:
    func_001D7500(p);
}

void func_002A8930(u8 *p) {
    f32 *s0, *s1, *s2, *s3;
    extern s32 func_00175700();
    extern void func_00183D90();
    extern void func_001757E0();
    s0 = (f32 *)(p + 0x5C);
    s1 = (f32 *)(p + 0x60);
    s2 = (f32 *)(p + 0x68);
    s3 = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)func_00175700(p) >= 0) {
        func_00183D90(p);
    } else {
        u32 t = p[6];
        p[6] = t + 1;
        *(u32 *)s0 = 0;
        *(u32 *)s1 = 0;
        *(u32 *)s2 = 0;
        *(u32 *)s3 = 0;
        func_001757E0(p, 2, 2);
    }
}

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G1;
extern G1 *D_004C2794;

void func_00313CC0(u8 *p, u8 *q) {
    extern void func_00185490();
    extern void func_00175C00();
    extern void func_00183D10();
    extern void func_001757E0();
    extern void func_00313DA0();
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    {
        u32 t = p[6];
        p[6] = t + 1;
    }
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    q[0x12] = 0;
    p[0x1B5] = 0x46;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0x16, 8);
    func_00313DA0(p, q);
}

void func_00219600(u8 *p) {
    extern s32 func_00175700();
    extern void func_0019B110();
    extern void func_00354460();
    extern void func_001757E0(u8 *, s32, u8);
    extern void func_001E3210();
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_0019B110(p, 5);
        func_00354460(p, 0);
        func_001757E0(p, 0x15, p[0x1B7] + 0x19);
        func_001E3210(p, 0x1F);
    }
    if (*(s8 *)(p + 0x151) != 0) {
        *(u32 *)(p + 0x5C) = 0xC12D5555;
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
    }
}

typedef struct { f32 a; f32 b; s32 c; s32 d; } T4;
extern T4 D_00462090[];

void func_0034D330(u8 *p) {
    u8 *o;
    s32 *a2;
    s16 h;
    extern void func_0034D080();
    extern void func_001E3710();
    h = *(s16 *)(p + 0x1C);
    o = *(u8 **)(p + 0x18);
    h = h - 1;
    *(s16 *)(p + 0x1C) = h;
    a2 = (s32 *)(p + 0xD0);
    if (h != 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(s32 *)(p + 0x48) = *(s32 *)(p + 0x48) + *a2;
    } else {
        T4 *t;
        f32 f;
        u32 i;
        u32 b = p[5];
        p[5] = b + 1;
        i = p[0x22];
        p[0x22] = i + 1;
        t = &D_00462090[i];
        f = t->a;
        if (p[0x20] != 0) f = -f;
        *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34) + f;
        *(f32 *)(p + 0x38) = *(f32 *)(o + 0x38) + t->b;
        *(s32 *)(p + 0x48) = t->c;
        func_0034D080(p);
        func_001E3710(p, 0x17);
    }
}
