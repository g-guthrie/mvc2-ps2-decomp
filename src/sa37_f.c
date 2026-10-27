typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct SA37_V3 { f32 x, y, z; } SA37_V3;

typedef struct SA37_N0 {
    u8 pad0[0x10];
    void (*w10)(u8 *);
    u8 pad14[0x20 - 0x14];
    u8 b20;
    u8 b21;
    u8 pad22[0x34 - 0x22];
    SA37_V3 pos;
    u8 pad40[0x50 - 0x40];
    SA37_V3 v50;
    u8 pad5c[0x78 - 0x5C];
    SA37_V3 v78;
    s32 w84;
    u8 pad88[0xCC - 0x88];
    s16 hcc;
    u8 padce[2];
    s32 wd0;
    u8 padd4[0x13C - 0xD4];
    u8 b13c;
} SA37_N0;

extern s32 D_004C27FC;
extern SA37_V3 D_00443E68[];

void func_0014A700(s32 n, s32 count, SA37_V3 *pos, s32 flag, f32 sc, f32 vx, f32 vy, f32 vz) {
    extern s32 func_0014A680(s32, s32);
    extern SA37_N0 *func_003DA750(s32, s32, s32);
    extern void func_0014A8B0(u8 *);
    s32 i;
    s32 d;
    s32 first;
    SA37_N0 *o;
    first = 0;
    for (i = 0; i < count; i++) {
        d = n / func_0014A680(10, count - i - 1);
        if (flag != 0 || d != 0 || first != 0 || i == count - 1) {
            d = d % 10;
            first = 1;
            if ((o = func_003DA750(0, 0xD, first)) == 0) return;
            o->b13c = first;
            o->w10 = func_0014A8B0;
            o->hcc = d + 0x25;
            o->w84 = D_004C27FC;
            o->wd0 = 0x411;
            o->b20 = flag;
            o->b21 = i;
            o->pos = *pos;
            o->pos.x += (f32)i * sc;
            o->v50 = *D_00443E68;
            o->v78.x = vx;
            o->v78.y = vy;
            o->v78.z = vz;
        }
    }
}
