typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G37;
extern G37 *D_004C2794;

void func_0037D690(u8 *p, u8 *q) {
    extern void func_001BAE10();
    extern int func_00175700(u8 *);
    extern void func_0037D930(u8 *, s32);
    extern void func_001BBD80(u8 *, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_001E7F60(u8 *);
    s32 f;
    u8 v;
    u8 *d;
    if (q[5] == 3) {
        func_001BAE10(p, q, 3);
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    if ((s8)func_00175700(p) < 0) {
        func_001BAE10(p, q, 2);
        p[4] = 2;
        return;
    }
    d = *(u8 **)(p + 0xD4);
    if (p[0x22] != 0) {
        f = *(s8 *)(p + 0x1B2);
        if (f != 0) {
            if (((s8)f & 0x11) != 0) {
                p[0x1B4] = 8;
                d[0x1B4] = 8;
            }
            p[0x22] = 0;
        }
    }
    v = p[0x15B];
    if (v != 0) {
        p[0x1B5] = v;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        p[0x15B] = 0;
        p[0x22] = 1;
    }
    if (*(s8 *)(p + 0x151) == 2) {
        p[0x151] = 0;
        func_0037D930(p, 4);
        func_001BBD80(p, 7);
        func_001E3210(p, 0x24);
    }
    if (*(s8 *)(p + 0x151) == 0xF) {
        p[0x151] = 0;
        func_0037D930(p, 5);
        func_001BBD80(p, 7);
        func_001E3210(p, 0x24);
    }
    if (*(s8 *)(p + 0x151) == 3) {
        p[0x151] = 0;
        func_001BBD80(p, 6);
    }
    func_001E7F60(p);
}
