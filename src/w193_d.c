typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern s8 D_004F7F4C[];
extern s8 D_004F7F33[];
extern s8 D_004F7F35[];
extern s8 D_004F7F36[];
extern s8 D_004F7F37[];
extern s8 D_004F7F38[];
extern s32 D_004C283C;
extern void func_003DAA40(u8 *);

void func_003CF930(u8 *p)
{
    s32 v;
    if (D_004F7F4C[0] != 4) {
        func_003DAA40(p);
        return;
    }
    if (D_004F7F33[0] != p[0x21]) {
        *(u32 *)(p + 0x80) = 0x3F333333;
        *(u32 *)(p + 0x7C) = 0x3F333333;
        *(u32 *)(p + 0x78) = 0;
    } else {
        *(u32 *)(p + 0x80) = 0x3F800000;
        *(u32 *)(p + 0x7C) = 0x3F800000;
        *(u32 *)(p + 0x78) = 0x3F800000;
    }
    switch (p[0x21]) {
    case 0:
        v = (s8)(D_004F7F35[0] + 0x23);
        break;
    case 1:
        v = (s8)(D_004F7F36[0] + 0x28);
        break;
    case 2:
        v = (s8)(0x2D - D_004F7F37[0]);
        break;
    case 3:
        if (D_004F7F38[0] != 0) {
            v = 0x15;
        } else {
            v = 0xD;
        }
        break;
    default:
        v = 0;
        break;
    }
    *(s16 *)(p + 0xCC) = (s8)v;
    *(s32 *)(p + 0x84) = D_004C283C;
}

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G7;
extern G7 *D_004C2794;
extern s32 D_004C12AC;
extern s32 D_004C12B0;
extern s32 D_004C12B4;
extern s32 D_004C12C4;
extern s32 D_004C12C8;
extern s32 D_004C12CC;
extern void func_001E3710(u8 *, u8);
extern void func_001757E0(u8 *, s32, s32);

