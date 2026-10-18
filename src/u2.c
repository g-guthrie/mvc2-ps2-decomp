typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004BEE80[];
extern u8 D_004BEEA0[];
extern u8 D_004BEED0[];
extern u8 D_004BEEC0[];
extern u8 D_004BEEF0[];
extern u8 *D_00633650;
extern u8 *D_00633640;
extern volatile s32 D_00633644;
extern u8 *D_00633648;
extern s32 D_0063364C;
extern void func_0011EB60();
extern void func_00400F08();
extern void func_0011D8F8();
extern void func_00400D38();
extern u8 *func_003DCF70();
extern void func_00400DE0();
extern void func_003FE5D8();

s32 func_00418B80(void) {
    func_0011EB60(D_004BEE80);
    func_00400F08(0);
    func_0011EB60(D_004BEEA0);
    func_0011D8F8(&D_00633650, 0, 0x14);
    D_00633650 = D_004BEEC0;
    func_00400D38(&D_00633650);
    func_0011EB60(D_004BEED0);
    func_0011D8F8(&D_00633640, 0, 0x10);
    D_00633640 = D_004BEEF0;
    D_00633644 = 0x80;
    D_0063364C = (D_00633644 + 1) * 40 + 0x140;
    D_00633648 = func_003DCF70(D_0063364C);
    func_00400DE0(&D_00633640);
    func_003FE5D8(0);
    return 1;
}

extern u8 D_0061C7A0[];
extern u8 D_004BA8C0[];
extern u32 func_003E93A0();
extern void func_003E9110();
extern s32 func_003EBD30();
extern void func_003ED0D0();
extern s32 func_003DCFE0();
extern void func_003EABA0();
extern void func_003E9250();

u32 func_003E9010(u8 *a, s32 b) {
    u32 w;
    u8 *e;
    w = func_003E93A0();
    e = D_0061C7A0 + (((w & 0xFFFF0000) >> 16) - 1) * 64;
    func_003E9110(a, w, b);
    if (*(s32 *)(a + 0x10) == 0) {
        if (func_003EBD30(&w, 1) == 0) {
            func_003ED0D0(D_004BA8C0);
            return 0;
        }
        *(s32 *)(e + 0x28) = func_003DCFE0(*(s32 *)(e + 8), 2);
    } else {
        if (*(s32 *)(a + 4) == 0x100) {
            func_003EABA0(a, e, 1);
        } else {
            func_003EABA0(a, e, 0);
        }
        func_003E9250(w, b);
    }
    return w >> 16;
}
