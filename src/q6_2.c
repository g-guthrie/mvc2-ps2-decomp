typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u8 *D_004C2794;
extern u32 D_00455458[];
extern s32 func_001757E0();
extern s32 func_00280E70(u8 *);
extern void func_0032D5F0(u8 *);
extern u8 *func_001E7FD0(u8 *);
extern void func_00185490(u8 *);
extern s32 func_00178B00(u8 *);
extern void func_00178D80(u8 *, s32);
extern void func_001266A0(u8 *, s32, s32);
extern void func_0015D010(u8 *, float *);
extern void func_0018C6E0(void *);
extern void func_001830D0();
extern void func_0036BFF0(u8 *, s32, s32, s32);
extern u32 D_004C2838;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_0015D6A0();
extern void func_00356980(u8 *);
extern void func_0018C8A0(u8 *);
extern s32 func_00153AA0();
extern void func_00170DA0(u32, s32, s32, s16);
typedef struct { float a, b; } E8;
extern E8 D_004B3CB0[];
typedef struct { float x, y, z; } V3;
extern s32 func_00175700();
extern u32 D_0044B770[];
extern u8 D_004531C0[];
extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
extern u8 D_004F1F40[];
extern void func_00183d50();
extern s32 func_0034A0D0();
extern void func_00137E60();
extern void func_00137DF0();
typedef struct { u8 *ptr; u8 pad[0x5B8 - 4]; } T5B8;
extern T5B8 D_004F20C8[];
extern u8 D_00583B92[];
extern s8 D_00583BC0[];
extern void func_003A6DC0();
extern s32 func_00174170();
extern void func_00169C90();
extern void func_0015DFC0();

void func_0015D420(float *src) {
    u8 *o;
    if ((o = func_003DA750(0, 8, 1)) != 0) {
        o[0x13C] = 1;
        *(u32 *)(o + 0x10) = (u32)func_0015D6A0;
        *(s16 *)(o + 0xCC) = 0xBA;
        *(u32 *)(o + 0x84) = D_004C2838;
        *(V3 *)(o + 0x34) = *(V3 *)src;
        *(float *)(o + 0x38) += 137.142853f;
        *(u32 *)(o + 0xD0) = 0x21;
        *(s16 *)(o + 0x1C) = 0;
        *(s16 *)(o + 0x1E) = 0;
        *(float *)(o + 0x74) = 1.0f;
    }
}

void func_00197B70(u8 *p, u8 *q) {
    if (*(s16 *)(p + 0x140) != 0) {
        *(float *)(p + 0x34) = 106.666664f + *(float *)(q + 0x34);
    } else {
        *(float *)(p + 0x34) = *(float *)(q + 0x34) - 106.666664f;
    }
    *(float *)(p + 0x38) = 411.428558f + *(float *)(q + 0x38);
    *(s32 *)(p + 0x14C) = 0x20202424;
    *(float *)(p + 0x60) = -12.8571424f;
    *(float *)(p + 0x6C) = 0.133928567f;
    func_001757E0(p, 0x13, 6);
}

void func_001F4610(u8 *p) {
    float v[4];
    u32 t;
    *(s16 *)(p + 0x3F8) = 2;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if ((s8)func_00175700(p) < 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        t = p[6] + 1;
        p[6] = t;
        v[0] = -40.0f;
        v[1] = 154.285706f;
        func_001830D0(p, v, 3, t);
        func_001757E0(p, 0xF, 0x37);
    }
}

void func_0023E260(u8 *p) {
    float v[4];
    s32 f;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    f = *(s8 *)(p + 0x151);
    if (f & 1) {
        p[0x151] = f & ~1;
        t = p[6] + 1;
        p[6] = t;
        v[0] = -13.3333330f;
        v[1] = 300.0f;
        v[2] = 0.0f;
        p[0x404] = 0;
        p[0x405] = 0;
        func_001830D0(p, v, 1, t);
    }
}

void func_00242190(u8 *p) {
    float v[4];
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        t = p[7] + 1;
        p[7] = t;
        p[0x151] = 0;
        v[0] = 26.666666f;
        v[1] = 205.714279f;
        func_001830D0(p, v, 1, t);
    }
}

void func_00242EF0(u8 *p) {
    float v[4];
    func_001266A0(p, 5, 5);
    if (*(u16 *)(p + 0x20E) & 0x800) {
        *(s16 *)(p + 0x140) ^= 1;
        p[0x1E6] ^= 1;
    }
    v[0] = -173.333328f;
    v[1] = 188.571426f;
    func_0015D010(p, v);
    func_0018C6E0(p);
    p[0x1B4] = 10;
    p[6] = 0;
    p[7] = 0;
    func_001757E0(p, 15, 1);
}

void func_002E7130(u8 *p) {
    float *d = (float *)D_004F1F40;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        p[7]++;
        func_001266A0(p, 5, 5);
        *(float *)(p + 0x5C) = 320.0f + d[0x88 / 4];
        *(float *)(p + 0x60) = d[0xA0 / 4] - 308.571411f;
    }
}

u8 *func_0030BC10(u8 *p) {
    u8 v = (*(u16 *)(p + 0x20E) & 0x1C00) >> 10;
    p[0x22] = v;
    if (v != 0) {
        if (p[0x1B7] == 1) {
            if (*(float *)(p + 0x38) > 137.142853f) {
                u8 *r = func_001E7FD0(p);
                if (r != 0) {
                    p[0x20B] = 2;
                    return r;
                }
            }
        }
    }
    return 0;
}
