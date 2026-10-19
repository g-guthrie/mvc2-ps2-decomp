#include "runtime_entry_table.h"
typedef signed int s32;
typedef long long s64;
typedef unsigned char u8;
extern s32 D_004C2474;
extern void func_0011D8F8(void *, s32, s32);
extern void func_0040CD38(void *);
extern void func_0040D630(void);
extern void func_0040D580(s32, s32);
extern RuntimeU8 D_00489818[];
void func_0040D6A0(void) {
    s32 i;
    if (--D_004C2474 == 0) {
        for (i = 0; i < 16; i++)
            if (((RuntimeEntrySlot *)D_00489818)[i].in_use == 1)
                func_0040CD38(&((RuntimeEntrySlot *)D_00489818)[i]);
        func_0011D8F8(D_00489818, 0, 0x4380); func_0040D630(); __asm__ volatile(""); func_0040D580(0, 0); __asm__ volatile("");
    }
}
extern volatile s64 D_004C2348;
extern volatile s64 D_004C22F8;
extern s64 D_004C2350;
extern volatile s32 D_004C22E0;
extern void func_00411A30(void);
extern void func_003FE170(void);
extern void func_00103C20(void);
void func_003FDE88(void) {
    while (!D_004C2348) {
        D_004C22F8++;
        D_004C22E0 = 1;
        func_00411A30();
        D_004C22E0 = 0;
        func_003FE170();
    }
    D_004C2350 = 1;
    func_00103C20();
}
extern char D_00479CF8[];
extern void func_00120440(void *, s32, s32);
extern void func_001200D8(void *, s32, s32);
extern void func_004112D8(void *);
extern void (*D_004C22A0)(void *, void *);
extern void *D_004C22A4;
void func_003FB178(s32 a, s32 b) {
    func_00120440(D_00479CF8, a, 0xFF);
    func_001200D8(D_00479CF8, b, 0xFF);
    if (D_004C22A0) D_004C22A0(D_004C22A4, D_00479CF8);
    func_004112D8(D_00479CF8);
}
