/* Allocate a runtime handle and initialize the default 500/44100 rate. */
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef struct {s32 active;u8 rest[0x38];} Handle;
extern Handle D_004854C0[16];
extern void *func_0011D8F8(void *,s32,unsigned int);
extern void func_003F9698(s32,s32,s16 *,s16 *);
void *func_00404290(void){
 s32 slot;Handle *scan;u8 *p;
 scan=D_004854C0;
 for(slot=0;slot<16;slot++,scan++){if(!scan->active)break;}
 if(slot==16)return 0;
 p=(u8 *)&D_004854C0[slot];func_0011D8F8(p,0,0x3C);
 *(s32 *)p=1;*(s32 *)(p+4)=slot;*(s32 *)(p+8)=0;*(s32 *)(p+0xC)=0;
 func_003F9698(500,44100,(s16 *)(p+0x30),(s16 *)(p+0x32));
 func_0011D8F8(p+0x28,0,8);
 return p;
}
