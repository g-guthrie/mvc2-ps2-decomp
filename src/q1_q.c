typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 b[28]; } E28;
typedef struct { u8 pad[0x184]; E28 *tab; } T184;

extern u8 *D_004C2840;
extern u16 D_00584BCA[], D_00584C40[], D_00584D2C[], D_00584DA2[], D_00584CB6[];

#define BUMP(T) \
        { u16 *e = &T[(u8)a]; if (*e < 9999) *e = *e + 1; }

void func_0038CCA0(s32 a)
{
    switch (*(s8 *)(D_004C2840 + 0x4C)) {
    case 0:
        BUMP(D_00584BCA)
        break;
    case 1:
        BUMP(D_00584C40)
        break;
    case 2:
        BUMP(D_00584D2C)
        break;
    case 5:
        BUMP(D_00584DA2)
        break;
    case 7:
        BUMP(D_00584CB6)
        break;
    }
}
