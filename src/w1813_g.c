typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x5C]; s8 b5C; } G3D;
extern G3D *D_004C2840;

typedef struct {
    s8 b0; u8 b1; u8 b2; u8 b3; u8 pad4[4];
    s16 h8; s16 hA; u8 padC[4];
    f32 f10; f32 f14;
    u8 pad18; s8 b19; u8 b1A;
} P3D;

void func_003D30A0(P3D *p, s32 flag)
{
    extern void func_003D6AC0();
    extern void func_003D3080(s32);
    extern void func_0016EE50();
    extern void func_001E4140(void);
    extern void func_001E3CE0(s32);
    p->b2 = 0;
    p->b3 = 0;
    *(u8 *)((u8 *)p + 0xC) = 0;
    p->b1A = 0;
    if (((p->b0 != 0) ^ 1) & 4) func_003D6AC0();
    p->h8 = 0x4650;
    p->hA = 10;
    if (flag != 0) {
        p->f10 = 80.0f;
        p->f14 = 88.0f;
        if (p->b19 != 0) {
            p->f10 = 200.0f;
            p->f14 = 120.0f;
        }
        if (D_004C2840->b5C != 0) {
            if (p->b0 == 0) func_003D3080(0);
        }
    } else {
        p->f10 = 192.0f;
        p->f14 = 32.0f;
        func_0016EE50();
        if (D_004C2840->b5C == 0) {
            func_003D3080(1);
            func_001E4140();
        }
        func_001E3CE0(0x39);
    }
}
