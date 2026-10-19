/* ./try.sh src/grok_bg_0031BA60.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2794;
extern u8 D_004C1768[];
extern void func_001E3210(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);

void func_0031BA60(u8 *p)
{
    s32 anim;
    s32 mode;

    switch (p[0x1FC]) {
    case 0:
        mode = 0;
        p[0x1B5] = 0;
        *(u8 **)(p + 0x408) = D_004C1768 + 0x28;
        p[0x1BB] = 0;
        anim = 30;
        break;
    case 1:
        p[0x20] = 0;
        mode = 1;
        p[0x1B5] = 1;
        *(u8 **)(p + 0x408) = D_004C1768 + 0x2C;
        p[0x1BB] = 1;
        anim = 31;
        break;
    case 2:
        mode = 2;
        p[0x1B5] = 2;
        *(u8 **)(p + 0x408) = D_004C1768 + 0x30;
        p[0x1BB] = 2;
        anim = 32;
        break;
    default:
        mode = 0;
        anim = 30;
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001E3210(p, anim);
    func_001757E0(p, 7, mode);
}
