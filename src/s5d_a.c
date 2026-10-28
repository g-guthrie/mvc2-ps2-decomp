/* s5d: MW 3.0, ./try30.sh src/s5d_a.c "-O3 -Op -sdatathreshold 8". static func_00185F90 is the real callee (credited in src/nh12_b.c). Mask built through one reused variable (m = ok + 10; m = 1 << m) gives retail and v0,v0,v1 operand order. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef signed char s8;
extern s8 D_004C2798[2];
extern u8 D_004D3170[];

static s32 func_00185F90(u8 a)
{
    s8 i; s32 j;
    i = 0; j = 0;
    for (; i < D_004C2798[a ^ 1]; i++, j += 4) {
        u8 *q = *(u8 **)(D_004D3170 + (a ^ 1) * 0x178 + j);
        if (q[3] < 5) {
            if ((q[0x15A] & 0xE0) >= 0x80) return 1;
        }
    }
    return 0;
}

typedef struct { u8 pad[0x34]; f32 f34; } V;
typedef struct { u8 pad[0x354]; u16 h354; } V2;
u8 func_00185EC0(u8 *p)
{
    f32 x;
    f32 y;
    f32 c;
    u8 *pp;
    u8 ok;
    u32 h;
    u32 m;
    if (p[0x20D] == 2) {
        pp = *(u8 **)(p + 0x220);
        ok = (*(f32 *)(p + 0x34) >= *(f32 *)(*(u8 **)(p + 0x220) + 0x34)) ? 0 : 1;
    } else {
        if (p[0x1E6] == 0)
            c = -23.333332061767578f;
        else
            c = 23.333332061767578f;
        pp = *(u8 **)(p + 0x220);
        x = *(f32 *)(p + 0x34); y = *(f32 *)(pp + 0x34); y += c; ok = (x > y) ? 0 : 1;
    }
    m = ok + 10; m = 1 << m; h = *(u16 *)(p + 0x354); if ((h & m) == 0) return 0;
    return func_00185F90(p[2]) != 0;
}
