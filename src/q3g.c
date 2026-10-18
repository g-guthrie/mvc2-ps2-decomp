typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern s32 D_004C2B4C;
extern s32 D_004C2B50;
extern u8 func_004188F0[];
extern void func_003FDAA0(void);
extern void func_00402818(void *a, s32 b);
extern s32 func_003DCF70(s32 a);
extern s32 func_00401150(s32 a, s32 b, s32 c);
extern void func_00402208(s32 a, s32 b);
extern void func_00402458(s32 a, s32 b);
extern void func_00400D18(s32 a);
extern void func_004188E0(void);
extern void func_004189A0(void);

void func_00418910(void) {
    func_003FDAA0();
    func_00402818(func_004188F0 + 0x10, 0);
    D_004C2B4C = func_003DCF70(0x301E4);
    do {
        D_004C2B50 = func_00401150(2, D_004C2B4C, 0x301E4);
    } while (D_004C2B50 == 0);
    func_00402208(D_004C2B50, 0x4B);
    func_00402458(D_004C2B50, 2);
    func_00400D18(0);
    func_004188E0();
    func_004189A0();
}
