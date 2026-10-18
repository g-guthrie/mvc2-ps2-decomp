typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;

extern volatile s32 D_004C2330, D_004C2334;
extern s32 func_003FE190();
extern void func_003FE120();
extern s32 func_003FE4F0();
void func_003FEAE8(void)
{
    if (func_003FE190(D_004C2330) == D_004C2330) {
        func_003FE120(D_004C2330);
    }
    if (func_003FE4F0() == 1) {
        if (func_003FE190(D_004C2334) == D_004C2334) {
            func_003FE120(D_004C2334);
            __asm__ volatile("");
        }
    }
}
