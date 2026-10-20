/* ./try.sh src/grok_gh_003143C0.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct G { u8 pad[0x7C]; s16 t[2]; } G;
extern G *D_004C2794;
extern s32 func_00175700(u8 *);
extern void func_00314760(u8 *, u8 *);
extern void func_001757E0(u8 *, int, int);
extern s32 func_00185980(u8 *);
extern void func_00185770(u8 *, u8 *);

void func_003143C0(u8 *p, u8 *q)
{
    u8 *r;
    s16 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00314760(p, q);
    if ((*(s16 *)(p + 0x1C) & 0xF) == 0) {
        p[0x1B5] = 0x39;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->t[p[2]]++;
    }
    t = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = t - 1;
    if (t == 0) {
        p[7]++;
        func_001757E0(p, 0x16, 0xD);
        q[0x13] = 1;
        q[2] = 0;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
    } else if (func_00185980(p)) {
        p[6]++;
        p[7] = 0;
        p[0x20B] = 4;
        p[0x20B] |= 0x40;
        p[0x20B] |= 0x80;
        r = *(u8 **)(p + 0x1C4);
        func_00185770(p, r);
        r[6] = 0;
        *(s32 *)(r + 0x6C) = 0;
        *(s32 *)(r + 0x68) = 0;
        *(s32 *)(r + 0x60) = 0;
        *(s32 *)(r + 0x5C) = 0;
        q[0x15] = 0;
        *(s16 *)(p + 0x1C) = 0x50;
    }
}
