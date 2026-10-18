typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern s8 D_00583BC8[];
typedef struct { u8 pad0[4]; s8 f4; u8 pad5[0x83]; s8 f88; u8 pad89[7]; s8 f90; s8 f91; s8 f92; } S197e;
extern S197e *D_004C2840;
extern void (*D_0045E2E0[])(void);
extern void func_00152570(void);
extern void func_00152660(void);
extern void func_0016E960(void);
extern void func_003DA6F0(s32);
extern void func_003D7310(void (*)(void));

void func_0032C230(void) {
    S197e *p, *r;
    s8 *q;
    if (D_00583BC8[0] != 0) {
        func_0016E960();
    } else {
        p = D_004C2840;
        q = (s8 *)((s32)p + 0x90);
        if (p->f90 != 0) {
            D_00583BC8[0] = 1;
            p->f88 = *q ^ 3;
            D_004C2840->f91 = 0;
            D_004C2840->f92 = 0;
        } else {
            D_0045E2E0[p->f4]();
        }
        func_003DA6F0(6);
        func_003DA6F0(8);
        func_003DA6F0(1);
    }
    r = D_004C2840;
    if (r->f90 != 0) {
        if (r->f92 < 2) {
            func_003D7310(func_00152570);
        }
        func_003D7310(func_00152660);
    } else {
        func_003D7310(func_00152570);
    }
}
