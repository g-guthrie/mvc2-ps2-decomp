/* Metrowerks 3.0: ./try.sh src/grok_nopi_349970.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef float f32;

extern int func_001757E0(u8 *, int, int);
extern void func_00175910(u8 *, int, int, int);
extern int func_00174470(u8 *);
extern void func_001E7F60(u8 *);
extern u16 D_004D18DC;
extern u8 D_004D18DB;

void func_00349970(u8 *p, u8 *q)
{
    u8 *r = *(u8 **)(p + 20);

    if (*(u16 *)(q + 0x168) != *(u16 *)(p + 0x88)) {
        p[5]++;
        p[0x169] = 22;
        p[0x168] = 33;
        func_001757E0(p, p[0x169], p[0x168]);
        return;
    }
    if (r[4] >= 2) {
        p[4]++;
        p[0x13C] = 0;
        return;
    }
    if (r[32] == 0)
        *(f32 *)(p + 52) = *(f32 *)(r + 52) + *(f32 *)(p + 92);
    else
        *(f32 *)(p + 52) = *(f32 *)(r + 52) + *(f32 *)(p + 104);
    *(f32 *)(p + 56) = *(f32 *)(r + 56);
    if ((D_004D18DC & (1 << D_004D18DB)) == 0) {
        p[0x169] = 22;
        p[0x168] = 30;
        func_00175910(p, p[0x169], p[0x168], *(s8 *)(r + 0x151));
        if (func_00174470(p) == 0) {
            p[4]++;
            p[0x13C] = 0;
        } else
            func_001E7F60(p);
    }
}
