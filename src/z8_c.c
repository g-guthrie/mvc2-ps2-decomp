typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G2E;
extern G2E *D_004C2794;

void func_002E5230(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    s8 r = func_00175700(p);
    if (r < 0) {
        func_001843A0(p);
        return;
    }
    switch (p[0x1FC]) {
    case 0:
        break;
    case 2:
        break;
    case 1:
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x1B5] = 0x19;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            p[0x151] = 0;
        }
        break;
    }
}

typedef struct { u16 f0; } G38;
extern G38 *D_004C29AC;
typedef struct S38 {
    u8 p0[5]; u8 f5; u8 p1[0x12]; struct S38 *f18; u8 p2[0x34 - 0x1C];
    f32 f34; f32 f38; u8 p3[0x161 - 0x3C]; s8 f161; u8 p4[6]; u16 f168;
} S38;

void func_003849C0(S38 *p) {
    extern void func_003859F0();
    extern void func_00175700();
    if (D_004C29AC->f0 != p->f18->f168) {
        func_003859F0(p);
        return;
    }
    p->f34 = p->f18->f34;
    p->f38 = p->f18->f38;
    if (p->f5 == 0) {
        if (p->f18->f161 < 0) {
            p->f5 = p->f5 + 1;
            func_00175700(p);
        } else {
            while (p->f161 != p->f18->f161) func_00175700(p);
        }
    } else {
        func_00175700(p);
    }
}

void func_002D3630(u8 *p) {
    extern s8 func_00175700();
    extern void func_00184540();
    extern void func_001843A0();
    extern u8 *func_0039C5B0();
    u8 *o;
    s8 r = func_00175700(p);
    if (r < 0) {
        if (p[0x20D] == 2) {
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x6C) = 0;
            func_00184540(p);
            return;
        } else {
            func_001843A0(p);
        }
    } else if (*(s8 *)(p + 0x151) != 0) {
        if ((o = func_0039C5B0(p, 4)) != 0) {
            u8 *q = o + 0x88;
            if (p[0x20D] == 2) *(s16 *)(q + 0x10) = 1;
            else *(s16 *)(q + 0x10) = 0;
            if (p[0x20D] != 2) func_0039C5B0(p, 0xA);
        }
        p[0x151] = 0;
    }
}

typedef struct { f32 x, y; s32 z, w; } T34;
extern T34 D_00462090[];
typedef struct S34 {
    u8 p0[4]; u8 f4; u8 f5; u8 p1[0x12]; struct S34 *f18; s16 f1c; u8 p2[2];
    u8 f20; u8 p3; u8 f22; u8 p4[0x11]; f32 f34; f32 f38; u8 p5[8]; s32 f44; s32 f48; u8 p6[0x10];
    f32 f5c; f32 f60; u8 p7[0x6C]; s32 fd0;
} S34;

void func_0034D420(S34 *p) {
    extern void func_001E7F60();
    extern void func_0034D080();
    S34 *q = p->f18;
    s32 *w;
    s16 v = p->f1c - 1;
    p->f1c = v;
    w = &p->fd0;
    if (v != 0) {
        p->f34 += p->f5c;
        p->f38 += p->f60;
        p->f48 += *w;
        func_001E7F60(p);
    } else {
        T34 *t;
        f32 d;
        p->f5 = 1;
        t = &D_00462090[p->f22];
        d = t->x;
        if (p->f20 != 0) d = -d;
        p->f34 = q->f34 + d;
        p->f38 = q->f38 + t->y;
        p->f48 = t->z;
        p->f22 = 0;
        func_0034D080(p);
    }
}

void func_0018E6C0(u8 *p) {
    extern void func_001757E0(u8 *, s32, u8);
    u8 a2;
    u8 fl;
    u32 t;
    if (p[0x20D] == 1) {
        fl = 1;
        a2 = 6;
    } else {
        u8 v = p[0x245];
        a2 = 3;
        fl = 0;
        if ((v & 0x80) == 0) {
            if ((v & 0x70) == 0) {
                if ((*(s8 *)(p + 0x1B3) & 4) == 1) a2 = 0;
            } else {
                a2 = 0;
            }
        }
    }
    p[0x20D] = fl;
    t = (u8)(*(s8 *)(p + 0x245) & 0x70);
    if (t != 0) {
        u8 u = t;
        if (u == 0x30) a2 += 2;
        else if (u == 0x20) a2 += 1;
    } else {
        u8 v = p[0x243];
        if (v >= 5) a2 += 1;
        if (v >= 12) a2 += 1;
    }
    func_001757E0(p, 13, a2);
}

void func_00251730(u8 *p) {
    extern void func_00175700();
    extern void func_001AD170();
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        f32 f;
        t = p[7];
        p[7] = t + 1;
        *(s16 *)(p + 0x1C) = 30;
        *(s16 *)(p + 0x1E) = 9;
        p[0x1B5] = 0x3E;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        p[0x22] = 1;
        if (p[0x1E6] != 0) f = 11.6666660309f; else f = -11.6666660309f;
        *(f32 *)(p + 0x5C) = f;
        func_001AD170(p, 5, 1);
    }
}

void func_001EC120(u8 *p, u8 *q) {
    extern void func_00175700();
    extern s32 func_0018AB10();
    extern void func_001757E0();
    s16 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(q + 3) >= 0 && func_0018AB10(p) != 0) {
        s32 t = *(s8 *)(q + 3);
        *(s8 *)(q + 3) = t - 1;
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        if (p[0x20D] != 2) func_001757E0(p, 0x16, 5);
        else func_001757E0(p, 0x16, 7);
    }
}

extern u8 D_004C0E18[4];
extern u8 D_004C0E1C[4];
extern u8 D_004C0E20[4];

void func_002C5EA0(u8 *p) {
    extern void func_001E3710();
    extern void func_001757E0();
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        func_001E3710(p, 0x14);
        *(u8 **)(p + 0x408) = D_004C0E18;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        func_001E3710(p, 0x15);
        *(u8 **)(p + 0x408) = D_004C0E1C;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        *(u8 **)(p + 0x408) = D_004C0E20;
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
}



typedef struct {
    u8 p0[6]; u8 f6; u8 p1[0x2D]; f32 f34; f32 f38; u8 p2[0x20]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c;

} S26;

void func_002688A0(u8 *p) {
    extern s8 func_00175700();
    extern void func_00183d50();
    extern void func_001843A0();
    f32 *a0, *a1, *a2, *a3;
    a3 = (f32 *)(p + 0x6C);
    a2 = (f32 *)(p + 0x68);
    a1 = (f32 *)(p + 0x60);
    a0 = (f32 *)(p + 0x5C);
    ((S26 *)p)->f34 += ((S26 *)p)->f5c;
    ((S26 *)p)->f5c += ((S26 *)p)->f68;
    ((S26 *)p)->f38 += ((S26 *)p)->f60;
    ((S26 *)p)->f60 += ((S26 *)p)->f6c;
    if (func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00183d50(p);
        *(s32 *)a0 = 0;
        *(s32 *)a1 = 0;
        *(s32 *)a2 = 0;
        *(s32 *)a3 = 0;
        func_001843A0(p);
    }
}

void func_00307D40(u8 *p) {
    extern s8 func_00175700();
    extern void func_001830D0();
    extern void func_001DACE0();
    extern void func_001757E0();
    u32 v[3];
    f32 f;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if (func_00175700(p) < 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        t = p[6];
        p[6] = t + 1;
        if (p[0x1E6] != 0) f = 11.6666660309f; else f = -11.6666660309f;
        *(f32 *)(p + 0x5C) = f;
        *(s16 *)(p + 0x1C) = 30;
        *(s16 *)(p + 0x1E) = 9;
        v[0] = 0xC2A00000;
        v[1] = 0x437CDB6D;
        func_001830D0(p, v, 1);
        func_001DACE0(p);
        func_001757E0(p, 0x16, 6);
    }
}

void func_003BFB60(u8 *p, u8 *a1) {
    extern void func_003BFC90();
    extern s32 func_00182C90();
    extern void func_001845F0();
    extern void func_001843A0();
    extern void func_001DCDE0();
    extern void func_003BFC80();
    u8 *q = *(u8 **)(p + 0xD4);
    s16 v;
    func_003BFC90(p);
    if (*(s8 *)(q + 0x1B3) == 0 || q[5] != 3) {
        if (p == *(u8 **)(q + 0x1E0)) {
            if (func_00182C90(q) != 0) *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 3;
            v = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = v;
            if (v >= 0) return;
            q[0x20A] = 0;
            q[0x203] = 8;
            if (*(s16 *)(q + 0x434) > 0) {
                if (q[0x20D] != 2) func_001843A0(q);
                else func_001845F0(q);
            }
        }
    }
    func_001DCDE0(p, 2);
    func_003BFC80(p, a1);
}

void func_001F26D0(u8 *p) {
    extern s8 func_00175700();
    extern void func_001757E0();
    extern void func_001266A0();
    u8 *q;
    u32 t;
    p[0x206] = 3;
    if (func_00175700(p) < 0) {
        t = p[7];
        p[7] = t + 1;
        *(u32 *)(p + 0x5C) = 0x40BAAAAA;
        *(u32 *)(p + 0x68) = 0xBDD55555;
        *(u32 *)(p + 0x60) = 0x414DB6DB;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        func_001757E0(p, 0xF, 0x21);
        func_001266A0(p, 0, 0);
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 2;
        if (p[0x269] == 3) {
            q[0x1B5] = 0x42;
            p[0x1B5] = 0x42;
        } else {
            q[0x1B5] = *(s8 *)(p + 0x1B7) + 0x41;
            p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x41;
        }
    }
}

void func_002CE4D0(u8 *p) {
    extern void func_00183d50();
    extern void func_001757E0();
    extern void func_00175700();
    extern void func_002CE330();
    s16 v;
    u32 t;
    ((S26 *)p)->f34 += ((S26 *)p)->f5c;
    ((S26 *)p)->f5c += ((S26 *)p)->f68;
    ((S26 *)p)->f38 += ((S26 *)p)->f60;
    ((S26 *)p)->f60 += ((S26 *)p)->f6c;
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        p[6] = 3;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00183d50(p);
        func_001757E0(p, 1, 3);
        return;
    }
    if (*(s8 *)(p + 0x151) < 0) {
        p[0x151] = 0;
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < 0) {
            t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0x15, 0xA);
            return;
        }
    }
    func_00175700(p);
    func_002CE330(p);
}


void func_003CE2D0(u8 *p, u8 *a1) {
    extern void func_001E7F60();
    extern void func_0018FAA0();
    extern void func_0015F4B0(u8 *, s8);
    extern void func_001E3710();
    extern void func_003CE3D0();
    u8 *q;
    u32 v;
    if (p[0x23] == 0) return;
    if (*(s8 *)(p + 0x1B2) != 0) {
        q = *(u8 **)(p + 0x1C4);
        if (q[0x425] == 0) {
            p[4] = 2;
            v = q[0x14C];
            *(f32 *)(p + 0x60) = (f32)v;
            *(u32 *)(p + 0x6C) = 0x412B6DB6;
            if (*(s16 *)(q + 0x438) > *(s16 *)(q + 0x434)) {
                *(u32 *)(p + 0x6C) = 0x41700000;
                func_0018FAA0(q, 1);
                func_0015F4B0(q, 4);
            }
            func_001E3710(p, 0x2A);
            func_003CE3D0(p, a1);
            return;
        }
        p[0x1B2] = 0;
    }
    func_001E7F60(p);
}

void func_001C6BF0(u8 *p, u8 *q) {
    extern void func_00175700();
    s16 d;
    f32 f;
    u32 t;
    func_00175700(p, q);
    ((S26 *)p)->f34 += ((S26 *)p)->f5c;
    ((S26 *)p)->f5c += ((S26 *)p)->f68;
    ((S26 *)p)->f38 += ((S26 *)p)->f60;
    ((S26 *)p)->f60 += ((S26 *)p)->f6c;
    if (q[0x1E4] != 0x16) {
        p[7] = 4;
    } else {
        d = *(s16 *)(p + 0x140);
        if (d == 0) f = 80.0f + *(f32 *)(q + 0x34);
        else f = *(f32 *)(q + 0x34) - 80.0f;
        if ((d == 0 && *(f32 *)(p + 0x34) <= f) || (d != 0 && !(*(f32 *)(p + 0x34) < f))) {
            t = p[7];
            p[7] = t + 1;
            *(s16 *)(q + 0x1C) = 0;
        }
    }
}

void func_002CF830(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    f32 *a0, *a1;
    f32 z = 0.0f;
    s32 v;
    u32 t;
    a1 = (f32 *)(p + 0x68);
    a0 = (f32 *)(p + 0x5C);
    ((S26 *)p)->f34 += ((S26 *)p)->f5c;
    ((S26 *)p)->f5c += ((S26 *)p)->f68;
    ((S26 *)p)->f38 += ((S26 *)p)->f60;
    ((S26 *)p)->f60 += ((S26 *)p)->f6c;
    func_00175700(p);
    v = *(s8 *)(p + 0x150);
    if (v != 0) {
        p[0x1B5] = v;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        p[0x150] = 0;
    }
    if (*(f32 *)(p + 0x60) < z) {
        t = p[6];
        p[6] = t + 1;
        *a0 = z;
        *a1 = z;
        *(u32 *)(p + 0x6C) = 0xBFCDB6DB;
        func_001757E0(p, 0x15, 0x1B);
    }
}



void func_002BEDC0(u8 *p) {
    extern void func_00175700();
    extern void func_001266A0();
    f32 *a, *c, *b, *d;
    f32 z = 0.0f;
    u32 t;
    if (*(s8 *)(p + 0x151) != 0) func_00175700(p);
    a = (f32 *)(p + 0x5C);
    b = (f32 *)(p + 0x68);
    c = (f32 *)(p + 0x60);
    d = (f32 *)(p + 0x6C);
    ((S26 *)p)->f34 += ((S26 *)p)->f5c;
    ((S26 *)p)->f5c += ((S26 *)p)->f68;
    ((S26 *)p)->f38 += ((S26 *)p)->f60;
    ((S26 *)p)->f60 += ((S26 *)p)->f6c;
    if (*(f32 *)(p + 0x60) <= z && *(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *a = z;
        *c = z;
        *b = z;
        *d = z;
        func_001266A0(p, 0, 0);
    }
}
