typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern u8 *D_004D18B8[][3];
extern u8 *D_004D18C0[][3];

void func_003273A0(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern void func_0018FFB0(u8 *);
    extern void func_00126400(void);
    extern void func_00186A60(u8 *, s32);
    extern void func_00191210(u8 *);
    extern void func_00185490(u8 *);
    extern void func_00186800(u8 *);
    extern void func_00180D20(u8 *, u8 *);
    extern void func_00183630(u8 *);
    extern void func_001913C0(u8 *);
    u8 *o, *a;
    s16 x;
    o = D_004D18B8[p[2]][p[0x26B]];
    if (*(s16 *)(o + 0x434) > 0 && *(s16 *)(o + 0x2B4) == 0) {
        func_001E3710(p, 0x51);
        func_0018FFB0(p);
        func_00126400();
        o[0] = 1;
        o[0x13C] = 0;
        o[4] = 1;
        o[5] = 0;
        o[7] = 0;
        o[6] = 0;
        func_00186A60(o, 0x1C);
        o[0x26A] = 8;
        o[0x269] = 6;
        o[0x404] = 0xFF;
        o[0x405] = 0x10;
        o[0x1B1] = 0;
        o[0x201] = 3;
        o[0x40D] = 0;
        o[0x40C] = 0;
        o[0x425] = 0;
        a = D_004D18C0[p[2]][0];
        if (*(s16 *)(a + 0x434) == 0) {
            p[0x425] = p[0x26B];
        } else {
            a[0x425] = 1;
            p[0x425] = 2;
        }
        p[4] = 1;
        p[5] = 0;
        p[7] = 0;
        p[6] = 0;
        func_00186A60(p, 0x1C);
        p[0x26A] = 2;
        p[0x1B1] = 0;
        p[0x201] = 3;
        func_00191210(p);
        *(V3 *)(o + 0x34) = *(V3 *)(p + 0x34);
        x = p[0x1E6];
        *(s16 *)(o + 0x140) = x;
        o[0x1E6] = x;
        o[0x211] = *(s8 *)(p + 0x211);
        o[0x159] = 0xFF;
        func_00185490(o);
        func_00186800(o);
        func_00180D20(o, p);
        func_00183630(o);
        func_001913C0(o);
    }
}
