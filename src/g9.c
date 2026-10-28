#include "actor_motion_node.h"
struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_0014E770();
extern void func_003DAA40(struct Object *);
extern int func_00175670(u8 *);

void func_0016C830(u8 *p) {
    *(float *)(p + 0x104) += 0.0005208333604969084f;
    *(float *)(p + 0x10C) += 0.0005208333604969084f;
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            u32 t = p[4];
            p[4] = t + 1;
            *(s16 *)(p + 0x1C) = 0xF0;
        }
    }
}

void func_0015F310(u8 *p) {
    if (p[0x23]) {
        func_003DAA40((struct Object *)p);
    } else {
        s16 v = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v == 0) {
            u32 t = p[4];
            p[4] = t + 1;
            *(s16 *)(p + 0x1E) = 4;
        }
    }
}

void func_001B3270(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = v - 1;
    if (v == 0) {
        u32 t = p[4];
        p[4] = t + 1;
    }
    *(float *)(p + 0x34) += *(float *)(p + 0x5C);
    *(float *)(p + 0x5C) += *(float *)(p + 0x68);
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    func_00175670(p);
}

extern void func_00321BE0();
void func_00321B80(u8 *p, u8 *q) {
    *(s8 *)(p + 0x151) = 12;
    *(float *)(p + 0x5C) = (*(float *)(q + 0x34) - *(float *)(p + 0x34)) / 32.0f;
    *(s32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x41092492;
    *(u32 *)(p + 0x6C) = 0xBF092492;
    *(float *)(p + 0x34) -= 4.0f * *(float *)(p + 0x5C);
    func_00321BE0(p, q);
}

extern s32 D_004CAB60;
extern s32 D_004CAB10;
extern void func_003FCCF0();
extern void func_0012E320();
extern void func_0012E4C0();
void func_0012E6B0(void) {
    if (D_004CAB60) {
        func_003FCCF0(D_004CAB60);
        D_004CAB60 = 0;
    }
    if (D_004CAB10) {
        func_003FCCF0(D_004CAB10);
        D_004CAB10 = 0;
    }
    func_0012E320();
    func_0012E4C0();
}

extern u8 *func_003DA750();
extern void func_003814D0();
void func_003813B0(u8 *a, s32 b) {
    u8 *v = func_003DA750(0, 1, 0);
    if (v) {
        *(void **)(v + 0x10) = func_003814D0;
        v[0x20] = b;
        *(u8 **)(v + 0x18) = a;
        *(s16 *)(v + 0x26) = 0x1903;
        v[0x1B7] = a[0x1B7];
    }
}

extern int func_00175700(u8 *);
extern void func_001757E0();
void func_002303F0(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
        p[0x169] = 0x14;
        p[0x168] = 5;
        func_001757E0(p, p[0x169], p[0x168]);
    }
}

extern void func_00366090();
void func_00366020(u8 *a, s32 b) {
    u8 *v = func_003DA750(a, 1, 2);
    if (v) {
        *(void **)(v + 0x10) = func_00366090;
        *(s32 *)(v + 0x18) = *(s32 *)(a + 0x18);
        *(u8 **)(v + 0x14) = a;
        v[0x20] = 3;
        v[0x21] = b;
        *(s16 *)(v + 0x26) = 0x1101;
    }
}

extern void func_00186A20();
extern void func_00183D10();
extern void func_001C09A0();
extern void func_001E3710();
void func_00289910(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        u32 t = p[7];
        p[7] = t + 1;
        func_00186A20(p);
        p[0x150] = 0;
        func_00183D10(p);
        func_001C09A0(p, 8);
        func_001E3710(p, 0x4B);
    }
}

extern void func_0022C5D0();
void func_00229A50(u8 *p) {
    s8 r = func_00175700(p);
    if (r >= 0) {
        if (*(s8 *)(p + 0x151) == 0) {
            *(float *)(p + 0x34) += *(float *)(p + 0x5C);
            *(float *)(p + 0x5C) += *(float *)(p + 0x68);
        }
    } else {
        func_0022C5D0(p);
    }
}

extern u32 D_0062BFE4;
extern u32 D_0062BFE0;
extern void func_003DC950();
extern void func_003ECD00();
extern void func_0011D8F8();
void func_00233200(u8 *p) {
    u8 *q = p + 0x2B8;
    s32 a = *(s32 *)q;
    s8 d;
    u8 b, c;
    b = p[0x2C6];
    c = p[0x2C7];
    d = *(s8 *)(p + 0x2C8);
    func_0011D8F8(p + 0x2B8, 0, 0x80);
    *(s32 *)q = a;
    q[0xE] = b;
    q[0xF] = c;
    *(s8 *)(q + 0x10) = d;
}

void func_00162740(u8 *p, u8 *q) {
    *(float *)(q + 0x34) = *(float *)(p + 0x34) + *(float *)(q + 0x5C);
    *(float *)(q + 0x38) = *(float *)(p + 0x38) + *(float *)(q + 0x60);
    {
        s16 v = *(s16 *)(q + 0x1E) - 1;
        *(s16 *)(q + 0x1E) = v;
        if (v == 0) {
            s16 w;
            q[4] = 1;
            w = *(s16 *)(q + 0x1C) + 1;
            *(s16 *)(q + 0x1C) = w;
            if (w >= 8) {
                q[4] = 3;
                *(s16 *)(q + 0x1C) = 7;
            }
        }
    }
}

extern void func_0035DF70();
void func_0035DE70(u8 *a, s32 b, s32 c) {
    u8 *v = func_003DA750(0, 1, 0);
    if (v) {
        *(void **)(v + 0x10) = func_0035DF70;
        *(s16 *)(v + 0x26) = 0xD02;
        *(u8 **)(v + 0x18) = a;
        v[0x20] = b;
        v[0x21] = c;
        v[1] = a[1];
    }
}

extern void func_001A2960();

extern int func_001A0880(void *, void *);
extern void func_001A2BE0();
extern void func_001A2B40();
extern u8 D_0044B000[];
void func_001A2720(u8 *p, u8 *q) {
    func_001A2960(p, q);
    {
        u32 t = p[4];
        p[4] = t + 1;
    }
    p[5] = 0;
    *(void **)(p + 0x1C4) = D_0044B000;
    func_001A09B0((ActorMotionNode *)p);
    func_001A0880(p, q);
    func_001A2BE0(p, q);
    func_001A2B40(p, q);
}


extern void func_00184540();
extern void func_001843A0();
extern void func_002C5030();
void func_002C2E80(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        if (p[0x20D] != 2) {
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x6C) = 0;
            p[0x338] = 0;
            func_001843A0(p);
        } else {
            func_00184540(p);
        }
    }
    func_002C5030(p);
}

void func_00230270(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        func_001843A0(p);
    } else {
        *(float *)(p + 0x34) += *(float *)(p + 0x5C);
        *(float *)(p + 0x5C) += *(float *)(p + 0x68);
        *(float *)(p + 0x38) += *(float *)(p + 0x60);
        *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    }
}

extern float func_00154710();
extern u8 D_00444BC0[];
extern u8 D_00444BD0[];
void func_00156930(u8 *p) {
    s16 a = *(s16 *)(p + 0x1C);
    if (a >= 5) {
        func_003DAA40((struct Object *)p);
    } else {
        float f = func_00154710(D_00444BC0, p + 4, a);
        *(float *)(p + 0x50) = f;
        *(float *)(p + 0x54) = f;
        f = func_00154710(D_00444BD0, p + 5, *(s16 *)(p + 0x1C));
        *(float *)(p + 0x78) = f;
        *(float *)(p + 0x7C) = f;
        *(float *)(p + 0x80) = *(float *)(p + 0x78);
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    }
}

void func_00223C10(u8 *p) {
    u32 m = p[0x1FC];
    u8 *q = p + 0x2B8;
    s8 r;
    switch (m) {
    case 0:
    case 1:
        if (q[0]) p[0x200] = 1;
    case 2:
        r = func_00175700(p);
        if (r < 0) func_001843A0(p);
    }
}

extern float D_0045CE50[];
void func_0030A450(u8 *p) {
    s32 v = *(s8 *)(p + 0x151);
    if (v < 0) {
        p[0x209] = 1;
        v = *(s8 *)(p + 0x151) & 0x7F;
        if (v) {
            float f;
            *(s8 *)(p + 0x151) = -128;
            f = D_0045CE50[v & 0xFF];
            if (p[0x1E6] == 0) f = -f;
            *(float *)(p + 0x34) += f;
        }
    }
}
