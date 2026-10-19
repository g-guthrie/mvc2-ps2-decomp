/* Metrowerks 3.0: ./try.sh src/grok_ef_3584f0.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern s32 func_00174170(void);
extern int func_00175910(u8 *, s32, s32, s32);
extern void func_00358620(u8 *);

void func_003584F0(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    s32 r;
    u32 t = p[4];

    p[4] = t + 1;
    n = 0x31;
    q = *(u8 **)(p + 0x18);
    s = (s32 *)(q + 0xEC);
    d = (s32 *)(p + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;
    } while (n > 0);
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
    p[0x24] = 0;
    p[0x1B0] = 0x45;
    p[0x1B1] = 0;
    p[6] = 0;
    *(s16 *)(p + 0x1E) = 1;
    r = func_00174170();
    func_00175910(p, 20, 3, (u32)r % 18);
    func_00358620(p);
}
