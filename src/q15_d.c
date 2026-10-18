typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct {
    u8 p0[0x34];
    f32 f34, f38, f3c;
    u8 p1[0x5C - 0x40];
    f32 f5c, f60, f64, f68, f6c;
    u8 p2[0x430 - 0x70];
    f32 f430;
} Obj;
extern s8 func_00175700();
extern void func_001757E0();

extern u16 *D_004C2718;
void func_001CF030(u8 *p) {
    *D_004C2718 = *(u16 *)(*(u8 **)(p + 0x18) + 0x168);
    p[6] = 0;
    p[5] = 0;
    p[0x13C] = 0;
    p[0x13D] = *(s8 *)(*(u8 **)(p + 0x18) + 0x13D);
    if (p[0x21] == (*(u8 **)(p + 0x18))[7]) p[4] = 3;
    p[0x24] = (p[0x21] & 1) ? 0 : 0;
}

extern s8 D_004C2858, D_004C2854, D_004C286C;
extern void func_001E41B0();
extern void func_001E41C0();
extern void func_001E46D0();
extern void func_001E4260();
void func_0038A9C0(void) {
    func_001E41B0((u8)(D_004C2858 << 3));
    func_001E41C0((u8)(*(u8 *)&D_004C2858 << 3));
    func_001E46D0(D_004C2854 * 35);
    if (D_004C286C != 0) {
        func_001E4260(1);
    } else {
        func_001E4260(0);
    }
}

extern void (*D_004BF670[2])();
void func_001A33E0(u8 *p, u8 *q) {
    if (*(u16 *)(q + 0x168) != *(u16 *)(p + 0xD0)) {
        u32 t = p[4];
        p[4] = t + 1;
        return;
    }
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    p[0x24] = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    D_004BF670[p[5]](p, q);
}
