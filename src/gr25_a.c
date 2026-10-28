#pragma padloop on
typedef unsigned char u8;
typedef short s16;
#define SEL(off,K) { float v; switch (*(s16*)(p+0x140)) { default: v = -K; break; case 0: v = K; break; } *(float*)(p+off) = v; }
void func_00370EA0(u8 *p)
{
 u8 *owner=*(u8**)(p+0x18);
 if(owner[0x1E4]!=29||owner[0x1FD]!=5){
  p[5]=5;SEL(0x5C,15.833333015441895f)
  SEL(0x68,0.3125f)
  *(float*)(p+0x60)=0;*(float*)(p+0x6C)=0;*(s16*)(p+0x1C)=60;owner[0x2C6]=0;
 }else{
  if((*(s16*)(p+0x1C))--==0){
  ++p[5];SEL(0x5C,15.833333015441895f)
  SEL(0x68,0.3125f)
  *(float*)(p+0x60)=0;*(float*)(p+0x6C)=0;*(s16*)(p+0x1C)=60;
  }
 }
}
