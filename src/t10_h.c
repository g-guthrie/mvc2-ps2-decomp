typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700();
extern void func_001757E0();
extern s32 func_00185980();
extern void func_00185640();
extern void func_00178F20();
extern void func_00179160();
extern void func_001E7F60();
extern u8 *func_003DA750();
extern void func_00396E30();
extern u8 *D_004C2794;
extern u8 D_004CAB79;
typedef struct { u8 a; u8 pad; u16 b; u32 c; } E8;
extern E8 D_004CA670[];

s32 func_00396D10(u8 *a0, u8 *a1) {
    s8 i = 0;
    s8 n = 0;
    while (i < 12) {
        u8 *o;
        if ((o = func_003DA750(a0, 1, 2)) != 0) {
            *(void **)(o + 0x10) = func_00396E30;
            o[0x20] = 1;
            *(u8 **)(o + 0x18) = a0;
            *(u16 *)(o + 0x26) = 0x2201;
            o[0x8E] = n;
            n++;
            o[0x98] = a1[0x10];
        }
        i++;
    }
    return 0;
}

