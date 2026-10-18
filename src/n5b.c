typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
#define F32(p, o) (*(f32 *)((p) + (o)))
#define U32(p, o) (*(u32 *)((p) + (o)))
#define S16(p, o) (*(s16 *)((p) + (o)))
#define S8(p, o) (*(s8 *)((p) + (o)))
typedef struct { f32 x, y, z; } V3;
extern s32 func_00175700(u8 *p);
extern void func_001843A0(u8 *p);
extern s32 func_00189310(u8 *p, void *a, void *b);
extern void func_00186A60(u8 *p, s32 a);
extern u8 D_00454F30[];
extern void func_0018A990(u8 *p, u8 *q);
extern void func_00257CC0(u8 *p);
extern u8 D_00458EA0[];

s32 func_0027ADC0(u8 *p) {
    if (!func_00189310(p, D_00454F30, p + 0x378)) {
        return 0;
    }
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

s32 func_002B2BC0(u8 *p) {
    s32 v;
    if (!func_00189310(p, D_00458EA0, p + 0x3D0)) {
        return 0;
    }
    v = S8(p, 0x1E8);
    if (v) {
        return 0;
    }
    v++;
    p[0x1E8] = v;
    func_0018A990(p, p + 0x3D0);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0xD;
    func_00186A60(p, 0x15);
    return 1;
}

void func_002572D0(u8 *p) {
    switch (p[0x1FC]) {
    case 3:
        func_00257CC0(p);
        break;
    case 4:
        func_00257CC0(p);
        break;
    case 0:
    case 1:
    case 2:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        }
        break;
    }
}
