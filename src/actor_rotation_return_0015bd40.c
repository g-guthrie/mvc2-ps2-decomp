typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[4]; u8 b4; u8 b5; u8 pad1[0x16]; s16 a; u8 pad2[0x28]; u32 w48; } PN;

typedef struct {u8 prefix[0x140];union {s16 value;s8 bytes[2];} facing;} RotationOwner;
static s32 func_0015BA00(u8 *a0, u8 *a1) {
    RotationOwner *owner=(RotationOwner *)a1;
    s16 v = owner->facing.value;
    s32 ret;
    if (v != a0[7]) {
        a0[5] = (u8)v;
        ret = 1;
        a0[7] = (u8)owner->facing.bytes[0];
    } else {
        a0[7] = (u8)v;
        ret = 0;
    }
    return ret;
}
void func_0015BD40(u8 *raw, u8 *q) {
    PN *p = (PN *)raw;
    extern s32 fptosi(f32);
    raw[0x13C] = 1;
    func_0015BA00(raw, q);
    if (p->b5 != 0) {
        f32 c = 10.0f; f32 d = (f32)p->a; p->a = fptosi(d + c);
        if (p->a >= 0) {
            p->a = 0;
            p->b4 = 0;
        }
        p->w48 = (u16)((u32)(s32)(0.5 + 65536.0 * (double)p->a / 360.0));
    } else {
        p->a = fptosi((f32)p->a - 10.0f);
        if (p->a < -179) {
            p->a = -180;
            p->b4 = 0;
        }
        p->w48 = (u16)((u32)(s32)(0.5 + 65536.0 * (double)p->a / 360.0));
    }
}
