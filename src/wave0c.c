typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 m[16]; } M16;

extern void func_001757E0();
extern void func_003DD260(void *);
extern void func_003DF850(s32, void *);
extern void func_003DE680();
extern s32 func_003D90A0();
extern void func_0033D3B0(s32);
extern s32 func_00174170();

void func_0033D360(void) {
    s32 i;
    if (func_003D90A0(0)) {
        for (i = 0; i < 3; i++) func_0033D3B0(i);
    }
}



f32 func_00153E60(f32 x) {
    f32 a[16];
    f32 r[4];
    f32 c[4];
    func_003DD260(a);
    func_003DF850(0x19, a);
    c[0] = 0; c[1] = 0; c[2] = x;
    func_003DE680(r, c);
    return r[2];
}
