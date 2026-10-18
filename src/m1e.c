typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00189310(void *, void *, void *);
extern u8 D_004580A0[], D_00450A50[];

s32 func_0029B970(u8 *p) {
s32 r;
if (func_00189310(p, D_004580A0, p + 0x388) == 0) {
return 0;
}
if (**(s8 **)(p + 0x420) <= 0) {
r = 0;
} else {
r = 1;
p[0x26C] = 3;
}
return r;
}
s32 func_00210BF0(u8 *p) {
    s32 r;
    if (func_00189310(p, D_00450A50, p + 0x380) == 0) {
        return 0;
    }
    if (**(s8 **)(p + 0x420) == 0) {
        r = 0;
    } else if (p[0x20D] == 2) {
        r = 0;
    } else {
        r = 1;
        p[0x26C] = 1;
    }
    return r;
}
