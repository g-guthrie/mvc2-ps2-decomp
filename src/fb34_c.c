typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

void func_00190710(u8 *p, u8 *q) {
    extern void func_00190F30(u8 *, u8 *, u8 *);
    extern void func_0018B500(u8 *, u8 *);
    extern void func_0018C6F0(u8 *);
    extern void func_0018DAC0(u8 *, u8 *);
    extern void func_00186A60(u8 *, s32);
    extern s32 func_00174170(void);
    extern void func_001E33D0(u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_0018D580(u8 *, u8 *);
    extern void func_0018D6F0(u8 *, u8 *, f32 *);
    extern void func_001BE7E0(u8 *, f32 *, u8);
    extern void func_001BFD10(u8 *, f32 *, u8);
    extern void func_001E38B0(u8 *);
    f32 v[4];
    u8 *s0;
    u8 a2;
    s32 h;
    u8 t;
    s0 = *(u8 **)(p + 0x1D0);
    t = s0[5];
    q[0x1B4] = t;
    p[0x1B4] = t;
    if (*(s8 *)(q + 0x1B0) & 1) {
        (*(u8 **)(p + 0x1CC))[0x1B4] = s0[5];
    }
    p[0x225] = 0;
    func_00190F30(p, q, s0);
    func_0018B500(p, q);
    func_0018C6F0(p);
    p[0x297] = *(s8 *)(p + 0x292);
    p[0x294] += (s0[0x17] != 0) ? s0[0x17] : s0[0xF];
    h = *(s16 *)(p + 0x434);
    if ((h != 0 && p[5] == 0) || p[0x20D] == 2) {
        if ((s16)h == 0) *(s16 *)(p + 0x434) = 1;
    } else {
        p[0x294] = 0;
        p[0x20D] = 0;
        p[0x247] = 0;
        func_0018DAC0(p, q);
        p[5] = 3;
        p[7] = 0;
        p[6] = 0;
        p[0x24C] = 0;
        p[0x13C] = 1;
        *(s32 *)(p + 0x48) = 0;
        *(V3 *)(p + 0x50) = *(V3 *)(p + 0x298);
        *(u32 *)(p + 0x118) = 0x3F800000;
        func_00186A60(p, 0x20);
        p[0x249] = 0;
        p[0x248] = 0;
        if ((func_00174170() & 1) == 0) func_001E33D0(p);
    }
    if (*(s16 *)(p + 0x434) == 0) {
        if (p[0x1F0] == 0) {
            p[0x1F0] = 0xFF;
            func_001E3210(p, 0);
        }
        if (p[1] == 0x18 || p[1] == 0x19) {
            (**(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x60))(p);
        }
    }
    if (p[1] == 0x18) {
        func_0018D580(p, q);
    } else {
        func_0018D6F0(p, q, v);
        a2 = *(s8 *)(p + 0x245) & 0x70;
        if (a2 != 0) {
            if ((a2 & 0xFF) == 0x30) a2 = 2;
            else if ((a2 & 0xFF) == 0x20) a2 = 1;
            else a2 = 0;
        } else {
            u8 w = p[0x243];
            if (w >= 5) a2++;
            if (w >= 0xC) a2++;
        }
        if (p[1] == 0x19) {
            func_001BE7E0(p, v, s0[0xB] % 3);
        } else if (*(u8 **)(*(u8 **)(p + 0x1C8) + 0x1C4) == p) {
            func_001BFD10(p, v, a2);
        }
    }
    func_001E38B0(p);
}
