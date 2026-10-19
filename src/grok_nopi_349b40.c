/* Metrowerks 3.0: ./try.sh src/grok_nopi_349b40.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef float f32;

extern int func_001757E0(u8 *, int, int);
extern int func_00175700(u8 *);
extern u8 *func_00348EB0(u8 *);
extern void func_001E7F60(u8 *);
extern u16 D_004D18DC;
extern u8 D_004D18DB;

void func_00349B40(u8 *p, u8 *q)
{
    u8 *r = *(u8 **)(p + 20);

    if (*(u16 *)(q + 0x168) != *(u16 *)(p + 0x88)) {
        p[5]++;
        p[0x169] = 22;
        p[0x168] = 38;
        func_001757E0(p, p[0x169], p[0x168]);
        return;
    }
    *(f32 *)(p + 52) = *(f32 *)(r + 52) + *(f32 *)(p + 92);
    *(f32 *)(p + 56) = *(f32 *)(r + 56) + *(f32 *)(p + 96);
    if ((D_004D18DC & (1 << D_004D18DB)) == 0) {
        func_00175700(p);
        if (*(s8 *)(p + 0x150) != 0) {
            u8 *n;
            p[0x150] = 0;
            n = func_00348EB0(p);
            if (n != 0) {
                *(u8 **)(*(u8 **)(r + 20) + 20) = n;
                *(u8 **)(r + 20) = n;
            }
        }
        func_001E7F60(p);
    }
}
