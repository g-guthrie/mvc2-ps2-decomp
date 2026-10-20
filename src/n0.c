typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00126400();
extern void func_00290E30();
extern void func_00294B20();
extern void func_00294BC0();
extern void func_001C09A0();
extern void func_00385A20();
extern u8 D_00456DB0[];
extern void func_002DB0E0(u8 *);
extern void func_001D18E0(u8 *);
extern void func_001843A0(u8 *);
extern void func_00183920(u8 *, u32 *);
extern void func_001E3710(u8 *, int);
extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern void (*D_0044B130[])(u8 *, u8 *);
extern f32 func_002ADC20(u8 *);
typedef struct { f32 x, y, z; } V3;
extern void func_00175910(u8 *, int, int, int);
extern void func_00361880(u8 *, u8 *);
extern void func_003610F0(u8 *, int, int);

void func_00239770(u8 *p) {
    func_00175700(p);
    if (*(s8*)(p+0x151) != 0) {
        u8 *q;
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        q = *(u8**)(p+0x1DC);
        *(u8**)(q+0x1C8) = p;
        q[0x20A] = 1;
        q[0x1E6] = p[0x1E6];
        q[0x20D] = 2;
        q[0x1B5] = 0x20;
        func_00126400();
    }
}

void func_00252F00(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    } else {
        s32 f = *(s8*)(p+0x151);
        if (f & 1) {
            u32 v[3];
            p[0x151] = 0;
            v[0] = 0;
            v[1] = 0x42564924;
            v[2] = 0;
            func_00183920(p, v);
        } else if (f & 2) {
            p[0x151] = 0;
            func_001E3710(p, 0x16);
        }
    }
}

void func_001A4140(u8 *a, u8 *b) {
    if (b[5] != 0 || b[0x1E4] != 0x15 || b[0x1FD] != 1) {
        a[4] = 2;
        a[0x13C] = 0;
    } else {
        a[0x24] = 0xC;
        if ((D_004D18DC & (1 << D_004D18DB)) == 0) {
            D_0044B130[a[5]](a, b);
        }
    }
}

void func_001D2B50(u8 *a, u8 *b) {
    a[0x13C] = 0;
    *(V3 *)(a + 0x34) = *(V3 *)(b + 0x34);
    *(s16 *)(a + 0x140) = *(s16 *)(b + 0x140);
    if (b[5] != 1) a[4] = 2;
    if (b[0x169] != 0xF) a[4] = 2;
    if (*(s8 *)(b + 0x151) != 0 && a[4] != 2) {
        a[0x13C] = 1;
        func_00175910(a, 0x17, (u8)(a[0x20] + 0x18), *(s8 *)(b + 0x151) - 1);
    }
}

void func_00361380(u8 *a, u8 *b) {
    u8 *c = a + 0xD0;
    func_00361880(a, b);
    func_00175700(a);
    *(s16 *)(a + 0x1C) += 1;
    func_003610F0(a, 1, *(s16 *)(a + 0x1C) & 3);
    if (b[0x2C0] != 0 || *(u16 *)(b + 0x168) != *(u16 *)c) {
        u32 t = a[5];
        a[5] = t + 1;
        func_001757E0(a, 0x17, 0x15);
    }
}

extern void func_003BD800(u8 *);
void func_003BC320(u8 *a) {
    u8 *b = *(u8 **)(a + 0x18);
    if (b[0x169] == 7 && b[0x168] == 1) {
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
        *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38);
        if ((s8)func_00175700(a) < 0) func_003BD800(a);
    } else {
        func_003BD800(a);
    }
}
