typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s32 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_003928B0(u8 *);
extern void func_001E7F60(u8 *);
extern s32 func_003DA750(s32, s32, s32);
extern void func_0015F8E0();
extern void func_00332C40();
extern u16 *D_004C29C8;
extern s32 D_004C283C;
extern V3 D_004454F8;
extern V3 D_004B7B10;

void func_00391F50(u8 *p) {
    if (*D_004C29C8 != *(u16 *)(*(u8 **)(p + 0x18) + 0x168)) {
        func_003928B0(p);
    } else if ((s8)func_00175700(p) < 0) {
        func_003928B0(p);
    } else {
        func_001E7F60(p);
    }
}

void func_0015FAA0(u8 *p) {
    u8 *r = (u8 *)func_003DA750(0, 6, 1);
    if (r) {
        r[0x13C] = 1;
        *(u32 *)(r + 0x10) = (u32)func_0015F8E0;
        *(s32 *)(r + 0xD0) = 0x3D;
        *(s16 *)(r + 0xCC) = 0x5A;
        *(s32 *)(r + 0x84) = D_004C283C;
        *(u8 **)(r + 0x14) = p;
        *(u32 *)(r + 0x74) = 0x3F800000;
        *(V3 *)(r + 0x50) = D_004454F8;
    }
}

void func_00332F70(u8 *p) {
    u8 *r = (u8 *)func_003DA750(0, 6, 1);
    if (r) {
        r[0x13C] = 1;
        *(u32 *)(r + 0x10) = (u32)func_00332C40;
        *(s16 *)(r + 0xCC) = 2;
        *(s32 *)(r + 0x84) = D_004C283C;
        *(s32 *)(r + 0xD0) = 0x803;
        *(V3 *)(r + 0x34) = D_004B7B10;
        *(u8 **)(r + 0x14) = p;
        *(u8 **)(r + 0xC8) = p + 0x88;
    }
}
