typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_003AF160();

void func_003AF110(u8 *p, u8 *q) {
    u8 *c = p;
    s32 i;
    for (i = 0; i < *(s8 *)(q + 0x28) + 4; i++) {
        u32 t = c[5];
        c[5] = t + 1;
        c = *(u8 **)(c + 0xC);
    }
    func_003AF160(p, q);
}

extern u8 *func_003DA750(s32, s32, s32);
extern void func_0019FCE0();

s32 func_0019FC30(u8 *a, s32 b) {
    s32 i = 0;
    s32 n = 0;
    u8 *o;
    u32 t;
    do {
        if ((o = func_003DA750(0, 3, 1)) != 0) {
            *(void (**)())(o + 0x10) = func_0019FCE0;
            *(s16 *)(o + 0x26) = 0xC00;
            o[0x20] = b;
            o[0x21] = i >> 1;
            if (i & 1) {
                o[0x21] |= 0x80;
            }
            *(u8 **)(o + 0x14) = a;
            t = *(u32 *)(a + 0x18);
            n++;
            *(u32 *)(o + 0x18) = t;
        }
        i++;
    } while (i < 8);
    return n;
}
