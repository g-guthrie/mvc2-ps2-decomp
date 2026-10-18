typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern u8 D_004BF3F4[4];
extern s32 D_004C27E8;
extern s32 D_004C27FC;
extern V3 D_00443E40[];
extern u8 *func_003DA750(s32, s32, s32);
extern void func_0014A4D0(void);

void func_0014A410(s32 n) {
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_0014A4D0;
        switch (n) {
        case 0:
            *(s16 *)(o + 0xCC) = D_004BF3F4[n];
            *(s32 *)(o + 0x84) = D_004C27E8;
            break;
        default:
            *(s16 *)(o + 0xCC) = D_004BF3F4[n];
            *(s32 *)(o + 0x84) = D_004C27FC;
            break;
        }
        *(s32 *)(o + 0xD0) = 1;
        *(V3 *)(o + 0x34) = D_00443E40[n];
    }
}
