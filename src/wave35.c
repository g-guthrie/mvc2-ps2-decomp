typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_001C88F0();
extern void func_00175700(u8 *a, u8 *b);
extern void func_001C8AE0();
extern u8 D_004B55F0[];
extern f32 D_004F1F4C, D_004F1F58, D_004F1F94, D_004F1FA0;


void func_00123410(void) {
    *(V3 *)&D_004F1F58 = *(V3 *)&D_004F1F4C;
    *(V3 *)&D_004F1FA0 = *(V3 *)&D_004F1F94;
}

void func_00388E80(u8 *a0, u8 *a1) {
    u8 v = a1[7];
    if (v == 1) { a0[6] = 1; a0[7] = 0; return; }
    if (v == 2) { a0[6] = 2; a0[7] = 0; return; }
    if (v == 7) { a0[6] = 3; a0[7] = 0; return; }
}

extern void func_001757E0(u8 *a, s32 b, s32 c);
void func_001C6E20(u8 *a0, u8 *a1) {
    if (a1[0x1E4] != 0x16) {
        a0[7] = 4;
        func_001757E0(a0, 0x19, 0x15);
    } else if (*(s8 *)(a1 + 0x151) != 0) {
        u32 t = a0[4];
        a0[4] = t + 1;
        a0[0x13C] = 0;
    } else {
        func_00175700(a0, a1);
    }
}

extern void func_00175C00(u8 *a, s32 b);
extern void func_003DAA40(u8 *a);
void func_00328BB0(u8 *a0, u8 *a1) {
    if (a1[0x23E] == 1) {
        s8 t = a1[0x23D] - 1;
        a1[0x23D] = t;
        if (t < 0) a1[0x23D] = 0;
    }
    func_00175C00(a1, 1);
    func_003DAA40(a0);
}
