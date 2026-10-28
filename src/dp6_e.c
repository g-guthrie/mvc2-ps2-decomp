/* nearmiss: mwcc 3.0.3 (try.sh) "-O3 -Op -sdatathreshold 0": 8/160 words; only residue is $a0 vs retail $a2 for the reloaded 0x1DC pointer after func_001823C0 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 h0, h2; u8 b4, b5; s8 b6; u8 b7; } E3001B0;
extern E3001B0 D_0045C270[][3];
typedef struct { u8 pad[0x1DC]; u8 *q1DC; } P3001B0;

void func_003001B0(u8 *p) {
    extern void func_00178F20();
    extern void func_001823C0();
    extern void func_001757E0();
    extern void func_00178EB0();
    E3001B0 *e;
    u8 *q;
    u8 *r;
    s8 a, b;
    P3001B0 *pa;

    if (p[0x21] != 0) {
    e = D_0045C270[p[1]];
    q = *(u8 **)(p + 0x1DC);
    e += *(s8 *)(q + 0x160) % 3;
    if (*(s16 *)(q + 0x140) != 0) {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) - 1.6666666269302368f * (f32)e->h0;
    } else {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + 1.6666666269302368f * (f32)e->h0;
    }
    func_001823C0(p);
    if (*(s8 *)(p + 0x211) != 0) {
        *(f32 *)(*(u8 **)(p + 0x1DC) + 0x34) = *(f32 *)(p + 0x34);
        r = *(u8 **)(p + 0x1DC);
        if (*(s16 *)(r + 0x140) != 0) {
            *(f32 *)(r + 0x34) += 1.6666666269302368f * (f32)e->h0;
        } else {
            *(f32 *)(r + 0x34) -= 1.6666666269302368f * (f32)e->h0;
        }
    }
    r = *(u8 **)(p + 0x1DC);
    *(f32 *)(p + 0x38) = *(f32 *)(r + 0x38) + 2.142857074737549f * (f32)e->h2;
    p[0x168] = e->b4;
    *(s16 *)(p + 0x140) = *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) ^ (e->b5 & 1);
    pa = (P3001B0 *)p;
    if (e->b6 > 0) {
        r = pa->q1DC;
        a = p[0x24];
        b = r[0x24];
        if (a < b) {
            p[0x24] = b;
            (pa->q1DC)[0x24] = a;
        }
    } else {
        r = pa->q1DC;
        a = p[0x24];
        b = r[0x24];
        if (b < a) {
            p[0x24] = b;
            (pa->q1DC)[0x24] = a;
        }
    }
    r = *(u8 **)(p + 0x1DC);
    *(s32 *)(p + 0x48) = (s32)((f32)*(s32 *)(r + 0x48) + (f32)(e->b7 << 8));
    if (*(s8 *)(*(u8 **)(p + 0x1DC) + 0x160) != *(s8 *)(p + 0x16A)) {
        func_001757E0(p, 0x10, p[0x168]);
        p[0x16A] = (*(u8 **)(p + 0x1DC))[0x160];
    }
    func_00178EB0(p);
    } else {
        func_00178F20(*(u8 **)(p + 0x1DC), p);
    }
}
