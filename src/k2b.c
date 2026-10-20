#include "cri_sj_ring_buffer_types.h"
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern volatile s32 D_004C24C8;
void func_0040EFE0(void) { D_004C24C8; D_004C24C8 = D_004C24C8 + 1; }

/* The matching unlock includes the native volatile read after the update. */
void func_0040EFF8(void) { D_004C24C8 = D_004C24C8 - 1; (void)D_004C24C8; }

extern s32 D_004C22A0;
extern s32 D_004C22A4;
extern void func_0011D8F8(void *, s32, s32);
extern char D_00479CF8[];
void func_003FB0D8(void) { func_0011D8F8(D_00479CF8, 0, 0x100); D_004C22A0 = 0; D_004C22A4 = 0; }

extern volatile s32 D_004C24D4;
extern s32 D_004C24D8;
void func_0040F550(void) { D_004C24D4; if (D_004C24D8 == 0) func_0011D8F8(D_00490DA8, 0, sizeof(D_00490DA8)); D_004C24D8++; }

