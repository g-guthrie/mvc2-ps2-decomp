typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern u8 D_006310C0[];
extern s32 D_004895C0;
extern s32 D_004895D4;
extern u8 D_004BE220[];
extern u8 D_004BE248[];
extern s32 func_0011D8F8(u8 *, s32, s32);
extern void func_0040C798(void);
extern void func_0040B098(void);
extern void func_0040C578(void);
extern s32 func_0040C2C0(u8 *, u8 *);
extern void func_0011EB60(u8 *, u8 *);
extern void func_0040AF58(s32, u8 *);
extern s32 func_0040C178(u8 *, u8 *, u32, u32);
extern u32 func_0040C3B0(u8 *, s32);

u32 func_0040C808(u8 *a, u8 *b, u32 c, u32 d)
{
    u32 n;
    u32 m;
    s32 t;
    func_0011D8F8(D_006310C0, 0, 0x1000);
    if (D_004895C0 == 0) {
        func_0040C798();
    }
    func_0040B098();
    func_0040C578();
    if (a == 0) {
        return 0;
    }
    if (b == 0) {
        return 0;
    }
    if (c == 0) {
        return 0;
    }
    if (func_0040C2C0(a, D_006310C0) == 0) {
        if (D_004895D4 != 2) {
            func_0011EB60(D_004BE220, a);
        }
        func_0040AF58(0, D_004BE248);
        return 0;
    }
    m = d + 9;
    t = func_0040C178(b, D_006310C0, c / m, d);
    d++;
    return (c / m) * 8 + func_0040C3B0(b, t) * d;
}
