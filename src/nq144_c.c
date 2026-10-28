typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;

typedef struct { u8 pad[0x38]; f32 f38; u8 pad3c[0x50 - 0x3C]; f32 f50; f32 f54; } F382;

extern u8 D_004645F0[];
extern s8 data_s8_004ACD08[];

void residual_00382240(u8 *o) {
    extern s32 func_00174170(void);
    extern void func_001754A0(u8 *, s32, s32);
    extern void func_00382420(u8 *);
    u8 *s;
    u32 t;
    f32 k;

    t = o[4];
    o[4] = t + 1;
    s = *(u8 **)(o + 0x18);
    *(B3c *)(o + 0xEC) = *(B3c *)(s + 0xEC);
    o[0x13C] = 1;
    o[2] = s[2];
    o[1] = s[1];
    *(f32 *)(o + 0x50) = *(f32 *)(s + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(s + 0x54);
    o[0x1B7] = s[0x1B7];
    o[0x1B8] = s[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(s + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(s + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(s + 0x24);
    o[0x22] = D_004645F0[func_00174170() & 0xF];
    o[0x24] = 0;
    *(V3 *)(o + 0x34) = *(V3 *)(s + 0x5C);
    k = 0.6000000238418579f;
    *(f32 *)(o + 0x50) *= k;
    *(f32 *)(o + 0x54) *= k;
    if (!(*(f32 *)(o + 0x38) <= *(f32 *)(s + 0x430))) {
        k = 0.800000011920929f;
        ((F382 *)o)->f50 *= k;
        ((F382 *)o)->f54 *= k;
        o[0x13D] = 1;
        *(s16 *)(o + 0x13E) = data_s8_004ACD08[o[0x1B8]] + 2;
    } else {
        k = 1.2000000476837158f;
        ((F382 *)o)->f50 *= k;
        ((F382 *)o)->f54 *= k;
    }
    *(u32 *)(o + 0x48) = (o[0x22] << 11) & 0xFFFF;
    func_001754A0(o, 0x1B, 1);
    func_00382420(o);
}
