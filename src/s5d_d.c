/* s5d: MW 3.0.3, ./try.sh src/s5d_d.c "-O3 -sdatathreshold 8". static func_003CAB00 is the real callee and address predecessor (credited in src/byte_setter_pairs.c). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00174470(u8 *);
static void func_003CAB00(u8 *p, u8 *owner) { p[316] = 0; p[4] = 3; }
extern void func_003CAB20(u8 *, u8 *, s32);
extern s32 func_00174170(void);
extern void func_001E3210(u8 *, u8);
extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, u8);
extern void func_001E7F60(u8 *);

void func_003CB790(u8 *p, u8 *q)
{
    s32 r;
    if (*(s16 *)(p + 0x1C) > 0) {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v <= 0) p[0x23] = 1;
    }
    if (func_00174470(p) == 0) {
        p[0x13C] = 0;
        if (p[0x23] != 0) {
            func_003CAB00(p, q);
            return;
        }
    } else {
        p[0x13C] = 1;
        if (*(s16 *)(p + 0x1E) != 0) {
            *(s16 *)(p + 0x1E) = 0;
            r = func_00174170();
            func_001E3210(p, (u32)r % 6 + 0x16);
        }
    }
    *(volatile s32 *)(q + 0x2B8) = 4;
    if (*(s8 *)(p + 0x1B3) != 0) {
        func_003CAB20(p, q, p[0x21] == 0x1C ? 0x16 : 8);
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    {
        f32 d = *(f32 *)(q + 0x34) - *(f32 *)(p + 0x34);
        if (*(s16 *)(p + 0x140) == 0) d = -d;
        if (d < 0.0f) {
            if (*(s8 *)(p + 0x151) != 0) {
                u32 t;
                s32 v = 0x14;
                if (p[0x20] == 0) v = 2;
                p[0x23] = 1;
                *(s16 *)(q + 0x1C) = v;
                t = p[0x168];
                func_001757E0(p, 0x17, t + 1);
            }
        }
    }
    func_001E7F60(p);
}
