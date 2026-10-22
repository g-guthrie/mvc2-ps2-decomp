typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks: ./try.sh src/w20b2_k.c "-O3 -Op -sdatathreshold 8" */
extern f32 D_0061BDA0[], D_0061BDB4[], D_0061BDC8[], D_0061BDD0[], D_0061BDD4[], D_0061BDD8[], D_0062BC30[];
extern u32 D_0061BDDC[];
extern f32 D_004C2A8C;
extern f32 D_004C2A88;

void func_003DD930(s32 a, s32 b, s32 c, s32 d, f32 e, f32 g) {
    extern void func_003DD260(f32 *);
    f32 hc = c / 2;
    f32 hd = d / 2;
    func_003DD260(D_0061BDA0);
    D_0061BDD8[0] = e;
    D_0061BDDC[0] = 0x3F800000;
    D_0061BDA0[0] = hc;
    D_0061BDC8[0] = g - e;
    D_0061BDD0[0] = a + hc;
    D_0061BDD4[0] = b + hd;
    D_0061BDB4[0] = -hd;
    D_0061BDC8[0] = D_0061BDC8[0] * (0.5f * -D_0062BC30[0]);
    D_0061BDD8[0] = 0.5f * D_0062BC30[0];
    D_0061BDD0[0] = D_004C2A8C;
    D_0061BDD4[0] = D_004C2A88;
}
