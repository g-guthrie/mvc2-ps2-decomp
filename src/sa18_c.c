typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G36;

extern G36 *D_004C2794;
extern u16 D_004C1C68[2];

void func_0036ACC0(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32, s32);
    p[0x13C] = 1;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = 0x36;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    *(u16 *)(p + 0x1C) = *(u16 *)((s32)D_004C1C68);
    *(s16 *)(p + 0x1E) = 1;
    *(f32 *)(p + 0x38) += 180.0f;
    *(f32 *)(p + 0x118) = 0.30000001192092896f;
    *(f32 *)(p + 0x68) = 0.03999999910593033f;
    *(f32 *)(p + 0x6C) = 0.2800000011920929f;
    *(f32 *)(p + 0x50) = 1.0f;
    *(f32 *)(p + 0x54) = 1.0f;
    *(f32 *)(p + 0x50) /= 100.0f;
    *(f32 *)(p + 0x54) /= 100.0f;
    func_001757E0(p, 0x17, 0, 0x3F800000);
}
