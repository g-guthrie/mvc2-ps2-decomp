typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
#include "runtime_directory_types.h"
extern char D_006310C0[];
extern s32 D_004895D4;
extern char D_004BE220[];
extern char D_004BE248[];
extern s32 func_0011D8F8(void *, s32, s32);
extern void func_0040C798();
extern void func_0040B098();
extern s32 func_0040C578(void);
extern s32 func_0040C2C0(void *, void *);
extern void func_0011EB60(void *, void *);
extern void func_0040AF58(void *, void *);
extern s32 func_0040C178(void *, void *, u32, s32);
extern s32 func_0040C3B0(void *, s32);

s32 func_0040C940(void *a, void *b, u32 n) {
    func_0011D8F8(D_006310C0, 0, 0x1000);
    if (D_004895C0.entries == 0) func_0040C798();
    func_0040B098();
    func_0040C578();
    if (a == 0 || b == 0 || n == 0) return 0;
    if (func_0040C2C0(a, D_006310C0) == 0) {
        if (D_004895D4 != 2) func_0011EB60(D_004BE220, a);
        func_0040AF58(0, D_004BE248);
        return 0;
    }
    return func_0040C3B0(b, func_0040C178(b, D_006310C0, n >> 3, 0x101)) << 3;
}
