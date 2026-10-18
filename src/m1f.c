typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern void func_0018ED20();
extern void func_0018EB00();
extern void func_001757E0(void *, s32, s32);

void func_0018F630(u8 *p) {
u8 *q = *(u8 **)(p + 0x1D0);
if (q != 0) {
if (q[1] & 0x40) {
func_0018ED20();
} else {
func_0018EB00();
}
} else {
func_0018EB00();
}
p[0x20D] = 2;
func_001757E0(p, 0xD, 0xA);
}

extern s32 func_00189310(void *, void *, void *);
extern void func_00186A60(void *, s32);
extern u8 D_0045BD60[];

s32 func_002F6E80(u8 *p) {
    s32 r;
    if (p[0x2CE] != 0) {
        return 0;
    }
    if (func_00189310(p, D_0045BD60, p + 0x3A0) == 0) {
        return 0;
    }
    if (**(s8 **)(p + 0x420) < 3) {
        r = 0;
    } else {
        p[5] = 0;
        p[7] = 0;
        p[6] = 0;
        p[0x1FD] = 4;
        func_00186A60(p, 0x1D);
        r = 1;
    }
    return r;
}
