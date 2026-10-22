typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern s16 *D_004C2794;

void func_0022C720(u8 *p) {
    u8 t = p[0x15B];
    if (t != 0) {
        p[0x15B] = 0;
        p[0x1B5] = t;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794[p[2] + 0x3E] += 1;
    }
}

extern u8 D_004C27D0;
extern u32 D_004C283C;
extern void func_001E7F60();
extern void func_0032F980();
extern u8 *func_003DA750();
extern void func_0032FA60();
extern void func_00170DF0(u32);

void func_003BEA00(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        u32 t = p[5];
        s32 c;
        p[5] = t + 1;
        *(s16 *)(p + 0x1E) = -0x4000;
        c = 0x3B;
        if (p[0x21]) c = 0x3C;
        p[0x1B5] = c;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794[p[2] + 0x3E] += 1;
    }
    func_001E7F60(p);
}

void func_0032F9E0(void) {
    u8 *o;
    if (D_004C27D0 == 9) {
        func_0032F980(0x15);
        func_0032F980(0x16);
    }
    o = func_003DA750(0, 6, 1);
    if (o) {
        o[0x13C] = 1;
        *(s16 *)(o + 0xCC) = 0x13;
        *(u32 *)(o + 0x84) = D_004C283C;
        *(void **)(o + 0x10) = func_0032FA60;
        *(u32 *)(o + 0xD0) = 0x800;
        func_00170DF0((u32)*(u32 *)(o + 0x84));
    }
}
