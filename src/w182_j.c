typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x93]; s8 b93; u8 pad1[4]; s32 w98; u8 pad2[3]; s8 b9F; u8 pad3[0x11]; s8 bB1; } G16;
extern G16 *D_004C2840;
extern s32 D_004C28AC, D_004C28B8, D_004C28BC;
extern u8 D_004D18A0[], D_004D18B8[];
extern u16 D_004ACC90[];

void func_0016F8A0(void)
{
    extern void func_0012DA40(s32, s32, s32);
    extern void func_0012DBA0(s32, s32, s32);
    s32 a, b;
    s32 i, k, sh, c, off;
    switch (D_004C2840->bB1) {
    case 0:
        a = 0x34D;
        b = 0x34E;
        break;
    case 1:
        a = 0x36A;
        b = 0x36B;
        break;
    case 2:
        a = 0x36C;
        b = 0x36D;
        break;
    }
    func_0012DA40(a, D_004C28AC, 2);
    func_0012DA40(b, D_004C28B8, 2);
    c = D_004C2840->b9F;
    if ((c ^ 1) != 0) {
        D_004C2840->w98 = D_004C28BC + 0x3F0000;
    } else {
        D_004C2840->w98 = D_004C28BC;
    }
    off = c * 12;
    D_004C2840->b93 = *(s8 *)(*(u8 **)(D_004D18B8 + off) + 0x540);
    i = 0;
    k = 0;
    sh = 0;
    do {
        u8 *e = *(u8 **)(D_004D18A0 + off + k + 0x18);
        func_0012DBA0(D_004ACC90[*(s8 *)(e + 0x540)], D_004C28B8 + 0x1D0000 + sh, 1);
        i++;
        sh += 0x10000;
        k += 4;
    } while (i < 3);
}
