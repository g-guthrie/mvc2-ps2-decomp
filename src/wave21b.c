typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2704;
void func_001BF550(u8 *a0) {
    if (*D_004C2704 < 11) {
        s16 t = *(s16 *)(a0 + 0x1E) - 1;
        *(s16 *)(a0 + 0x1E) = t;
        if (t <= 0) {
            u32 c;
            *(s16 *)(a0 + 0x1E) = 1;
            c = *D_004C2704;
            *D_004C2704 = c + 1;
            *(f32 *)(a0 + 0x34) += 53.333332f;
        }
    }
}

typedef float f32;
extern f32 D_004C1FF8[2];
extern f32 D_004F1FC8[];
extern f32 D_004F1FCC[];
s32 func_003B5640(u8 *a);
extern s8 *D_004C2840;
extern u8 D_004D18A0[];
void func_003D8F90(u8 *a);
void func_003D51E0(s8 *a0) {
    a0[0xE] = 0;
    D_004C2840[0xAB] = a0[6];
    D_004C2840[0xAC] = a0[7];
    D_004C2840[0xAD] = a0[8];
    D_004C2840[0xAE] = a0[0xD];
    D_004C2840[0x87] = a0[0xA];
    D_004C2840[0x1B] = a0[0xB];
    D_004C2840[0x8D] = a0[0xC];
    D_004C2840[0xB2] = a0[9];
    D_004C2840[0xB0] = a0[0x19];
    func_003D8F90(D_004D18A0);
}

void func_00294C20(u8 *a, s32 b);
void func_00293FD0(u8 *a);
void func_00294BC0(u8 *a);
s32 func_00175700();
void func_00293AE0(u8 *a0) {
    a0[0x40C] = 2;
    a0[0x33C] = 5;
    a0[0x22] = D_004C2840[0x1C] & 1;
    func_00175700(a0);
    if (*(s8 *)(a0 + 0x151) == 0) {
        u32 t = a0[6];
        a0[6] = t + 1;
        func_00294C20(a0, 3);
        func_00294C20(a0, 4);
        func_00294C20(a0, 5);
    }
    func_00293FD0(a0);
    func_00294BC0(a0);
}
