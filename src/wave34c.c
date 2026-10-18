typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004C0AD0[4];
extern u8 D_004C0AC8[4];
s32 func_00174170(void);
void func_001757E0(u8 *a, s32 b, s32 c);
void func_00296EA0(u8 *a) {
    u32 t = a[6];
    u32 c;
    a[6] = t + 1;
    c = D_004C0AD0[a[0x20]];
    if (a[0x20] == 0) {
        *(s16*)(a + 0x1C) = func_00174170() & 3;
        c = D_004C0AC8[*(s16*)(a + 0x1C)];
    }
    func_001757E0(a, 0x13, c);
}

extern void (*D_004BF5D8[2])(u8 *, s32);
void func_0019EB00(u8 *a, s32 b) {
    u8 *p = *(u8**)(a + 0x14);
    if (p[4] != 1) {
        u32 t = a[4];
        a[4] = t + 1;
    } else if (p[0x20] != 1 || p[0x21] != 0) {
        u32 t = a[4];
        a[4] = t + 1;
    } else {
        D_004BF5D8[a[5]](a, b);
    }
}

extern u8 D_004C0F10[4];
extern u8 D_004C0F08[4];
void func_001E3210(u8 *a, u8 b);
void func_002CD7E0(u8 *a) {
    u32 t = a[6];
    u32 s;
    a[6] = t + 1;
    s = D_004C0F10[a[0x20]];
    if (a[0x20] == 0) {
        s = D_004C0F08[func_00174170() & 7];
        func_001E3210(a, (func_00174170() & 1) + 0xF);
    }
    func_001757E0(a, 0x13, s);
}

extern u8 *D_004C2840;
void func_00175700(u8 *a);
void func_0028D910(u8 *a, s32 b);
void func_0028CC80(u8 *a);
void func_0028D8B0(u8 *a);
void func_0028C770(u8 *a) {
    a[0x40C] = 2;
    a[0x33C] = 5;
    a[0x22] = ((s8*)D_004C2840)[0x1C] & 1;
    func_00175700(a);
    if (((s8*)a)[0x151] == 0) {
        u32 t = a[6];
        a[6] = t + 1;
        func_0028D910(a, 3);
        func_0028D910(a, 4);
        func_0028D910(a, 5);
    }
    func_0028CC80(a);
    func_0028D8B0(a);
}
