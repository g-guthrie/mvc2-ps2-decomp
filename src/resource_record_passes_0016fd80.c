/* Two resource passes with native 16-byte record copies. Field meanings are unresolved. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { float x,y,z,w; } FloatRecord4;
extern u32 *D_004C28AC __attribute__((section(".sdata")));
extern FloatRecord4 *D_004C28B8 __attribute__((section(".sdata")));
extern s32 D_004C2818 __attribute__((section(".sdata")));
extern s32 D_004C2820 __attribute__((section(".sdata")));
extern const FloatRecord4 D_00446930;
extern void func_0016F4D0(u32 *,u8 *);
extern void func_0016F530(s32,s32,s32,s32,s32,s32);
void func_0016FD80(void) {
 FloatRecord4 saved;
 FloatRecord4 *rows;
 func_0016F4D0(D_004C28AC,(u8 *)D_004C28B8);
 rows=D_004C28B8;
 saved=rows[4];
 rows[4]=D_00446930;
 func_0016F530(0x810,D_004C2818,(s32)D_004C28AC,(s32)D_004C28B8,6,0);
 rows[0]=saved;
 rows[1]=rows[5];
 rows[2]=rows[6];
 rows[3]=rows[7];
 rows[4]=rows[8];
 rows[5]=rows[9];
 rows[6]=D_00446930;
 func_0016F530(0x910,D_004C2820,(s32)D_004C28AC,(s32)D_004C28B8,6,0);
}
