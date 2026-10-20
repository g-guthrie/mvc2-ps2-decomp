typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x,y,z; } V3;
typedef struct { u32 words[49]; } Payload;
extern u8 *D_004C2840;
extern int func_001757E0(u8*,int,int);
extern void func_0015E630(u8*);
extern void func_001C1F60(u8*);
extern void func_001A9870(u8*);
void func_001C1E10(u8*p){u8*q;
if(*(u32*)(D_004C2840+0x14)==128){p[4]=2;p[5]=0;return;}
p[4]++;*(unsigned short*)(p+0x26)=0x1c03;q=*(u8**)(p+0x18);
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);*(s8*)(p+0x24)=*(s8*)(q+0x24);
p[0x14c]=24;p[0x14d]=24;p[0x14e]=32;p[0x14f]=32;p[0x24]=12;
func_001757E0(p,25,0);func_0015E630(p);*(s16*)(p+0x1e)=4;
if(q[0x425]){p[6]=5;p[0]=0;p[0x13c]=0;}
func_001C1F60(p);}
void func_001A9720(u8*p){u8*q;
if(*(u32*)(D_004C2840+0x14)==128){p[4]=2;p[5]=0;return;}
p[4]++;*(unsigned short*)(p+0x26)=0x1003;q=*(u8**)(p+0x18);
*(Payload*)(p+0xec)=*(Payload*)(q+0xec);
p[0x13c]=1;p[2]=q[2];p[1]=q[1];
*(f32*)(p+0x50)=*(f32*)(q+0x50);*(f32*)(p+0x54)=*(f32*)(q+0x54);
p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8*)(p+0x30)=*(s8*)(q+0x30);
*(V3*)(p+0x50)=*(V3*)(q+0x50);*(s8*)(p+0x24)=*(s8*)(q+0x24);
p[0x14c]=24;p[0x14d]=24;p[0x14e]=16;p[0x14f]=16;p[0x24]=12;
func_001757E0(p,23,0);func_0015E630(p);*(s16*)(p+0x1e)=4;
if(q[0x425]){p[6]=5;p[0]=0;p[0x13c]=0;}
func_001A9870(p);}

extern s16 D_0044DEE0[];
extern void func_001CFD20(u8*);
void func_001CFBB0(u8*p){u8*q=*(u8**)(p+0x18);p[4]++;
*(Payload *)(p+0xEC)=*(Payload *)(*(u8 **)(p+0x18)+0xEC);
 p[0x13C]=1;
 p[2]=(*(u8 **)(p+0x18))[2];
 p[1]=(*(u8 **)(p+0x18))[1];
 *(f32 *)(p+0x50)=*(f32 *)(*(u8 **)(p+0x18)+0x50);
 *(f32 *)(p+0x54)=*(f32 *)(*(u8 **)(p+0x18)+0x54);
 p[0x1B7]=(*(u8 **)(p+0x18))[0x1B7];
 p[0x1B8]=(*(u8 **)(p+0x18))[0x1B8];
 *(s8 *)(p+0x30)=*(s8 *)(*(u8 **)(p+0x18)+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(*(u8 **)(p+0x18)+0x50);
 *(s8 *)(p+0x24)=*(s8 *)(*(u8 **)(p+0x18)+0x24);
 p[0x13c]=1;p[0x24]=15;*(s16*)(p+0x1c)=0;
*(f32*)(p+0x34)=*(f32*)(q+0x34);
*(f32*)(p+0x38)=*(f32*)(q+0x430)+2.142857074737549f*(f32)D_0044DEE0[p[0x20]];
func_001757E0(p,23,(s8)(p[0x20]?23:0));func_001CFD20(p);}
