#include "runtime_resource_record.h"
/* Two resource passes preserve complete 16-byte records and their terminator. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
extern u32 *D_004C28AC __attribute__((section(".sdata")));
extern void *D_004C28B8 __attribute__((section(".sdata")));
extern s32 D_004C2818 __attribute__((section(".sdata")));
extern s32 D_004C2820 __attribute__((section(".sdata")));
extern const ResourceRecord D_00446930;
extern void func_0016F4D0(u32 *,u8 *);
void func_0016FD80(void) {
 ResourceRecord saved;
 ResourceRecord *rows;
 u32 roots_address;
 u32 records_address;
 s32 group_address;
 func_0016F4D0(D_004C28AC,(u8 *)D_004C28B8);
 rows=D_004C28B8;
 saved=rows[4];
 rows[4]=D_00446930;
 roots_address=(u32)D_004C28AC;
 records_address=(u32)D_004C28B8;
 group_address=D_004C2818;
 func_0016F530(0x810,group_address,(u32 *)roots_address,(ResourceRecord *)records_address,6,0);
 rows[0]=saved;
 rows[1]=rows[5];
 rows[2]=rows[6];
 rows[3]=rows[7];
 rows[4]=rows[8];
 rows[5]=rows[9];
 rows[6]=D_00446930;
 roots_address=(u32)D_004C28AC;
 records_address=(u32)D_004C28B8;
 group_address=D_004C2820;
 func_0016F530(0x910,group_address,(u32 *)roots_address,(ResourceRecord *)records_address,6,0);
}
