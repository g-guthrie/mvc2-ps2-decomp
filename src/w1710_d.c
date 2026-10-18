typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x7C]; s16 h7c[1]; } G12;
typedef struct { u8 pad0[2]; u8 b2; u8 pad3[0x2E]; s8 b31; u8 pad32[0x2A]; f32 f5c; u8 pad60[8]; f32 f68; u8 pad6c[0xD4]; s16 h140; u8 pad142[0x26]; u8 b168; u8 b169; } S12;
extern G12 *D_004C2794;
void func_00349420(S12 *p, u8 *q) {
    extern void func_00175910();
    extern void func_0034A080();
    u8 *t = *(u8 **)((u8 *)p + 0x14);
    u16 *d;
    *(u32 *)((u8 *)p + 0x14C) = 0x20203030;
    *(u8 *)((u8 *)p + 0x1B0) = 0x42;
    *(u8 *)((u8 *)p + 0x1B1) = 0;
    *(u8 *)((u8 *)p + 0x1B5) = 0x47;
    ((u8 *)p)[0x1B2] = *(u16 *)((u8 *)p + 0x1C0) = 0;
    *(s32 *)((u8 *)p + 0x1D8) = 0;
    D_004C2794->h7c[p->b2]++;
    *(u32 *)&p->f5c = 0x43200000;
    *(u32 *)&p->f68 = 0x42D20000;
    d = (u16 *)((u8 *)p + 0x88);
    if (p->h140 == 0) {
        p->f5c = -p->f5c;
        p->f68 = -p->f68;
    }
    *d = *(u16 *)(q + 0x168);
    p->b169 = 0x16;
    p->b168 = 0x24;
    func_00175910(p, p->b169, p->b168, *(s8 *)(t + 0x151));
    p->b31 = -6;
    func_0034A080(p, q);
}

static void func_00213FD0(u8 *p) {
    *(u32 *)(p + 0x5C) = 0x41555555;
    *(u32 *)(p + 0x68) = 0xBED55555;
    if (p[0x1E6] == 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    *(s16 *)(p + 0x364) = 0;
    *(s16 *)(p + 0x366) = 0;
    *(s16 *)(p + 0x1C) = 0;
}

void func_00214340(u8 *p) {
    extern s8 func_00175700();
    extern s32 func_0018AB10();
    extern void func_001757E0();
    if (func_00175700(p) >= 0) {
        if (*(s8 *)(p + 0x151) != 0) {
            if (func_0018AB10(p) != 0 || ((*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x360) != 0)
                *(s16 *)(p + 0x1C) = 1;
        }
    } else if (*(s16 *)(p + 0x1C) == 0) {
        p[6] = 5;
        func_001757E0(p, 0x14, 0x10);
    } else {
        p[6]++;
        func_00213FD0(p);
        p[0x1B5] = 0x3E;
        ((u8 *)p)[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->h7c[p[2]]++;
        func_001757E0(p, 0x14, 0xC);
    }
}
