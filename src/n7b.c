typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 *D_004C2840;
extern void (*D_0043CC20[])();
extern void func_003DA6F0(int);
extern void func_003D7310(void *);
extern void func_001527F0();

/* 0x001283C0 */
void func_001283C0(void) {
    D_0043CC20[D_004C2840[3]]();
    func_003DA6F0(6);
    func_003DA6F0(0xD);
    if (D_004C2840[7] == 0) {
        func_003D7310(func_001527F0);
    }
}

/* 0x0032D020 */
extern s8 D_00583BC8[];
extern void func_0032DF00();
extern void func_001E40E0();
extern void func_001E4150();
void func_0032D020(void) {
    D_004C2840[3]++;
    D_004C2840[4] = 0;
    D_004C2840[5] = 0;
    D_004C2840[6] = 0;
    D_004C2840[7] = 0;
    *(s16 *)(D_004C2840 + 8) = 0;
    D_004C2840[0x91] = 0;
    D_004C2840[0x92] = 0;
    D_004C2840[0x90] = 0;
    D_00583BC8[0] = 0;
    D_004C2840[0x9E] = 0;
    func_0032DF00();
    func_001E40E0();
    func_001E4150();
}

/* 0x003AF650 */
extern u8 D_004C1F58[2];
extern void func_00175580(u8 *, int, int, int);
typedef struct { f32 x, y, z; } V3;
void func_003AF650(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    s32 f; if ((s8)q[0x151] >= 0) f = 0; else f = 1;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    func_00175580(p, 0x1B, D_004C1F58[*(u16 *)(q + 0x2B8)], f);
    p[0x13C] = 1;
}

/* 0x003119B0 */
extern void (*D_004C16D8[2])();
extern void func_00183D90();
extern void func_001863F0(u8 *);
void func_003119B0(u8 *p) {
    if (p[0x213] == 3) {
        func_00183D90();
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    D_004C16D8[p[7]](p);
}
