typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700();

void func_0036B7F0(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 280) = *(f32 *)(p + 280) - 0.04f;
    if (*(s8 *)(p + 339) < 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[316] = 0;
    }
}

void func_00292090(u8 *p, u8 *q) {
    s16 t = *(s16 *)(p + 0x1c) - 1;
    *(s16 *)(p + 0x1c) = t;
    if (t == 0) {
        u32 n = q[0x18];
        q[0x18] = n + 1;
        *(s16 *)(p + 0x1c) = 10;
        if (p[0x1e6] == 0) {
            *(f32 *)(p + 0x68) = 0.41666666f;
        } else {
            *(f32 *)(p + 0x68) = 0.41666666f;
        }
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5c);
    *(f32 *)(p + 0x5c) += *(f32 *)(p + 0x68);
}

typedef struct { f32 x, y, z; } V3;
extern int func_001754A0(u8 *p, s32 a, int b);

void func_001990A0(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    if (*(s8 *)(q + 352) == 0) {
        p[4] = 2;
    } else {
        u8 v;
        p[316] = 0;
        *(V3 *)(p + 52) = *(V3 *)(q + 52);
        v = *(s8 *)(q + 337) >> 6;
        if (v != 0) {
            p[316] = 1;
            { u32 w = v; w = (u8)w & 3; func_001754A0(p, 27, (u8)(w + 11)); }
        }
    }
}



typedef struct { f32 x, y, z, w; } V2;
extern void func_001843A0(u8 *p);
extern void func_00183920(u8 *p, V2 *v);
extern void func_001E3710(u8 *p, s32 a);

void func_00201EA0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    } else {
        if (*(s8 *)(p + 337) != 0) {
            V2 v;
            p[337] = 0;
            v.x = -53.333332f;
            v.y = 137.14285f;
            func_00183920(p, &v);
        }
        if (p[347] != 0) {
            func_001E3710(p, 22);
        }
    }
}

extern f32 D_004F1FCC[4];
extern void func_00175670(u8 *p);

void func_001BF290(u8 *p, u8 *q) {
    if (q[484] != 22) {
        u32 t = p[4];
        p[4] = t + 1;
        p[316] = 0;
    } else {
        p[316] = 1;
        *(s16 *)(p + 320) = 0;
        *(f32 *)(p + 80) = 3.5f;
        *(f32 *)(p + 84) = 0.8f;
        *(f32 *)(p + 280) = 0.75f;
        *(f32 *)(p + 52) = 53.333332f + D_004F1FCC[0];
        *(f32 *)(p + 56) = *(f32 *)(q + 1072);
        func_00175670(p);
    }
}

extern void func_001757E0(u8 *p, s32 a, s32 b);

void func_0034AC00(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        u32 t;
        *(s16 *)(p + 28) = 30;
        t = p[5];
        t++;
        p[5] = t;
        *(f32 *)(p + 92) = 3.3333333f;
        *(f32 *)(p + 108) = 0.0f;
        *(f32 *)(p + 96) = -4.2857141f;
        *(f32 *)(p + 108) = -1.0714285f;
        if (*(s16 *)(p + 320) != 0) {
            *(f32 *)(p + 92) = -*(f32 *)(p + 92);
        }
        func_001757E0(p, 22, 19);
    }
}
