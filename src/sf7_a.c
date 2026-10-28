typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x430]; f32 f430; } O;
typedef struct { u8 pad0[0x18]; O *o; s16 h1c; u8 pad2[2]; u8 b20; u8 pad3[0x17]; f32 f38; } P;
extern f32 D_0044E950[];

void func_001DBAE0(P *p)
{
    extern void func_001DBC80(P *);
    extern void func_001DBCD0(P *);
    f32 z = 0.0f;
    f32 d;
    s32 s;
    d = 17.14285659790039f + (p->o->f430 + D_0044E950[p->b20]) - p->f38;
    if (d < z) d = -d;
    s = (s32)(d / 2.142857074737549f);
    if (p->h1c > s / 8) { func_001DBC80(p); return; }
    p->h1c = s / 8;
    func_001DBCD0(p);
}

void func_001DBBB0(P *p)
{
    extern void func_001DBC80(P *);
    extern void func_001DBCD0(P *);
    f32 z = 0.0f;
    f32 d;
    s32 s;
    d = 17.14285659790039f + (p->o->f430 + D_0044E950[p->b20]) - p->f38;
    if (d < z) d = -d;
    s = (s32)(d / 2.142857074737549f);
    if (p->h1c > s / 16) { func_001DBC80(p); return; }
    p->h1c = s / 16;
    func_001DBCD0(p);
}

extern s16 D_0044ED20[];
extern s16 D_0044ED22[];

void func_001DE790(u8 *p, u8 *q) {
    extern void func_00175700(u8 *);
    s16 v;
    if (*(u16 *)(q + 0x168) != *(u16 *)(p + 0xD0)) {
        u32 t = p[4];
        p[4] = t + 1;
        return;
    }
    ((s8 *)p)[0x24] = ((s8 *)q)[0x24];
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    v = (s32)(1.6666666269302368f * (f32)D_0044ED20[p[0x21] * 2]);
    if (*(s16 *)(q + 0x140) != 0) v = -v;
    *(f32 *)(p + 0x34) += (f32)v;
    *(f32 *)(p + 0x38) += 2.142857074737549f * (f32)D_0044ED22[p[0x21] * 2];
    func_00175700(p);
}
