typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern f32 D_004F1FEC[];
extern f32 D_004F1FF8[];
extern u8 *D_004C25D4[1];
extern void func_00126970();
extern void func_00126280();
extern void func_00126340();
extern u8 *func_003DA750(s32, s32, s32);
extern void func_00333B00();
extern void func_003305E0();
extern u32 D_004C283C[1];
extern V3 D_004B7CD8;
extern V3 D_0045E858;
extern u8 *D_004C2840[1];
extern void func_001619B0(u8 *);
extern void func_001618E0(u8 *);

void func_00330750(s32 n) {
    u8 *o = func_003DA750(0, 6, 1);
    if (o != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_003305E0;
        *(s16 *)(o + 0xCC) = n * 2 + 8;
        *(u32 *)(o + 0x84) = D_004C283C[0];
        *(V3 *)(o + 0x34) = D_0045E858;
        *(u32 *)(o + 0x44) = 0xDD29;
        *(u32 *)(o + 0xD0) = 0x805;
        o[0x20] = n;
    }
}

void func_00161880(u8 *p) {
    switch (*(s8 *)(D_004C2840[0] + 0x9C) & 0xF) {
    case 0: break;
    case 4: func_001619B0(p); break;
    default: func_001618E0(p); break;
    }
}
