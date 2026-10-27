typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 p0[6]; u8 b6; u8 p7[0x1C-7]; s16 h1c; u8 p1e[0x34-0x1E]; f32 f34; f32 f38; u8 p3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; } PH;
void func_002660D0(PH *p) {
    extern void func_00175700(PH *);
    extern void func_001757E0(PH *, s32, s32);
    s16 v;
    *(u8 *)((u8 *)p + 0x40C) = 2;
    *(u8 *)((u8 *)p + 0x33C) = 5;
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    v = p->h1c - 1;
    p->h1c = v;
    if (v <= 0) {
        u32 t = p->b6;
        p->b6 = t + 1;
        p->h1c = 10;
        func_001757E0(p, 0x16, 8);
    }
}
typedef struct { u8 p0[6]; u8 b6; u8 b7; u8 p8[0x140-8]; s16 h140; u8 p142[0x1B4-0x142]; u8 b1b4; u8 p1b5[0x1DC-0x1B5]; s32 w1dc; u8 p1e0[0x1E6-0x1E0]; u8 b1e6; u8 p1e7[0x20E-0x1E7]; u16 h20e; } PB;
void func_002E82F0(PB *p) {
    extern void func_001266A0(PB *, s32, s32);
    extern void func_0018C6E0(void *);
    extern void func_0015D010(PB *, f32 *);
    extern u8 *func_001D45D0(u8 *, u8);
    extern void func_00182C30(s32, s32);
    extern void func_00182DB0(PB *, s32);
    extern void func_001757E0(PB *, s32, s32);
    f32 v[3];
    func_001266A0(p, 5, 5);
    if (p->h20e & 0x400) {
        p->h140 ^= 1;
        p->b1e6 ^= 1;
    }
    func_0018C6E0(p);
    *(u32 *)&v[0] = 0xC3055555;
    *(u32 *)&v[1] = 0x42CDB6DB;
    func_0015D010(p, v);
    p->b1b4 = 10;
    func_001D45D0((u8 *)p, 2);
    func_00182C30(p->w1dc, 0x32);
    func_00182DB0(p, 3);
    p->b6 = 0;
    p->b7 = 0;
    func_001757E0(p, 15, 2);
}
typedef struct { u8 p0[0x38]; f32 f38; u8 p3c[0x430-0x3C]; f32 f430; } PDo;
typedef struct { u8 p0[6]; u8 b6; u8 p7[0x1C-7]; s16 h1c; u8 p1e[0x34-0x1E]; f32 f34; f32 f38; u8 p3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0x1DC-0x70]; PDo *o; u8 p1e0[0x430-0x1E0]; f32 f430; } PD;
void func_002D5990(PD *p) {
    extern void func_00175700(PD *);
    extern void func_001266A0(PD *, s32, s32);
    extern void func_00182C30(PDo *, s32);
    extern void func_00182DB0(PD *, s32);
    extern void func_001757E0(PD *, s32, s32);
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f430 > p->f38) {
        u32 t = p->b6;
        p->b6 = t + 1;
        p->o->f38 = p->o->f430;
        p->h1c = 60;
        func_001266A0(p, 13, 6);
        func_00182C30(p->o, 30);
        func_00182DB0(p, 3);
        func_001757E0(p, 15, 2);
    }
}
typedef struct { u8 p0[6]; u8 b6; u8 p7[0x1C-7]; s16 h1c; u8 p1e[0x1FC-0x1E]; u8 b1fc; } PG;
void func_002F3280(PG *p) {
    extern s8 func_00175700(PG *);
    extern void func_001843A0(PG *);
    extern void func_001757E0(PG *, s32, s32);
    switch (p->b1fc) {
    case 0:
    case 1:
        if (func_00175700(p) < 0) func_001843A0(p);
        break;
    case 2:
        if (p->b6 == 0) {
            func_00175700(p);
            if (p->h1c == 0) {
                u32 t = p->b6;
                p->b6 = t + 1;
                func_001757E0(p, 20, 1);
            } else {
                s16 v = p->h1c - 1;
                p->h1c = v;
            }
        } else {
            if (func_00175700(p) < 0) func_001843A0(p);
        }
        break;
    default:
        break;
    }
}
typedef struct { u8 b0; u8 p1[3]; u8 b4; u8 b5; u8 p6[0x34-6]; f32 f34; u8 p38[0x5C-0x38]; f32 f5c; u8 p60[8]; f32 f68; u8 p6c[0xD0-0x6C]; s32 wd0; u8 pd4[0x13C-0xD4]; u8 b13c; u8 p13d[3]; s16 h140; } PJ;
void func_00364C90(PJ *p, PJ *q) {
    extern void func_00175700(PJ *);
    extern int func_00174470(const void *);
    extern void func_001E3710(PJ *, s32);
    extern void func_001757E0(PJ *, s32, s32);
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    if (func_00174470(p) == 0) {
        u32 t = p->b4;
        p->b4 = t + 1;
        p->b13c = 0;
        p->b0 = 0;
    } else if (p->wd0 != 0) {
        s16 h = p->h140;
        if ((h == 0 && p->f34 <= q->f34) || (h != 0 && !(p->f34 < q->f34))) {
            u32 t = p->b5;
            p->b5 = t + 1;
            func_001E3710(p, 0x2A);
            func_001757E0(p, 0x17, 0xD);
        }
    }
}
typedef struct { f32 x, y, z; } V3R;
void func_001A6F90(u8 *p, u8 *q) {
    extern s32 func_00174170(void);
    extern void func_001757E0(u8 *, s32, s32);
    s32 t, a, idx;
    if (q[5] != 0 || q[0x169] != 0x14 || (q[0x168] != 2 && q[0x168] != 1)) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x31) = -8;
    *(V3R *)(p + 0x34) = *(V3R *)(q + 0x34);
    t = *(s8 *)(q + 0x151);
    if (t & 1) {
        q[0x151] = t ^ 1;
        p[0x13C] = 1;
        a = q[0x1E6] + ((func_00174170() & 1) << 1);
        if (p[0x20] == 2) a += 0x15; else a += 0x19;
        func_001757E0(p, 0x17, (u8)a);
    }
    if (*(s8 *)(q + 0x151) & 2) {
        p[4] = 2;
        p[0x13C] = 0;
    }
}
typedef struct { u8 p0[6]; u8 b6; u8 b7; u8 p8[0x1C-8]; s16 h1c; u8 p1e[0x151-0x1E]; s8 b151; u8 p152[0x20B-0x152]; u8 b20b; } PR;
typedef struct { u8 p0[0x20D]; u8 b20d; } PRo;
void func_002F98F0(PR *p) {
    extern void func_00175700(PR *);
    extern void func_001757E0(PR *, s32, s32);
    extern u8 *func_001E7FD0(u8 *);
    extern u8 *func_001E8070(u8 *);
    extern void func_00185640(u8 *, u8 *);
    extern void func_002F8E40(PR *);
    PRo *o;
    s16 h = p->h1c;
    p->h1c = h - 1;
    if (h == 0) {
        u32 t = p->b6;
        p->b6 = t + 1;
        func_001757E0(p, 0x15, 9);
        return;
    }
    func_00175700(p);
    if (p->b151 != 0) {
        o = (PRo *)func_001E7FD0((u8 *)p);
        if (o != 0 && o->b20d == 2) {
            p->b20b = 3;
            p->b20b |= 0x40;
            p->b20b |= 0x80;
            func_00185640((u8 *)p, (u8 *)o);
            p->b7 = 0;
            p->b6 = 0;
            return;
        }
        o = (PRo *)func_001E8070((u8 *)p);
        if (o != 0 && o->b20d == 2) {
            p->b20b = 3;
            p->b20b |= 0x40;
            p->b20b |= 0x80;
            func_00185640((u8 *)p, (u8 *)o);
            p->b7 = 0;
            p->b6 = 0;
            return;
        }
    }
    func_002F8E40(p);
}
