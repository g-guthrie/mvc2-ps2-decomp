typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } W31;

void func_0019CBC0(u8 *p) {
    extern void func_0019CB70(u8 *);
    extern void func_0019CCE0(u8 *);
    p[4]++;
    *(W31 *)(p + 0xEC) = *(W31 *)(*(u8 **)(p + 0x18) + 0xEC);
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
    p[0x13C] = 1;
    p[0x24] = 0xF;
    p[0x21] = 0xFF;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    func_0019CB70(p);
    func_0019CCE0(p);
}

void func_001B3300(u8 *p) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_001B3430();
    u8 *o;
    if ((o = func_003DA750(0, 3, 0)) != 0) {
        *(void **)(o + 0x10) = func_001B3430;
        *(u8 **)(o + 0x18) = p;
        *(W31 *)(o + 0xEC) = *(W31 *)(*(u8 **)(o + 0x18) + 0xEC);
        o[0x13C] = 1;
        o[2] = (*(u8 **)(o + 0x18))[2];
        o[1] = (*(u8 **)(o + 0x18))[1];
        *(f32 *)(o + 0x50) = *(f32 *)(*(u8 **)(o + 0x18) + 0x50);
        *(f32 *)(o + 0x54) = *(f32 *)(*(u8 **)(o + 0x18) + 0x54);
        o[0x1B7] = (*(u8 **)(o + 0x18))[0x1B7];
        o[0x1B8] = (*(u8 **)(o + 0x18))[0x1B8];
        *(s8 *)(o + 0x30) = *(s8 *)(*(u8 **)(o + 0x18) + 0x30);
        *(V3 *)(o + 0x50) = *(V3 *)(*(u8 **)(o + 0x18) + 0x50);
        *(s8 *)(o + 0x24) = *(s8 *)(*(u8 **)(o + 0x18) + 0x24);
        *(s16 *)(o + 0x26) = 0x1400;
        o[0x14D] = 0x20;
        o[0x14C] = 0x20;
        o[0x14F] = 0x24;
        o[0x14E] = 0x24;
        o[0x24] = 0;
        o[4] = 0;
        o[0x13C] = 0;
    }
}
