#pragma padloop on
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef struct {s16 lifetime[3];s16 x,y,dx,dy;} SpawnPattern;
extern SpawnPattern D_00472FD0[];
extern int func_00174170(void);
extern u8 *func_003A8D20(u8 *,s16,s16);
void func_003A8DB0(u8 *owner)
{
 s16 i;
 for(i=0;i<8;i++) {
  SpawnPattern *pattern=&D_00472FD0[func_00174170()&7];
  u8 *child;
  if((child=func_003A8D20(owner,0,0))!=0) {
   child[0x21]=0;
   child[0x20]=i;
   *(s32 *)(child+0xdc)=pattern->lifetime[0];
  }
  if((child=func_003A8D20(owner,pattern->x,pattern->y))!=0) {
   child[0x21]=1;
   child[0x20]=i;
   *(s32 *)(child+0xdc)=pattern->lifetime[1];
  }
  if((child=func_003A8D20(owner,(s16)(pattern->x+pattern->dx),(s16)(pattern->y+pattern->dy)))!=0) {
   child[0x21]=1;
   child[0x20]=i;
   *(s32 *)(child+0xdc)=pattern->lifetime[2];
  }
 }
}
