/* func_0037C2A0: MW 3.0 ./try30.sh src/s6c_e.c "-O3 -Op -sdatathreshold 0". Fix: func_0037CB60 really takes (p, q) (retail reads $a1 = q), so q lives in $a1 from the start. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef signed int s32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u16 h0, h2, h4, h6, h8; } ST;
typedef struct {
    u8 pad[0x2DC];
    s32 countdown;
    u8 pad2[0xC];
    s32 c2EC;
} Owner;

void func_0037C2A0(u8 *p)
{
    extern void func_0037CB50(u8 *);
    extern void func_0037CB60(u8 *, Owner *);
    extern s32 func_0037BDE0(u8 *);
    extern void func_0037C520(u8 *);
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    s32 v;
    f32 c;
    u32 t;
    ST *st;
    Owner *q;
    q = *(Owner **)(p + 0x18);
    st = (ST *)(p + 0xD0);
    p[0x24] = *(s8 *)((u8 *)q + 0x24);
    if (p[0x23] == 0) {
        *(s8 *)(p + 0x31) = -1;
    }
    *(V3 *)(p + 0x34) = *(V3 *)(*(u8 **)(p + 0x18) + 0x34);
    if (((u8 *)q)[0x20D] == 2) {
        c = *(s16 *)(p + 0x140) ? 182.0f : -182.0f;
        *(f32 *)(p + 0x34) += c;
        *(f32 *)(p + 0x38) += 170.0f;
    } else {
        c = *(s16 *)(p + 0x140) ? 182.0f : -182.0f;
        *(f32 *)(p + 0x34) += c;
        *(f32 *)(p + 0x38) += 170.0f;
    }
    *(f32 *)(p + 0x64) = *(f32 *)(p + 0x34);
    if (*(s16 *)(p + 0x140) != 0) {
        v = p[0x23] * 35;
    } else {
        v = -(p[0x23] * 35);
    }
    *(f32 *)(p + 0x34) += (f32)v;
    *(f32 *)(p + 0x70) = *(f32 *)(p + 0x38);
    if (p[1] != (*(u8 **)(p + 0x18))[1]) {
        func_0037CB50(p);
        return;
    }
    if (st->h0 != *(u16 *)(*(u8 **)(p + 0x18) + 0x168)) {
        p[4] = 2;
        p[0x13C] = 0;
    }
    if (p[0x23] == 0) {
        if (q->countdown != 0) {
            *(s32 *)((s32)q + 0x2DC) = 0;
        }
        t = st->h2;
        if (t != 0) {
            st->h2 = t - 1;
        } else {
            st->h2 = 8;
            q->c2EC += 1;
            q->c2EC = q->c2EC % 5;
            q->countdown = 1;
        }
    }
    if (p[0x23] % 3 == 0) {
        p[0x1B0] = 0x42;
        p[0x1B1] = 0x42;
        if (q->countdown != 0) {
            func_0037CB60(p, q);
        }
        func_001E7F60(p);
    }
    if (func_0037BDE0(p) == 0) {
        p[0x13C] = 1;
    } else {
        p[0x13C] = 0;
    }
    func_0037C520(p);
    func_00175700(p);
}
