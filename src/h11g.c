typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s8 *D_004C2840;
extern u8 *D_004C2794;
extern u8 D_00583B9B[];
extern u32 D_004D3690[];
extern s16 D_00449268[];
extern s32 func_0032C180(s32);
extern void func_00123760(void);
extern void func_001E3CE0(s32);
extern void func_00122FE0(void);
extern void func_00151A20(u8);
extern void func_001520E0(u8);

void func_00153530(s32 a) {
    if (D_004C2840[0x9C] == 0 && D_004D3690[a] != 0) {
        func_00122FE0();
        func_00151A20(a);
        func_001520E0(a);
    }
}

void func_0032C560(void) {
    *(s16 *)(D_004C2840 + 8) -= 1;
    if (*(s16 *)(D_004C2840 + 8) <= 0) {
        D_004C2840[4]++;
        D_004C2840[7] = 1;
        *(s16 *)(D_004C2840 + 8) = 0x32;
    } else {
        func_0032C180(0);
    }
}

void func_00191BF0(u32 *a, u32 *b) {
    u8 *o;
    u8 x;
    s32 v;
    *a = 0;
    *b = 0;
    o = D_004C2794;
    x = o[(s8)o[0x3E] + 0x9A];
    if (x > 4) x = 4;
    v = D_00449268[x];
    *b = v;
    if (v != 0) {
        *a = *b >> 8;
        *b = *b << 24;
    }
}
