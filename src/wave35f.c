typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00174470();
extern s32 func_00175700();
extern void func_001757E0();
extern void func_00398540();
extern void func_001E7F60();

void func_00398460(u8 *a0) {
    if (func_00174470(a0) == 0) {
        func_00398540(a0);
        return;
    }
    if (*(s8 *)(a0 + 0x1B2) != 0 || *(s8 *)(a0 + 0x1B3) != 0) {
        u32 t = a0[4];
        a0[4] = t + 1;
        func_001757E0(a0, 0x14, 1);
    } else {
        *(f32 *)(a0 + 0x34) += *(f32 *)(a0 + 0x5C);
        func_001E7F60(a0);
        func_00175700(a0);
    }
}

void func_00310E40(u8 *a0) {
    func_00175700(a0);
    if (!(*(f32 *)(a0 + 0x430) < *(f32 *)(a0 + 0x38))) {
        u32 t;
        *(f32 *)(a0 + 0x38) = *(f32 *)(a0 + 0x430);
        *(u32 *)(a0 + 0x60) = 0;
        *(u32 *)(a0 + 0x6C) = 0;
        t = a0[6];
        a0[6] = t + 1;
        *(u32 *)(a0 + 0x5C) = 0xC112AAAA;
        *(u32 *)(a0 + 0x68) = 0x3E8C0000;
        if (*(s16 *)(a0 + 0x140) != 0) {
            *(f32 *)(a0 + 0x5C) = -*(f32 *)(a0 + 0x5C);
            *(f32 *)(a0 + 0x68) = -*(f32 *)(a0 + 0x68);
        }
        func_001757E0(a0, 8, 3);
    }
}

extern void func_001830D0();
void func_002DF470(u8 *a0) {
    u32 v[3];
    u32 t;
    a0[0x40C] = 2;
    a0[0x33C] = 5;
    a0[0x405] = (a0[0x269] == 6) ? 2 : 0;
    func_00175700(a0);
    if (*(s8 *)(a0 + 0x151) != 0) {
        a0[0x404] = 0;
        a0[0x405] = 0;
        t = a0[7];
        a0[7] = t + 1;
        a0[0x151] = 0;
        v[1] = 0x434DB6DB;
        v[0] = 0;
        func_001830D0(a0, v, 1);
    }
}

void func_00296CE0(u8 *a0) {
    *(f32 *)(a0 + 0x34) += *(f32 *)(a0 + 0x5C);
    *(f32 *)(a0 + 0x5C) += *(f32 *)(a0 + 0x68);
    *(f32 *)(a0 + 0x38) += *(f32 *)(a0 + 0x60);
    *(f32 *)(a0 + 0x60) += *(f32 *)(a0 + 0x6C);
    if (*(f32 *)(a0 + 0x68) * *(f32 *)(a0 + 0x5C) > 0.0f) {
        u32 t = a0[6];
        a0[6] = t + 1;
        func_001757E0(a0, 2, 3);
    } else {
        func_00175700(a0);
    }
}
