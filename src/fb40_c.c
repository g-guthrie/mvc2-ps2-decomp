typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern s32 D_004C25FC;
extern s32 D_004CA040[];
extern s32 D_004CA044[];
extern s32 D_004CA048[];
extern s32 D_004CA04C[];
extern s16 D_004CA050[];
extern s16 D_004CA052[];
extern s16 D_004CA054[];
extern s16 D_004CA056[];
extern s16 D_004CA058[];
extern s16 D_004CA05A[];
extern s16 D_004CA05C[];
extern u8 D_004CA062[];
extern u8 D_004CA068[];
extern u8 D_004CA06E[];
extern s16 D_004CA078[];
extern void (*D_0043CD08[])(s32, s32);

void func_0012C8E0(s32 a, s32 b) {
    extern void func_003DA650(s32);
    extern void func_0014D700(void);
    extern void func_00146C80(s32);
    extern void func_001489E0(s32, s32);
    extern void func_0011D8F8(void *, s32, s32);
    extern void func_0012C120(void *);
    extern s32 func_0014C910(void);
    extern void func_0014CF20(s32, s32, s32);
    extern void func_0014D1C0(s32, s32, void *);
    extern s32 func_0014D630(void);
    extern s32 func_0014D410(void);
    extern s32 func_0014D570(void);
    extern s32 func_0012C5C0(void *, s32, s32);
    extern void func_003298B0(s32, s32, s32);
    extern void func_0014C280(s32, s32, s32);
    extern void func_0012CE00(s32, s32);
    extern void func_0012CB50(s32, s32);
    s32 r;
    func_003DA650(13);
    func_0014D700();
    func_00146C80(6);
    func_001489E0(12, 12);
    func_0011D8F8(D_004CA040, 0, 0x3C);
    func_0012C120(D_004CA040);
    D_004CA04C[0] = func_0014C910();
    func_0014CF20(D_004CA050[0], D_004CA054[0], D_004CA05C[0]);
    func_0014D1C0(0, D_004CA056[0], D_004CA062);
    func_0014D1C0(1, D_004CA058[0], D_004CA068);
    func_0014D1C0(2, D_004CA05A[0], D_004CA06E);
    D_004CA044[0] = func_0014D630();
    D_004CA048[0] = func_0014D410();
    D_004CA040[0] = func_0014D570();
    D_004CA052[0] = 1;
    D_004CA078[0] = 0;
    r = func_0012C5C0(D_004CA040, 1, 0);
    D_004C25FC = D_004C25FC + 1;
    func_003298B0(0xFF000000, 10, 0);
    switch (r) {
    case -1:
        D_004C2840[5] = 3;
        func_0014C280(0, 0, 1);
        func_0014C280(1, 0, 1);
        func_0014C280(2, 0, 1);
        func_0014C280(3, 0, 1);
        D_0043CD08[0] = func_0012CE00;
        break;
    case 1:
        D_004C2840[5] = 4;
        D_0043CD08[0] = func_0012CB50;
        func_0014C280(0, 0, 2);
        func_0014C280(1, 0, 2);
        func_0014C280(2, 0, 2);
        func_0014C280(3, 0, 2);
        D_0043CD08[0] = func_0012CE00;
        break;
    default:
        D_004C2840[5] = 0;
        D_0043CD08[0] = func_0012CB50;
        break;
    }
    D_0043CD08[0](a, b);
}
