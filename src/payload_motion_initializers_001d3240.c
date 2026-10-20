typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x,y,z; } V3;
typedef struct { u32 words[49]; } Payload;
extern void func_0015E630(u8*);
extern int func_001757E0(u8*,int,int);
extern void func_001DEC50(u8*,u8*);
void func_001D3240(u8*p,u8*q){f32 *fp=(f32*)p;f32 offset;
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);*(s8*)(p+0x24)=*(s8*)(q+0x24);
p[4]++;p[0x24]=12;offset=-60.0f;p[0x14e]=48;p[0x14f]=48;fp[23]=10.0f;
if(q[0x1e6]){offset=-offset;fp[23]=-fp[23];}
*(f32*)(p+0x34)=*(f32*)(q+0x34)+offset;*(f32*)(p+0x38)=*(f32*)(q+0x430);
func_0015E630(p);func_001757E0(p,23,30);}

void func_001DEB20(u8*p,u8*q){f32 *fp=(f32*)p;p[4]++;
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);*(s8*)(p+0x24)=*(s8*)(q+0x24);
p[0x13c]=1;*(s8*)(p+0x31)=-1;
*(f32*)(p+0x34)=*(f32*)(q+0x34);*(f32*)(p+0x38)=*(f32*)(q+0x38);*(f32*)(p+0x3c)=*(f32*)(q+0x3c);
fp[23]=-65.0f;*(f32*)(p+0x60)=216.428558349609375f;
if(*(s16*)(p+0x140))fp[23]=-fp[23];
func_001757E0(p,23,29);func_001DEC50(p,q);}
