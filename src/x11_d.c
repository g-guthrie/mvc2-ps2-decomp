typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x7C]; s16 h7c[1]; } G12;
typedef struct { u8 pad0[2]; u8 b2; u8 pad3[3]; u8 b6; u8 pad7[0x2D]; f32 f34; u8 pad38[0x24]; f32 f5c; u8 pad60[8]; f32 f68; u8 pad6c[0xD4]; s16 h140; u8 pad142[0xF]; s8 b151; u8 pad152[9]; u8 b15b; } S12;
extern G12 *D_004C2794;
void func_002AED80(S12 *p) {
    extern void func_00175700();
    extern void func_00186A20();
    func_00175700(p);
    if (p->b15b != 0) {
        u8 t = p->b15b;
        *(u8 *)((u8 *)p + 0x1B5) = t;
        ((u8 *)p)[0x1B2] = *(u16 *)((u8 *)p + 0x1C0) = 0;
        *(s32 *)((u8 *)p + 0x1D8) = 0;
        D_004C2794->h7c[p->b2]++;
        p->b15b = 0;
    }
    p->f34 += p->f5c;
    p->f5c += p->f68;
    if (p->b151 == 0) {
        u32 u = p->b6;
        p->b6 = u + 1;
        *(u32 *)&p->f68 = 0x3ED55555;
        if (p->h140 != 0) p->f68 = -p->f68;
        func_00186A20(p);
    }
}

void func_0035CA40(u8 *p, u8 *q) {
    extern void func_001E7F60();
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    if (*(s16 *)(p + 0x1E) == 0) {
        func_001E7F60(p);
        if (*(s8 *)(p + 0x1B2) != 0) {
            *(s8 *)(q + 0x1B4) = *(s8 *)(p + 0x1B4);
            *(s16 *)(p + 0x1E) = 1;
        }
    }
    if (*(f32 *)(q + 0x38) <= 480.0f + *(f32 *)(q + 0x430)) {
        p[0x1B5] = 0x57;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->h7c[p[2]]++;
        {
            u32 t = p[5];
            p[5] = t + 1;
        }
        return;
    }
}

