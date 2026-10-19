/* Initialize the stream engine and its two callback/context pairs. */
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef struct {s16 active;u8 rest[0xAE];} Engine;
extern Engine D_004791F8[16];
extern void *func_0011D8F8(void *,s32,unsigned int);
extern void *func_00404290(void);
extern void func_003F7D58(void *);
extern s32 func_003F7BE8(u8 *,s32 *,s32 *,s32 *);
extern s32 func_003F7C18(u8 *,s32,s32);
void *func_003F7C38(s32 count,s32 position,s32 available,s32 capacity){
 s32 slot;Engine *scan;u8 *p;
 scan=D_004791F8;
 for(slot=0;slot<16;slot++,scan++){if(!scan->active)break;}
 if(slot==16)return 0;
 p=(u8 *)&D_004791F8[slot];func_0011D8F8(p,0,0xB0);
 *(s16 *)p=1;
 *(void **)(p+8)=func_00404290();
 if(!*(void **)(p+8)){func_003F7D58(p);return 0;}
 *(s32 *)(p+0x38)=count;*(s32 *)(p+0x3C)=position;*(s32 *)(p+0x40)=available;*(s32 *)(p+0x44)=capacity;
 *(s32 (**)(u8 *,s32 *,s32 *,s32 *))(p+0x78)=func_003F7BE8;
 *(s32 (**)(u8 *,s32,s32))(p+0x80)=func_003F7C18;
 *(void **)(p+0x7C)=p;*(void **)(p+0x84)=p;
 return p;
}
