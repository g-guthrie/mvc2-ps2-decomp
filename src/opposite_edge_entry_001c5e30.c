/* Opposite-edge initialization and its owner-forwarding phase dispatcher. */
typedef unsigned char u8;
typedef signed short s16;
extern float D_004F1FC8,D_004F1FCC,D_004F1FD0;
extern int func_001757E0(u8 *,int,int);
extern void func_0015E630(u8 *),func_001C5F40(u8 *,u8 *);
void func_001C5E30(u8 *p,u8 *owner)
{
 p[7]++;p[0x14C]=16;p[0x14D]=16;p[0x14E]=16;p[0x14F]=16;*(s16*)(p+0x1C)=16;
 if((*(s16*)(p+0x140)=*(s16*)(owner+0x140)^1)==0) {
  *(float*)(p+0x34)=80.0f+D_004F1FCC;*(float*)(p+0x5C)=-6.666666507720947265625f;
 } else {
  *(float*)(p+0x34)=D_004F1FC8-80.0f;*(float*)(p+0x5C)=6.666666507720947265625f;
 }
 *(float*)(p+0x38)=D_004F1FD0-205.7142791748046875f;
 *(float*)(p+0x68)=0;*(float*)(p+0x60)=0;*(float*)(p+0x6C)=0;
 func_001757E0(p,25,20);p[0]=1;func_0015E630(p);func_001C5F40(p,owner);
}

typedef void (*OwnerPhase)(u8 *,u8 *);
extern OwnerPhase const jtbl_0044CD10[6];
void func_001C5DE0(u8 *p,void *owner_context)
{
 u8 *owner=owner_context;
 u8 *work=owner+0x2B8;
 if(owner[5]||owner[0x1E4]!=29) {work[11]=0;work[10]=1;}
 jtbl_0044CD10[p[7]](p,owner);
}
