/* ./try.sh src/grok_as_00307010.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct G { u8 pad[0x7C]; s16 t[2]; } G;
extern G *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_001E3210(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);

void residual_00307010(u8 *p, u8 *q)
{
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[6]++;
    q[0xB] = 0;
    q[0xC] = 0;
    q[0xD] = 0;
    q[0xE] = 0;
    q[0xF] = 0;
    q[0xA] = 0x10;
    func_00185490(p);
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    func_00183D10(p);
    p[0x1B5] = 0x2E;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->t[p[2]]++;
    func_001E3210(p, 0x16);
    func_001757E0(p, 0x16, 0);
}
