typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G275;
extern G275 *D_004C2794;

void func_00275B20(u8 *p) {
    u32 t;
    extern void func_00185490();
    extern void func_00175C00(u8 *, s32);
    extern void func_001BA010(u8 *, s32);
    extern void func_00275A80();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00275C20(u8 *);
    t = p[6];
    p[6] = t + 1;
    if (p[0x20D] == 2) {
        p[0x168] = 3;
        func_00185490(p);
        func_00175C00(p, 0);
        func_001BA010(p, 1);
    } else {
        func_00275A80(p);
        p[0x168] = 0;
        func_001BA010(p, 0);
    }
    func_001757E0(p, 0x16, p[0x168]);
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    *(s32 *)(p + 0x2EC) = 0;
    p[0x1B5] = 0x39;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_00275C20(p);
}
