typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_001E3210(u8 *,int),func_0018C4B0(u8 *,int);
extern void func_00185490(u8 *),func_00183D10(u8 *),func_0021F340(u8 *);
extern int func_001757E0(u8 *,int,int);
#define ENTER_ACTION(action) do { \
 p[0x1B5]=(action); \
 p[0x1B2]=*(u16*)(p+0x1C0)=0; \
 *(u32*)(p+0x1D8)=0; \
 ((s16*)(D_004C2794+0x7C))[p[2]]++; \
} while(0)
typedef void (*StateCallback)(u8 *);
extern StateCallback const jtbl_00453F20[9];
extern void func_00175C00(u8 *,int),func_00329700(u8 *),func_00176160(u8 *,int,int,int);

void func_0021F110(u8 *p)
{
 p[6]++;
 func_001E3210(p,0x14);
 func_001E3210(p,0x1F);
 func_0018C4B0(p,5);
 if(p[0x20D]==2) {
  if(p[0x269]==3)ENTER_ACTION(0x55);
  else if(p[0x1B7])ENTER_ACTION(0x3F);
  else ENTER_ACTION(0x3D);
  p[0x20D]=2;
  p[0x168]=1;
  *(float*)(p+0x5C)/=8.0f;
  *(float*)(p+0x68)/=8.0f;
  *(float*)(p+0x60)/=8.0f;
  *(float*)(p+0x6C)/=8.0f;
 } else {
  if(p[0x269]==3)ENTER_ACTION(0x55);
  else ENTER_ACTION(*(s8*)(p+0x1B7)+0x3B);
  *(float*)(p+0x5C)=0.0f;
  *(float*)(p+0x60)=0.0f;
  *(float*)(p+0x68)=0.0f;
  *(float*)(p+0x6C)=0.0f;
  func_00185490(p);
  p[0x20D]=0;
  *(float*)(p+0x38)=*(float*)(p+0x430);
  p[0x168]=0;
  func_00183D10(p);
 }
 func_001757E0(p,0x15,p[0x168]);
 func_0021F340(p);
}

void func_0025E440(u8 *p)
{
 if(p[0x23]==5) {
  *(float*)(p+0x50)=1.09000003337860107421875f;
  *(float*)(p+0x54)=1.09000003337860107421875f;
 }
 if(p[0x23]==10) {
  *(float*)(p+0x50)=1.019999980926513671875f;
  *(float*)(p+0x54)=1.019999980926513671875f;
 }
 if(p[0x23]==4) {
  *(float*)(p+0x50)=1.0f;
  *(float*)(p+0x54)=1.0499999523162841796875f;
 }
 jtbl_00453F20[p[6]](p);
}

void func_002E6130(u8 *p)
{
 u8 *state;
 p[6]++;
 p[0x209]=2;
 p[0x2BE]=0;
 p[0x2BD]=(p[0x20D]&2)>>1;
 *(float*)(p+0x5C)=0.0f;*(float*)(p+0x60)=0.0f;
 *(float*)(p+0x68)=0.0f;*(float*)(p+0x6C)=0.0f;
 ENTER_ACTION(*(s8*)(p+0x1B7)+0x32);
 state=p+0x2B8;
 if(p[0x20D]==2)*(float*)(p+0x38)+=-85.7142791748046875f;
 else {
  p[0x20D]=0;
  *(float*)(p+0x38)=*(float*)(p+0x430);
  func_00183D10(p);
 }
 func_00185490(p);
 func_00329700(p);
 func_001757E0(p,0x15,(u8)(*(s8*)(state+5)+3));
 func_00175C00(p,0);
 func_00176160(p,1,p[0x25]*0x30+0x2F,1);
}

void func_0031FEE0(u8 *p)
{
 int animation;
 if(p[0x269]==6) {p[0x404]=0xFF;p[0x405]=16;}
 p[7]++;
 *(float*)(p+0x5C)=0.0f;*(float*)(p+0x60)=0.0f;
 *(float*)(p+0x68)=0.0f;*(float*)(p+0x6C)=0.0f;
 ENTER_ACTION(0x44);
 animation=11;
 if(p[0x20D]==2) {
  *(float*)(p+0x60)=8.5714282989501953125f;
  *(float*)(p+0x6C)=-0.66964280605316162109375f;
  animation++;
 } else func_00183D10(p);
 func_00185490(p);
 func_00176160(p,2,0,1);
 func_001757E0(p,0x16,(u8)animation);
}

/* Only the four float fields at each selected 28-byte record prefix are
 * interpreted here. Other movement-bank bytes remain opaque DATA. */
extern const u8 D_004539E0[];
void func_0025E4C0(u8 *p)
{
 const float *movement;
 u8 *state;
 p[6]++;
 func_0018C4B0(p,5);
 func_00185490(p);
 func_00175C00(p,0);
 movement=(const float*)D_004539E0;
 func_001757E0(p,0x15,0);
 if(p[0x1B7]==0) {
  p[0x23]=*(s16*)(p+0x140)?1:2;
  movement+=*(s16*)(p+0x140)?7:14;
 } else if(p[0x20D]!=2) {
  p[0x23]=*(s16*)(p+0x140)?9:10;
  movement+=*(s16*)(p+0x140)?63:70;
 } else {
  p[0x23]=*(s16*)(p+0x140)?1:2;
  movement+=*(s16*)(p+0x140)?7:14;
 }
 if(p[0x20D]!=2)func_00183D10(p);
 *(float*)(p+0x5C)=movement[0];
 *(float*)(p+0x68)=movement[1];
 *(float*)(p+0x60)=movement[2];
 *(float*)(p+0x6C)=movement[3];
 *(s16*)(p+0x1C)=30;
 *(s16*)(p+0x1E)=0;
 p[0x2BE]=0;
 *(s16*)(p+0x2C0)=0;
 state=p+0x2B8;
 if(p[0x269]==3) {
  ENTER_ACTION(0x48);
  state[6]=3;
  *(s16*)(p+0x1E)=3;
 } else ENTER_ACTION(0x33);
}
