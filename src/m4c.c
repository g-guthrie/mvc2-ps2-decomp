typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void *func_003A23F0(u8 *p, u8 n, u8 i);
void func_003A26F0(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        s32 i = 0;
        do {
            if (func_003A23F0(p, 2, i) == 0) break;
            i++;
        } while (i <= 12);
        *(s16 *)(p + 0x1C) = 10;
        p[5]++;
    }
}

typedef float f32;
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_0013C330(void);
extern u8 *D_004C2924;
extern u8 *D_004C2830;
extern void func_001E3CE0(s32 a, s32 b);
void func_0013BEF0(s32 a0) {
    u8 *o = func_003DA750(a0, 6, 3);
    if (o != 0) {
        o[0x13C] = 1;
        *(u8 **)(o + 0xC8) = D_004C2924 + 0x88;
        *(void **)(o + 0x10) = (void *)func_0013C330;
        *(f32 *)(o + 0x50) = 1.4f;
        *(f32 *)(o + 0x54) = 1.4f;
        *(f32 *)(o + 0x58) = 1.4f;
        *(f32 *)(o + 0x74) = 1.0f;
        *(s16 *)(o + 0xCC) = 0x58;
        *(u8 **)(o + 0x84) = D_004C2830;
        *(s32 *)(o + 0x44) = 0xC71C;
        *(s32 *)(o + 0xD0) = 0x835;
        func_001E3CE0(0x32, 0xC71C);
    }
}

extern u8 *func_001E7FD0(u8 *p);
u8 *func_002779A0(u8 *p) {
    s32 v = (*(u16 *)(p + 0x20E) & 0x1C00) >> 10;
    u8 *r;
    p[0x22] = v;
    if ((u8)v != 0) {
        if (p[0x212] == 1) {
            if (p[0x1B7] == 1) {
                if (*(f32 *)(p + 0x38) > 137.14285278f) {
                    r = func_001E7FD0(p);
                    if (r != 0) {
                        p[0x20B] = 0;
                        return r;
                    }
                }
            }
        }
    }
    return 0;
}

extern void func_0016B0C0(void *p, void *q, s32 n);
extern int func_00166C80(void *p, void *q, s32 n);
int func_001682B0(u8 *a, u8 *b) {
    s16 y;
    func_0016B0C0(a, b, 0);
    func_0016B0C0(a, b, 2);
    y = *(s32 *)(a + 0x4C8) * 144 / 200;
    return func_00166C80(a, b, y >= *(s16 *)(a + 0x434));
}

u32 func_003DBD20(u32 x) {
    u32 q = x / 0x70000;
    if (x % 0x70000 != 0) q++;
    return q << 7;
}
