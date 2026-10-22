typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern s32 D_004C283C;
extern V3 D_0045ECD0;
extern V3 D_00460CC0[];
extern u8 *func_003DA750();
extern void func_0033C300();
extern void func_0033C250();
extern void func_00343B10();
extern void func_00170DF0();
extern void func_003B3880();
extern void func_00175700();
extern void func_001E7F60();
extern void func_001757E0();
extern int func_00174470(const void *);
extern void func_003B3870();
extern void func_0016B0C0();
extern void func_00166C80();
extern void func_001830D0();
extern void func_001863F0();
extern void func_0022FFB0();
extern void func_00231D70();

void func_0033C470(void) {
    u8 *o;
    s32 i;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0033C300;
        *(s16 *)(o + 0xCC) = 0x1C;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(V3 *)(o + 0x34) = D_0045ECD0;
        *(s32 *)(o + 0xD0) = 0x805;
        i = 0;
        do {
            func_0033C250(o, i);
            i++;
        } while (i < 2);
    }
}

