/* Metrowerks 3.0: ./try30.sh src/nq112_a.c "-O3,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G_7230;
extern G_7230 *D_004C2794;
typedef struct { u32 w[0x31]; } C_7230;
typedef struct { f32 x, y, z; } V3_7230;
typedef struct { u8 pad[0x5C]; f32 f5c; } N_7230;
void func_003B7230(u8 *a, u8 *b) {
    extern void func_001757E0(u8 *, s32, s32);
    u8 *c;
    N_7230 *sa;
    { u32 t = a[4]; a[4] = t + 1; }
    *(C_7230 *)(a + 0xEC) = *(C_7230 *)(b + 0xEC);
    c = a + 2;
    a[0x13C] = 1;
    a[2] = b[2];
    a[1] = b[1];
    *(f32 *)(a + 0x50) = *(f32 *)(b + 0x50);
    *(f32 *)(a + 0x54) = *(f32 *)(b + 0x54);
    a[0x1B7] = b[0x1B7];
    a[0x1B8] = b[0x1B8];
    *(s8 *)(a + 0x30) = *(s8 *)(b + 0x30);
    *(V3_7230 *)(a + 0x50) = *(V3_7230 *)(b + 0x50);
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
    a[0x1B0] = 0x42;
    a[0x1B1] = 0x44;
    *(u32 *)(a + 0x5C) = 0x4353AAAA;
    *(u32 *)(a + 0x60) = 0x43700000;
    sa = (N_7230 *)a;
    if (*(s16 *)(a + 0x140) == 0) sa->f5c = -sa->f5c;
    *(s8 *)(a + 0x31) = -1;
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24) + *(s8 *)(a + 0x31);
    a[0x1B5] = 0x37;
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(u32 *)(a + 0x1D8) = 0;
    D_004C2794->f7c[*c]++;
    func_001757E0(a, 0x17, 1);
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) + *(f32 *)(a + 0x60);
}
