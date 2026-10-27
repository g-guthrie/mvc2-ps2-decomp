typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003205C0(u8 *p) {
    extern void func_00175700();
    extern void func_001830D0();
    extern void func_00131AB0();
    u32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) & 1) {
        p[0x404] = 0;
        p[0x405] = 0;
        p[0x151] = *(s8 *)(p + 0x151) ^ 1;
        v[0] = 0x41200000;
        v[1] = 0x4311B6DB;
        func_001830D0(p, v, 1);
    }
    if (*(s8 *)(p + 0x151) & 2) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = *(s8 *)(p + 0x151) ^ 1;
        p[0x214] = 1;
        *(s16 *)(p + 0x3FE) = 0x1E0;
        func_00131AB0(p, (u8 *)((s32)p + 0x3FE), 2);
    }
}

void func_002E3920(u8 *p, u8 *q) {
    extern void func_00175C00();
    extern void func_001266A0();
    extern void func_001D3E00();
    extern void func_001757E0(u8 *, s32, u8);
    extern void func_0015D010();
    extern void func_0018C6E0(void *);
    u32 v[4];
    s32 r;
    s16 h;
    u32 t;
    func_00175C00(p, 0);
    p[0x1B4] = 10;
    func_001266A0(p, 5, 5);
    if (*(u16 *)(p + 0x2B8) & 0x400) {
        *(s16 *)(p + 0x140) = *(s16 *)(p + 0x140) ^ 1;
        t = p[0x1E6];
        p[0x1E6] = t ^ 1;
    }
    t = p[0x1E6];
    h = t ^ 1;
    *(s16 *)(q + 0x140) = h;
    q[0x1E6] = h;
    if (p[0x20B] == 0) {
        r = 0;
        func_001D3E00(p);
    } else {
        r = 2;
        *(s16 *)(p + 0x1C) = 0x20;
        p[6] = 0;
    }
    func_001757E0(p, 0xF, r);
    v[0] = 0xC2F00000;
    v[1] = 0x43870000;
    func_0015D010(p, v);
    func_0018C6E0(p);
}

void func_00313DA0(u8 *p) {
    extern void func_00175700();
    extern void func_001830D0();
    extern void *func_003C3A60(u8 *, u8, u8);
    extern void func_001266A0();
    extern void func_001843A0();
    u32 v[4];
    s32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    t = *(s8 *)(p + 0x151);
    if (t & 2) p[0x151] = t & ~2;
    t = *(s8 *)(p + 0x151);
    if (t & 1) {
        p[0x151] = t & ~1;
        v[0] = 0x413AAAAA;
        v[1] = 0x43250000;
        p[0x404] = 0;
        p[0x405] = 0;
        func_001830D0(p, v, 1);
        if (func_003C3A60(p, 0, 0) == 0) {
            func_001266A0(p, 0, 0);
            func_001843A0(p);
        } else {
            func_001266A0(p, 1, 1);
            *(s16 *)(p + 0x1C) = 4;
            {
                u32 u = p[6];
                p[6] = u + 1;
            }
        }
    }
}

void func_001FFD70(u8 *p) {
    extern void func_00175700();
    extern void func_00348C90();
    extern void func_001E3710();
    extern void func_001757E0();
    extern s32 func_0018AAC0();
    extern s32 func_0018AB10();
    u8 *q;
    s16 v;
    p[0x40C] = 2;
    q = p + 0x2B8;
    p[0x33C] = 5;
    p[0x2CA] = 6;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 1) {
        p[0x151] = 0;
        func_00348C90(p);
        func_001E3710(p, 0x48);
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x16, 0x1C);
        return;
    }
    q[0x13] = 0;
    if (*(s8 *)(p + 0x539) == 0) {
        if (func_0018AAC0(p) != 0) *(s8 *)(q + 0x13) = -1;
        if (func_0018AB10(p) != 0) {
            s32 w = *(s8 *)(q + 0x14);
            if (w != 0) {
                *(s8 *)(q + 0x14) = w - 1;
                *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
            }
        }
    }
}

void func_002F9620(u8 *p, u8 *q) {
    extern void func_00185490();
    extern void func_001757E0();
    extern void func_002F8DE0();
    extern s8 func_00175700();
    extern void func_002F8EB0();
    extern void func_00183210();
    extern void func_00175C00();
    extern void func_00190660();
    extern void func_00131AB0();
    extern void func_002F8E40();
    u32 v[4];
    if (p[7] == 0) {
        u32 t = p[7];
        p[7] = t + 1;
        func_00185490(p);
        func_001757E0(p, 0x15, 5);
        func_002F8DE0(p);
        return;
    }
    if (func_00175700(p) < 0) {
        func_002F8EB0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        v[0] = 0xC0D55555;
        v[1] = 0x434B9249;
        func_00183210(p, v, 1);
        func_00175C00(p, 0);
        q[0xD] = 1;
        *(s16 *)(q + 0xE) = 0x258;
        q[0x14] = 0;
        q[0x15] = 0;
        func_00190660(p, *(s16 *)(q + 0xE), 0x28);
        func_00131AB0(p, q + 0xE, 0);
        p[0x214] = 0;
        *(s16 *)(p + 0x3FE) = 0;
    }
    func_002F8E40(p);
}

extern u32 D_00457950[];
extern u8 D_00457200[];

void func_00292840(u8 *p) {
    extern s32 func_00294BC0();
    extern void func_00131AB0();
    extern s32 func_00174170();
    extern void func_00185490();
    extern void func_00175C00();
    extern void func_003892F0();
    extern void func_00294B20();
    extern void func_001757E0();
    u8 *q;
    u32 t;
    p[0x40C] = 2;
    q = p + 0x2B8;
    p[0x33C] = 5;
    if (func_00294BC0(p) == 0) {
        t = p[6];
        p[6] = t + 1;
        q[0xA] = 0;
        q[0x19] = 0;
        q[0x1C] = 0;
        p[0x215] = 1;
        *(s16 *)(q + 0x1E) = 0xB4;
        func_00131AB0(p, q + 0x1E, 6);
        *(u32 *)(q + 0x14) = D_00457950[func_00174170() & 3];
        q[0x1B] = 1;
        func_00185490(p);
        func_00175C00(p, 0);
        func_003892F0(p, 0);
        func_003892F0(p, 1);
        func_003892F0(p, 2);
        func_003892F0(p, 3);
        func_003892F0(p, 4);
        func_00294B20(p, D_00457200);
        func_001757E0(p, 0x16, 0x12);
    }
}
