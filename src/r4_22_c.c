/* MW 3.0.3: ./try.sh src/r4_22_c.c "-O3 -Op -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3c;
extern G3c *D_004C2794;

void func_003581A0(u8 *p) {
    extern void func_00358430();
    extern void func_00357940(u8 *);
    extern void func_00357A40();
    extern s8 func_00175700();
    extern void func_001E3210(u8 *, s32);
    extern void func_001E7F60(u8 *);
    u8 *o;
    u8 *r;
    u8 *f;
    u32 t;
    u32 c7;
    o = *(u8 **)(p + 0x18);
    if ((t = p[5]) == 0) {
        if (o[0x169] != 0x15 || o[0x168] < 6 || o[0x168] > 0xD) {
            p[4]++;
            func_00358430(p);
            return;
        }
        if (o[0x169] == 0x15 && o[0x168] >= 0xA && o[0x168] < 0xE) {
            p[5] = t + 1;
            func_001E3210(p, 0x2B);
        }
        if (*(s8 *)(p + 0x1B2) != 0) { f = *(u8 **)(p + 0x14) + 7; if (*f == 0) { *f = p[6]; r = *(u8 **)(p + 0x14); f = r + 0x23; if (*f > 1) { *f = *f - 1; p[0x1B5] = *(s8 *)(p + 0x21) + 0x34; p[0x1B2] = *(u16 *)(p + 0x1C0) = 0; *(s32 *)(p + 0x1D8) = 0; D_004C2794->f7c[p[2]]++; } } }
        if (*(f32 *)(p + 0x38) <= *(f32 *)(o + 0x430)) {
            r = *(u8 **)(p + 0x14);
            f = r + 7;
            if (r[7] == 0 && r[6] >= p[6]) *f = p[6];
        }
        func_00357940(p);
        func_00357A40();
        r = *(u8 **)(p + 0x14);
        c7 = r[7];
        if (c7 == 0 || (u8)c7 == p[6]) {
            if (r[6] >= p[6] && r[0x23] > 0) {
                func_001E7F60(p);
                return;
            }
        }
        return;
    }
    func_00357940(p);
    if (func_00175700() < 0) func_00358430(p);
}
