typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 *D_004C2840;
extern void func_003298B0();
extern void func_003DA410();
extern void func_00122840();
extern void func_001E40E0();
extern void func_001E4140();
extern void func_001E4150();

void func_0016BF10(void) {
    D_004C2840[5] = 5;
    *(u16 *)(D_004C2840 + 8) = 0xF0;
    func_003298B0(0xFF000000, 0x20, 0);
    func_003DA410();
    func_00122840(0xFF000000);
    func_001E40E0();
    func_001E4140();
    func_001E4150();
}

extern u8 D_004C0088[2];
extern u8 D_004C0080[8];
extern s32 func_00174170();
extern void func_001757E0();

void func_00227B90(u8 *p) {
    u32 t = p[6];
    u32 a2;
    p[6] = t + 1;
    a2 = D_004C0088[p[0x20]];
    if (p[0x20] == 0) {
        a2 = D_004C0080[func_00174170() & 3];
        *(u32 *)(p + 0x2CC) = a2;
    }
    func_001757E0(p, 0x13, a2);
}
