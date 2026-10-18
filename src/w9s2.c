typedef signed int s32;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned char u8;

extern char D_004BE7F0[];
extern s32 func_0011EB60(void *);
void func_0040E930(void) { func_0011EB60(D_004BE7F0); }

extern s32 func_0010B970(s32, s32, s32, void *, s32);
void func_0010BB98(s32 a, s32 b, s32 c) { char buf[16]; func_0010B970(a, b, c, buf, 0); }

typedef struct { u8 b0, b1, b2, b3; s32 w4, w8, wC, w10, w14, w18, w1C, w20, w24, w28, w2C; } T3FC978;
extern T3FC978 *func_003FC918(void);
T3FC978 *func_003FC978(void) {
    T3FC978 *p = func_003FC918();
    if (p) { p->b1 = 1; p->w4 = 0; p->w18 = 0; p->w1C = 0; p->w20 = 0; p->b2 = 0; p->w8 = 0; p->w2C = 0x200; p->b0 = 1; }
    return p;
}

typedef signed char s8;
extern s8 D_00478E78[];
extern void func_003F63E0(void *);
void func_003F6408(void) {
    s32 i;
    s8 *p = D_00478E78;
    for (i = 7; i >= 0; i--) {
        if (*p == 1) func_003F63E0(p);
        p += 0x30;
    }
}

extern s32 func_00106E68(void *, s32, s32, void *, s32, void *, s32, void *, s32);
extern char D_00487FA0[];
extern s32 D_0062FEC0[4];
extern s32 D_0062FFC0[];
s32 func_004090D8(s32 a, s32 b, s32 c, s32 d) {
    D_0062FEC0[0] = a; D_0062FEC0[1] = b; D_0062FEC0[2] = c; D_0062FEC0[3] = d;
    func_00106E68(D_00487FA0, 2, 0, D_0062FEC0, 0x10, D_0062FFC0, 4, 0, 0);
    return D_0062FFC0[0];
}
