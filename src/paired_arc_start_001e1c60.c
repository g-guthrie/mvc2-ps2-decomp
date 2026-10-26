#pragma padloop on
typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef int s32;typedef unsigned int u32;
typedef struct {s16 x,y;} Pair;
typedef struct {Pair row[10];} PairTable;
typedef struct {u8 frame[10];} Frames;
typedef struct {s16 angle[5];} Angles;
typedef struct {u32 words[49];} State;
typedef struct {float x,y,z;} V3;
extern PairTable D_0044F050,D_0044F090;extern Frames D_0044F078;extern Angles D_0044F0B8;
extern int func_001754A0(u8*,int,int);extern void func_0015E630(u8*);
void func_001E1C60(u8*p,u8*owner){
 PairTable position=D_0044F050;Frames frames=D_0044F078;PairTable velocity=D_0044F090;Angles angles=D_0044F0B8;
 float dx,vx;
 ++p[4];*(State*)(p+0xEC)=*(State*)(owner+0xEC);p[0x13C]=1;p[2]=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];p[0x30]=*(s8*)(owner+0x30);*(V3*)(p+0x50)=*(V3*)(owner+0x50);p[0x24]=*(s8*)(owner+0x24);
 p[0x13C]=1;p[0x24]=15;*(s16*)(p+0x13E)+=6;if(!(p[0x21]&1))*(s16*)(p+0x140)^=1;
 dx=(float)position.row[p[0x21]].x;if(*(s16*)(owner+0x140))dx=-dx;*(float*)(p+0x34)=*(float*)(owner+0x34)+dx;
 *(float*)(p+0x38)=*(float*)(owner+0x430)+(float)position.row[p[0x21]].y;
 vx=(1.6666666269302368f*(float)velocity.row[p[0x21]].x)/256.0f;if(*(s16*)(owner+0x140))vx=-vx;*(float*)(p+0x5C)=vx;
 *(float*)(p+0x60)=(2.142857074737549f*(float)velocity.row[p[0x21]].y)/256.0f;
 *(float*)(p+0x6C)=0;*(float*)(p+0x68)=0;*(u32*)(p+0x44)=0;*(u32*)(p+0x40)=0;
 *(s32*)(p+0x48)=angles.angle[p[0x21]>>1];p[0x14D]=64;p[0x14C]=64;p[0x14F]=32;p[0x14E]=32;
 func_001754A0(p,27,frames.frame[p[0x21]]);p[0]=1;p[0x159]=0;func_0015E630(p);
}
