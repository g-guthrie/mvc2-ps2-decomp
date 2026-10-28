#include "action_record.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern int func_00175670(u8 *);
extern void func_001B81D0(u8 *);
void func_001B8030(u8 *p) {
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if ((s8)func_00175670(p) < 0) { func_001B81D0(p); return; }
}

extern s32 func_00174170(void);
extern f32 D_0044EB00[];
extern f32 D_0044EB04[];
void func_001DBDF0(u8 *p) {
    s32 i;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x5C) = 0;
    i = func_00174170() & 3;
    *(f32 *)(p + 0x60) = D_0044EB00[i * 2];
    *(f32 *)(p + 0x6C) = D_0044EB04[i * 2];
}

extern int func_00175700(u8 *);
typedef void (*Fn_0036E6F0)(u8 *, u8 *, s32 *);
extern Fn_0036E6F0 D_00463DA0[];
extern void func_00372260(u8 *);
void func_0036E6F0(u8 *p) {
    D_00463DA0[p[5]](p, *(u8 **)(p + 0x18), (s32 *)(p + 0x88));
    if (p[1] != (*(u8 **)(p + 0x18))[1]) { func_00372260(p); return; }
}

void func_001B66C0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else if (*(s8 *)(p + 0x150)) {
        *(s32 *)(p + 0x48) = -0x1000;
    } else {
        *(s32 *)(p + 0x48) = 0;
    }
}

extern void func_003859F0(u8 *);
void func_00385220(u8 *p) {
    u8 *q = *(u8 **)(*(u8 **)(p + 0x18) + 0x1DC);
    *(s16 *)(p + 0x1C) = 2;
    if (q[5] == 2 && q[0x20A] == 0) {
        s16 v = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v >= 0) return;
    }
    *(s16 *)(p + 0x1C) = 0;
    func_003859F0(p);
}

extern u8 *func_003DA750();
extern void func_001E0280();
void *func_001E0020(u8 *p) {
    u8 *o = func_003DA750(0, 4, 0);
    if (o) {
        *(void **)(o + 0x10) = (void *)func_001E0280;
        o[0x21] = 0;
        o[0x20] = 0;
        *(u8 **)(o + 0x18) = p;
        o[1] = p[1];
        *(s16 *)(o + 0x26) = 0x3801;
        *(u32 *)(o + 0xD0) = *(u16 *)(p + 0x168);
    }
    return o;
}

void func_0036A4C0(u8 *p) {
    u32 t;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        t = p[5]; p[5] = t + 1;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        *(u32 *)(p + 0x60) = 0x41CDB6DB;
        *(u32 *)(p + 0x6C) = 0xBD092492;
    }
}

extern void func_00381FD0();
void func_00381EC0(u8 *p, u8 q) {
    u8 *o = func_003DA750(p, 1, 2);
    if (o) {
        *(void **)(o + 0x10) = (void *)func_00381FD0;
        *(s32 *)(o + 0x18) = *(s32 *)(p + 0x18);
        *(u8 **)(o + 0x14) = p;
        o[0x20] = q;
        *(s16 *)(o + 0x26) = 0x1A00;
        *(s16 *)(o + 0x1E) = *(s16 *)(p + 0x1E);
    }
}

extern void func_00186A60(u8 *, s32);
void func_00304A10(u8 *p) {
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0:
        p[0x1FD] = 2;
        p[0x1B7] = 0;
        break;
    case 1:
        p[0x1FD] = 0;
        p[0x1B7] = 1;
        break;
    case 2:
        p[0x1FD] = 9;
        p[0x1B7] = 1;
        break;
    }
    func_00186A60(p, 0x15);
}

extern void func_00154850(f32 *, s32, s32, s32);
void func_00154940(u8 *p, f32 *q, s32 r) {
    f32 v[4];
    if (*(s16 *)(p + 0x140)) {
        v[0] = *(f32 *)(p + 0x34) - q[0];
    } else {
        v[0] = *(f32 *)(p + 0x34) + q[0];
    }
    v[1] = *(f32 *)(p + 0x38) + q[1];
    v[2] = *(f32 *)(p + 0x3C);
    func_00154850(v, *(s16 *)(p + 0x140), r, 0);
}

extern void func_00179160(u8 *, s32, s32);
extern s32 func_00393390(u8 *);
extern s32 func_003933A0(u8 *);
s32 func_003931C0(u8 *p) {
    u8 *o;
    u32 t;
    s32 a = *(s32 *)(p + 0x1DC);
    *(u8 *)(*(u8 **)(p + 0x18) + 0x1FE) = 1;
    *(u8 *)(*(u8 **)(p + 0x18) + 0x201) = 2;
    *(u8 *)(*(u8 **)(p + 0x18) + 0x209) = 2;
    func_00179160(p, a, 1);
    t = p[5];
    p[5] = t + 1;
    if (func_00393390(p)) return func_003933A0(p);
}

extern void func_0028D810(u8 *, u8 *);
extern void func_0028D8B0(u8 *);
extern void func_001C09A0(u8 *, s32);
extern void func_00385EE0(u8 *, s32);
extern Mvc2ActionRecord D_00455CF0[];
void func_002892D0(u8 *p) {
    u32 t;
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        t = p[7];
        p[7] = t + 1;
        p[0x151] = 0;
        func_0028D810(p, (u8 *)D_00455CF0);
        func_0028D8B0(p);
        func_001C09A0(p, 4);
        func_00385EE0(p, 1);
    }
}

extern s32 D_00471988[];
s32 func_0038D310(s32 a0, s32 a1) {
    switch (a0) {
    case 0: return 0;
    case 1: return 0xC718;
    case 2: return 0;
    case 3: return 0;
    case 4: return D_00471988[a1];
    }
    return 0;
}

extern void func_001757E0();
extern void func_00291CB0();
void func_00291C30(u8 *p, u8 *q) {
    u32 t = q[0x18];
    q[0x18] = t + 1;
    *(s16 *)(p + 0x1C) = 6;
    q[0x19] = 0;
    if (p[0x1E6] == 0) {
        *(u32 *)(p + 0x5C) = 0xC0A00000;
    } else {
        *(u32 *)(p + 0x5C) = 0x40A00000;
    }
    *(s32 *)(p + 0x68) = 0;
    func_001757E0(p, 0x16, 8);
    func_00291CB0(p, q);
}

extern void func_00361180();
void func_003610F0(u8 *p, u8 a, u8 b) {
    u8 *o = func_003DA750(0, 1, 1);
    if (o) {
        *(void **)(o + 0x10) = (void *)func_00361180;
        *(s16 *)(o + 0x26) = 0xF04;
        *(s32 *)(o + 0x18) = *(s32 *)(p + 0x18);
        *(u8 **)(o + 0x14) = p;
        o[1] = p[1];
        o[0x20] = a;
        o[0x21] = b;
        *(u16 *)(o + 0xD0) = *(u16 *)(p + 0xD0);
    }
}

extern void func_0015CF60();
void func_0015CED0(u8 *p, u8 q, u8 r) {
    u8 *o = func_003DA750(0, (u8)(r == 9 ? 0x1F : 0x43), 1);
    if (o) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_0015CF60;
        *(u32 *)(o + 0xD0) = 0x800400;
        *(u8 **)(o + 0xC8) = p + 0x88;
        o[0x20] = q;
    }
}

void func_003726F0(u8 *p) {
    u8 *q;
    u32 t = p[4];
    p[4] = t + 1;
    *(u32 *)(p + 0x5C) = 0xBFD55555;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0xBF892492;
    *(u32 *)(p + 0x48) = 0;
    if (*(s16 *)(p + 0x140)) *(u32 *)(p + 0x5C) = 0x3FD55555;
    *(s16 *)(p + 0x1C) = 0;
    func_001757E0(p, 0x15, 9);
    q = *(u8 **)(p + 0x18);
    if (p[1] == q[1]) q[0x21] = 0;
}

extern s32 func_0019B710();
extern void func_0019B740();
void func_0019B3D0(u8 *p) {
    if (p[5] == 0) {
        if (func_0019B710(p, 0xB) == 0) {
            func_0019B740(p);
            return;
        }
    }
    if ((s8)func_00175670(p) < 0) {
        func_0019B740(p);
    } else {
        *(V3 *)(p + 0x34) = *(V3 *)(*(u8 **)(p + 0x18) + 0x34);
    }
}

extern void func_0018D0C0();
extern void func_00191210();
void func_00177430(u8 *p) {
    u32 t;
    f32 z;
    func_0018D0C0(p);
    z = 0.0f;
    if (*(f32 *)(p + 0x5C) == z) {
        t = p[6]; p[6] = t + 1;
        p[0x20D] = 0;
        if ((p[0x245] & 7) == 5) {
            *(s16 *)(p + 0x1F8) = 2;
            func_00191210(p);
        } else {
            p[0x1F7] = 0x3C;
            *(s16 *)(p + 0x1F8) = 0x78;
            func_00191210(p);
        }
    }
}
