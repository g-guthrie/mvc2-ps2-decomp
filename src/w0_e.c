typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { void (*fn)(); s32 arg; } CB;
extern CB D_004C2B20;
extern u8 D_00496748[];
void func_004112D8(char *fmt, ...) {
    extern void func_0011D8F8();
    extern int func_00122340();
    char *ap;

    func_0011D8F8(D_00496748, 0, 0x100);
    func_00122340(D_00496748, fmt, __builtin_next_arg(fmt) - 56);
    if (D_004C2B20.fn != 0) D_004C2B20.fn(D_004C2B20.arg, D_00496748);
}
