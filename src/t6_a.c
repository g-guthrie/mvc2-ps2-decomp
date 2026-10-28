typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_0035F430();
extern int func_00175700(u8 *);
extern void func_001E7F60();
extern u16 D_004D18DC;
extern u8 D_004D18DB;
void func_0035F360(u8 *p, s32 b) {
    if ((D_004D18DC & (1 << D_004D18DB)) == 0) {
        func_0035F430(p, b);
        if ((s8)func_00175700((u8 *)p) < 0) {
            p[4] = 2;
            p[0x13C] = 0;
            return;
        }
    }
    func_001E7F60(p);
}


extern int func_00175670(u8 *);
void func_001993A0(u8 *p) {
    if (p[5] == 0) {
        func_00175670(p);
        if (*(s8 *)(p + 0x150) != 0) {
            if (*(u8 *)(*(u8 **)(p + 0x18) + 0x1E4) != 0x16) {
                u32 t = p[5];
                p[5] = t + 1;
            }
        }
    } else {
        if ((s8)func_00175670(p) < 0) {
            u32 t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
        }
    }
}


extern u8 *func_0035EF40();
extern void func_001757E0();
extern void func_00185870();
extern void func_001A5590();
void func_0035EE90(u8 *a, u8 *b) {
    u8 *s0;
    u8 *s1;
    a[0x21] = 1;
    s0 = b + 0x2B8;
    if ((s1 = func_0035EF40(a)) != 0) {
        s0[2] = 1;
        s1[0x20D] = 0;
        func_001757E0(s1, 0xD, 2);
        b[0x20B] = 0xC4;
        *(s8 *)(b + 0x16A) = -1;
        func_00185870(a, s1);
        s1[0x20A] = 0xC;
        func_001A5590(b, s1, 0);
        *(u8 **)(s0 + 8) = s1;
    }
}


extern void func_001843A0();
extern void func_00248330();
void func_002448B0(u8 *p, s32 b) {
    switch (p[0x1FC]) {
    case 0:
    case 1:
        if ((s8)func_00175700((u8 *)p) < 0) func_001843A0(p);
        break;
    case 2:
        func_00248330(p);
        if ((s8)func_00175700((u8 *)p) < 0) func_001843A0(p);
        break;
    }
}





typedef struct O_003900C0 {
    u8 p0[0x18]; struct O_003900C0 *w18; u8 pp[0x18]; f32 f34; f32 f38; u8 p3[0x20]; f32 f5c; f32 f60; u8 p4[4]; f32 f68; f32 f6c;
} O_003900C0;
extern void func_001E3210();
void func_003900C0(O_003900C0 *p) {
    if (*(s8 *)((u8 *)p + 0x151) == 0) func_00175700((u8 *)p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 < *(f32 *)((u8 *)p->w18 + 0x430)) {
        u32 t = *((u8 *)p + 6);
        *((u8 *)p + 6) = t + 1;
        p->f38 = *(f32 *)((u8 *)p->w18 + 0x430);
        func_001E3210(p->w18, 0x20);
    }
}


typedef struct O_00243500 {
    u8 p0[0x34]; f32 f34; f32 f38; u8 p3[0x20]; f32 f5c; f32 f60; u8 p4[4]; f32 f68; f32 f6c;
    u8 p5[0x3C0]; f32 f430;
} O_00243500;
void func_00243500(O_00243500 *p) {
    u32 *a, *b, *c, *d;
    func_00175700((u8 *)p);
    a = (u32 *)&p->f5c;
    c = (u32 *)&p->f68;
    b = (u32 *)&p->f60;
    d = (u32 *)&p->f6c;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 < p->f430) {
        p->f38 = p->f430;
        *((u8 *)p + 0x20D) = 0;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_001843A0(p);
    }
}


extern void func_00355BE0();
void func_00223CA0(u8 *p, s32 b) {
    switch (p[0x1FC]) {
    case 2:
        if ((s8)func_00175700((u8 *)p) < 0) {
            func_001843A0(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            *(s8 *)(p + 0x151) = 0;
            func_00355BE0(p, 1);
        }
        break;
    case 0:
    case 1:
        if ((s8)func_00175700((u8 *)p) < 0) func_001843A0(p);
        break;
    }
}


typedef struct O_00160B80 {
    u8 p0[0x38]; f32 f38; f32 f3c; s32 w40;
} O_00160B80;
extern f32 D_004F1F54, D_004F1FE8, D_004F1F50;
extern s32 func_00417690(f32 a, f32 b);
void func_00160B80(O_00160B80 *p) {
    p->f38 = ((D_004F1F54 - p->f3c) * (D_004F1FE8 - D_004F1F50)) / D_004F1F54;
    p->w40 = func_00417690(p->f38, D_004F1F54 - p->f3c);
    if (D_004F1F54 - p->f3c < 0.0f) p->w40 += 0x8000;
    p->f38 += D_004F1F50;
}


extern void func_001830D0();
extern void func_001266A0();
void func_003257F0(u8 *p) {
    u32 v[4];
    s16 h;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700((u8 *)p);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h <= 0) {
        u32 t;
        p[0x404] = 0;
        p[0x405] = 0;
        t = p[6];
        p[6] = t + 1;
        v[0] = 0;
        v[1] = 0x425EDB6D;
        func_001830D0(p, v, 1);
        func_001266A0(p, 7, 7);
    }
}


extern void func_001E3A40();
void func_00214F40(u8 *p) {
    if (*(s8 *)(p + 0x151) != 0) {
        u8 *q;
        u8 x;
        *(s8 *)(p + 0x151) = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 2;
        q[0x1B5] = 0x20;
        p[0x20D] = 3;
        *(s16 *)(p + 0x1FA) = 0;
        x = *(s8 *)(p + 0x140) ^ 1;
        q[0x1E6] = x;
        *(s16 *)(q + 0x140) = x;
        func_001E3A40(q);
    } else {
        if ((s8)func_00175700((u8 *)p) < 0) {
            u32 t = p[6];
            p[6] = t + 1;
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
            func_001757E0(p, 0x11, 0);
        }
    }
}


extern void func_002EBB00();
extern void func_003A6DC0();
void func_002EB9D0(u8 *a, u8 *b) {
    s16 h;
    s16 g;
    func_002EBB00(a);
    func_00175700((u8 *)a);
    if (*(s8 *)(b + 8) != 0) {
        h = *(s16 *)(a + 0x1C);
        *(s16 *)(a + 0x1C) = h - 1;
        if (h == 0) {
            *(s16 *)(a + 0x1C) = 3;
            func_003A6DC0(a, 2, 1);
            *(s8 *)(b + 8) = *(s8 *)(b + 8) - 1;
        }
    }
    g = *(s16 *)(a + 0x1E) - 1;
    *(s16 *)(a + 0x1E) = g;
    if (g == 0) {
        u32 t = a[7];
        a[7] = t + 1;
        func_001757E0(a, 0x15, (u8)(a[0x1B7] + 6));
    }
}


typedef struct { f32 x, y; } V2_0018ED90;
extern void func_00185550();
extern void func_0018F1A0();
void func_0018ED90(u8 *a, s32 b) {
    V2_0018ED90 v;
    f32 z = 0.0f;
    s16 h;
    func_00185550(a);
    func_0018F1A0(a[0x242], b, &v);
    h = *(s16 *)(a + 0x140);
    if (h != 0 && v.x < z) {
        v.x = -v.x;
    } else if (h == 0 && v.x > z) {
        v.x = -v.x;
    }
    *(f32 *)(a + 0x22C) = v.x;
    *(u32 *)(a + 0x68) = 0;
    *(f32 *)(a + 0x230) = v.y;
    *(u32 *)(a + 0x6C) = 0xBF4DB6DB;
}


typedef struct O_002AACB0 {
    u8 p0[6]; u8 b6; u8 pq[0x2D]; f32 f34; f32 f38; u8 p3[0x20]; f32 f5c; f32 f60; u8 p4[4]; f32 f68; f32 f6c;
    u8 p5[0x3C0]; f32 f430;
} O_002AACB0;
void func_002AACB0(O_002AACB0 *p) {
    u32 *a, *b, *c, *d;
    if (*(s8 *)((u8 *)p + 0x151) == 0) func_00175700((u8 *)p);
    a = (u32 *)&p->f5c;
    c = (u32 *)&p->f68;
    b = (u32 *)&p->f60;
    d = (u32 *)&p->f6c;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 <= p->f430) {
        u32 t = p->b6;
        p->b6 = t + 1;
        p->f38 = p->f430;
        *((u8 *)p + 0x20D) = 0;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
    }
}


extern void func_00176160();
extern void func_00175C00();
void func_002E45D0(u8 *a, u8 *b) {
    if (a[0x169] == 0xF && a[0x168] == 2) {
        if (*(s16 *)(a + 0x1C) != 0) {
            s8 c;
            func_00176160(a, 0, *(s8 *)(b + 0xE) + (a[0x25] * 0x30 + 0x14), 1);
            c = *(s8 *)(b + 0xD) - 1;
            *(s8 *)(b + 0xD) = c;
            if (c == 0) {
                *(s8 *)(b + 0xD) = 9;
                *(s8 *)(b + 0xF) = -*(s8 *)(b + 0xF);
            }
            *(s8 *)(b + 0xE) = *(s8 *)(b + 0xE) + *(s8 *)(b + 0xF);
        } else {
            func_00175C00(a, 0);
        }
    }
}

