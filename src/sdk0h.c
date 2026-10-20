#include "runtime_entry_table.h"
typedef signed int s32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
extern RuntimeU8 D_00489818[];
RuntimeEntrySlot *func_0040CBD0(void) {
    RuntimeEntrySlot *r = 0;
    s32 i;
    for (i = 0; i < 16; i++) {
        RuntimeEntrySlot *p = (RuntimeEntrySlot *)((u32)D_00489818 + i * 0x438);
        if (p->in_use == 0) { r = p; break; }
    }
    return r;
}
typedef struct S2 { s8 flag; u8 pad[0x43]; } S2;
extern u8 D_00487B60[];
extern void func_0040EFE0(void);
extern void func_00409470(S2 *);
extern void func_0040EFF8(void);
void func_00409810(void) {
    s32 i;
    u32 row_address;
    func_0040EFE0();
    row_address = (u32)D_00487B60;
    for (i = 7; i >= 0; i--, row_address += 0x44)
        if (*(s8 *)row_address == 1) func_00409470((S2 *)row_address);
    func_0040EFF8();
}
typedef struct S3 { s32 state; u8 pad[0x38]; } S3;
extern S3 D_004854C0[];
extern void func_004044E0(S3 *);
void func_004045D8(void) {
    s32 i;
    S3 *p = D_004854C0;
    for (i = 15; i >= 0; i--, p++)
        if (p->state == 1) func_004044E0(p);
}
