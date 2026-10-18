typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3_00198460;
extern void func_001754A0();
void func_00198460(u8 *a, u8 *b) {
    s32 n;
    s32 *d;
    s32 *s;
    u8 *t0;
    s = (s32 *)(b + 0xEC);
    t0 = *(u8 **)(a + 0x14);
    d = (s32 *)(a + 0xEC);
    n = 49;
    do {
        *d = *s;
        n--;
        s++;
        d++;
    } while (n > 0);
    a[0x13C] = 1;
    a[2] = b[2];
    a[1] = b[1];
    *(f32 *)(a + 0x50) = *(f32 *)(b + 0x50);
    *(f32 *)(a + 0x54) = *(f32 *)(b + 0x54);
    a[0x1B7] = b[0x1B7];
    a[0x1B8] = b[0x1B8];
    *(s8 *)(a + 0x30) = *(s8 *)(b + 0x30);
    *(V3_00198460 *)(a + 0x50) = *(V3_00198460 *)(b + 0x50);
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
    *(s16 *)(a + 0x140) = *(s16 *)(t0 + 0x140);
    *(f32 *)(a + 0x34) = *(f32 *)(t0 + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(t0 + 0x38);
    func_001754A0(a, 0x1B, 3);
}

