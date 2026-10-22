typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 a, b, c; } Ro;
extern Ro D_004A6A60[];
extern u8 D_004BEE18[];
extern u8 D_004BEE20[];
extern u8 D_004BEE30[];
extern s32 D_004C2B54;

void func_004189A0(void) {
    extern s32 func_004188F0();
    extern void func_0011F938(u8 *, u8 *, s32);
    extern s32 func_003FBE88(s32, u8 *, s32, s32);
    extern void func_00120288(u8 *, u8 *, s32);
    extern void func_00418B10();
    extern s32 func_003FC090(s32);
    u8 buf[0x40];
    s32 i, r;
    Ro *p;
    p = D_004A6A60;
    i = 0;
top:
    if (i == 0 || func_004188F0() == 0) {
        func_0011F938(buf, D_004BEE18, p->a);
    } else {
        func_0011F938(buf, D_004BEE20, p->a);
    }
    if (func_003FBE88(i, (u8 *)((s32)buf + 0), 0, p->b) < 0) {
        func_00120288(buf, D_004BEE30, 3);
        goto top;
    }
    for (;;) {
        func_00418B10();
        r = func_003FC090(i);
        if (r == 3) break;
        if (r == 4) goto top;
    }
    i++;
    p++;
    if (i < 4) goto top;
    D_004C2B54 = 0;
}
