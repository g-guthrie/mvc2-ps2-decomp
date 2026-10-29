/* func_00352740: MW 3.0 (try30.sh) "-O3 -Op -sdatathreshold 8". The b[8] store takes a u8 local z chained off the earlier b[2] = 0 store (z = b[2] = 0;), which keeps retail's andi v1,zero,0xFF in the bnez slot. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;
typedef struct { u8 pad[0x24]; s8 f24; } A24;

void func_00352740(u8 *o, u8 *b) {
    extern void func_0019A4C0(u8 *, s32);
    extern u8 *func_003DA750(u8 *, s32, s32);
    extern void func_00352950(u8 *, u8 *);
    u8 *par;
    u8 *n;
    u32 t; u8 z;
    t = o[4];
    o[4] = t + 1;
    par = *(u8 **)(o + 0x18);
    *(B3c *)(o + 0xEC) = *(B3c *)(par + 0xEC);
    o[0x13C] = 1;
    o[2] = par[2];
    o[1] = par[1];
    *(f32 *)(o + 0x50) = *(f32 *)(par + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(par + 0x54);
    o[0x1B7] = par[0x1B7];
    o[0x1B8] = par[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(par + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(par + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(par + 0x24);
    o[0x14F] = 0x40;
    o[0x14E] = 0x40;
    o[0x14D] = 0x40;
    o[0x14C] = 0x40;
    if (o[0x20] == 0) {
        ((A24 *)o)->f24 = ((A24 *)par)->f24 - 1;
        *(s8 *)(o + 0x31) = -1;
        b[0] = 0;
        b[1] = 4;
        b[4] = 0;
        b[5] = 2;
        b[3] = 0;
        b[6] = 0;
        z = b[2] = 0;
        b[0x2C] = 1;
        b[0x2B] = 1;
        o[0x22] = par[0x2B8];
        *(s8 *)(b + 0xA) = *(s8 *)(par + 0x2BA);
        if (b[0xB] == 0) {
            b[0x2A] = 0; b[8] = z;
            func_0019A4C0(o, 5);
        } else if (par[0x169] == 0xF) {
            b[0x2A] = 0;
            func_0019A4C0(o, 6);
        }
        if ((n = func_003DA750(o, 1, 2)) != 0) {
            *(s32 *)(n + 0x10) = *(s32 *)(o + 0x10);
            n[0x20] = 1;
            *(s8 *)(n + 0x24) = *(s8 *)(o + 0x24);
            *(s8 *)(n + 0x31) = -2;
            *(s32 *)(n + 0x18) = *(s32 *)(o + 0x18);
            *(s16 *)(n + 0x26) = 0x601;
            *(u8 **)(n + 0x94) = o;
            n[0x8C] = 0xFF;
            n[0x8B] = 0xFF;
        }
    }
    o[0x22] = par[0x22];
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    b[7] = 0;
    *(s8 *)(o + 0x31) = -1;
    func_00352950(o, b);
}
