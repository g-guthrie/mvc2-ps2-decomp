#pragma padloop on
typedef unsigned char u8;typedef signed char s8;
typedef struct {u8 pad[5];u8 state;u8 pad6[0x154];u8 input;u8 pad15B[0xB2];u8 mode;u8 pad20E[0x29B];s8 flags;} FlagView;
struct Object;
extern unsigned int func_0016B240(struct Object*,int);
int func_0016B250(FlagView*p,int kind) {
 int flag;
 switch(kind) {
 case 0:if(p->mode==2)return 0;break;
 case 5:
  if(p->mode==2)return 0;
  if(p->flags&2)goto evaluate;
  break;
 case 2:if((!p->input)&0xE0)goto evaluate;break;
 }
 if(p->flags<0)return 1;
 evaluate:
 if(!func_0016B240((struct Object*)p,kind))return 0;
 flag=p->flags;
 if(flag) {
  if((s8)flag&2) {
   p->flags=flag^2;
   p->flags|=-128;
  }
 }
 return 1;
}
