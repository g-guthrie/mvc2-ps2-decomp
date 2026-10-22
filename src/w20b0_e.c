typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern void (*D_00477170[])();
extern u16 D_004F4484[];
extern u16 D_004F4498[];

void func_003D1580(void) {
    extern void func_00417A40();
    extern void func_00174170();
    extern s32 func_0012F930(s32);
    extern void func_001E4150();
    extern void func_001E40E0();
    extern void func_001E4140();
    extern void func_001E46C0(s32);
    extern void func_001E4480(s32, s32);
    extern void func_001E4340(s32);
    extern void func_001E3CE0(s32);
    extern void func_0012E6B0();
    s32 r;
    u8 *q, *c;
    s32 b;
    D_004C2840[0x2E] = 0;
    D_00477170[*(s8 *)(D_004C2840 + 1)]();
    func_00417A40();
    func_00174170();
    r = 0;
    if (*(s8 *)(D_004C2840 + 1) != 10) {
        r = func_0012F930(1);
    }
    if (r != 0) return;
    if (*(s32 *)((q = D_004C2840) + 0x14) != 0x40) return;
    c = q + 1;
    b = *(s8 *)c;
    if (b == 9 || b == 0xC || b == 0xD) return;
    if ((D_004F4484[0] & 0x8000) == 0) {
        if ((D_004F4498[0] & 0x8000) == 0) return;
    }
    switch (b) { case 10: case 8: case 7: return; }
    *c = 7;
    D_004C2840[2] = 0;
    func_001E4150();
    func_001E40E0();
    func_001E4140();
    func_001E46C0(0x7F);
    func_001E4480(6, 1);
    func_001E4340(1);
    func_001E3CE0(0);
    func_0012E6B0();
}
