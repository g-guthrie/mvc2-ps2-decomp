#include "runtime_message_callback.h"
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;

extern s32 D_00489018;
extern s32 D_0048831C;
extern s32 D_004895D0;
extern s32 D_004895D4;
extern u32 D_0047B580;
extern s8 D_004872F1;
extern s32 D_00487324;
extern u8 D_004872F2;
extern RuntimeMessageCallback D_004891AC;
extern void *D_004891B0;
extern s32 D_00488314;
extern s32 D_00488318;

void func_0040A2A8(s32 value) { D_00489018 = value; }
s32 func_0040A2B8(void) { return D_00489018; }
s32 func_0040A2E8(void) { return D_0048831C; }
s32 func_0040CBA0(void) { return D_004895D0; }
void func_0040CBB0(s32 value) { D_004895D4 = value; }
s32 func_0040CBC0(void) { return D_004895D4; }
void func_003FD8E0(u32 value) { D_0047B580 = value; }
s8 func_00408608(void) { return D_004872F1; }
s32 func_00408618(void) { return D_00487324; }
void func_00408790(void) { D_004872F2 = 9; }
void func_0040B3A0(RuntimeMessageCallback callback, void *context) {
    D_004891AC = callback;
    D_004891B0 = context;
}
void func_00409AC8(s32 left, s32 right) {
    D_00488314 = left;
    D_00488318 = right;
}
