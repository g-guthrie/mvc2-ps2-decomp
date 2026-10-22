typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 D_004D18A0[];

void func_003271D0(u8 *p) {
    extern void func_00186A60(u8 *, s32);
    extern void func_0018C6B0(u8 *, s32);
    u8 *o;
    s32 i;
    s32 n;
    u32 m;
    s32 off;
    s16 hh;
    s32 k;
    k = p[0x1B8];
    m = (k / 2) & 0xFF;
    i = 1;
    n = i;
    off = 4;
    for (; i < 3 && (s8)n < *(s8 *)(p + 0x26D); i++) {
        o = *(u8 **)(off + (u32)(D_004D18A0 + p[2] * 12) + 0x18);
        if (*(s16 *)(o + 0x434) > 0 && *(s16 *)(o + 0x2B4) == 0) {
            o[0] = 1;
            o[0x13C] = 0;
            o[4] = 1;
            o[5] = 0;
            o[6] = 0;
            o[7] = 0;
            func_00186A60(o, 0x1C);
            o[0x26A] = 3;
            o[0x269] = 5;
            o[0x404] = 0xFF;
            o[0x405] = 0x10;
            n = (s8)(n + 1);
            hh = p[0x1E6];
            *(s16 *)(o + 0x140) = hh;
            o[0x1E6] = hh;
            *(V3 *)(o + 0x34) = *(V3 *)(p + 0x34);
            o[0x159] = 0xFF;
            *(s16 *)(o + 0x356) = 0;
            *(s16 *)(o + 0x35C) = 0;
            *(s16 *)(o + 0x354) = 0;
            *(s16 *)(o + 0x360) = 0;
            *(s16 *)(o + 0x362) = 0;
            *(s16 *)(o + 0x35E) = 0;
            D_004D18A0[0x42 + p[2]] |= (1 << *(s8 *)(o + 0x425));
            m = (m | (u8)(1 << *(s8 *)(o + 0x1B8))) & 0xFF;
        }
        off += 4;
    }
    *(s8 *)(p + 0x26D) = n;
    p[0x33D] = m;
    func_0018C6B0(p, (s8)n);
}
