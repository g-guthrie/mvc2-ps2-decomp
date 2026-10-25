/* Choose the action from input, opponent type, and the current actor state. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef struct {u16 buttons;u8 remainder[18];} ControllerInput;
typedef struct {u8 pad[0x5C];float vx,vy,vz,ax,ay;} Motion;
extern ControllerInput D_004F4480[];
extern int func_00174170(void),func_001841C0(u8 *),func_001757E0(u8 *,int,int);
extern void func_00176160(u8 *,int,int,int),func_001A70B0(u8 *,u8,u8),func_001E3210(u8 *,u8);
void func_00245780(u8 *p)
{
 u8 choice=func_00174170()&1;
 Motion *motion=(Motion*)p;
 if(*(s8*)(p+0x539)==0){
  u16 buttons=D_004F4480[p[2]].buttons;
  if(buttons&0x200)choice=0;
  else if(buttons&0x100)choice=1;
 }
 {u8 type=(*(u8**)(p+0x220))[1];if(type==24 || type==25 || type==26)choice=1;}
 if(func_001841C0(p)>=2)choice=2;
 switch(choice){
 case 0:
  p[0x21]=0;func_001757E0(p,0,2);
  *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
  motion->vx=-5.0f;
  if(*(short*)(p+0x140))motion->vx=-motion->vx;
  break;
 case 1:
  p[0x21]=1;*(short*)(p+0x140)=0;func_001757E0(p,19,1);
  func_00176160(p,3,p[0x25]*28+3,1);func_001A70B0(p,0,0);func_001A70B0(p,0,1);
  break;
 default:
  p[0x21]=2;func_001757E0(p,19,0);func_001E3210(p,16);break;
 }
 ++p[6];p[7]=0;
}
