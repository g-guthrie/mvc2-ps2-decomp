typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x74]; s8 f74[2]; u8 b76; u8 pad2[5]; s16 f7c[16]; } G_w178e;
extern G_w178e *D_004C2794;

void func_00238070(u8 *p) {
    extern s32 func_00175700();
    extern void func_001757E0();
    u32 *a, *b;
    u8 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    a = (u32 *)(p + 0x5C);
    b = (u32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if ((s8)func_00175700(p) >= 0) {
        t = p[0x15B];
        if (t != 0) {
            p[0x1B5] = t;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            *(s16 *)(p + 0x1C0) = 0x40;
            p[0x15B] = 0;
        }
    } else {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *a = 0;
        *(u32 *)(p + 0x60) = 0;
        *b = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001757E0(p, 0x16, 0x1F);
    }
}

void func_00258330(u8 *p) {
    extern void func_001861B0();
    extern void func_0018C4B0();
    extern void func_001757E0();
    extern void func_00183D90();
    extern void func_001863F0();
    extern s32 func_00175700();
    extern void func_001843A0();
    if (p[6] == 0) {
        func_001861B0(p);
        p[6]++;
        if (p[0x212] == 0) {
            func_0018C4B0(p, 5);
            p[0x1B5] = 0x12;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            p[0x20D] = 1;
            func_001757E0(p, 0x14, 0x13);
        }
    }
    if (p[0x213] == 3) func_00183D90(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
}

void func_00217260(u8 *p) {
    extern s32 func_00175700();
    extern void func_001843A0();
    extern s32 func_001853E0();
    extern void func_001855D0();
    extern void func_001E3710();
    extern void func_001757E0();
    switch (p[0x1FC]) {
    case 0:
    case 2:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    case 1:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
            break;
        }
        if (*(s8 *)(p + 0x151) != 0) {
            if (func_001853E0(p) == 0) {
                if (((*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x40) != 0) {
                    *(u16 *)(p + 0x366) = 0;
                    p[0x1B5] = 0x1B;
                    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                    *(u32 *)(p + 0x1D8) = 0;
                    D_004C2794->f7c[p[2]]++;
                    func_001855D0(p);
                    func_001E3710(p, 0x15);
                    func_001757E0(p, 8, 4);
                }
            }
        }
        break;
    }
}

void func_001830D0(u8 *p, s32 b, s32 c) {
    extern void func_001834A0();
    extern void func_001E3710();
    extern void func_001E3210();
    extern void func_001581C0();
    extern void func_0018C6B0();
    extern void func_0016EDA0();
    extern void func_001E3BB0();
    extern void func_00183210();
    u8 t = p[0x269];
    if (t == 4) {
        p[0x33B] = 4;
        D_004C2794->b76 = (*(s8 *)(p + 2) << 4) | 4;
        p[0x33C] = 0x10;
        func_001834A0(p, b);
        func_001E3710(p, 0x1E);
        func_001E3210(p, 0x2B);
    } else if (t == 6) {
        func_001581C0();
        func_0018C6B0(p, (s8)c);
        p[0x40D] = 0xFF;
        p[0x40C] = 0x10;
        func_0016EDA0(p[2], 5);
        func_001E3BB0(p, (u8)(D_004C2794->f74[p[2]] - 1));
    } else if (t < 3) {
        p[0x33B] = D_004C2794->f74[p[2]];
        D_004C2794->b76 = D_004C2794->f74[p[2]] | (p[2] << 4);
        p[0x33C] = 0x10;
        func_00183210(p, b, c);
        p[0x40D] = 0xFF;
        p[0x40C] = 0x10;
    }
}

