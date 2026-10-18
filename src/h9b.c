typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s16 D_004C27A4;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_003A9FC0(void);
u8 *func_003A9F30(u8 *p) {
    s32 i;
    u8 *o;
    if (D_004C27A4 < 2) return 0;
    i = 0;
    do {
        o = func_003DA750(0, 1, 0);
        *(void **)(o + 0x10) = func_003A9FC0;
        *(u8 **)(o + 0x18) = p;
        *(u16 *)(o + 0x1C) = *(u16 *)(p + 0x168);
        o[0x20] = i;
        *(u16 *)(o + 0x26) = 0x3000;
        i++;
    } while (i < 2);
    return o;
}
extern u8 *D_004C2840;
extern void func_00172370(s32);
extern void func_0012E6B0(void);
extern void func_0012E780(s32);
void func_001723C0(void) {
    D_004C2840[2] = 0;
    D_004C2840[3] = 0;
    D_004C2840[4] = 0;
    D_004C2840[3] = 0;
    D_004C2840[5] = 0;
    D_004C2840[6] = 0;
    D_004C2840[7] = 0;
    D_004C2840[0x88] = 0;
    D_004C2840[0x18] = 3;
    D_004C2840[0x89] = 3;
    D_004C2840[0x90] = 3;
    func_00172370(3);
    func_0012E6B0();
    func_0012E780(12);
}
extern void func_003A5900(void *);
extern void (*D_004C1EA8[2])();
void func_003A5700(u8 *p, u8 *q) {
    s32 v;
    u32 t;
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    if (*(s8 *)(p + 0x24) > 7) *(s8 *)(p + 0x24) = 7;
    if (*(s8 *)(p + 0x24) < 0) *(s8 *)(p + 0x24) = 0;
    if (q[0x169] != 9) {
        t = p[4];
        p[4] = t + 1;
        func_003A5900(p);
    } else {
        D_004C1EA8[p[5]]();
    }
}
