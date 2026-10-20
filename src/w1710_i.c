typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

typedef struct { s32 x[49]; } B9;



void func_001B0060(u8 *p) {
    extern void func_001754A0();
    u8 *q;
    f32 c;
    u32 t = p[4];
    p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    *(B9 *)(p + 0xEC) = *(B9 *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x13C] = 1;
    p[0x24] = 0xF;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    if (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) c = 110.0f; else c = -110.0f;
    *(f32 *)(p + 0x34) += c;
    *(f32 *)(p + 0x38) -= 17.142856597900391f;
    *(s16 *)(p + 0x1C) = 0x78;
    func_001754A0(p, 0x1B, 0xA);
}

void func_0034FDA0(u8 *p) {
    extern void func_001757E0();
    f32 c;
    p[0x13C] = 1;
    *(B9 *)(p + 0xEC) = *(B9 *)(*(u8 **)(p + 0x18) + 0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    *(s16 *)(p + 0x140) = *(s16 *)(*(u8 **)(p + 0x18) + 0x140);
    p[0x24] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (*(s16 *)(p + 0x140) != 0) c = 10.0f; else c = -10.0f;
    *(f32 *)(p + 0x5C) = c;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0xC0092492;
    *(u32 *)(p + 0x6C) = 0x3E092492;
    func_001757E0(p, 0x12, 2);
}

void func_001DFBD0(u8 *p, u8 *q) {
    extern void func_001757E0();
    extern void func_001E3210();
    extern void func_003DAA40();
    u8 t = p[4];
    if (t == 0) {
        p[4] = t + 1;
        *(B9 *)(p + 0xEC) = *(B9 *)(q + 0xEC);
        p[0x13C] = 1;
        p[2] = q[2];
        p[1] = q[1];
        *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
        p[0x1B7] = q[0x1B7];
        p[0x1B8] = q[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
        *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
        *(u16 *)(p + 0x1C) = *(u16 *)(q + 0x168);
        *(s8 *)(p + 0x31) = -8;
        func_001757E0(p, 0x12, (u8)(p[0x21] + 7));
        func_001E3210(q, 0x1F);
    }
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    if (*(s16 *)(p + 0x1C) != *(u16 *)(q + 0x168)) func_003DAA40(p);
}
