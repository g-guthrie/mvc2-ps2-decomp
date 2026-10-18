typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_003A5090(void);

void func_003A5000(u8 *p, s32 b, s32 c, s32 d) {
    u8 *r = func_003DA750(0, 1, 1);
    if (r != 0) {
        *(void **)(r + 0x10) = func_003A5090;
        *(s16 *)(r + 0x26) = 0x2E00;
        *(u32 *)(r + 0x18) = *(u32 *)(p + 0x18);
        *(u8 **)(r + 0x14) = p;
        r[1] = p[1];
        r[0x20] = b;
        r[0x21] = c;
        r[0x23] = d;
    }
}

extern s32 func_00175700(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_003C80C0(void *p, s32 a, s32 b);

extern void func_00190A80(void *p);

void func_001909E0(u8 *p) {
    s32 a = *(s8 *)(p + 0x1B3);
    if (a != 0 && p[5] == 0 && *(s16 *)(p + 0x434) != 0 && ((s8)a & 0xC0) == 0) {
        u32 t = p[0x295];
        p[0x295] = t + 1;
        *(s8 *)(p + 0x1B4) = *(s8 *)(p + 0x1B4) + 6;
        func_00190A80(p);
        return;
    }
    {
        s8 v = *(s8 *)(p + 0x297);
        if (v != 0) {
            v = v - 1;
            *(s8 *)(p + 0x297) = v;
            if (v == 0) {
                p[0x294] = 0;
            }
        }
    }
}
