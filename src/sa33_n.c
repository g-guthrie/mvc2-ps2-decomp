typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct N1841 { u8 pad0[0x18]; u8 *tab[2][3]; u8 pad30[0xE]; s8 b3E; } N1841;
extern N1841 *D_004C2794;
extern s16 D_004BF500[3];
extern f32 D_004F1F4C[];

void func_001841E0(void)
{
    extern void func_00186CE0(u8 *, s32);
    extern void func_00184540(u8 *);
    extern void func_00175C00(u8 *, s32);
    u8 *o;
    s32 i;
    i = 0;
    do {
        o = D_004C2794->tab[D_004C2794->b3E][i];
        if (o[0] == 0) {
            o[0] = 1;
            o[4] = 1;
            o[5] = 0;
            *(f32 *)(o + 0x38) = *(f32 *)(o + 0x430);
            func_00186CE0(o, 0);
        } else {
            *(s32 *)(o + 0x5C) = 0;
            *(s32 *)(o + 0x60) = 0;
            *(s32 *)(o + 0x68) = 0;
            *(s32 *)(o + 0x6C) = 0;
            func_00184540(o);
        }
        if (*(s16 *)(o + 0x434) == 0) {
            *(s16 *)(o + 0x438) = 1;
            *(s16 *)(o + 0x434) = 1;
            o[0x1F0] = 0;
        }
        *(f32 *)(o + 0x34) = D_004F1F4C[0] + 1.6666666269302368f * (f32)D_004BF500[i] / 256.0f;
        if (((*(u32 *)(o + 0x428) & 0x100000) | (*(u32 *)(o + 0x42C) & 0x4000000)) != 0) o[0x216] = 0;
        func_00175C00(o, 1);
        i++;
    } while (i < 3);
    o = D_004C2794->tab[D_004C2794->b3E ^ 1][0];
    if (o[1] == 0x1A) {
        o[4] = 1;
        o[5] = 0;
        o[0x13C] = 0;
        func_00186CE0(o, 0x17);
        *(f32 *)(o + 0x34) = D_004F1F4C[0];
        *(f32 *)(o + 0x38) = *(f32 *)(o + 0x430);
        o[0x201] = 0x10;
        o[0x1B1] = 0;
    }
}
