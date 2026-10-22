typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern s32 D_004F1CB8;

void func_0022A5C0(u8 *p) {
    extern u32 func_00174170();
    extern void func_00154850(V3 *, s32, s32, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_00191480(u8 *, u8 *, s32);
    extern void func_00126400();
    V3 v;
    u8 *q;
    s16 h;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    D_004F1CB8 = 2;
    h = *(s16 *)(p + 0x1E) + 0x4000;
    *(s16 *)(p + 0x1E) = h;
    if (h == 0) {
        v = *(V3 *)(p + 0x34);
        v.x += 1.6666666269302368f * (f32)(s16)((u8)func_00174170() - 0x80);
        v.y += 2.142857074737549f * (f32)(s16)((func_00174170() & 0x7F) + 0x20);
        func_00154850(&v, *(s16 *)(p + 0x140), 1, 0);
        if (func_00174170() & 1) {
            func_001E3710(p, 0);
        } else {
            func_001E3710(p, 1);
        }
    }
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h <= 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0x40;
        q = *(u8 **)(p + 0x1DC);
        func_00191480(q, p, 0xE);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 8;
        q[0x20D] = 0;
        p[0x1B5] = 0x23;
        q[0x1B5] = 0x23;
        func_00126400();
        D_004F1CB8 = 0;
    }
}
