typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct FS {
    u8 _p0[0x7];
    u8 b7;
    u8 _p1[0x8];
    u32 w10;
    u8 _p2[0x4];
    struct FS * w18;
    s16 h1c;
    u8 _p3[0x5];
    u8 b23;
    u8 _p4[0x10];
    f32 f34;
    f32 f38;
    u8 _p5[0x8];
    u32 w44;
    u8 _p6[0x8];
    f32 f50;
    f32 f54;
    u8 _p7[0x4];
    f32 f5c;
    f32 f60;
    u8 _p8[0x20];
    u32 w84;
    u8 _p9[0x44];
    s16 hcc;
    u8 _p10[0x2];
    u32 wd0;
    u8 _p11[0x4];
    u32 wd8;
    s32 wdc;
    u8 _p12[0x5C];
    u8 b13c;
    u8 _p13[0x3];
    s16 h140;
    u8 _p14[0xA];
    u8 b14c;
    u8 _p15[0x1];
    u8 b14e;
} FS;

extern s32 D_004C2838;
extern s32 fptosi(f32);

void func_0015EAA0(FS *p)
{
    extern FS *func_003DA750(s32, s32, s32);
    extern void func_0015E800();
    extern s32 func_00174170();
    extern s32 func_00417A40();
    FS *o;
    u32 i;
    s32 r, x, t;

    for (i = 0; (u8)i < 5; i = (u8)(i + 1)) {
        if ((o = func_003DA750(0, 0x2D, 1)) == 0) return;
        o->b13c = 0;
        o->w10 = (u32)func_0015E800;
        o->wd0 = 0x800025;
        o->b23 = i;
        o->f50 = 1.0f;
        o->f54 = 1.0f;
        o->wd8 = o->b23 << 3;
        o->w18 = p;
        o->w44 = (p->h140 != 0) ? 0x8000 : 0;
        o->wdc = func_00174170();
        o->wdc = o->wdc % 2;
        if (o->wdc != 0) {
            o->hcc = 0x1D;
            o->w84 = D_004C2838;
        } else {
            o->hcc = 0x1D;
            o->w84 = D_004C2838;
        }
        r = func_00417A40();
        x = fptosi(1.6666666269302368f * (f32)(u32)p->b14e * p->f50);
        if (r % 2 != 0) {
            t = r % x;
        } else {
            t = -(r % x);
        }
        o->f5c += (f32)t;
        r = func_00417A40();
        x = fptosi(2.142857074737549f * (f32)(u32)p->b14c * p->f54);
        o->f60 += (f32)(r % x);
        o->f34 = p->f34 + o->f5c;
        o->f38 = p->f38 + o->f60;
        o->b7 = 4;
        o->h1c = 2;
    }
}
