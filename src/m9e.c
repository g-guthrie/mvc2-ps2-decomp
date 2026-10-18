typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;



extern u16 *D_004C2718;
extern void func_001CF6F0();
extern void func_00175C00();
extern s32 func_001CF6A0();
extern void func_00175670();
extern s32 func_001CF720();
s32 func_001CF200(u8 *p) {
    func_001CF6F0(p);
    p[0x13C] = 1;
    if (*D_004C2718 != *(u16 *)(*(u8 **)(p + 0x18) + 0x168)) {
        func_00175C00(*(u8 **)(p + 0x18), 0);
        return func_001CF6A0(p);
    } else {
        if (*(s8 *)(*(u8 **)(p + 0x18) + 0x1B4) == 0) func_00175670(p);
        return func_001CF720(p);
    }
}
