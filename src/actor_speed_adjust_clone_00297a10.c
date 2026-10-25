/* Adjust horizontal speed and initialize the native clone and timer. */
/* Adjust horizontal speed according to facing and its current sign. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_0018C4B0(u8 *,int),func_00185490(u8 *);
extern u8 *func_001C8FD0(u8 *,int);
extern int func_001757E0(u8 *,int,int);
extern u8 *D_004C2794 __attribute__((section(".sdata")));
void func_00297A10(u8 *p)
{
 float speed;
 ++p[6];func_00185490(p);
 func_0018C4B0(p,5);
 p[0x1B5]=*(s8*)(p+0x1B7)+61;
 p[0x1B2]=*(u16*)(p+0x1C0)=0;
 *(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 if(p[0x1B7])speed=4.166666507720947f;
 else speed=2.5f;
 if(p[0x1E6]){
  if((double)*(float*)(p+0x5C)<0.0)speed=-speed;
 }else{
  speed=-speed;
  if((double)*(float*)(p+0x5C)>0.0)speed=-speed;
 }
 *(float*)(p+0x5C)+=speed;
 *(float*)(p+0x68)=0;
 func_001C8FD0(p,0);
 *(s16*)(p+0x1C)=p[0x1B7]*2+1;
 func_001757E0(p,21,8);
}
