typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_001757E0(void *p, s32 a, s32 b);

extern s8 func_00175700();
extern void func_001843A0(void *p);
extern void func_001E3A40(void *p);
extern void func_001266A0(void *p, s32 a, s32 b);
void func_001FB920(u8 *p) {
    if (func_00175700(p) < 0) func_001843A0(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u8 *q;
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 0xB;
        q[0x20D] = 0;
        func_001266A0(p, 0, 0);
        q[0x1B5] = 0x20;
        q[0x1E6] = p[0x1E6];
        func_001E3A40(p);
    }
}

extern void func_0029D5E0(void *p);
extern void func_0018C4B0(void *p, s32 a);
extern void func_001E3710(void *p, s32 a);
void func_0029F500(u8 *p) {
    s16 *e;
    u32 t = p[6]; p[6] = t + 1;
    func_0029D5E0(p);
    func_0018C4B0(p, 5);
    p[0x1B5] = 0x34;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    e = (s16 *)((u8 *)(p[2] * 2) + (u32)D_004C2794);
    e[0x7C / 2] = e[0x7C / 2] + 1;
    func_001757E0(p, 0x15, 5);
    func_001E3710(p, 0x17);
}

typedef struct { f32 x, y, z; } V3;
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_00160E50();
extern u32 D_004C2838;
void func_00160C80(V3 *pos) {
    u8 *q = func_003DA750(0, 9, 1);
    if (q != 0) {
        q[0x13C] = 1;
        *(void **)(q + 0x10) = func_00160E50;
        *(s16 *)(q + 0xCC) = 0xDC;
        *(u32 *)(q + 0x84) = D_004C2838;
        *(V3 *)(q + 0x34) = *pos;
        *(u32 *)(q + 0xD0) = 0x800025;
        *(s16 *)(q + 0x1C) = 0;
        *(u32 *)(q + 0x74) = 0;
        *(u32 *)(q + 0x78) = 0;
        *(u32 *)(q + 0x7C) = 0;
        *(u32 *)(q + 0x80) = 0;
    }
}


extern void func_001757E0(void *p, s32 a, s32 b);
void func_002EB480(u8 *p) {
    s16 *e;
    u32 t = p[6]; p[6] = t + 1;
    p[0x20D] = 2;
    *(u32 *)(p + 0x5C) = 0xC1F00000;
    if (p[0x1E6] != 0) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0xBE892492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    p[0x1B5] = 0x3F;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    e = (s16 *)((u8 *)(p[2] * 2) + (u32)D_004C2794);
    e[0x7C / 2] = e[0x7C / 2] + 1;
    func_001757E0(p, 0x14, 1);
}
