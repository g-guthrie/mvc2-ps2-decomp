typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_00359B30(u8 *p);

extern u8 D_004C2168[8];
extern u8 *D_004C2840;
extern u32 D_004C28BC;
extern void func_001757E0();
extern void func_00123760();
extern void func_001E3CE0();
extern void func_003DA6F0();
extern void func_003D7310();
extern void func_001527F0();
extern u8 *func_00416180();
extern void func_00176230();
extern u8 D_00446C08[];

void func_003C84E0(u8 *p, float x, float y) {
    *(float *)(p + 0x5C) = x / 32.0f;
    *(float *)(p + 0x60) = y / 32.0f;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    *(s16 *)(p + 0x1C) = 0;
    func_001757E0(p, 0x14, D_004C2168[p[0x20] * 2]);
}

void func_0032C040(void) {
    *(s16 *)(D_004C2840 + 8) = *(s16 *)(D_004C2840 + 8) - 1;
    if (*(s16 *)(D_004C2840 + 8) <= 0) {
        *(s8 *)(D_004C2840 + 4) = *(s8 *)(D_004C2840 + 4) + 1;
        func_00123760(2);
        func_001E3CE0(0x49);
    }
}

void func_001765C0(void) {
    ((void (**)(void))D_00446C08)[*(s8 *)(D_004C2840 + 3)]();
    func_003DA6F0(6);
    func_003DA6F0(0xD);
    func_003D7310(func_001527F0);
}

void func_001E6610(u8 *a, s32 n) {
    u8 *r;
    if (n >= 0x1B) n -= 3;
    r = func_00416180(D_004C28BC + 0x100000, n);
    func_00176230(r, D_004C28BC + 0x300000 + ((u32)a << 17));
}
