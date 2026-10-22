typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef void (*Unary)(u8 *);
extern Unary const jtbl_00440400[6],jtbl_00440420[6],jtbl_004405E0[6];
extern int func_0013BCE0(u8 *);
extern void func_0013BD00(u8 *);

void func_0013BA40(u8 *p){jtbl_00440400[(*(u8**)(p+0x18))[4]](p);}

void func_0013BB80(u8 *p){jtbl_00440420[(*(u8**)(p+0x18))[4]](p);}

void func_0013BA70(u8 *p)
{
 switch(p[5]) {
 case 0:
  if(func_0013BCE0(p)) {
   p[5]++;
   *(s16*)(p+0x1C)=3*p[0x22]+10;
  }
  break;
 case 1:
  if(func_0013BCE0(p)) {
   --*(s16*)(p+0x1C);
   if(*(s16*)(p+0x1C)<=0) {p[5]++;p[0x13C]=1;}
  } else func_0013BD00(p);
  break;
 case 2:
  if(!func_0013BCE0(p))func_0013BD00(p);
  break;
 }
}

void func_0013BBB0(u8 *p)
{
 switch(p[5]) {
 case 0:
  if(func_0013BCE0(p)) {
   p[5]++;
   p[0x13C]=1;
   *(float*)(p+0x50)=0.0f;
   *(float*)(p+0x54)=0.0f;
   *(float*)(p+0x58)=0.0f;
   *(s16*)(p+0x1C)=10;
   *(float*)(p+0x5C)=0.1f;
  }
  break;
 case 1:
  if(func_0013BCE0(p)) {
   --*(s16*)(p+0x1C);
   if(*(s16*)(p+0x1C)<=0)p[5]++;
   else {
    *(float*)(p+0x50)+=*(float*)(p+0x5C);
    *(float*)(p+0x54)+=*(float*)(p+0x5C);
    *(float*)(p+0x58)+=*(float*)(p+0x5C);
   }
  } else func_0013BD00(p);
  break;
 case 2:
  if(!func_0013BCE0(p))func_0013BD00(p);
  break;
 }
}

void func_0013D300(u8 *p){jtbl_004405E0[(*(u8**)(p+0x18))[4]](p);}

void func_0013D330(u8 *p){p[0x13C]=0;}
