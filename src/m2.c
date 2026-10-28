#include "runtime_resource_record.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00185980(u8 *a);
extern void func_001E3210(u8 *a, int b);
static void func_002B5100(u8 *p) {
    f32 v;
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(f32 *)(p + 0x60) * *(f32 *)(p + 0x6C);
    if (!(v <= 0.0f)) {
        *(u32 *)(p + 0x6C) = 0xBFCDB6DB;
    }
}
extern void func_00183d50(void *p);
extern s8 func_00175700(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_00175C00(void *p, s32 a);
extern void func_001843A0(void *p);
extern void func_00184540(void *p);
extern void func_001E3710(void *p, s32 a);
typedef struct { f32 x, y, z; } V3;
extern void func_00177630(void *p);
extern void func_00126400();
extern void func_001266A0(void *p, s32 a, s32 b);
extern void func_0022C5D0(void *p);
extern void func_00175670(void *p);
extern int func_00415320(void *a, u32 *b, s32 c);
extern void func_00415590(void *a, u32 *b, s32 c, s32 d);


/* Called directly by func_0036E750 as (actor, owner, state), state an s32 array. */
void func_0036EA50(u8 *actor, u8 *owner, s32 *state) {
    if (func_00185980(actor)) {
        func_001E3210(actor, 0x24);
        state[1] = 1;
        return;
    }
}


void func_00179F60(u8 *p) {
    switch (p[1]) {
    case 0xA:
        (*(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x60))(p);
        break;
    case 0x38:
        (*(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x60))(p);
        break;
    }
}


void func_00313B80(u8 *p, u8 *q) {
    s8 v = p[0x1B2];
    if (v) {
        s32 f = v;
        if (!(f & 1) && !(f & 0x10)) {
            u8 *r = *(u8 **)(p + 0x1C4);
            if (!r[3] && !r[0x425] && !(*(u32 *)(r + 0x428) & 0x7000000) && r[5] == 3) {
                q[0xF] = 1;
            }
        }
    }
}

void func_002B51C0(u8 *p) {
    func_002B5100(p);
    if (*(f32 *)(p + 0x430) > *(f32 *)(p + 0x38)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00183d50(p);
    } else if (*(s8 *)(p + 0x151) == 0) {
        func_00175700(p);
    }
}

void func_0020F1D0(u8 *p) {
    u32 t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        func_001757E0(p, 0x14, 0x10);
    } else {
        s8 r = func_00175700(p);
        if (r < 0) {
            func_00175C00(p, 0);
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x6C) = 0;
            func_001843A0(p);
        }
    }
}


void func_002D4610(u8 *p) {
    u32 t = p[6];
    if (t != 0) {
        s8 r = func_00175700(p);
        if (r < 0) {
            func_001843A0(p);
        }
    } else {
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_001757E0(p, 0x14, 4);
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
    }
}


void func_00253770(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x151)) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
    }
}

void func_002730B0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x1DC);
    s8 r = func_00175700(p);
    if (r < 0) {
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_00184540(p);
    } else if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x1B5] = 0x21;
    }
}

void func_002A5A10(u8 *p) {
    u32 t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        p[0x20D] = 1;
        func_001757E0(p, 0x14, 6);
    } else {
        s8 r = func_00175700(p);
        if (r < 0) {
            func_00175C00(p, 0);
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x6C) = 0;
            func_001843A0(p);
        }
    }
}

void func_00221780(u8 *p) {
    func_00175700(p);
    if (*(f32 *)(p + 0x430) > *(f32 *)(p + 0x38)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x210] = 0;
        func_001E3710(p, 0x34);
        func_00183d50(p);
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        p[0x20D] = 0;
        func_001757E0(p, 0x15, 0xE);
    }
}

void func_001775A0(u8 *p) {
    u32 t = p[6];
    p[6] = t + 1;
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x22C);
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x230);
    *(s32 *)(p + 0x68) = 0;
    *(s16 *)(p + 0x1C) = 0;
    if (p[0x247] == 0x16) {
        func_001757E0(p, 0xD, 0x1C);
        p[0x13C] = 1;
        *(s32 *)(p + 0x48) = 0;
        *(V3 *)(p + 0x50) = *(V3 *)(p + 0x298);
        *(f32 *)(p + 0x118) = 1.0f;
    }
    func_00177630(p);
}

void func_001FB9B0(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        func_00184540(p);
    }
    if (*(s8 *)(p + 0x151)) {
        u8 *q;
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x20D] = 2;
        func_00126400();
        func_001266A0(p, 0, 0);
        q[0x1B5] = 0x23;
        *(s8 *)(q + 0x1E6) = *(s8 *)(p + 0x1E6) ^ 1;
    }
}

void func_00228780(u8 *p) {
    s8 r;
    *(s32 *)(p + 0x2DC) = 4;
    r = func_00175700(p);
    if (r >= 0) {
        if (*(s8 *)(p + 0x151) == 0) {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        }
    } else {
        *(s32 *)(p + 0x2DC) = 0;
        func_0022C5D0(p);
    }
}

void func_0019AEA0(u8 *p) {
    u8 *q;
    p[0x13C] = 0;
    q = *(u8 **)(p + 0x14);
    if (q[3] != 1 || *(u16 *)(q + 0x26) != 0x601 || q[4] >= 2) {
        u32 t = p[4];
        p[4] = t + 1;
    } else {
        u8 *r = q + 0x88;
        if (q[0xB2]) {
            *(V3 *)(p + 0x34) = *(V3 *)(r + 0x10);
            func_00175670(p);
            p[0x13C] = 1;
        }
    }
}

void func_0016F530(s32 a0, s32 a1, u32 *a2, ResourceRecord *a3, s32 t0, s32 t1) {
    func_00415020(a0, a3);
    func_00415320((void *)(u32)a1, a2, a0);
    func_00415590((void *)(u32)a1, a2, t0, t1);
}
