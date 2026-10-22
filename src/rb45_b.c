typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H_a;
extern H_a *D_004C2794;

typedef struct { u8 pad[0x160]; s8 b[8]; } O_a;

void func_0034BDF0(u8 *p)
{
    extern void func_00175910(u8 *, s32, s32, s8);
    extern void func_001E7F60(u8 *);
    u8 *o;
    s32 t;
    s8 *bp;
    u8 k;
    s32 n;

    o = *(u8 **)(p + 0x18);
    n = *(s8 *)(p + 0x1B4);
    if (n != 0) {
        p[0x1B4] = n - 1;
        o[0x1B4] = n;
    }
    p[0x13C] = 0;
    if (o[0x20D] != 2 || o[0x210] != 0 || *(f32 *)(o + 0x38) == *(f32 *)(o + 0x430)) return;
    bp = ((O_a *)o)->b;
    t = bp[0];
    if (t == 0) return;
    if (bp[1] == 0x24) return;
    if (o[5] == 1) return;
    if (o[0x213] == 2) return;
    switch (o[0x1FC]) {
    case 0: k = 0xF; break;
    case 1: k = 0x10; break;
    case 2: k = 0x11; break;
    default: return;
    }
    p[0x13C] = 1;
    *(s16 *)(p + 0x140) = *(s16 *)(o + 0x140);
    *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34);
    if (o[0x15F] != p[0x21]) {
        p[0x21] = o[0x15F];
        p[0x1B5] = k;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]] += 1;
    }
    func_00175910(p, 0x14, 6, (s8)t);
    if (o[0x15F] != 0) func_001E7F60(p);
}
