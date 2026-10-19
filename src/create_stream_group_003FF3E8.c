/* Allocate a 0x9C-byte stream group, initialize its engine and register
 * the position/availability callback. The two stream slots at 0x0C precede
 * the request spans beginning at 0x1C, as consumed by func_003FF810. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef struct {s8 active;u8 prefix[11];void *streams[2];u8 rest[0x88];} Group;
extern Group D_00484100[16];
extern s32 func_0040FCD0(void *),func_0040FCD8(void *),func_0040FCE0(void *);
extern void *func_003F7C38(s32,s32,s32,s32);
extern int func_003FF810(u8 *,int *,int *,int *);
extern void func_003F80F8(void *,int (*)(u8 *,int *,int *,int *),void *);
extern void func_003FF3B0(void *);
void *func_003FF3E8(void *resource,s32 count,void **streams){
 s32 slot,i,position,half,tail;Group *scan;u8 *p;void *first=streams[0];void *engine;
 slot=0;scan=D_00484100;
 for(;slot<16;slot++,scan++){if(!scan->active)break;}
 if(slot==16)return 0;
 p=(u8 *)&D_00484100[slot];
 position=func_0040FCD0(first);
 half=func_0040FCD8(first)/2;
 tail=func_0040FCE0(first)/2;
 engine=func_003F7C38(count,position,half,half+tail);
 *(void **)(p+4)=engine;
 if(!engine)return 0;
 func_003F80F8(engine,func_003FF810,p);
 *(void **)(p+8)=resource;p[2]=count;
 i=0;if(count>0){do{((Group *)p)->streams[i]=streams[i];i++;}while(i<count);}
 p[1]=0;func_003FF3B0(p);
 *(s32 *)(p+0x48)=0;*(s32 *)(p+0x4C)=0;*(s32 *)(p+0x50)=0;*(s32 *)(p+0x54)=0;p[0]=1;
 return p;
}
