typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
extern G *D_004C2794;
extern s16 D_004C1D78;
extern f32 D_004649A0[];
extern f32 D_004649A4[];
extern f32 D_004649A8[];
extern f32 D_004649AC[];

void func_00387580(u8 *a, u8 *b)
{
    extern void func_00387710(u8 *, u8 *);
    f32 c1;
    f32 c2;
    u32 t;
    t = a[5];
    a[5] = t + 1;
    *(s32 *)(a + 0xD8) = 0;
    if (b[1] == 0x1C) {
        c1 = -53.33333206176758f;
        c2 = 94.28571319580078f;
    } else {
        c1 = -53.33333206176758f;
        c2 = 81.4285659790039f;
    }
    if (b[0x1E6] == 0) {
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + c1;
        *(f32 *)(a + 0x5C) = D_004649A0[b[0x1B7] * 4];
        *(f32 *)(a + 0x68) = D_004649A4[b[0x1B7] * 4];
    } else {
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) - c1;
        *(f32 *)(a + 0x5C) = -D_004649A0[b[0x1B7] * 4];
        *(f32 *)(a + 0x68) = -D_004649A4[b[0x1B7] * 4];
    }
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) + c2;
    *(f32 *)(a + 0x60) = D_004649A8[b[0x1B7] * 4];
    *(f32 *)(a + 0x6C) = D_004649AC[b[0x1B7] * 4];
    *(s32 *)(a + 0xD0) = D_004C1D78;
    *(s32 *)(a + 0xD4) = 1;
    a[0x1B0] = 0x42;
    a[0x1B1] = 0x42;
    a[0x1B5] = 0x3A;
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(s32 *)(a + 0x1D8) = 0;
    D_004C2794->f7c[a[2]]++;
    func_00387710(a, b);
}
