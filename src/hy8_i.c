typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[8]; s16 h8; } H8S;
extern H8S *D_004C2840;
extern s8 D_004BF3A0[8];
extern s8 *D_00443A30[];

static void func_00147D20(u8 *p)
{
    s32 a3;
    s8 a2;
    u8 t0;
    s32 t1;
    f32 f;
    t1 = *(s32 *)(p + 0xD4);
    if ((t1 & 0x7F) != 0) {
        t0 = p[0x20];
        a3 = D_004BF3A0[t0];
        a2 = *D_00443A30[a3];
        if (a3 == 2) a2 ^= 1;
        if (t0 == D_004C2840->h8) {
            if (a3 >= 0 && a2 == t1 - 1) f = 1.0f; else f = 0.5f;
            *(f32 *)(p + 0x80) = f;
            *(f32 *)(p + 0x7C) = f;
            *(f32 *)(p + 0x78) = f;
        } else {
            if (a3 >= 0 && a2 == t1 - 1) {
                *(u32 *)(p + 0x78) = 0;
                *(u32 *)(p + 0x80) = 0x3F333333;
                *(u32 *)(p + 0x7C) = 0x3F333333;
            } else {
                *(u32 *)(p + 0x80) = 0x3E4CCCCC;
                *(u32 *)(p + 0x7C) = 0x3E4CCCCC;
                *(u32 *)(p + 0x78) = 0x3E4CCCCC;
            }
        }
    } else {
        if (p[0x20] == D_004C2840->h8) f = 1.0f; else f = 0.7f;
        *(f32 *)(p + 0x80) = f;
        *(f32 *)(p + 0x7C) = f;
        *(f32 *)(p + 0x78) = f;
    }
}

typedef struct { f32 x, y, z; } V3;
typedef struct { V3 a; V3 b; u16 s18; u8 p1A; s8 b1B; } H8E;
extern H8E D_00442B50[];
extern u32 D_004C2804;

void func_00147E50(u8 *p)
{
    extern u8 *func_00147920(u8 *, u32, s32);
    extern void func_00147AB0(u8, s8);
    extern u8 *func_00147870(s8, s8);
    H8E *e;
    s32 t;
    p[4]++;
    p[0x13C] = 1;
    e = &D_00442B50[p[0x20]];
    *(u16 *)(p + 0xCC) = e->s18;
    *(u32 *)(p + 0x84) = D_004C2804;
    *(V3 *)(p + 0x34) = e->a;
    *(V3 *)(p + 0x50) = e->b;
    *(u32 *)(p + 0xD0) |= 0x420;
    *(u32 *)(p + 0xD4) = 0;
    *(u32 *)(p + 0x74) = 0x3F800000;
    func_00147D20(p);
    func_00147920(p, 3, p[0x20]);
    t = e->b1B;
    if (t != 0) {
        if ((s8)t & 0x80) {
            func_00147AB0(5, (s8)p[0x20]);
            return;
        }
        func_00147870(6, (s8)p[0x20]);
    }
}
