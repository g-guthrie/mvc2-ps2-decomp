typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef double f64;

extern u32 D_00583BA0, D_00583BA4, D_00583BA8, D_00583BAC;

static void func_00137860(u8 *p, s8 *o1, u32 *o2) {
    if (p[0x21] >= 0x20) {
        *o2 = D_00583BA4 | D_00583BAC;
        *o1 = *(s8 *)(p + 0x21) - 0x20;
    } else {
        *o2 = D_00583BA0 | D_00583BA8;
        *o1 = p[0x21];
    }
}
extern f32 D_0043F760[];
extern f32 D_0043F764[];

void func_00137910(u8 *p) {
    extern void func_0032DE90(u8 *, s16, f32, f32);
    s8 c;
    u32 m;
    f32 a;
    f32 b;
    u32 o;
    func_00137860(p, &c, &m);
    if ((m & (1 << c)) == 0) {
    o = p[0x21] * 8;
    a = 0.5 - (f64)*(f32 *)((u8 *)D_0043F760 + o);
    b = (f64)*(f32 *)((u8 *)D_0043F764 + o) - 0.25;
    func_0032DE90(p, (s16)(p[0x20] + 10), a, b);
    p[0x22] = 1;
    }
}

void func_00137A00(u8 *p) {
    extern void func_0032DE90(u8 *, s16, f32, f32);
    s8 c;
    u32 m;
    f32 a;
    f32 b;
    u32 o;
    func_00137860(p, &c, &m);
    if ((m & (1 << c)) == 0) return;
    if (p[0x22] == 0) return;
    o = p[0x21] * 8;
    a = -(0.5 - (f64)*(f32 *)((u8 *)D_0043F760 + o));
    b = -((f64)*(f32 *)((u8 *)D_0043F764 + o) - 0.25);
    func_0032DE90(p, (s16)(p[0x20] + 10), a, b);
    p[0x22] = 0;
}
