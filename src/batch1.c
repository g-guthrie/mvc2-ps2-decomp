typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_0011D8F8(void *, s32, s32);
extern void func_003DD260(void *);
extern s32 D_004C28A0;
extern s32 D_004C2B40;
extern u8 D_0056EE70[];
extern u8 D_006327B0[];


void func_0040FCE8(u8 *p, s32 a, s32 b, s32 v) { a <<= 1; a += b; a <<= 2; a += (s32)p; *(s32 *)(a + 0x28) = v; }


void func_004152E0(void) { D_004C28A0 = 0; func_0011D8F8(D_0056EE70, 0, 0xF700); }
void func_00415300(void) { D_004C28A0 = 0; func_0011D8F8(D_0056EE70, 0, 0xF700); }

void func_004171E0(void) { func_003DD260(D_006327B0 + D_004C2B40 * 64); }







