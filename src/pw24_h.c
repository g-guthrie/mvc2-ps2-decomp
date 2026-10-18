typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern V3 D_0045F988;
extern u8 D_0045F9B0[], D_0045F9C0[], D_0045F9D0[];
extern f32 func_00154710();
extern void func_003DAA40();

void func_0033FC20(u8 *a) {
    s32 t = *(s16 *)(a + 0x1C);
    if (t >= 0x1770) {
        func_003DAA40();
        return;
    }
    *(f32 *)(a + 0x34) = func_00154710(D_0045F9B0, a + 4, t);
    *(f32 *)(a + 0x38) = func_00154710(D_0045F9C0, a + 5, *(s16 *)(a + 0x1C));
    *(f32 *)(a + 0x3C) = func_00154710(D_0045F9D0, a + 6, *(s16 *)(a + 0x1C));
    *(s16 *)(a + 0x1C) = *(s16 *)(a + 0x1C) + 1;
    D_0045F988 = *(V3 *)(a + 0x34);
}
