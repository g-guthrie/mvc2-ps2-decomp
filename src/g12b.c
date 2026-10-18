typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern void func_00136DA0(s32 i);
extern u8 D_004C262C;
extern u8 D_004C2630;
void func_00136D50(void) {
    s32 i = 0;
    D_004C262C = 0;
    D_004C2630 = 0;
    do { func_00136DA0(i); i++; } while (i < 0x3B);
}

extern s32 func_00174170();
extern void func_001757E0();
extern u8 D_004C1738[2][4];
void func_0031B210(u8 *p) {
    s8 k = *(s8 *)(p + 0x151);
    s32 r;
    if (k) k = 1;
    r = func_00174170() & 3;
    func_001757E0(p, 0, D_004C1738[k][r]);
}
