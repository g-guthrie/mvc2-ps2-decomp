typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x160]; s8 b[8]; } S_n;
typedef struct { u8 pad[0x34]; f32 f34, f38; u8 pad2[0x5C - 0x3C]; f32 f5c, f60; u8 pad3[0x68 - 0x64]; f32 f68, f6c; } F_n;
typedef struct { u8 pad[0x2]; u8 b2; u8 pad1[0x1B2 - 3]; s8 b1b2; u8 pad2[2]; u8 b1b5; u8 pad3[0x1C0 - 0x1B6]; s16 h1c0; u8 pad4[0x1D8 - 0x1C2]; s32 f1d8; } U_n;
typedef struct { u8 pad[0x33B]; u8 b33b, b33c; u8 pad2[0x40C - 0x33D]; u8 b40c, b40d; } T_n;
typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G_n;
extern G_n *D_004C2794;

void func_002C9E90(S_n *p, u8 *r)
{
    extern void func_00183D90(S_n *);
    extern s8 func_00175700(S_n *);
    extern void func_001843A0(S_n *);
    s8 *b;
    s8 *a1;
    s32 *s0, *s1, *s2, *s3;
    s32 t;
    *(u8 *)((s32)p + 0x40C) = 2;
    *(u8 *)((s32)p + 0x33C) = 5;
    b = p->b;
    a1 = b + 1;
    if (b[1] == 2) {
        ((T_n *)p)->b40d = 0;
        ((T_n *)p)->b40c = 0;
        ((T_n *)p)->b33b = 0;
        ((T_n *)p)->b33c = 0;
        *a1 = 0;
        *(s32 *)((s32)p + 0x5C) = 0;
        *(s32 *)((s32)p + 0x68) = 0;
    }
    func_00183D90(p);
    s0 = (s32 *)((s32)p + 0x5C);
    s2 = (s32 *)((s32)p + 0x68);
    s1 = (s32 *)((s32)p + 0x60);
    s3 = (s32 *)((s32)p + 0x6C);
    ((F_n *)p)->f34 += ((F_n *)p)->f5c;
    ((F_n *)p)->f5c += ((F_n *)p)->f68;
    ((F_n *)p)->f38 += ((F_n *)p)->f60;
    ((F_n *)p)->f60 += ((F_n *)p)->f6c;
    if (func_00175700(p) < 0) {
        *s0 = 0;
        *s1 = 0;
        *s2 = 0;
        *s3 = 0;
        func_001843A0(p);
        return;
    }
    t = r[5];
    r[5] = t - 1;
    if ((u8)(t - 1) == 0 && ((U_n *)p)->b1b2 != 0) {
        ((U_n *)p)->b1b5 = 0x3E;
        *(u8 *)((s32)p + 0x1B2) = *(u16 *)((s32)p + 0x1C0) = 0;
        ((U_n *)p)->f1d8 = 0;
        D_004C2794->f7c[((U_n *)p)->b2]++;
    }
}
