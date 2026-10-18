typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/w188_e.c "-O3,p -sdatathreshold 8" */

extern s16 D_004C27A4;
u8 *func_003C9240(u8 *a) {
    u8 *o = 0;
    u8 *s0;
    u8 *s1;
    s32 s2;
    extern u8 *func_003DA750(u8 *, s32, s32);
    extern void func_003C9330(void);
    if (D_004C27A4 > 7) {
        o = func_003DA750(0, 2, 0);
        *(void (**)(void))(o + 0x10) = func_003C9330;
        o[0x21] = 0;
        o[0x20] = 0;
        *(u8 **)(o + 0x18) = a;
        o[1] = a[1];
        *(s16 *)(o + 0x26) = 0x3803;
        s1 = o;
        s2 = 6;
        do {
            s0 = o;
            o = func_003DA750(o, 2, 2);
            *(void (**)(void))(o + 0x10) = func_003C9330;
            o[0x20] = 1;
            o[0x21] = 0;
            *(s32 *)(o + 0x18) = *(s32 *)(s0 + 0x18);
            o[1] = a[1];
            *(s16 *)(o + 0x26) = 0x3803;
            *(u8 **)(o + 0xD4) = s1;
            o[0xD8] = s2;
            o[0x22] = 0xFF;
            s2--;
            o[0x13C] = 0;
        } while (s2 >= 0);
    }
    return o;
}

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G_0023FC90;
extern G_0023FC90 *D_004C2794;
extern s8 data_s8_004C02CC;
extern s8 D_004C02E4;
extern s8 D_004C02D0;
extern s8 D_004C02E8;
extern s8 D_004C02D4;
extern s8 D_004C02EC;
void func_0023FC90(u8 *a) {
    s32 x;
    s32 y;
    s32 z;
    extern void func_001E3710(u8 *, u8);
    extern void func_001757E0(u8 *, s32, u8);
    switch (a[0x1FC]) {
    case 0:
        x = 0xF;
        z = 0;
        y = 0x14;
        if (a[0x210] == 0) *(s8 **)(a + 0x408) = &data_s8_004C02CC;
        else *(s8 **)(a + 0x408) = &D_004C02E4;
        a[0x1BB] = 0;
        break;
    case 1:
        z = 1;
        x = 0x10;
        y = 0x15;
        if (a[0x210] == 0) *(s8 **)(a + 0x408) = &D_004C02D0;
        else *(s8 **)(a + 0x408) = &D_004C02E8;
        a[0x1BB] = 1;
        break;
    case 2:
        z = 2;
        x = 0x11;
        y = 0x16;
        if (a[0x210] == 0) *(s8 **)(a + 0x408) = &D_004C02D4;
        else *(s8 **)(a + 0x408) = &D_004C02EC;
        a[0x1BB] = 2;
        break;
    }
    a[0x1B5] = x;
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(u32 *)(a + 0x1D8) = 0;
    D_004C2794->f7c[a[2]]++;
    func_001E3710(a, y);
    func_001757E0(a, 0xC, z);
}

void func_003B73B0(u8 *a, u8 *b) {
    s32 v;
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003B7520(u8 *);
    extern void func_001E7F60(u8 *);
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) + *(f32 *)(a + 0x60);
    a[0x1B3] = 0;
    if (b[5] != 0 || b[0x1E4] != 0x1D) {
        a[4]++;
        a[0x13C] = 0;
        return;
    }
    if (b[6] >= 3) {
        if (a[5] == 0) {
            a[5] = a[5] + 1;
            a[0x13C] = 1;
            func_001757E0(a, 0x17, 2);
        }
    }
    if (a[5] == 0) {
        func_00175700(a);
    } else {
        if ((s8)func_00175700(a) < 0) {
            a[4]++;
            a[0x13C] = 0;
            return;
        }
    }
    v = *(s8 *)(a + 0x151);
    if (v != 0) {
        a[0x1B5] = v;
        a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
        *(u32 *)(a + 0x1D8) = 0;
        D_004C2794->f7c[a[2]]++;
        a[0x151] = 0;
    }
    func_003B7520(a);
    func_001E7F60(a);
}
