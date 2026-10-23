typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


typedef struct { u8 pad[0x7C]; s16 h7C[8]; } G7C;
extern G7C *D_004C2794;
extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

void func_002673D0(u8 *p, u8 *state_unused) {
    extern int func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00374E50(u8 *, s32);
    u32 t;
    if ((s8)func_00175700(p) < 0) {
        t = p[7];
        p[7] = t + 1;
        D_004F1F45[0] = 2;
        D_004F1F46[0] = 1;
        p[0x1B5] = 0x45;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->h7C[p[2]]++;
        t = *(u16 *)(p + 0x354);
        if ((t & 0x3000) == 0) {
            func_001757E0(p, 0x16, 0x29);
            func_00374E50(p, 0);
        } else if (t & 0x2000) {
            p[7] = 2;
            func_001757E0(p, 0x16, 0x28);
            func_00374E50(p, 0);
        } else {
            p[7] = 3;
            func_001757E0(p, 0x16, 0x2A);
            func_00374E50(p, 0);
        }
    }
}
