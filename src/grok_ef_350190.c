/* Metrowerks 3.0: ./try.sh src/grok_ef_350190.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_001E3710(u8 *, s32);
extern int func_001757E0(u8 *, s32, s32);
extern void func_00350680(u8 *);

void func_00350190(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    f32 k;

    p[0x13C] = 1;
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
    k = 17.142856597900390625f;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    *(s16 *)(p + 0x140) = *(s16 *)(*(u8 **)(p + 0x18) + 0x140);
    p[0x24] = 0xB;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = k + *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    func_001E3710(p, 73);
    func_001757E0(p, 23, 24);
    func_00350680(p);
}
