typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002687B0(u8 *p, u8 *q)
{
    extern void func_001266A0();
    extern void func_00175700();
    extern s32 func_00268A60();
    extern void func_001E3210();
    extern void func_001843A0();
    func_001266A0(p, 1, 7);
    *(s16 *)(q + 0x1C) = *(s16 *)(q + 0x1C) - 0x800;
    *(s32 *)(p + 0x48) = *(s16 *)(q + 0x1C);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (func_00268A60(p) == 0) {
        if (!(51.42856979370117f + *(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
            p[0x20D] = 0;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            *(s16 *)(q + 0x1C) = 0;
            *(s32 *)(p + 0x48) = 0;
            func_001E3210(p, 3);
            func_001266A0(p, 0, 0);
            func_001843A0(p);
        }
    }
}

typedef struct { u8 pad0[0x18]; u8 *w18; u8 pad1[5]; u8 b21; u8 pad2[0x12]; f32 f34, f38; u8 pad3[0x20]; f32 f5c, f60; u8 pad4[4]; f32 f68, f6c; } P35A340;
void func_0035A340(P35A340 *p, u8 *q)
{
    extern void func_00175700();
    extern void func_0035ADE0();
    extern void func_0035A2C0();
    extern void func_0035A7B0();
    extern void func_0035AE70();
    u8 *o = p->w18;
    f32 t;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    func_0035ADE0(p, q);
    t = 34.28571319580078f + *(f32 *)(o + 0x430);
    if (t < p->f38) {
        func_0035A2C0(p, q);
        func_0035A7B0(p, q);
    } else {
        p->f38 = t;
        func_0035A7B0(p, q);
        p->b21 = 0;
        func_0035AE70(p, q);
        func_0035A2C0(p, q);
    }
}

extern u8 D_0045D480[], D_0045D484[];
void func_00312A70(u8 *p)
{
    extern int func_00175700(u8 *);
    extern int func_001757E0(u8 *, s32, s32);
    s16 v;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 2));
        *(s16 *)(p + 0x1C) = *(s8 *)(p + 0x151);
        *(f32 *)(p + 0x5C) = 1.6666666269302368f * (f32)*(s32 *)(D_0045D480 + (p[0x1B7] << 3)) / 65536.0f;
        *(f32 *)(p + 0x68) = 1.6666666269302368f * (f32)*(s32 *)(D_0045D484 + (p[0x1B7] << 3)) / 65536.0f;
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
}
