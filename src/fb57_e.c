typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B31;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H_e;
extern H_e *D_004C2794;
extern f32 D_00475EA0[];
extern f32 D_00475F70[];

void func_003C4D30(u8 *p, u8 *q)
{
    extern u8 *func_003C4990(u8 *, u8, u8);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003C4FB0(u8 *, u8 *);
    extern s32 fptosi(f32);
    u8 *s;
    u32 t, idx, n;
    s16 a;
    s32 c;
    u8 *r;

    if (p[0x21] == 0) {
        func_003C4990(p, 1, 4);
        func_003C4990(p, 1, 3);
        func_003C4990(p, 1, 2);
        func_003C4990(p, 1, 1);
    }
    t = p[4]; p[4] = t + 1;
    *(B31 *)(p + 0xEC) = *(B31 *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    s = p + 2;
    if (q[0x1FD] == 6) idx = 2; else idx = p[0x1B7];
    a = fptosi(D_00475EA0[idx]);
    if (*(s16 *)(q + 0x140) != 0) a = -a;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + (f32)a;
    p[0x14F] = 0x40;
    p[0x14E] = 0x40;
    p[0x14D] = 0x40;
    p[0x14C] = 0x40;
    p[0x1B0] = 3;
    p[0x1B1] = 0;
    if (q[0x1FD] == 6) c = 0x40;
    else {
        c = 0x4E;
        if (p[0x1B7] == 0) c = 0x31;
    }
    p[0x1B5] = c;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[*s]++;
    n = p[0x21];
    if (n == 4) t = p[0x1B7] * 8 + 0xB;
    else { t = p[0x1B7] * 8 + 9; t += n; }
    func_001757E0(p, 0x16, t & 0xFF);
    r = q;
    if (p[0x21] != 0) r = *(u8 **)(p + 8);
    *(f32 *)(p + 0x38) = *(f32 *)(r + 0x38) + D_00475F70[p[0x21]];
    func_003C4FB0(p, q);
}
