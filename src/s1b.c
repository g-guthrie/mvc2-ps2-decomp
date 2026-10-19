#include "runtime_entry_table.h"
typedef signed int s32;
typedef unsigned int u32;
extern void (*D_004C2214)(void);
void func_003F64F0(void) { D_004C2214(); }
extern void func_0041F900(void);
extern void func_0041DE10(void);
extern s32 D_004C2B78, D_004C2B7C;
extern volatile s32 D_004C2470;
extern s32 D_004C2474;
extern void func_0040D548(void *);
extern void func_0040D568(void *);
extern void func_0040D628(void);
extern RuntimeU8 D_00489818[];
extern void func_0011D8F8(void *, s32, s32);
void func_0040D638(void) {
    char buf[16];
    (void)D_004C2470;
    func_0040D548(buf);
    if (D_004C2474 == 0) { func_0011D8F8(D_00489818, 0, 0x4380); func_0040D628(); func_0040D580(0, 0); }
    D_004C2474++;
    func_0040D568(buf);
}
