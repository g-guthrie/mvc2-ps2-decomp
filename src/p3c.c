typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_0011D8F8(void *, s32, s32);
extern u8 D_00490DA8[];
extern s32 D_004C24D8;

void func_0040F598(void) {
    if (--D_004C24D8 == 0) func_0011D8F8(D_00490DA8, 0, 0x4000);
}

typedef struct { s8 b; u8 pad[63]; } E400258;
extern E400258 D_00484AC0[];
extern s32 D_004C23AC;
extern s32 D_004C23A8;
extern void func_00400148(E400258 *, s32, s32, s32, s32);

E400258 *func_00400258(s32 a, s32 b, s32 c, s32 d) {
    E400258 *p = 0;
    s32 i;
    for (i = 0; i < D_004C23AC; i++) {
        p = &D_00484AC0[D_004C23A8 + i];
        if (p->b == 0) break;
    }
    if (i == D_004C23AC) return 0;
    func_00400148(p, a, b, c, d);
    return p;
}
