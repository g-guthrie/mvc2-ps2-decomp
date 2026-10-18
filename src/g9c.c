typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern float D_004B4290[];
extern s32 D_004C2838;
extern void func_001CF6F0();
extern s8 func_00175670();
extern void func_001CF720();
extern void func_00175C00();
extern void func_001CF6A0();
extern u16 *D_004C2718;
void func_001CF180(u8 *p) {
    s8 r;
    func_001CF6F0(p);
    *(s8 *)(p + 0x13C) = 1;
    if (*D_004C2718 == *(u16 *)(*(u8 **)(p + 0x18) + 0x168)) {
        r = func_00175670(p);
        if (r >= 0) {
            func_001CF720(p);
            return;
        }
    }
    func_00175C00(*(u8 **)(p + 0x18), 0);
    func_001CF6A0(p);
}

extern void (*D_004BF950[2])();
void func_001B5E30(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (*(u16 *)(p + 0xD0) != *(u16 *)(q + 0x168)) {
        p[4] = 2;
    } else {
        D_004BF950[p[6]](p);
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        *(s8 *)(p + 0x31) = -1;
    }
}
