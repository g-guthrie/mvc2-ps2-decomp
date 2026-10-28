/* MW 3.0: ./try30.sh src/r4_22_b.c "-O3 -Op -sdatathreshold 0". func_003578A0 is a static copy of the real callee (n0op.c). */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef struct { u8 pad[0x1C]; s16 h1C; } SC;

typedef float f32;
extern s16 D_00462D80[];
extern s16 D_00462D82[];
static void func_003578A0(u8 *p) {
 f32 a, b, c, d;
 a = 1.666666627f * (f32)D_00462D80[p[0x21] * 2]; if (*(s16*)(p+0x140) != 0) a = -a;
 b = *(f32*)(*(u8**)(p+0x18) + 0x34); *(f32*)(p+0x34) = b; *(f32*)(p+0x34) = b + a;
 c = 2.142857075f * (f32)D_00462D82[p[0x21] * 2]; *(f32*)(p+0x38) = *(f32*)(*(u8**)(p+0x18) + 0x38) + c;
}
extern void func_00358430();

void residual_00358080(u8 *p)
{
    extern void func_00357830(u8 *);

    extern s8 func_00175700();
    u8 *o;
    u32 t;
    func_00357830(p);
    if ((t = p[5]) == 0) {
        o = *(u8 **)(p + 0x18);
        if (o[0x169] != 0x15 || o[0x168] < 6 || o[0x168] > 0xD) { p[4]++; func_00358430(p); return; }
        if (o[0x169] == 0x15 && o[0x168] >= 0xA && o[0x168] < 0xE) {
            p[5] = t + 1;
        }
        p[7] = 0;
        func_003578A0(p);
        {
            s16 v = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = v;
            if (v <= 0 && p[6] < 0xB) {
                ((SC *)p)->h1C = 1;
                p[6]++;
                return;
            }
        }
        return;
    }
    func_003578A0(p);
    if (func_00175700() < 0) {
        func_00358430(p);
    }
}
