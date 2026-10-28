typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* EE GCC 2.96: ./tryee.sh src/sa3_m.c sn */
typedef struct { u8 pad0[2]; s8 b2; u8 pad3[0x31]; s32 w34; } P_m;
extern volatile s32 D_0048733C, D_00487338, D_00487344;
extern char D_004BD5D0[];
extern void func_00411288(void);
extern void func_004112B0(void);
extern s32 func_0010FB48(void);
extern void func_0011EB60(char *, s32);

s32 func_004080E8(P_m *p) {
    s32 t;
    if (D_0048733C == 0) return 0;
    if (p->b2 != 2) return 0;
    D_00487344 = 1;
    if (D_00487338 == 1) {
        func_00411288();
        t = func_0010FB48();
        func_004112B0();
    } else {
        t = func_0010FB48();
    }
    D_00487344 = 0;
    if ((u32)(t + 1) >= 2) { p->w34 = t; func_0011EB60(D_004BD5D0, t); return 1; } return 0;
}
