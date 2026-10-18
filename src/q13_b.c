typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F7F91;
extern u16 D_004F7F92;
extern u8 D_004F7F90;
extern u8 D_004F7FAE;
extern u16 D_004F7F94;
extern u16 D_004F7F96;
extern u16 D_004F7F98;
extern u16 D_004F7F9A;
extern u16 D_004F7FA0;
extern u16 D_004F7FA8;
extern u16 D_004F7F9C;
extern u16 D_004F7FA2;
extern u16 D_004F7FAA;
extern u16 D_004F7F9E;
extern u16 D_004F7FA4;
extern u16 D_004F7FAC;
extern u8 D_004F7FAF;
extern u8 D_004F7FB0;
extern u8 D_004F7FB1;
extern void func_001A52F0(void *p, void *q);
extern void func_001A5090(void *p, void *q);
extern void func_001A4FB0(void *p, void *q);
extern void func_001A4E10(void *p, void *q);
extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern void func_0015D010(void *p, f32 *v);
extern void func_0018C4B0(void *p, s32 a);
extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_00183D10(void *p);

void func_00131290(void) {
    D_004F7F91 = 0;
    D_004F7F92 = 0;
    D_004F7F90 = 1;
    D_004F7FAE = 2;
    D_004F7F94 = 0;
    D_004F7F96 = 0;
    D_004F7F98 = 0;
    D_004F7F9A = 0;
    D_004F7FA0 = 0;
    D_004F7FA8 = 0;
    D_004F7F9C = 0;
    D_004F7FA2 = 0;
    D_004F7FAA = 0;
    D_004F7F9E = 0;
    D_004F7FA4 = 0;
    D_004F7FAC = 0;
    D_004F7FAF = 0;
    D_004F7FB0 = 0;
    D_004F7FB1 = 0;
}

void func_001A4D60(u8 *p, u8 *q) {
    u8 *r = q + 0x2B8;
    if ((D_004D18DC & (1 << D_004D18DB)) == 0) {
        s8 c;
        func_001A52F0(p, q);
        func_001A5090(p, q);
        func_001A4FB0(p, q);
        c = r[6];
        if (c == 2 || c == -1) {
            p[4] = 2;
            func_001A4E10(p, q);
        }
    }
}

void func_001F6600(void *p) {
    f32 v[4];
    *(u32*)&v[0] = 0xC2F00000;
    *(u32*)&v[1] = 0x42CDB6DB;
    func_0015D010(p, v);
    func_0018C4B0(p, 5);
    func_001757E0(p, 15, 4);
    func_00183D10(p);
}
