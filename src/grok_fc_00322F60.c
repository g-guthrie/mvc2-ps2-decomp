/* ./try.sh src/grok_fc_00322F60.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_001861B0(u8 *);
extern void func_0018C4B0(u8 *, s32);
extern int func_001757E0(u8 *, int, int);
extern void func_00183D90(u8 *);
extern void func_001863F0(u8 *);
extern int func_00175700(u8 *);
extern void func_003266E0(u8 *);
extern void func_003CD6B0(u8 *, s32);

void func_00322F60(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        func_001861B0(p);
        func_0018C4B0(p, 5);
        p[0x20D] = 0;
        p[0x1B5] = 0x76;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
        func_001757E0(p, 0x14, 1);
    }
    if (p[0x213] == 3)
        func_00183D90(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if ((s8)func_00175700(p) < 0) {
        func_003266E0(p);
        return;
    }
    if (*(s8 *)(p + 0x151)) {
        func_003CD6B0(p, *(s8 *)(p + 0x151) - 1);
        p[0x151] = 0;
    }
}
