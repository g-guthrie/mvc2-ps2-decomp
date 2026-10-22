typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 w; s32 x; } E423750;
extern s32 D_004C2538;
extern E423750 D_00633E30[];
extern s32 D_00633E28[];
extern s32 D_00633E18[];
extern u8 D_00634060[];
extern u8 D_00634100[];

s32 func_00423750(s32 a)
{
    extern s32 func_00103E30(s32);
    extern void func_00103E20(s32);
    extern void func_00103E00(s32);
    extern s32 func_00423E30(E423750 *);
    extern s32 func_00106E68(u8 *, s32, s32, u8 *, s32, u8 *, s32, void *, s32);
    extern void func_00423890(void);
    s32 h;
    E423750 *p;
    s32 v, w;

    if (a != 0) {
        if (func_00103E30(D_004C2538) < 0) return -1;
    } else {
        func_00103E20(D_004C2538);
    }
    h = D_00633E28[0];
    while ((p = &D_00633E30[h])->w >= 0) {
        if (func_00423E30(p) < 0) break;
        h = h + 1;
        p->w = -1;
        h = h % 64;
    }
    D_00633E28[0] = h;
    v = D_00633E18[0];
    if (v != 0) {
        w = (v + 16) & -16;
        if (a != 0) a = 1;
        if (func_00106E68(D_00634060, 0, a, (u8 *)D_00634100, w, (u8 *)D_00634100, 0, (void *)func_00423890, D_004C2538) < 0) {
            func_00103E00(D_004C2538);
            return -1;
        }
        D_00633E18[0] = 0;
    } else {
        func_00103E00(D_004C2538);
    }
    return 0;
}
