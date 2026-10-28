typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3b;
typedef struct { u8 pad[0x1C]; s16 h1c; } P3b;

void residual_0037B4B0(u8 *o, u8 *q) {
    extern s32 func_00417A40(void);
    extern void func_001754A0(u8 *, s32, s32);
    u32 t;
    s32 v;
    o[0x13C] = 0;
    if ((v = *(s16 *)(o + 0x1C)) != 0) {
        ((P3b *)o)->h1c = v - 1;
        return;
    }
    *(B3b *)(o + 0xEC) = *(B3b *)(q + 0xEC);
    o[0x13C] = 1;
    o[2] = q[2];
    o[1] = q[1];
    *(f32 *)(o + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(q + 0x54);
    o[0x1B7] = q[0x1B7];
    o[0x1B8] = q[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(q + 0x24);
    o[0x24] = 0;
    t = o[4];
    o[4] = t + 1;
    *(s16 *)(o + 0x1C) = 8;
    *(V3 *)(o + 0x34) = *(V3 *)(q + 0x34);
    *(s32 *)(o + 0xD4) = func_00417A40();
    *(s32 *)(o + 0xD4) = *(s32 *)(o + 0xD4) % 360;
    *(u32 *)(o + 0x48) = (u32)(s32)(0.5 + 65536.0 * (double)(*(s32 *)(o + 0xD4)) / 360.0) & 0xFFFF;
    *(u32 *)(o + 0x54) = *(u32 *)(o + 0x50) = 0x3F800000;
    if (*(s32 *)(o + 0xD4) % 2 != 0) {
        func_001754A0(o, 0x1B, 0xE);
    } else {
        func_001754A0(o, 0x1B, 0xF);
    }
}


