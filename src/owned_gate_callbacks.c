typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef void (*Unary)(u8 *);
typedef void (*Owned)(u8 *,u8 *);
extern Owned const jtbl_00445470[5],jtbl_00445490[5],jtbl_00445510[5];
extern void func_00152550(void *,Unary);
extern void func_0015E2F0(u8 *),func_0015E9F0(u8 *),func_001601A0(u8 *);

void func_0015E100(u8 *p){jtbl_00445470[p[4]](*(u8**)(p+0x18),p);}

void func_0015E800(u8 *p){jtbl_00445490[p[4]](*(u8**)(p+0x18),p);}

void func_0015FFB0(u8 *p){jtbl_00445510[p[4]](*(u8**)(p+0x18),p);}

void func_0015E130(u8 *owner,u8 *p)
{
 if(owner[0x23E]!=1)*(u32*)(p+0xD8)=0;
 if((*(u32*)(p+0xD8))--==0) {
  p[4]=1;
  func_00152550(p,func_0015E2F0);
 }
}

void func_0015E830(u8 *owner,u8 *p)
{
 if(owner[0x23E]!=1)*(u32*)(p+0xD8)=0;
 if((*(u32*)(p+0xD8))--==0) {
  p[4]=1;
  func_00152550(p,func_0015E9F0);
 }
}

void func_0015FFE0(u8 *owner,u8 *p)
{
 if(owner[0x23E]!=1)*(u32*)(p+0xD8)=0;
 if((*(u32*)(p+0xD8))--==0) {
  p[4]=1;
  func_00152550(p,func_001601A0);
 }
}
