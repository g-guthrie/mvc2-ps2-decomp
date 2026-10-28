/* MW 3.0 (try30.sh) "-O3 -Op -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G7c;
extern G7c *D_004C2794;
typedef struct { u8 pad[0x1C]; s16 h1c; } S1C;
extern u8 D_004C0900[2];

void func_00284B40(u8 *p, u8 *q) {
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00383B80(u8 *, s32, s32);
    u16 h;
    u8 c;
    s8 s0;
    s8 s1;
    u16 v;
    func_00175700(p);
    if (*(s16 *)(p + 0x1C) != *(s8 *)(p + 0x151)) {
        ((S1C *)p)->h1c = *(s8 *)(p + 0x151);
        if (p[0x20D] == 2) {
            v = (p[0x1B7] != 0 ? 0x55 : 0x53) & 0xFFFF;
        } else {
            v = (p[0x1B7] != 0 ? 0x4F : 0x4D) & 0xFFFF;
        }
        p[0x1B5] = v;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
    if (*(s8 *)(p + 0x539) != 0) {
        s16 t = *(s16 *)(p + 0x1E);
        *(s16 *)(p + 0x1E) = t - 1;
        if (t < 0) p[6]++;
        return;
    }
    h = *(u16 *)(p + 0x362);
    if ((h & 0x60) == 0) {
        s8 v = *(s8 *)(q + 5) - 1;
        *(s8 *)(q + 5) = v;
        if (v < 0) p[6]++;
        return;
    }
    c = (h & 0x40) ? 0 : 1;
    if (*(s8 *)(q + 5) <= D_004C0900[c]) {
        p[6]++;
    } else {
        q[5] = 0xF;
        if (p[0x1B7] == c) return;
        p[0x1B7] = c;
        s0 = *(s8 *)(p + 0x152);
        s1 = *(s8 *)(p + 0x151);
        if (p[0x20D] == 2) {
            p[0x168] = p[0x1B7] != 0 ? 0xF : 0xD;
        } else {
            p[0x168] = p[0x1B7] != 0 ? 9 : 7;
        }
        func_001757E0(p, 0x15, p[0x168]);
        func_00383B80(p, 4, 3);
        while (*(s8 *)(p + 0x151) != s1) {
            p[0x152] = 1;
            func_00175700(p);
        }
        p[0x152] = s0;
    }
}
