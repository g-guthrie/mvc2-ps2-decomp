#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;
typedef struct {u32 words[49];} Fields;
typedef struct {float x,y,z;} V3;
/* Native constructor creates slots 0..8. Slot 8 reads the low
 * halfword of the first neighboring velocity value. */
extern s16 D_0044A8A0[9];
extern float D_0044A8B0[4][2],D_0044A8B4[4][2];
extern void func_0019C190(u8*),func_0019C100(u8*),func_001E3210(u8*,int);
extern int func_001757E0(u8*,int,int);
#define OWNER (*(u8**)(p+0x18))
void func_0019BE90(u8 *p) {
 if(--*(s16*)(p+0x1C)<=0) {
  int remaining=--p[0x21];
  if(remaining<=0) {p[4]=2;func_0019C190(p);}
  else {
   ++p[4];*(Fields*)(p+0xEC)=*(Fields*)(OWNER+0xEC);p[0x13C]=1;
   p[2]=OWNER[2];p[1]=OWNER[1];
   *(float*)(p+0x50)=*(float*)(OWNER+0x50);*(float*)(p+0x54)=*(float*)(OWNER+0x54);
   p[0x1B7]=OWNER[0x1B7];p[0x1B8]=OWNER[0x1B8];p[0x30]=*(s8*)(OWNER+0x30);
   *(V3*)(p+0x50)=*(V3*)(OWNER+0x50);p[0x24]=*(s8*)(OWNER+0x24);
   p[0x13C]=1;p[0x24]=0;
   *(float*)(p+0x34)=*(float*)(OWNER+0x34);*(float*)(p+0x38)=*(float*)(OWNER+0x38);
   if(p[0x20]&4) {
    float *vel=&D_0044A8B0[0][0],*acc=&D_0044A8B4[0][0];
    func_001757E0(p,23,5);
    *(float*)(p+0x5C)=*(float*)((u8*)vel+(p[0x20]-4)*8);
    *(float*)(p+0x68)=*(float*)((u8*)acc+(p[0x20]-4)*8);
    *(float*)(p+0x60)=90.0f/7.0f;*(float*)(p+0x6C)=-(15.0f/7.0f)/8.0f;
   } else {
    func_001757E0(p,23,4);
    *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
   }
   *(float*)(p+0x34)+=(5.0f/3.0f)*(float)D_0044A8A0[p[0x20]];
   *(float*)(p+0x38)+=(15.0f/7.0f)*(float)*(s16*)(p+0x1E);
   if(p[0x20]==0)func_001E3210(p,10);
   func_0019C100(p);
  }
 }
}
