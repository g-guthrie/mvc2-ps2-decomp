typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s32 w[0x31]; } W31;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x22]; s8 b22; } P22;
typedef struct { s16 h0; u8 b2; u8 b3; V3 v; } E3786C0;
typedef struct { u8 pad[0x7C]; s16 f7c[4]; } G3786C0;
extern E3786C0 *D_004C298C;
extern G3786C0 *D_004C2794;
extern s16 D_00464030[];
extern s16 D_00464032[];
extern s8 D_00464034[];
extern u8 D_004640D0[];
extern f32 D_00464090[];

void residual_003786C0(u8 *p) {
    extern void func_001757E0(u8 *, s32, u8);
    extern f32 func_00417500(s32);
    extern f32 func_00417440(s32);
    extern void func_00378A00(u8 *);
    u8 *par;
    u8 *q2;
    P22 *sa;
    u32 t;
    par = *(u8 **)(p + 0x18);
    t = p[4]; p[4] = t + 1;
    *(W31 *)(p + 0xEC) = *(W31 *)(*(u8 **)(p + 0x18) + 0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x14C] = 0xFF;
    p[0x14D] = 0xFF;
    p[0x14E] = 0x80;
    p[0x14F] = 0x80;
    p[0x24] = 0xB;
    q2 = p + 2;
    sa = (P22 *)p;
    func_001757E0(p, 0x17, *(s16 *)((u8 *)D_00464030 + p[0x21] * 6) + 1);
    *(s16 *)(p + 0x1E) = 1;
    *(s32 *)(p + 0x48) = *(s16 *)((u8 *)D_00464032 + p[0x21] * 6);
    *(s8 *)(p + 0x22) = *(s8 *)((u8 *)D_00464034 + p[0x21] * 6);
    if (*(s16 *)(p + 0x140) == 0) {
        sa->b22 = (0x20 - sa->b22) & 0x1F;
    }
    D_004C298C->b2 = 0x10;
    D_004C298C->h0 = 500;
    D_004C298C->b3 = D_004640D0[p[0x21]];
    D_004C298C->v = *(V3 *)(*(u8 **)(par + 0x220) + 0x34);
    D_004C298C->v.y += 68.57142639160156f;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x38) += 205.7142791748047f;
    if (*(s16 *)(p + 0x140) != 0) {
        *(f32 *)(p + 0x34) -= 60.0f * func_00417500(*(s32 *)(p + 0x48));
    } else {
        *(f32 *)(p + 0x34) += 60.0f * func_00417500(*(s32 *)(p + 0x48));
    }
    *(f32 *)(p + 0x38) += 60.0f * func_00417440(*(s32 *)(p + 0x48));
    *(s16 *)(p + 0x1C) = 0;
    p[0x20] = 0;
    *(f32 *)(p + 0x68) = D_00464090[p[0x21]];
    p[0x1B5] = 0x3E;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { s32 x = *q2; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    func_00378A00(p);
}
