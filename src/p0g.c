typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_004C24A8;
extern s32 D_004C2494;
extern s32 D_004C24B8;
extern s32 D_004C24B0;
extern void func_0010AE38(s32);
extern void func_004093E8(s32);
extern void func_0040DE60(void);
extern void func_00409698(void);
extern void func_004110D8(void);
extern void func_00410BD8(void);
void func_0040E4B0(void) {
    if (--D_004C24A8 == 0) {
        func_0010AE38(D_004C2494);
        D_004C2494 = 0;
        func_004093E8(D_004C24B8);
        D_004C24B8 = 0;
        func_0010AE38(D_004C24B0);
        D_004C24B0 = 0;
        func_0040DE60();
        func_00409698();
        func_004110D8();
        func_00410BD8();
    }
}

extern volatile long D_004C2358;
extern volatile long D_004C2300;
extern volatile long D_004C2360;
extern volatile s32 D_004C2330;
extern volatile s32 D_004C2334;
extern volatile s32 D_004C22DC;
extern void func_003FE1F8(s32);
extern s32 func_003FE4F0(void);
extern void func_003FEB58(void);
extern void func_00411A48(void);
extern void func_003FE170(void);
extern void func_00103C20(void);
void func_003FDEE8(void) {
    if (D_004C2358 == 0) {
        do {
            D_004C2300++;
            func_003FE1F8(D_004C2330);
            if (func_003FE4F0() == 1) func_003FE1F8(D_004C2334);
            func_003FEB58();
            D_004C22DC = 1;
            func_00411A48();
            D_004C22DC = 0;
            func_003FE170();
        } while (D_004C2358 == 0);
    }
    D_004C2360 = 1;
    func_00103C20();
}

