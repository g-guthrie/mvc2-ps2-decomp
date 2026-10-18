typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern void func_003DA410(void);
extern void func_00122840(u32);
extern void func_001E40E0(void);
extern void func_001E4140(void);
extern void func_001E4150(void);
extern void func_0012E770(u32);
void func_0016EC30(void) {
    D_004C2840[2] = 0;
    D_004C2840[3] = 0;
    D_004C2840[4] = 0;
    D_004C2840[5] = 0;
    D_004C2840[6] = 0;
    D_004C2840[7] = 0;
    D_004C2840[0x91] = 0;
    D_004C2840[0x92] = 0;
    D_004C2840[0x19] = 1;
    func_003DA410();
    func_00122840(0xFF000000);
    func_001E40E0();
    func_001E4140();
    func_001E4150();
    func_0012E770(D_004C2840[0x88]);
}

extern u8 *D_004C2840;
extern void func_00136B60(void);
extern void func_001237A0(void);
void func_0032A380(void) {
    *(s16 *)(D_004C2840 + 8) -= 1;
    if (*(s16 *)(D_004C2840 + 8) <= 0) {
        (*(s8 *)(D_004C2840 + 4))++;
        func_00136B60();
    }
    if (*(s8 *)(D_004C2840 + 0x4C) != 1) {
        func_001237A0();
    }
}

extern u8 *func_003DA780(s32, s32, s32);
extern void func_003CE5D0(void);
extern u32 D_004C283C;
extern void func_00170DF0(u32);
void func_003CE560(void) {
    u8 *o = func_003DA780(0, 0x10, 0);
    if (o) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_003CE5D0;
        *(s16 *)(o + 0xCC) = 1;
        *(u32 *)(o + 0x84) = D_004C283C;
        *(u32 *)(o + 0x34) = 0;
        *(u32 *)(o + 0x38) = 0;
        *(u32 *)(o + 0x3C) = 0;
        *(u32 *)(o + 0xD0) = 0x801;
        *(u32 *)(o + 0xD8) = 0;
        func_00170DF0(*(u32 *)(o + 0x84));
    }
}
