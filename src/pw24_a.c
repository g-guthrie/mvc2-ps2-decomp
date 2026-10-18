typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00361880(u8 *a, u8 *b) {
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38);
    if (*(s16 *)(a + 0x140) == 0) {
        *(f32 *)(a + 0x34) += -211.666656f;
    } else {
        *(f32 *)(a + 0x34) -= -211.666656f;
    }
    *(f32 *)(a + 0x38) += 205.714279f;
    *(f32 *)(a + 0x50) = 1.2f;
}

extern void func_00185770();
extern void func_00186A60();

void func_002FA2C0(u8 *a, u8 *b) {
    a[5] = 0;
    a[6] = 1;
    a[7] = 0;
    a[0x20B] = 4;
    a[0x20B] |= 0x40;
    a[0x20B] |= 0x80;
    func_00185770(a);
    a[0x1FD] = 4;
    func_00186A60(a, 0x1D);
    b[6] = 0;
    *(s32 *)(b + 0x6C) = 0;
    *(s32 *)(b + 0x68) = 0;
    *(s32 *)(b + 0x60) = 0;
    *(s32 *)(b + 0x5C) = 0;
}

extern void func_00175670();
extern s32 func_00174240();
extern s32 func_001E1FC0();

s32 func_001E1F30(u8 *a, u8 *b) {
    func_00175670(a);
    a[0x159] = 0;
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    if (func_00174240(a) == 0) {
        return func_001E1FC0(a, b);
    }
}

extern void func_001C3DC0();
extern void func_001C3E60();
extern s8 func_00175700();
extern u8 D_0044CA70[];

void func_001C20E0(u8 *a, u8 *b) {
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    if (!(*(f32 *)(b + 0x430) < *(f32 *)(a + 0x38))) {
        u32 t = a[7];
        a[7] = t + 1;
        *(f32 *)(a + 0x38) = *(f32 *)(b + 0x430);
        *(s16 *)(a + 0x140) = *(s16 *)(b + 0x140);
        func_001C3DC0(a, b, D_0044CA70);
        func_001C3E60(a, b);
        func_00175700(a);
    }
}

extern void func_001863F0();
extern void func_0030F650();
extern void func_0030D640();

void func_0030D5A0(u8 *a) {
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    func_001863F0(a);
    if (*(s32 *)(a + 0x334) == 0) {
        if (func_00175700(a) < 0) {
            func_0030F650(a);
        }
    } else {
        func_0030D640(a);
    }
}
