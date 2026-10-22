typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z, w; } V4;

extern s32 D_004F1CB8;

static void func_002555E0(u8 *p) {
    if (*(s16 *)(p + 696) > 0) {
        p[1037] = 0;
        p[1036] = 0;
        p[828] = 5;
    } else {
        p[1036] = 2;
        p[828] = 5;
    }
}

void func_0025A8D0(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    extern u32 func_00174170(void);
    extern void func_00154940(u8 *, V4 *, u8);
    extern void func_001E3710(u8 *, u8);
    extern void func_00191480(u8 *, u8 *, s32);
    extern void func_0018FC10(u8 *, s32);
    u8 *o;
    V4 v;
    s16 h;
    func_002555E0(p);
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    D_004F1CB8 = 2;
    h = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = h - 1;
    if (h == 0) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 0x50;
        func_001757E0(p, 0x16, 8);
    }
    if (*(s16 *)(p + 0x1C) % 9 == 1) {
        o = *(u8 **)(p + 0x1DC);
        v.x = 1.666666627f * (f32)(func_00174170() & 0x3F);
        v.y = 2.142857075f * (f32)(func_00174170() & 0x5F);
        func_00154940(o, &v, (func_00174170() & 7) + 9);
        func_001E3710(p, func_00174170() % 3 + 4);
        func_00191480(o, p, 1);
        func_0018FC10(o, -2);
    }
}
