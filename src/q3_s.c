typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F20B0[];
extern u8 D_004F2668[];
extern u8 D_004F2C20[];
extern u8 D_004F31D8[];
extern u8 D_004F3790[];
extern u8 D_004F3D48[];
extern void (*D_0045E0F0[])();
typedef struct { u8 pad[0x18]; u8 *obj; u8 pad2[0x0]; } E;
extern u8 D_004D18A0[];

void func_00326B70(void) {
    extern void func_00327570();
    u8 *tab[6];
    u8 *o;
    s32 i;
    s32 off;
    s32 j;
    off = 0;
    i = 0;
    tab[0] = D_004F20B0;
    tab[1] = D_004F2668;
    tab[2] = D_004F2C20;
    tab[3] = D_004F31D8;
    tab[4] = D_004F3790;
    tab[5] = D_004F3D48;
    do {
        o = *(u8 **)((u8 *)tab + off);
        if (o[0x268] != 0) {
            D_0045E0F0[o[0x268]](o);
            o[0x268] = 0;
        }
        i++;
        off += 4;
    } while (i < 6);
    i = 0;
    j = 0;
    do {
        o = *(u8 **)(D_004D18A0 + j + 0x18);
        if (*(s8 *)(o + 0x2B0) != 0) {
            func_00327570(o);
            o[0x2B0] = 0;
        }
        i++;
        j += 12;
    } while (i < 2);
}
