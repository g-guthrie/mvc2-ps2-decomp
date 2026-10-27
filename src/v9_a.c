#include "action_record.h"
typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;typedef signed int s32;typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 p0[4]; u8 f4; u8 p5[0x19]; u16 f1e_; } X;
typedef struct { u8 p0[4]; u8 f4; u8 p5[0x19]; s16 f1e; u8 p20; u8 f21; u8 p22; u8 f23; u8 p24[0x10]; V3 pos; u8 p40[0x1C]; V3 vel; V3 prev; } S;
extern V3 D_0043DD80[];
extern Mvc2ActionRecord D_00456080[];

void func_002A6500(u8 *p) {
    extern int func_00175700(u8 *); extern void func_00183d50();
    if (*(s8*)(p+0x151) == 0) func_00175700(p);
    *(f32*)(p+0x34) += *(f32*)(p+0x5C);
    *(f32*)(p+0x5C) += *(f32*)(p+0x68);
    *(f32*)(p+0x38) += *(f32*)(p+0x60);
    *(f32*)(p+0x60) += *(f32*)(p+0x6C);
    if (*(f32*)(p+0x38) <= *(f32*)(p+0x430)) {
        p[6]++;
        *(f32*)(p+0x38) = *(f32*)(p+0x430);
        p[0x20D] = 0;
        func_00183d50(p);
    }
}

void func_00376D40(u8 *p) {
    extern int func_00175700(u8 *); extern void func_001757E0();
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        *(s16*)(p+0x1C) = (s16)(p[0x1B7] ? 9 : 6);
        if (p[0x20] != 0) *(u32*)(p+0x5C) = 0xC0D55555;
        else *(u32*)(p+0x5C) = 0xC0555555;
        *(s32*)(p+0x68) = 0;
        if (*(s16*)(p+0x140) != 0) *(f32*)(p+0x5C) = -*(f32*)(p+0x5C);
        func_001757E0(p, 0x17, 6);
    }
}

s32 func_00165000(u8 *p, s32 q) {
    extern s32 func_0016B240(); extern void func_0016B0C0(); extern void func_00186CE0(); extern s32 func_001640A0();
    if (func_0016B240(p, 0) == 0) return 0;
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 3);
    p[0x451]++;
    *(f32*)(p+0x460) = *(f32*)(p+0x4C8);
    *(f32*)(p+0x464) = *(f32*)(p+0x34);
    *(s32*)(p+0x468) = 10;
    *(s32*)(p+0x46C) = 0;
    func_00186CE0(p, 10);
    return func_001640A0(p, q);
}

void func_001A9A40(u8 *p, u8 *q) {
    extern int func_00175700(u8 *); extern void func_001757E0();
    func_00175700(p);
    *(f32*)(p+0x34) += *(f32*)(p+0x5C);
    *(f32*)(p+0x5C) += *(f32*)(p+0x68);
    *(f32*)(p+0x38) += *(f32*)(p+0x60);
    *(f32*)(p+0x60) += *(f32*)(p+0x6C);
    if (*(f32*)(p+0x38) <= *(f32*)(q+0x430)) {
        p[7]++;
        p[0x24] = 0xC;
        *(f32*)(p+0x38) = *(f32*)(q+0x430);
        func_001757E0(p, 0x17, 0x16);
    }
}

void func_0029A4A0(u8 *p) {
    extern void func_001266A0(); extern void func_0015D010(); extern void func_0018C6E0(void *); extern void func_001757E0();
    f32 v[4];
    p[0x1E6] ^= 1;
    *(s16*)(p+0x140) = p[0x1E6];
    if ((p[0x22] & 2) == 0) {
        p[0x1E6] ^= 1;
        *(s16*)(p+0x140) = p[0x1E6];
    }
    func_001266A0(p, 5, 5);
    *(u32*)&v[0] = 0xC2A6AAAA;
    *(u32*)&v[1] = 0x431E9249;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_0018C6E0(p);
    *(s32*)(p+0x5C) = 0;
    *(s32*)(p+0x60) = 0;
    *(s32*)(p+0x68) = 0;
    *(s32*)(p+0x6C) = 0;
    func_001757E0(p, 0xF, 1);
}

void func_002A9490(u8 *p) {
    extern int func_00175700(u8 *); extern void func_00183d50(); extern void func_001757E0();
    *(f32*)(p+0x34) += *(f32*)(p+0x5C);
    *(f32*)(p+0x5C) += *(f32*)(p+0x68);
    *(f32*)(p+0x38) += *(f32*)(p+0x60);
    *(f32*)(p+0x60) += *(f32*)(p+0x6C);
    if (*(s8*)(p+0x161) >= 0) func_00175700(p);
    if (*(f32*)(p+0x38) <= *(f32*)(p+0x430)) {
        p[6]++;
        *(f32*)(p+0x38) = *(f32*)(p+0x430);
        p[0x20D] = 0;
        func_00183d50(p);
        func_001757E0(p, 0x15, 6);
    }
}

void func_00218840(u8 *p) {
    extern int func_00175700(u8 *); extern void func_001757E0(); extern void func_00183d50(); extern void func_001843A0();
    if (p[7] == 0) {
        *(f32*)(p+0x38) += *(f32*)(p+0x60);
        *(f32*)(p+0x60) += *(f32*)(p+0x6C);
        func_00175700(p);
        if (*(f32*)(p+0x38) < *(f32*)(p+0x430)) {
            p[7]++;
            p[0x20D] = 0;
            *(f32*)(p+0x38) = *(f32*)(p+0x430);
            func_001757E0(p, 0x15, (u8)(p[0x1B7] + 5));
            func_00183d50(p);
        }
    } else {
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
    }
}

void func_00132880(S *p, u8 *q) {
    u32 t = q[0x425];
    if (p->f21 != t) {
        V3 *e;
        p->f4++;
        p->f23 = 0x20;
        p->f1e = 0;
        p->f21 = t;
        if (t != 0) p->f1e |= 0x8000;
        e = &D_0043DD80[(t << 1) + q[2]];
        p->vel.x = (e->x - p->pos.x) / 32.0f;
        p->vel.y = (e->y - p->pos.y) / 32.0f;
        p->vel.z = (e->z - p->pos.z) / 32.0f;
        p->prev = p->pos;
    }
}

void func_0028A1D0(u8 *p) {
    extern int func_00175700(u8 *); extern void func_0028D810(u8 *, u8 *); extern void func_001830D0();
    u8 *q;
    f32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    q = p + 0x2B8;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8*)(p+0x151) == 0) {
        p[6]++;
        p[0x404] = 0;
        p[0x405] = 0;
        q[0xB] = 2;
        q[0xA] = 0xFF;
        func_0028D810(p, (u8 *)D_00456080);
        *(u32*)&v[0] = 0xC1555555;
        *(u32*)&v[1] = 0x42D20000;
        *(s32*)&v[2] = 0;
        func_001830D0(p, v, 1);
    }
}

void func_002B7B70(u8 *p) {
    extern void func_0015D010(); extern void func_0018C6E0(void *); extern void func_001757E0();
    f32 v[4];
    p[0x1B4] = 10;
    if (((p[0x22] << 10) & 0x800) != 0) {
        *(s16*)(p+0x140) ^= 1;
        p[0x1E6] ^= 1;
    }
    *(u32*)&v[0] = 0x42555555;
    *(u32*)&v[1] = 0x432B6DB6;
    func_0015D010(p, v);
    func_0018C6E0(p);
    *(u32*)(p+0x60) = 0x41092492;
    *(u32*)(p+0x6C) = 0xBF4DB6DB;
    if (p[0x210] != 0) {
        *(f32*)(p+0x5C) /= 2.0f;
        *(f32*)(p+0x68) /= 2.0f;
    }
    func_001757E0(p, 0xF, 1);
}

void func_00246BA0(u8 *p, u8 *q) {
    extern void func_002482C0(); extern int func_00175700(u8 *); extern void func_001830D0();
    f32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_002482C0(p, q);
    func_00175700(p);
    if (*(s8*)(p+0x151) != 0) {
        p[0x151] = 0;
        p[7]++;
        *(s16*)(p+0x1C) = 0x5A;
        *(s16*)(p+0x1E) = 0;
        q[7] = 5;
        *(u32*)&v[0] = 0xC22D5555;
        *(u32*)&v[1] = 0x42BC9249;
        *(s32*)&v[2] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        func_001830D0(p, v, 1);
    }
}

/* Called with actor and context at 00246870. Retail initializes all three
 * words of this 12-byte, 16-byte-aligned local vector at SP+0x30. */
void func_00246890(u8 *p, u8 *q) {
    extern int func_00175700(u8 *);
    extern void func_001830D0(u8 *, float *, int);
    f32 v[3] __attribute__((aligned(16)));
    typedef char LocalVectorSizeCheck[(sizeof(v) == 12) ? 1 : -1];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8*)(p+0x151) != 0) {
        p[0x151] = 0;
        p[7]++;
        *(s16*)(p+0x1C) = 0x5A;
        *(s16*)(p+0x1E) = 0;
        q[7] = 5;
        *(u32*)&v[0] = 0xC2855555;
        *(u32*)&v[1] = 0x434DB6DB;
        *(s32*)&v[2] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        func_001830D0(p, v, 1);
    }
}
