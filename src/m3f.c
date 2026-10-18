typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern void func_00365F50(u8 *);
extern u8 *D_004C2970;

void func_00365760(u8 *p) {
    f32 k = 0.0500000007f;
    f32 v;
    func_00175700(p);
    v = *(f32 *)(p + 0x118) - k;
    *(f32 *)(p + 0x118) = v;
    if (v <= 0.0f) {
        u32 t = p[4];
        p[4] = t + 1;
        *D_004C2970 = 0;
        func_00365F50(p);
    }
}
