typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct H { u8 pad[0x7C]; s16 h7C[1]; } H;
typedef struct Pair { f32 a; f32 b; } Pair;
typedef struct V3 { f32 x, y, z; } V3;

extern H *D_004C2794;
extern Pair D_004A6AA8[];
extern const u8 *const jtbl_004A6CA0[12];
extern int func_001757E0(u8 *, s32, s32);
extern s32 func_0041ABD0(u8 *, u8 *);
extern void func_0041A040(u8 *, s32);
extern void func_0041AA10(u8 *, u8 *);

void func_0041A860(u8 *p, u8 *q)
{
    p[5]++;
    *(s16 *)(p + 0x140) = 0;
    p[0x14C] = 16;
    p[0x14D] = 16;
    p[0x14E] = 16;
    p[0x14F] = 16;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    if (*(s16 *)(p + 0x140) == 0)
        *(f32 *)(p + 0x34) += 1.66666662693023681640625f * D_004A6AA8[p[0x20]].a;
    else
        *(f32 *)(p + 0x34) -= 1.66666662693023681640625f * D_004A6AA8[p[0x20]].a;
    *(f32 *)(p + 0x38) += 2.142857074737548828125f * D_004A6AA8[p[0x20]].b;
    p[0x1B0] = 0x44;
    p[0x1B1] = 0x44;
    p[0x1B5] = 0x43;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7C[p[2]]++;
    func_001757E0(p, 0x17, 0xB);
    p[0x22] = (u8)func_0041ABD0(p, q);
    *(u8 **)(p + 0x14) = (u8 *)jtbl_004A6CA0[p[0x20] - 3];
    *(s16 *)(p + 0x1C) = 1;
    func_0041A040(p, 0xF);
    func_0041AA10(p, q);
}
