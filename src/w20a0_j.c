typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;

void func_002BCBE0(u8 *p, u8 *q) {
    extern void func_002BCE90();
    extern s32 func_00185980();
    extern void func_002BD2D0();
    extern void func_00185770();
    extern void func_0015D010();
    extern void func_00174A40();
    extern s32 func_002BD330();
    extern s32 func_002BD580();
    extern s32 func_002BD410();
    extern s32 func_002BD4E0();
    extern void func_001757E0();
    u32 t;
    s32 a;
    s16 h;
    u32 v[3];
    f32 f;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x209] = 1;
    if (p[7] != 0) {
        func_002BCE90(p);
        return;
    }
    if (*(s16 *)(p + 0x1E) == 0 && ((s8 *)p)[0x1B2] != 0) {
        if (func_00185980() == 0) {
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            func_002BD2D0(p, q);
            return;
        }
        *(s16 *)(p + 0x1E) = 1;
        t = q[0xC];
        q[0xC] = t - 1;
    }
    if (q[0xC] == 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        t = p[6];
        p[6] = t + 1;
        p[0x20B] = 0xC6;
        p[0x1B5] = 0x5D;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        *(s16 *)((p[2] << 1) + (u32)D_004C2794 + 0x7C) += 1;
        func_00185770(p, *(u32 *)(p + 0x1C4));
        h = p[0x1E6] ^ 1;
        *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = h;
        *(s8 *)(*(u8 **)(p + 0x1DC) + 0x1E6) = h;
        *(s16 *)(p + 0x1C) = 0x10;
        if (p[0x1E6]) f = 1.6666666269302368f;
        else f = -1.6666666269302368f;
        *(f32 *)(p + 0x5C) = f;
        *(s32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x42092492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        v[2] = 0;
        v[0] = 0xC22D5555;
        v[1] = 0x42960000;
        func_0015D010(p, v);
        p[0x1B4] = 10;
        func_001757E0(p, 0xF, 6);
        return;
    }
    func_00174A40(p, 0x960);
    a = p[0x22] >> 3;
    switch (a) {
    case 0:
        if (!func_002BD330(p, q)) func_002BD580(p, q);
        break;
    case 1:
        if (!func_002BD580(p, q)) func_002BD410(p, q);
        break;
    case 2:
        if (!func_002BD410(p, q)) func_002BD4E0(p, q);
        break;
    case 3:
        if (!func_002BD4E0(p, q)) func_002BD330(p, q);
        break;
    }
    if (p[7] != 0) func_002BCE90(p, q);
}
