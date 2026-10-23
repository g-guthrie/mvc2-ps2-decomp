typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_001B3D90(u8 *,u8 *),func_001B3E20(void *);
extern int func_001754A0(u8 *,int,int);
extern const u8 D_004B5714[];
#define CACHE_ANIMATION() do { \
 *(u16*)state=*(u16*)(owner+0x168); \
 state[1]=owner[0x169];state[0]=owner[0x168]; \
}while(0)
void func_001B3450(u8 *p)
{
 u8 *state=p+0xD0;
 u8 *owner=*(u8**)(p+0x18);
 *(u32*)(p+0x48)=0;
 switch(owner[0x169]) {
 case 5:
  CACHE_ANIMATION();
  p[4]++;p[5]=0;p[0x13C]=0;
  if(owner[0x168]>=4)p[0x21]=1;else p[0x21]=0;
  break;
 case 6:
  p[0x21]=2;CACHE_ANIMATION();
  p[4]++;p[5]=0;p[0x13C]=0;
  break;
 case 11:
  if(owner[0x168]==2) {
   p[0x21]=3;*(u16*)state=*(u16*)(owner+0x168);
   p[4]++;p[5]=3;p[6]=0;p[0x13C]=0;
  }
  break;
 case 24:
  if(owner[0x168]==1) {
   p[0x21]=4;CACHE_ANIMATION();
   p[4]++;p[5]=1;p[0x13C]=1;
   func_001B3D90(owner,p);
   func_001754A0(p,27,D_004B5714[6*p[0x21]]);
  }
  break;
 case 15:
  if(owner[0x168]==5) {
   p[0x21]=5;CACHE_ANIMATION();p[4]++;p[5]=4;
  }
  break;
 }
 func_001B3E20(p);
}
