typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002DB4E0(u8 *p) {
    extern void func_003A0110();
    extern void func_00175700();
    s16 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(s32 *)(p + 0x2F8) = 0x60;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[6];
        p[6] = t + 1;
    }
    if (*(u16 *)(p + 0x362) & 0x360) {
        s16 w = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = w;
        if (w >= 0) {
            s16 x = *(s16 *)(p + 0x1C) + 1;
            *(s16 *)(p + 0x1C) = x;
        }
    }
    func_003A0110(p);
    func_00175700(p);
}

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G2B;
extern G2B *D_004C2794;

void func_002B1340(u8 *p) {
    extern s8 func_00175700();
    extern void func_001845F0();
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (func_00175700(p) < 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_001845F0(p);
        return;
    }
    {
        u8 t = p[0x15B];
        if (t != 0) {
            p[0x1B5] = t;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            p[0x15B] = 0;
        }
    }
}

extern char D_004BA508[];
extern char D_004BA510[];

s32 func_003DCBB0(char *a0, s32 a1, s32 a2) {
    extern void func_0011FE88();
    extern s32 func_0011FFA0();
    extern void func_0011FC10();
    extern void func_00120868();
    extern s32 func_00107E90();
    extern void func_00108730();
    extern void func_00108118();
    char buf[0x800];
    char *s;
    s32 fd;
    func_0011FE88(buf, D_004BA508);
    s = buf + func_0011FFA0(buf);
    func_0011FC10(buf, a0);
    func_00120868(s);
    func_0011FC10(buf, D_004BA510);
    if ((fd = func_00107E90(buf, 0x602)) < 0) {
        return 0;
    }
    func_00108730(fd, a1, a2);
    func_00108118(fd);
    return 1;
}
