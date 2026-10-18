typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32; typedef signed int s32; typedef float f32;

void func_001EC940(u8 *p) {
    extern void func_00175700();
    extern void func_001ECF90();
    extern void func_001830D0();
    f32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    func_001ECF90(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = -25.0f;
        v[1] = 98.57143f;
        v[2] = 0.0f;
        func_001830D0(p, v, 3, t + 1);
    }
}

typedef struct { u8 p0[0x34]; f32 f34; u8 p38[0x108]; s16 h140; u8 p142[0x1E]; u16 h160; } S_9A20;
void func_00279A20(S_9A20 *p) {
    extern s32 func_00175700();
    extern void func_001E3210();
    extern void func_001843A0();
    s8 r = func_00175700(p);
    u16 a0;
    if (r < 0) {
        func_001E3210(p, 0x2B);
        func_001843A0(p);
        return;
    }
    a0 = p->h160;
    if (a0 != 0) {
        if (p->h140 == 0) {
            p->f34 += 1.6666666f * (s16)a0;
        } else {
            p->f34 -= 1.6666666f * (s16)a0;
        }
        p->h160 = 0;
    }
}

typedef struct { f32 x, y, z; } V_5230;
void func_001D5230(u8 *p, u8 *q) {
    extern s32 func_00175700();
    s8 r;
    f32 c;
    if (q[5] != 0 || q[0x1E4] != 0x1D) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    r = func_00175700(p);
    if (r < 0) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    *(V_5230 *)(p + 0x34) = *(V_5230 *)(q + 0x34);
    if (*(s8 *)(p + 0x151) != 0) {
        c = -13.333333f;
        if (*(s16 *)(p + 0x140) != 0) c = -c;
        *(f32 *)(p + 0x34) += c;
    }
}

void func_003155D0(u8 *p) {
    extern void func_0018C6E0();
    extern void func_001757E0();
    extern void func_0015D010();
    u8 *q = p + 0x2B8;
    f32 v[3];
    if (p[0x22] & 1) {
        p[0x1E6] ^= 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    p[0x1B4] = 10;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 0x12);
    q[0x14] = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x5C) = -15.0f;
    *(f32 *)(p + 0x68) = -0.20833333f;
    if (*(s16 *)(p + 0x140) != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    v[0] = -20.0f;
    v[1] = 184.2857056f;
    v[2] = 0.0f;
    func_0015D010(p, v);
}
