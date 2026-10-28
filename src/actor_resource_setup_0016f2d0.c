/* Callee prototypes match their matched definitions: func_0012E770 (gp_small_accessors.c),
   func_0016F1B0 (resource_section_bind_0016f1b0.c), func_00174E90 (q14_g.c),
   func_00176340 (grok_r2_0014.c). jtbl_004CA000 is a .bss pointer table. */
typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef short s16;typedef unsigned int u32;
typedef struct {u8 a[0x30];s8 type;u8 b[0x10c];u8 active;s16 palette;u8 c[2];s16 stride;u8 d[0x30];u16 *palettes;u8 e[0x18];u32 unknown;u8 f[0x3a4];s8 region;u8 g[3];u8 *resource;s8 character,variant;} Actor;
extern u8 *jtbl_004CA000[];
extern s8 data_s8_004ACD08[6];
extern s8 D_004ACD90[];
extern void func_0012E770(u8),func_0016F1B0(u8 *,int),func_00176340(int,int);
extern int func_00174E90(u16 *,int,int);
void func_0016F2D0(u8 *p,int index){
 Actor *a=(Actor*)p;
 a->resource=jtbl_004CA000[index];
 func_0012E770(3);
 func_0016F1B0(p,index);
 a->unknown=0;a->active=1;
 a->palette=data_s8_004ACD08[a->region];
 a->type=D_004ACD90[a->character];
 a->stride=256;
 if(a->character==52)a->stride=512;
 func_00174E90((u16 *)((u8 *)a->palettes+a->variant*256),a->palette,8);
 func_00176340(index,(a->palette-16)/8);
}
