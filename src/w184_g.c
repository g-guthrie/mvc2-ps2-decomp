typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

void func_003AE740(u8 *p)
{
    extern void func_003AE8A0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00175700(u8 *);
    s32 i;
    u32 *d;
    u32 *s;
    u8 *q;
    q = *(u8 **)(p + 0x18);
    if (*(u16 *)(q + 0x168) != *(s16 *)(p + 0x1C)) {
        func_003AE8A0(p);
        return;
    }
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    if (p[4] == 0) {
        p[4]++;
        s = (u32 *)(q + 0xEC);
        d = (u32 *)(p + 0xEC);
        i = 0x31;
        do {
            *d++ = *s++;
            i--;
        } while (i > 0);
        p[0x13C] = 1;
        p[2] = q[2];
        p[1] = q[1];
        *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
        p[0x1B7] = q[0x1B7];
        p[0x1B8] = q[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
        *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        if (p[0x21] == 0) {
            p[0x168] = 0xD;
            p[0x24] = 0;
        } else {
            p[0x168] = 0xE;
            p[0x24] = 7;
        }
        func_001757E0(p, 0x17, p[0x168]);
    } else {
        func_00175700(p);
    }
}
