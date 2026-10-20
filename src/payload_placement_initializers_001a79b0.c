typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x,y,z; } V3;
typedef struct { u32 words[49]; } Payload;
typedef unsigned short u16;
typedef struct Placement {s16 x,y;s8 pose;u8 animation;} Placement;
extern Placement D_0044B470[],D_0044C0E0[];
extern s32 func_001754A0(u8*,u8,u8);
extern void func_001A7B50(u8*);extern void func_001BC960(u8*);
void func_001A79B0(u8*p){u8*q=*(u8**)(p+0x18);Placement*t;f32*fp=(f32*)p;p[4]++;*(u16*)(p+0x26)=0x1000;
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);*(s8*)(p+0x24)=*(s8*)(q+0x24);
t=&D_0044B470[p[0x20]];*(s8*)(p+0x24)=t->pose;
if(!*(s16*)(p+0x140))fp[13]=*(f32*)(q+0x34)+1.66666662693023681640625f*(f32)t->x;
else fp[13]=*(f32*)(q+0x34)-1.66666662693023681640625f*(f32)t->x;
fp[14]=*(f32*)(q+0x38)+2.142857074737548828125f*(f32)t->y;
func_001754A0(p,27,t->animation);func_001A7B50(p);}
void func_001BC7C0(u8*p){u8*q=*(u8**)(p+0x18);Placement*t;f32*fp=(f32*)p;p[4]++;*(u16*)(p+0x26)=0x1800;
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);*(s8*)(p+0x24)=*(s8*)(q+0x24);
t=&D_0044C0E0[p[0x20]];*(s8*)(p+0x24)=t->pose;
if(!*(s16*)(p+0x140))fp[13]=*(f32*)(q+0x34)+1.66666662693023681640625f*(f32)t->x;
else fp[13]=*(f32*)(q+0x34)-1.66666662693023681640625f*(f32)t->x;
fp[14]=*(f32*)(q+0x38)+2.142857074737548828125f*(f32)t->y;
func_001754A0(p,27,t->animation);func_001BC960(p);}

extern Placement D_0044C3C0[];
extern void func_001BEAB0(u8*);
void func_001BE910(u8*p){u8*q=*(u8**)(p+0x18);Placement*t;f32*fp=(f32*)p;p[4]++;*(u16*)(p+0x26)=0x1900;
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);*(s8*)(p+0x24)=*(s8*)(q+0x24);
t=&D_0044C3C0[p[0x20]];*(s8*)(p+0x24)=t->pose;
if(!*(s16*)(p+0x140))fp[13]+=1.66666662693023681640625f*(f32)t->x;
else fp[13]-=1.66666662693023681640625f*(f32)t->x;
fp[14]+=2.142857074737548828125f*(f32)t->y;
func_001754A0(p,27,t->animation);func_001BEAB0(p);}

typedef struct EffectLaunch {s8 flags,paletteDelta,pose;s16 velocityX,velocityY;u8 animation,variant;} EffectLaunch;
extern EffectLaunch D_0044C530[];extern void func_001C0C30(u8*);
void func_001C0A90(u8*p){u8*q;EffectLaunch*t;f32*fp=(f32*)p;p[4]++;*(u16*)(p+0x26)=0x1c00;p[0x13c]=1;q=*(u8**)(p+0x18);
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);*(s8*)(p+0x24)=*(s8*)(q+0x24);
t=&D_0044C530[p[0x20]];
if(t->flags){p[0x13d]=t->flags;if(q[2])*(s16*)(p+0x13e)+=t->paletteDelta+8;else *(s16*)(p+0x13e)+=t->paletteDelta;}
*(s8*)(p+0x31)=t->pose;
fp[23]=1.66666662693023681640625f*(f32)t->velocityX;
fp[24]=-(2.142857074737548828125f*(f32)t->velocityY);
func_001754A0(p,t->animation,t->variant);func_001C0C30(p);}
