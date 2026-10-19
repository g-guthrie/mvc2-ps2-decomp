typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef float f32;

extern s32 D_004C22EC;
extern void func_003FE170(void);
void func_003FEBB8(void) { D_004C22EC = 1; func_003FE170(); }

extern s32 D_004C2418;
extern volatile s32 D_004C2414;
extern u8 D_00485880[];
extern void func_0011D8F8(void *, s32, s32);
void func_00404638(void) {
    s32 n = D_004C2418;
    (void)D_004C2414;
    if (n == 0) {
        func_0011D8F8(D_00485880, 0, 0x700);
        n = D_004C2418;
    }
    n++;
    D_004C2418 = n;
}

