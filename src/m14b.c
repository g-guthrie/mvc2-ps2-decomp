typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


typedef struct { f32 x, y, z; } V3;
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_00343D30(void);
extern s8 D_004C196C[8];
extern V3 D_00460CF0[];
extern u8 *D_004C283C;
void func_00343C90(u32 n) {
    u8 *r = func_003DA750(0, 6, 0);
    if (r) {
        r[0x13C] = 1;
        *(void **)(r + 0x10) = (void *)func_00343D30;
        *(s16 *)(r + 0xCC) = D_004C196C[n];
        *(u8 **)(r + 0x84) = D_004C283C;
        *(s32 *)(r + 0xD0) = 0x801;
        *(V3 *)(r + 0x34) = D_00460CF0[n];
        r[0x20] = n;
    }
}

extern void func_0032F540(void);
extern u8 D_004C27D0;
extern V3 D_0045E470;
extern V3 D_0045E47C;
void func_0032F4A0(void) {
    u8 *r = func_003DA750(0, 6, 0);
    if (r) {
        r[0x13C] = 1;
        *(void **)(r + 0x10) = (void *)func_0032F540;
        *(s16 *)(r + 0xCC) = 0xB;
        *(u8 **)(r + 0x84) = D_004C283C;
        if (D_004C27D0 == 0) {
            *(V3 *)(r + 0x34) = D_0045E470;
        } else {
            *(V3 *)(r + 0x34) = D_0045E47C;
        }
        *(s32 *)(r + 0xD0) = 0x801;
    }
}
