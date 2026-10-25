#pragma padloop on
typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef unsigned short u16;
typedef struct {u8 pad[0x28C];s16 timer;} RecoveryActor;
extern int func_00169CE0(u8*,int,int);
int func_00185080(u8*p) {
 RecoveryActor *actor=(RecoveryActor*)p;
 if(--actor->timer<=0){actor->timer=0;p[7]=2;}
 if(p[0x20B]&0x40)return 0;
 if(*(s8*)(p+0x539)) {
  if(func_00169CE0(p,30,2)){p[7]=4;actor->timer=10;return 0;}
  actor->timer=0;p[7]=2;
 }
 if((*(u16*)(p+0x35E)&0xC00)&&(*(u16*)(p+0x362)&0x120)){p[7]=4;actor->timer=10;}
 return 0;
}
