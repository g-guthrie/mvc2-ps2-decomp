typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad2[0x2]; u8 b2; u8 pad6[0x3]; u8 b6; u8 pad34[0x2D]; f32 f34; f32 f38; u8 pad5C[0x20]; f32 f5c; f32 f60; u8 pad68[0x4]; f32 f68; f32 f6c; u8 pad1B2[0x142]; u8 b1b2; u8 pad1B5[0x2]; u8 b1b5; u8 pad1C0[0xA]; u16 h1c0; u8 pad1D8[0x16]; s32 w1d8; u8 pad20D[0x31]; u8 b20d; u8 pad269[0x5B]; u8 b269; u8 pad430[0x1C6]; f32 f430; } S13_q;
typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G13;
extern G13 *D_004C2794;
void func_00213B60(S13_q *p) {
    extern int func_00175700(u8 *);
    extern void func_001757E0();
    u32 t;
    u8 a;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (!(p->f38 <= p->f430)) {
        func_00175700((u8 *)p);
    } else {
        t = p->b6;
        p->b6 = t + 1;
        p->f38 = p->f430;
        p->b20d = 0;
        a = 0x40;
        if (p->b269 == 3) a = 0x47;
        p->b1b5 = a;
        p->b1b2 = p->h1c0 = 0;
        p->w1d8 = 0;
        D_004C2794->f7c[p->b2]++;
        func_001757E0(p, 0x15, 0x2E);
    }
}

typedef struct { f32 x, y, z; } V3_x;
typedef struct { s16 a, b; } H2_x;
extern H2_x D_0043DED0[];
extern V3_x D_0043DEF0[];
extern s32 D_004C2834;
extern u8 D_004F24D5[];
extern u8 D_004F20B0[];
typedef struct { u8 pad[0x5B8]; } E5B8_x;
void func_00132120(u8 *p, s32 idx) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00132F70();
    u8 *o = func_003DA750(0, 0xE, 1);
    if (o != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00132F70;
        *(s16 *)(o + 0xCC) = D_0043DED0[idx].a;
        *(s32 *)(o + 0x84) = D_004C2834;
        *(V3_x *)(o + 0x34) = D_0043DEF0[idx & 1];
        *(s32 *)(o + 0xD0) = 0x10C21;
        o[0x20] = idx;
        o[0x21] = D_004F24D5[idx * 0x5B8];
        *(u8 **)(o + 0x18) = D_004F20B0 + idx * 0x5B8;
        *(u8 **)(o + 0x14) = p;
        *(u8 **)(o + 0xC8) = p + 0x88;
    }
}

void func_002EE9F0(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_002F1DF0();
    extern void func_001757E0();
    extern void func_002F1D90();
    s32 v, a;
    u32 t;
    if ((s8)func_00175700(p) < 0) {
        func_002F1DF0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x1B2] = 0;
        if (((*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x200) != 0 && 1 != 0) {
            *(s16 *)(p + 0x366) = 0;
            v = 0;
            a = 0;
            t = p[7] ^ 1;
            p[7] = t;
            if ((u8)t != 0) {
                v = 0x19;
                a = 3;
            }
            p[0x1B5] = v;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            func_001757E0(p, 7, (u8)a);
            func_002F1D90(p);
        }
    }
}

