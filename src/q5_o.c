typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FD0[];
extern f32 D_004F1FCC[];
extern f32 D_004F1FC8[];
typedef struct { u8 pad[0x7C]; s16 h7c[1]; } G1;
extern G1 *D_004C2794;

void func_0036CD60(u8 *a) {
    extern void func_001757E0();
    u8 *o = *(u8 **)(a + 0x18);
    u8 *p = *(u8 **)(o + 0x220);
    a[0x13C] = 1;
    *(f32 *)(a + 0x34) = *(f32 *)(p + 0x34);
    *(f32 *)(a + 0x38) = 171.428558f + D_004F1FD0[0];
    *(f32 *)(a + 0x3C) = *(f32 *)(*(u8 **)(a + 0x18) + 0x3C);
    if (*(s16 *)(a + 0x140) != 0) {
        if (D_004F1FCC[0] < *(f32 *)(a + 0x34)) {
            *(f32 *)(a + 0x34) = D_004F1FCC[0] - 53.3333321f;
        }
    } else {
        if (!(D_004F1FC8[0] <= *(f32 *)(a + 0x34))) {
            *(f32 *)(a + 0x34) = 53.3333321f + D_004F1FC8[0];
        }
    }
    a[0x1B0] = 0x42;
    a[0x1B1] = 0x42;
    a[0x1B5] = 0x30;
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(s32 *)(a + 0x1D8) = 0;
    D_004C2794->h7c[a[2]]++;
    a[0x24] = 0xB;
    *(s32 *)(a + 0x5C) = 0;
    *(s32 *)(a + 0x68) = 0;
    *(s32 *)(a + 0x60) = 0;
    *(u32 *)(a + 0x6C) = 0xBF9A4924;
    func_001757E0(a, 0x17, 0x17);
}
