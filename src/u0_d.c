typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;typedef signed int s32;
extern s32 D_00633694, D_006336B4, D_006336B8, D_006336BC, D_00633690;
extern s32 func_00110350(s32, s32, s32);
s32 func_004199F0(s32 a, s32 b, s32 c) {
    s32 i;
    if (D_00633694 != 0) return -1;
    i = 0;
    do {
        if (func_00110350(a, b, c) == 0) {
            D_006336B4 = a;
            D_00633694 = 4;
            D_006336B8 = b;
            D_006336BC = c;
            if (D_00633690 == 0) D_00633690 = 5;
            return 0;
        }
        i++;
    } while (i < 5);
    return -1;
}
typedef float f32;
extern void func_003F4440(f32 *, f32);
void func_003F39E0(f32 *m, f32 ang) {
    f32 v[3];
    v[0] = m[0]; v[1] = m[1]; v[2] = m[2];
    func_003F4440(v, ang);
    m[0] = v[0]; m[1] = v[1]; m[2] = v[2];
    v[0] = m[4]; v[1] = m[5]; v[2] = m[6];
    func_003F4440(v, ang);
    m[4] = v[0]; m[5] = v[1]; m[6] = v[2];
    v[0] = m[8]; v[1] = m[9]; v[2] = m[10];
    func_003F4440(v, ang);
    m[8] = v[0]; m[9] = v[1]; m[10] = v[2];
}
typedef struct { s32 w; u8 b; u8 pad[3]; } Ent;
extern Ent D_00633E30[]; extern s32 D_00633E20;
s32 func_004232C0(u32 a0, u32 a1, u32 a2) {
    Ent *e = &D_00633E30[D_00633E20];
    u32 t;
    if (e->w >= 0) return -1;
    if (a1 > 0x18 || a2 > 0x18) return -2;
    a0 = (a0 + 0x3F) >> 6;
    t = ((a0 & 0xFFFF) << 8) | a1;
    e->w = (t & 0xFFFFFF) | 0x77000000;
    e->b = a2;
    D_00633E20 = ++D_00633E20 % 64;
    return 0;
}
s32 func_003EAA30(s16 a) {
    s32 i = 1;
    do {
        if (!((1 << i) < a)) return i;
        i++;
    } while (i <= 10);
    return 1;
}
