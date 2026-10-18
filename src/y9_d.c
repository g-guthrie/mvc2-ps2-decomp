typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3a;
typedef struct { f32 x, y, z, w; } V4a;
extern V3a D_00442890;
extern V4a D_004428A0;

void func_00147580(void) {
    extern void func_00146CD0();
    extern u8 *func_003DA750();
    extern void D_00147560();
    s32 i;
    u8 *o;
    i = 0;
    do {
        func_00146CD0(0, (s8)i);
        i++;
    } while (i < 4);
    func_00146CD0(4, 0);
    i = 0;
    do {
        if ((o = func_003DA750(0, 0xF, 0)) != 0) {
            o[0x13C] = 0;
            *(void **)(o + 0x10) = D_00147560;
            o[0x23] = 2;
            o[0x20] = i;
            *(V3a *)(o + 0x50) = D_00442890;
            *(V4a *)(o + 0x74) = D_004428A0;
        }
        i++;
    } while (i < 2);
}
