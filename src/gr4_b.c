typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { u8 pad[3]; s8 b3; s8 b4; } G;
extern G *D_004C2840;
extern void func_0012D670(void);
extern void func_0012D6B0(void);
void func_0012D570(void) {
    extern s32 func_0012ABC0(s32, s32);
    extern s32 func_0012ABA0(u32, s32, s32);
    extern s32 func_003299D0(void);
    extern s32 func_001315F0(void);
    extern s32 func_001316D0(void);
    extern void func_003298B0(s32, s32, s32);
    extern void func_00129060(s32, void *);
    u32 h;
    h = func_0012ABC0(3, 0) & 0xFFFF;
    if (func_003299D0() == 0) {
        D_004C2840->b4 = func_0012ABA0(h, D_004C2840->b4, 3);
        switch (func_001315F0()) { default:
            func_003298B0(0xFF000000, 10, 1);
            if (D_004C2840->b4 == 3) { D_004C2840->b3 = 4; func_00129060(8, func_0012D670); }
            else { D_004C2840->b3 = 3; func_00129060(8, func_0012D6B0); }
            return;
        case 0:
        if (func_001316D0() != 0) {
            D_004C2840->b3 = 4; func_003298B0(0xFF000000, 10, 1); func_00129060(8, func_0012D670);
        } }
    }
}
