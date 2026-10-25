/* Start on the opposite edge at the owner-relative height, then continue. */
typedef unsigned char u8;
typedef signed short s16;
extern float D_004F1FC8,D_004F1FCC;
extern int func_001757E0(u8 *,int,int);
extern void func_0015E630(u8 *),func_001C6BF0(u8 *,u8 *);
void func_001C6AE0(u8 *p,u8 *owner)
{
 p[7]++;p[0x14C]=16;p[0x14D]=16;p[0x14E]=16;p[0x14F]=16;p[0x24]=0;
 if((*(s16*)(p+0x140)=*(s16*)(owner+0x140)^1)==0) {
  *(float*)(p+0x34)=80.0f+D_004F1FCC;*(float*)(p+0x5C)=-6.666666507720947265625f;
 } else {
  *(float*)(p+0x34)=D_004F1FC8-80.0f;*(float*)(p+0x5C)=6.666666507720947265625f;
 }
 *(float*)(p+0x38)=*(float*)(owner+0x430);
 *(float*)(p+0x38)+=4.285714149475098f;
 *(float*)(p+0x68)=0;*(float*)(p+0x60)=0;*(float*)(p+0x6C)=0;
 func_001757E0(p,25,21);p[0]=1;func_0015E630(p);func_001C6BF0(p,owner);
}
