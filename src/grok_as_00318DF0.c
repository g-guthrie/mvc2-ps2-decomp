/* ./try.sh src/grok_as_00318DF0.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

typedef struct G { u8 pad[0x7C]; s16 t[2]; } G;
extern G *D_004C2794;
extern void func_00175C00(u8 *, s32);
extern void func_00318500(u8 *);
extern int func_001757E0(u8 *, s32, s32);
extern void func_001266A0(u8 *, s32, s32);
extern void func_00183D10(u8 *);

void func_00318DF0(u8 *p)
{
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[6]++;
    func_00175C00(p, 0);
    func_00318500(p);
    p[0x1B5] = 0x3D;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->t[p[2]]++;
    p[0x2BD] = 0;
    func_001757E0(p, 0x16, 0x18);
    func_001266A0(p, 1, 0);
    p[0x2BB] = 0;
    p[0x2BA] = 0;
    func_00175C00(p, 0);
    func_00183D10(p);
}
