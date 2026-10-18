typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct V3 { float x, y, z; } V3;
extern s32 D_004C283C;
extern V3 D_0045EB58;
extern u8 *func_003DA750();
extern void func_0033B0D0();
extern void func_0033AEE0();

void func_0033B0E0(void) {
    u8 *o;
    s32 i;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0033B0D0;
        *(s16 *)(o + 0xCC) = 9;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(V3 *)(o + 0x34) = D_0045EB58;
        *(s32 *)(o + 0x44) = 0x9B07;
        *(s32 *)(o + 0xD0) = 0x807;
        i = 0;
        do {
            func_0033AEE0(o, i);
            i++;
        } while (i < 12);
    }
}
