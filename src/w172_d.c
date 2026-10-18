typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x160]; s8 b[8]; } S;
typedef struct { f32 x, y; } V2;

extern V2 D_004535E0[];
extern void (*D_00471AB0[])(void *);

void func_00201950(u8 *s1) {
    extern s8 func_00175700(void *);
    extern void func_001266A0(void *, s32, s32);
    extern void func_001757E0(void *, s32, s32);
    extern void func_00185870(void *, void *);
    extern void func_00190D50(void *, void *);
    extern void func_0018FDB0(void *);
    extern void func_00200990(void *);
    u8 *s2;
    u8 *s0;
    s8 *p, *q;
    s8 f;
    s0 = s1 + 0x2B8;
    if (func_00175700(s1) < 0) {
        u32 t = s1[7];
        s1[7] = t + 1;
        func_001266A0(s1, 0, 0);
        *(s16 *)(s1 + 0x140) = *(s16 *)(s1 + 0x140) ^ 1;
        func_001757E0(s1, 0x16, 0x18);
        return;
    }
    p = ((S *)s1)->b;
    f = p[1];
    q = p + 1;
    if (f != 0) {
        *q = 0;
        s1[0x20B] = 0xC5;
        func_00185870(s1, *(u8 **)s0);
        s2 = *(u8 **)s0;
        func_00190D50(s2, s1);
        func_00190D50(s2, s1);
        s0[0x16] = 2;
    }
    if (*(s8 *)(s1 + 0x151) != 0) {
        s0 = *(u8 **)s0;
        *(u8 **)(s0 + 0x1C8) = s1;
        s0[0x1B5] = *(s8 *)(s1 + 0x151);
        s1[0x1B5] = *(s8 *)(s1 + 0x151);
        s1[0x151] = 0;
        func_0018FDB0(s1);
        func_00190D50(s0, s1);
        func_0018FDB0(s1);
        func_00190D50(s0, s1);
        func_00200990(s1);
    }
}

static void func_002555E0(u8 *p) {
    if (*(s16 *)(p + 0x2B8) > 0) {
        p[1037] = 0;
        p[1036] = 0;
        p[828] = 5;
    } else {
        p[1036] = 2;
        p[828] = 5;
    }
}
void func_00259E70(u8 *s0) {
    extern void func_001830D0(void *, void *, s32);
    extern void func_00183D10(void *);
    extern void func_00175700(void *);
    u8 *a3;
    f32 v[4];
    f32 t;
    f32 *w;
    a3 = s0 + 0x2B8;
    func_002555E0(s0);
    if (*(s8 *)(s0 + 0x151) == 1) {
        s0[0x151] = 0;
        *(u32 *)&v[0] = 0xC2200000;
        *(u32 *)&v[1] = 0x43092492;
        if (*(s16 *)a3 == 0) {
            func_001830D0(s0, v, 1);
        } else {
            func_001830D0(s0, v, 0);
        }
    }
    if (*(s8 *)(s0 + 0x151) == 2) {
        u32 u = s0[6];
        s0[6] = u + 1;
        s0[0x151] = 0;
        *(u32 *)(s0 + 0x5C) = 0;
        *(u32 *)(s0 + 0x60) = 0;
        *(u32 *)(s0 + 0x68) = 0;
        *(u32 *)(s0 + 0x6C) = 0;
        *(s16 *)(s0 + 0x1C) = 2;
        w = (f32 *)D_004535E0;
        *(f32 *)(s0 + 0x5C) = w[0];
        *(f32 *)(s0 + 0x68) = w[1];
        if (s0[0x1E6]) {
            t = -*(f32 *)(s0 + 0x5C);
        } else {
            t = *(f32 *)(s0 + 0x5C);
        }
        *(f32 *)(s0 + 0x5C) = t;
        if (s0[0x1E6]) {
            t = -*(f32 *)(s0 + 0x68);
        } else {
            t = *(f32 *)(s0 + 0x68);
        }
        *(f32 *)(s0 + 0x68) = t;
        func_00183D10(s0);
    }
    func_00175700(s0);
}

void func_0038FC40(u8 *s0) {
    extern s8 func_00175700(void *);
    extern void func_001757E0(void *, s32, s32);
    extern void func_001E7F60(void *);
    u32 a1;
    s0[0x24] = *(s8 *)(*(u8 **)(s0 + 0x18) + 0x24);
    a1 = s0[5];
    if (a1 == 0) {
        if (*(s8 *)(s0 + 0x1B2) != 0) {
            s0[5] = a1 + 1;
            func_001757E0(s0, 0x17, 0xA);
            return;
        }
        if (*(s8 *)(s0 + 0x1B3) != 0) {
            u32 t = s0[4];
            s0[4] = t + 1;
            s0[0x13C] = 0;
        } else {
            u32 v;
            D_00471AB0[s0[0x20]](s0);
            v = s0[0x22];
            if (v != 0) {
                s0[0x13C] = (s8)v & 1;
                v = s0[0x22];
                v = v - 1;
                s0[0x22] = v;
                if ((v & 0xFF) == 0) {
                    u32 t = s0[4];
                    s0[4] = t + 1;
                }
            } else {
                func_001E7F60(s0);
            }
        }
    } else {
        if (func_00175700(s0) < 0) {
            u32 t = s0[4];
            s0[4] = t + 1;
        }
    }
}

void func_003ADB80(u8 *s1) {
    extern void func_003AD500(void *);
    extern s8 func_00175700(void *);
    extern void func_001757E0(void *, s32, s32);
    u8 *s0;
    s16 v = *(s16 *)(s1 + 0x1E) - 1;
    s0 = *(u8 **)(s1 + 0x18);
    *(s16 *)(s1 + 0x1E) = v;
    if (v <= 0) {
        func_003AD500(s1);
        if (s1[5] == 0) {
            *(s16 *)(s1 + 0x1E) = 4;
        } else {
            *(s16 *)(s1 + 0x1E) = 7;
        }
        s1[0x22] = (s1[0x22] + 1) & 7;
    }
    if (s1[5] == 0) {
        func_00175700(s1);
        if (s0[0x15B] != 0) {
            u32 t = s1[5];
            s1[5] = t + 1;
            func_001757E0(s1, 0x12, (s1[0x21] + 3) & 0xFF);
        }
    } else {
        if (func_00175700(s1) < 0) {
            u32 t = s1[4];
            s1[4] = t + 1;
            s1[0x13C] = 0;
        }
    }
}

void func_003AEFE0(u8 *s2, u8 *s1) {
    extern void func_003AF6D0(void *);
    extern void func_003AF110(void *, void *);
    extern void func_003AF770(void *, void *, void *);
    extern void func_003AF280(void *, void *);
    extern void func_003AF890(void *, void *, void *);
    u8 *s0 = *(u8 **)(s2 + 0x18);
    u8 *v1, *a1;
    s32 v0;
    if (s0[6] == 4) {
        func_003AF6D0(s2);
        return;
    }
    if (s0[6] == 6) {
        func_003AF110(s2, s1);
        return;
    }
    func_003AF770(s2, s1, s0);
    s2[0x13C] = 1;
    v1 = *(u8 **)(s2 + 0xC);
    *(f32 *)(v1 + 0x34) = *(f32 *)(s2 + 0x34) + *(f32 *)(s1 + 0xC);
    *(f32 *)(v1 + 0x38) = *(f32 *)(s2 + 0x38) + *(f32 *)(s1 + 0x10);
    v1[0x13C] = 1;
    *(s16 *)(v1 + 0x1C) = 1;
    a1 = *(u8 **)(v1 + 0xC);
    *(f32 *)(a1 + 0x34) = *(f32 *)(s2 + 0x34) + *(f32 *)(s1 + 0x14);
    *(f32 *)(a1 + 0x38) = *(f32 *)(s2 + 0x38) + *(f32 *)(s1 + 0x18);
    a1[0x13C] = 1;
    *(s16 *)(a1 + 0x1C) = 1;
    v0 = *(s8 *)(s1 + 0x28);
    s1[0x29] = v0;
    if (v0 != 0) {
        u8 *a0 = *(u8 **)(a1 + 0xC);
        func_003AF280(a0, a0 + 0x88);
    } else {
        *(f32 *)(s0 + 0x34) = *(f32 *)(a1 + 0x34) - *(f32 *)(s1 + 0x1C);
        *(f32 *)(s0 + 0x38) = *(f32 *)(a1 + 0x38) - *(f32 *)(s1 + 0x20);
        func_003AF890(s2, a1, s0);
    }
}
