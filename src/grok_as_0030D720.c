/* ./try.sh src/grok_as_0030D720.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef signed char s8;
typedef float f32;

typedef struct G { u8 pad[0x7C]; s16 t[2]; } G;
extern G *D_004C2794;
extern void func_001861B0(u8 *);
extern void func_0018C4B0(u8 *, s32);
extern int func_001757E0(u8 *, s32, s32);
extern void func_001DD470(u8 *, s32);
extern void func_00183D90(u8 *);
extern void func_001863F0(u8 *);
extern s32 func_00175700(u8 *);
extern void func_0030F650(u8 *);

void func_0030D720(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        func_001861B0(p);
        func_0018C4B0(p, 5);
        p[0x20D] = 1;
        p[0x1B5] = 0x47;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->t[p[2]]++;
        func_001757E0(p, 0x14, 6);
        func_001DD470(p, 2);
    }
    if (p[0x213] == 3)
        func_00183D90(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if ((s8)func_00175700(p) < 0)
        func_0030F650(p);
}
