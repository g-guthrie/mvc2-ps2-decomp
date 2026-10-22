typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct {
    u8 pad0[0x1C];
    s16 s1C;
    s16 s1E;
    u8 pad20[0x34 - 0x20];
    V3 pos;
    u8 pad40[0x13C - 0x40];
    u8 b13C;
} S36;

extern u8 *D_004C2840;

void func_0036A290(S36 *p) {
    extern s32 func_00174170();
    extern void func_0015B200(S36 *, V3 *, s32, s32);
    extern void func_0036A8A0(S36 *);
    extern void func_001E7F60(S36 *);
    V3 v;
    s32 t;
    s32 r;
    s32 i;
    s16 c = p->s1C - 1;
    p->s1C = c;
    if (c == 0) {
        i = 0;
        do {
            v = p->pos;
            t = func_00174170() & 0xFF;
            if (t & 0x80) t = -(t & 0x3F); else t &= 0x3F;
            v.x += 1.6666666269302368f * (f32)t;
            do {
                r = func_00174170() & 0x7F;
            } while (r < 16);
            v.y += 2.142857074737549f * (f32)r;
            func_0015B200(p, &v, 1, 0x178);
            i++;
        } while (i < 5);
        func_0036A8A0(p);
        return;
    } else {
        s16 d;
        p->b13C = (*(u32 *)(D_004C2840 + 0x1C) & 4) ? 0 : 1;
        d = p->s1E - 1;
        p->s1E = d;
        if (d == 0) {
            p->s1E = func_00174170() & 0xF;
            if (p->s1E < 8) p->s1E = 8;
            v = p->pos;
            t = func_00174170() & 0xFF;
            if (t & 0x80) t = -(t & 0x3F); else t &= 0x3F;
            v.x += 1.6666666269302368f * (f32)t;
            r = func_00174170() & 0x7F;
            v.y += 2.142857074737549f * (f32)r;
            func_0015B200(p, &v, 1, 0xF9);
        }
        func_001E7F60(p);
    }
}
