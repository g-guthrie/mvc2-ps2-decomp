/* Select the action, animation bank, and facing-dependent movement from buttons. */
#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {u8 prefix[0x20E];u16 buttons;} InputView;
typedef struct {u8 prefix[0x1B5];u8 action;} ActionView;
typedef struct {u8 prefix[0x5C];float vx;u8 pad60[8];float ax;} Motion;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern u8 D_004BFD84[] __attribute__((section(".sdata")));
extern u8 D_004BFD88[] __attribute__((section(".sdata")));
extern u8 D_004BFD8C[] __attribute__((section(".sdata")));
extern void func_001E3710(u8 *,u8);
extern int func_001757E0(u8 *,int,int);
#define RESET() do{ ((ActionView*)p)->action=p[0x1B5];p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0; {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;} }while(0)
void func_00203FB0(u8 *p)
{
 Motion *motion=(Motion*)p;
 InputView *input=(InputView*)p;
 switch(p[0x1FC]){
 case 0:
  if(input->buttons&0x400){
   p[0x168]=11;p[0x1B5]=18;func_001E3710(p,21);
   *(u8**)(p+0x408)=D_004BFD88;p[0x1BB]=1;
   RESET();func_001757E0(p,20,p[0x168]);return;
  }
  p[0x168]=0;p[0x1B5]=3;func_001E3710(p,20);
  *(u8**)(p+0x408)=D_004BFD84;p[0x1BB]=0;
  break;
 case 1:
  p[0x168]=1;p[0x1B5]=4;func_001E3710(p,21);
  *(u8**)(p+0x408)=D_004BFD88;p[0x1BB]=1;
  break;
 case 2:
  if(input->buttons&0xC00){
   motion->vx=-1.6666666269302368f;motion->ax=0.01953125f;
   if(((input->buttons&0x400)&&!*(s16*)(p+0x140)) || ((input->buttons&0x800)&&*(s16*)(p+0x140))){motion->vx=-motion->vx;motion->ax=-motion->ax;}
  }else{motion->vx=0;motion->ax=0;}
  p[0x168]=2;p[0x1B5]=5;func_001E3710(p,22);
  *(u8**)(p+0x408)=D_004BFD8C;p[0x1BB]=2;
  break;
 }
 RESET();func_001757E0(p,8,p[0x168]);
}
