typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 b[28]; } E28;
typedef struct { u8 pad[0x184]; E28 *tab; } T184;

extern u8 *D_004C2794;

void func_002C3420(u8 *p)
{
    extern void func_0018C4B0();
    extern void func_00185490();
    extern void func_001757E0();
    unsigned int offset;
    u32 t = p[6];
    p[6] = t + 1;
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[0x1B5] = 0x42;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(s16 *)(offset + 0x7C);
    func_0018C4B0(p, 10);
    func_00185490(p);
    *(s16 *)(p + 0x1C) = 3;
    p[0x20] = 0x60;
    *(f32 *)(p + 0x5C) /= 16.0f;
    *(f32 *)(p + 0x60) /= 8.0f;
    *(s32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x6C) /= 64.0f;
    func_001757E0(p, 0x16, 4);
}

#define RESET(cmd) \
    p[0x1B5] = cmd; \
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0; \
    *(s32 *)(p + 0x1D8) = 0; \
    offset = p[2] * 2; \
    offset += (unsigned int)D_004C2794; \
    ++*(s16 *)(offset + 0x7C);

void func_0030B850(u8 *p)
{
    extern void func_00175C00();
    extern void func_00185490();
    extern void func_001757E0();
    extern void func_003BA230();
    extern void func_00309310();
    unsigned int offset;
    if (p[6] == 0) {
        p[6]++;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        if (p[0x269] == 3) {
            RESET(0x40)
        } else {
            RESET(0x42)
        }
        func_00175C00(p, 0);
        func_00185490(p);
        func_001757E0(p, 0x15, 0x1B);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        func_003BA230(p, 6, 0);
    }
    func_00309310(p);
}

void func_002402A0(u8 *p)
{
    extern void func_001861B0();
    extern void func_0018C4B0();
    extern void func_001E3710();
    extern void func_001757E0();
    extern void func_00183D90();
    extern void func_001863F0();
    extern s32 func_00175700();
    extern void func_001843A0();
    unsigned int offset;
    if (p[6] == 0) {
        p[6]++;
        p[0x20D] = 0;
        RESET(0x12)
        func_001861B0(p);
        func_0018C4B0(p, 5);
        func_001E3710(p, 0x15);
        func_001757E0(p, 0x14, 4);
    }
    if (p[0x213] == 3) func_00183D90(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
}

void func_002DD230(u8 *p)
{
    extern s32 func_00175700();
    extern void func_001843A0();
    extern void func_001E3710();
    unsigned int offset;
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    switch (p[0x1FC]) {
    case 0:
        if (*(s8 *)(p + 0x151) != 0) {
            *(s8 *)(p + 0x151) = 0;
            RESET(0x19)
            func_001E3710(p, 0x14);
        }
        break;
    case 1:
        break;
    case 2:
        if (*(s8 *)(p + 0x151) != 0) {
            *(s8 *)(p + 0x151) = 0;
            RESET(0x1A)
            func_001E3710(p, 0x16);
        }
        break;
    }
}

void func_0029CBE0(u8 *p)
{
    extern void func_001861B0();
    extern void func_0018C4B0();
    extern void func_001E3710();
    extern void func_001757E0();
    extern void func_00183D90();
    extern void func_001863F0();
    extern s32 func_00175700();
    extern void func_001843A0();
    unsigned int offset;
    if (p[6] == 0) {
        func_001861B0(p);
        p[6]++;
        p[0x1B5] = 0x42;
        p[0x20D] = 0;
        *(volatile u8 *)(p + 0x1B5) = p[0x1B5];
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
        func_0018C4B0(p, 5);
        func_001E3710(p, 0x15);
        func_001757E0(p, 0x14, 4);
    }
    if (p[0x213] == 3) func_00183D90(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
}

void func_0029C720(u8 *p)
{
    extern s32 func_00175700();
    extern void func_001843A0();
    unsigned int offset;
    switch (p[0x1FC]) {
    case 2:
        if ((*(s8 *)(p + 0x151) & 1) != 0) {
            *(s8 *)(p + 0x151) = 0;
            RESET(8)
        }
        if ((*(s8 *)(p + 0x151) & 2) != 0) {
            *(s8 *)(p + 0x151) = 0;
            RESET(0x1A)
        }
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}

void func_002A9360(u8 *p)
{
    extern s32 func_00175700();
    extern void func_001757E0();
    unsigned int offset;
    f32 z;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x161) >= 0) {
        func_00175700();
        if (*(s8 *)(p + 0x151) != 0) {
            *(s8 *)(p + 0x151) = 0;
            if (p[0x269] == 3) {
                RESET(0x52)
            } else {
                RESET(0x36)
            }
        }
    }
    z = 0.0f;
    if (*(f32 *)(p + 0x60) < z) {
        p[6]++;
        func_001757E0(p, 0x15, 5);
    }
}
