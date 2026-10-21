typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {u8 prefix[0x1c];s16 timer,repeat;u8 gap20[0x14];f32 x,y,z;u8 gap40[8];u32 angle;u8 gap4c[4];f32 scaleX,scaleY;u8 gap58[4];f32 vx,vy,vz,ax,ay;u8 gap70[0xd0];s16 facing;} Motion;

extern void func_00354360(u8 *,u16,f32 *,f32 *);
extern int func_00354330(f32,f32,f32);
typedef struct {u8 prefix[4];u16 first,second,third,flags;} CollisionDescriptor;
typedef struct {u8 prefix[3];u8 kind;u8 gap4[0x1d0];CollisionDescriptor *descriptor;} CollisionTarget;
void func_003540B0(u8 *p,u8 *context) {
 Motion *m=(Motion *)p;CollisionTarget *target=*(CollisionTarget **)(p+0x1c4);f32 upper,lower,height;s16 count;s32 i,secondIndex;s16 secondCount;u16 index;
 if(target->kind==0 && target->descriptor!=0) {
 upper=-500.0f;lower=500.0f;
 index=target->descriptor->first;if(index)func_00354360((u8 *)target,(u16)index,&upper,&lower);
 index=target->descriptor->second;if(index)func_00354360((u8 *)target,(u16)index,&upper,&lower);
 index=target->descriptor->third;if(index)func_00354360((u8 *)target,(u16)index,&upper,&lower);
 {s32 flags=target->descriptor->flags&0x1fff;if(flags)func_00354360((u8 *)target,(u16)flags,&upper,&lower);}
 height=154.28570556640625f+m->y;count=0;
 if(func_00354330(height,upper,lower)){
  for(i=0;i<4;i++){count++;height-=34.28571319580078f;if(func_00354330(height,upper,lower)==0)goto firstDone;}
  count=10;
 }else{
  count=10;for(i=0;i<4;i++){count++;height-=34.28571319580078f;if(func_00354330(height,upper,lower))goto firstDone;}count=0;
 }
 firstDone:
 *(s16 *)(context+0xa)=count;
 height=17.14285659790039f+m->y;secondCount=0;
 if(func_00354330(height,upper,lower)){
  for(secondIndex=0;secondIndex<4;secondIndex++){secondCount++;height-=34.28571319580078f;if(func_00354330(height,upper,lower)==0)goto secondDone;}secondCount=10;
 }else{
  secondCount=10;for(secondIndex=0;secondIndex<4;secondIndex++){secondCount++;height-=34.28571319580078f;if(func_00354330(height,upper,lower))goto secondDone;}secondCount=0;
 }
 secondDone:
 *(s16 *)(context+0xc)=secondCount;
 }
}
