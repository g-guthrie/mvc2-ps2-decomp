/* ./try.sh src/grok_kp_0022D210.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2794;
extern s8 D_004C00D8;
extern s8 D_004C00DC;
extern s8 D_004C00E0;
extern void func_001E3710(u8 *, s32);
extern void func_001757E0(u8 *, s32, u8);

void func_0022D210(u8 *p)
{
    u8 *sub = p + 0x2B8;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        if (sub[0xE])
            p[0x1B5] = 6;
        else
            p[0x1B5] = 0x14;
        func_001E3710(p, 0x14);
        *(s8 **)(p + 0x408) = &D_004C00D8;
        p[0x1BB] = 0;
        break;
    case 1:
        if (sub[0xE]) {
            p[0x168] = 1;
            p[0x1B5] = 7;
        } else {
            p[0x168] = 4;
            p[0x1B5] = 0x15;
        }
        func_001E3710(p, 0x15);
        *(s8 **)(p + 0x408) = &D_004C00DC;
        p[0x1BB] = 1;
        break;
    case 2:
        if (sub[0xE]) {
            p[0x168] = 2;
            p[0x1B5] = 8;
        } else {
            p[0x168] = 5;
            p[0x1B5] = 0x16;
        }
        func_001E3710(p, 0x16);
        *(s8 **)(p + 0x408) = &D_004C00E0;
        p[0x1BB] = 2;
        break;
    }
    /* Native code explicitly reloads and rewrites the selected byte. */
    p[0x1B5] = (s8)p[0x1B5];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    {
        u8 *q = (u8 *)((p[2] << 1) + (u32)D_004C2794);
        *(s16 *)(q + 0x7C) = *(s16 *)(q + 0x7C) + 1;
    }
    func_001757E0(p, 9, p[0x168]);
}
