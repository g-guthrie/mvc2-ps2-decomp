typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B31;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3c;
extern G3c *D_004C2794;

void func_003C93E0(u8 *p, u8 *q)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    extern void func_001E3710(u8 *, s32);
    u32 t;
    f32 k;
    u8 *n;
    s32 i;
    u8 *q50;
    B31 *qe;
    u8 *q2, *q1, *q54, *q1b7, *q1b8, *q30, *q24;

    qe = (B31 *)(q + 0xEC);
    t = p[4]; p[4] = t + 1;
    *(B31 *)(p + 0xEC) = *qe;
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    q2 = q + 2; q1 = q + 1; q50 = q + 0x50; q54 = q + 0x54;
    q1b7 = q + 0x1B7; q1b8 = q + 0x1B8; q30 = q + 0x30; q24 = q + 0x24;
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x1B5] = 0x34;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    { s32 x = p[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    p[0x1B0] = 0x43;
    p[0x1B1] = 0x42;
    p[0x22] = 0xFF;
    *(s16 *)(p + 0x1C) = 10;
    *(u32 *)(p + 0x60) = 0x43AB6DB6;
    k = 13.333333015441895f;
    if (*(s16 *)(p + 0x140) != 0) k = -k;
    *(f32 *)(p + 0x5C) += k;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + k;
    { f32 c = 342.85711669921875f; *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + c; }
    *(s8 *)(p + 0x31) = -1;
    func_001757E0(p, 0x16, 2);
    func_001E7F60(p);
    n = p;
    i = 0;
    do {
        n = *(u8 **)(n + 0xC);
        *(B31 *)(n + 0xEC) = *qe;
        n[0x13C] = 1;
        n[2] = *q2;
        n[1] = *q1;
        *(f32 *)(n + 0x50) = *(f32 *)q50;
        *(f32 *)(n + 0x54) = *(f32 *)q54;
        n[0x1B7] = *q1b7;
        n[0x1B8] = *q1b8;
        *(s8 *)(n + 0x30) = *(s8 *)q30;
        *(V3 *)(n + 0x50) = *(V3 *)q50;
        *(s8 *)(n + 0x24) = *(s8 *)q24;
        n[0x1B0] = 0x43;
        n[0x1B1] = 0x42;
        n[0x14F] = 0x40;
        n[0x14E] = 0x40;
        n[0x14D] = 0x40;
        n[0x14C] = 0x40;
        i++;
    } while (i <= 6);
    *(u8 **)(p + 0xD0) = n;
    p[0xD9] = 0;
    func_001E3710(p, 0x48);
}
