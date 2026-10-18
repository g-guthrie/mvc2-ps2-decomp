typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern void func_001754A0(u8 *, s32, s32);
extern void func_001B8710(u8 *);

void func_001B8490(u8 *p) {
    s32 n;
    s32 *d;
    s32 *s;
    u32 t;
    f32 k;
    n = 0x31;
    t = p[4]; p[4] = t + 1;
    d = (s32 *)(p + 0xEC);
    s = (s32 *)(*(u8 **)(p + 0x18) + 0xEC);
    do {
        *d++ = *s++;
    } while (--n > 0);
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
    p[0x24] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    k = (*(s16 *)(p + 0x140) != 0) ? 1.6666666269302368f : -1.6666666269302368f;
    *(f32 *)(p + 0x5C) = k;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0xBF092492;
    func_001754A0(p, 0x1B, 10);
    func_001B8710(p);
}
