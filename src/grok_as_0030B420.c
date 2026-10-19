/* ./try.sh src/grok_as_0030B420.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

typedef struct G { u8 pad[0x7C]; s16 t[2]; } G;
extern G *D_004C2794;
extern void func_00185490(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00183D10(u8 *);

void residual_0030B420(u8 *p)
{
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[6]++;
    func_00185490(p);
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    p[0x1B5] = 0x3E;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->t[p[2]]++;
    *(s16 *)(p + 0x1C) = 0x60;
    *(s16 *)(p + 0x1E) = 2;
    if (p[0x20D] == 2)
        func_001757E0(p, 0x16, 0xF);
    else {
        p[0x20D] = 0;
        func_001757E0(p, 0x16, 0xD);
        func_00183D10(p);
    }
}
