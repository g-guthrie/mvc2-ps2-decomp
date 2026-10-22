typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {float x,y,z;} Vec3;
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int);
extern void func_00176160(u8 *,int,int,int);
extern int func_00354A20(u8 *);
extern void func_00179160(void *,void *);
extern void func_001266A0(u8 *,int,int);
extern void func_0018C6E0(void *),func_0015D010(u8 *,const float *);
extern void func_001E3A40(u8 *),func_00185770(u8 *,u8 *),func_001E3C40(u8 *);
extern u8 *func_001E7FD0(u8 *);
extern void func_00178F20(u8 *,u8 *);
extern int func_00174470(const void *);
extern void func_00345B40(u8 *),func_00345AE0(u8 *),func_001E7F60(u8 *);
extern void func_00185490(u8 *),func_0018C4B0(u8 *,int);
extern void func_0034FA60(u8 *),func_0018D930(u8 *);
extern void func_0034F330(u8 *),func_0034F3B0(u8 *);
extern void func_001B87E0(void *,u8);

void func_0021AD10(u8 *p)
{
 p[0x40C]=2;
 p[0x33C]=5;
 *(float*)(p+0x34)+=*(float*)(p+0x5C);
 *(float*)(p+0x5C)+=*(float*)(p+0x68);
 *(float*)(p+0x38)+=*(float*)(p+0x60);
 *(float*)(p+0x60)+=*(float*)(p+0x6C);
 func_00175700(p);
 if(*(float*)(p+0x38)<*(float*)(p+0x430))*(float*)(p+0x60)=0.0f;
 if(--*(s16*)(p+0x1C)==0) {
  p[7]++;
  *(float*)(p+0x5C)/=16.0f;
  *(float*)(p+0x60)/=16.0f;
  *(float*)(p+0x68)=0.0f;
  *(float*)(p+0x6C)=0.0f;
  func_001757E0(p,0x16,0xD);
  func_00176160(p,2,0,1);
  func_00354A20(p);
 }
}

void func_002532F0(u8 *p)
{
 Vec3 position;
 u8 *owner;
 func_001266A0(p,6,6);
 func_0018C6E0(p);
 p[0x1B4]=10;
 position.x=-90.0f;
 position.y=154.28570556640625f;
 position.z=0.0f;
 func_0015D010(p,&position.x);
 owner=*(u8**)(p+0x1DC);
 if(*(u32*)(owner+0x42C)&0x4000000)
  *(float*)(owner+0x38)=128.5714263916015625f+*(float*)(p+0x430);
 else if(*(u32*)(owner+0x428)&0x20000000)
  *(float*)(owner+0x38)=42.85713958740234375f+*(float*)(p+0x430);
 func_001757E0(p,0xF,0);
 position=*(Vec3*)(p+0x34);
 func_00179160(p,*(u8**)(p+0x1DC));
 *(Vec3*)(p+0x34)=position;
}

void func_002BE730(u8 *p)
{
 Vec3 offset;
 func_0018C6E0(p);
 offset.x=-80.0f;
 offset.y=184.28570556640625f;
 offset.z=0.0f;
 func_0015D010(p,&offset.x);
 p[0x1B4]=10;
 (*(u8**)(p+0x1DC))[0x1E6]=*(s16*)(*(u8**)(p+0x1DC)+0x140)=p[0x1E6]^1;
 if(!(p[0x22]&1)) {
  p[0x1E6]=*(s16*)(p+0x140)=p[0x1E6]^1;
  (*(u8**)(p+0x1DC))[0x1E6]=*(s16*)(*(u8**)(p+0x1DC)+0x140)=p[0x1E6]^1;
 }
 func_001757E0(p,0xF,0);
}

void func_002BF440(u8 *p)
{
 float *vx,*vy,*ax,*ay;
 if(*(s8*)(p+0x151)==0)func_00175700(p);
 vx=(float*)(p+0x5C);ax=(float*)(p+0x68);
 vy=(float*)(p+0x60);ay=(float*)(p+0x6C);
 *(float*)(p+0x34)+=*(float*)(p+0x5C);
 *(float*)(p+0x5C)+=*(float*)(p+0x68);
 *(float*)(p+0x38)+=*(float*)(p+0x60);
 *(float*)(p+0x60)+=*(float*)(p+0x6C);
 if(*(float*)(p+0x38)<=*(float*)(p+0x430)) {
  *(float*)(p+0x38)=*(float*)(p+0x430);
  p[0x20D]=0;
  *vx=0.0f;*vy=0.0f;*ax=0.0f;*ay=0.0f;
  if(*(s8*)(p+0x151)) {
   p[6]++;
   p[0x151]=0;
   func_001E3A40(p);
  }
 }
}

void func_002E69E0(u8 *p)
{
 u8 *target;
 if((s8)func_00175700(p)<0) {
  p[6]++;
  func_001757E0(p,0x15,0x11);
 } else {
  if((target=func_001E7FD0(p))!=0) {
   p[7]++;
   p[0x206]=3;
   p[0x1FE]=1;
   p[0x20B]=0xC3;
   func_001266A0(p,5,5);
   func_00185770(p,target);
   target[0x24A]=0;
   func_001757E0(p,0x15,0xD);
   func_001E3C40(p);
  }
 }
}

void func_0026A4B0(u8 *p)
{
 Vec3 saved;
 u8 *owner;
 p[6]++;
 func_00175700(p);
 p[0x150]=0;
 *(s16*)(p+0x1C)=24;
 *(u8**)(p+0x1DC)=*(u8**)(p+0x1C4);
 owner=*(u8**)(p+0x1DC);
 saved=*(Vec3*)(owner+0x34);
 func_00178F20(p,owner);
 *(float*)(owner+0x5C)=(*(float*)(owner+0x34)-saved.x)/24.0f;
 *(float*)(owner+0x68)=0.0f;
 *(float*)(owner+0x6C)=-1.0714285373687744140625f;
 *(float*)(owner+0x60)=(*(float*)(owner+0x38)-saved.y)/24.0f-(24.0f**(float*)(owner+0x6C))/2.0f;
 *(Vec3*)(owner+0x34)=saved;
 *(s16*)(owner+0x144)=0;
 *(s16*)(owner+0x146)=0x66;
}

void func_003201D0(u8 *p)
{
 p[0x40C]=2;
 p[0x33C]=5;
 *(float*)(p+0x34)+=*(float*)(p+0x5C);
 *(float*)(p+0x5C)+=*(float*)(p+0x68);
 *(float*)(p+0x38)+=*(float*)(p+0x60);
 *(float*)(p+0x60)+=*(float*)(p+0x6C);
 func_00175700(p);
 if(*(float*)(p+0x38)<*(float*)(p+0x430))*(float*)(p+0x60)=0.0f;
 if(--*(s16*)(p+0x1C)==0) {
  p[7]++;
  *(float*)(p+0x5C)/=16.0f;
  *(float*)(p+0x60)/=16.0f;
  *(float*)(p+0x68)=0.0f;
  *(float*)(p+0x6C)=0.0f;
  func_001757E0(p,0x16,0xD);
  func_00354A20(p);
 }
}

void func_00345A10(u8 *p)
{
 if(!func_00174470(p))func_00345B40(p);
 else if(*(s8*)(p+0x1B2))func_00345AE0(p);
 else if(*(s8*)(p+0x1B3)) {
  p[0x1B3]=0;
  func_00345AE0(p);
 } else {
  *(float*)(p+0x34)+=*(float*)(p+0x5C);
  *(float*)(p+0x5C)+=*(float*)(p+0x68);
  *(float*)(p+0x38)+=*(float*)(p+0x60);
  *(float*)(p+0x60)+=*(float*)(p+0x6C);
  func_00175700(p);
  func_001E7F60(p);
 }
}

void func_002B7460(u8 *p)
{
 u8 *target;
 p[0x40C]=2;
 p[0x33C]=5;
 if((s8)func_00175700(p)<0) {
  p[6]++;
  p[0x40D]=0;
  p[0x40C]=0;
  p[0x33B]=0;
  p[0x33C]=0;
  if(*(s16*)(p+0x140))*(float*)(p+0x5C)=-0.104166664183139801025390625f;
  else *(float*)(p+0x5C)=0.104166664183139801025390625f;
  func_001757E0(p,0x16,7);
 } else if(*(s8*)(p+0x151)==0) {
  *(float*)(p+0x34)+=*(float*)(p+0x5C);
  *(float*)(p+0x5C)+=*(float*)(p+0x68);
  if((target=func_001E7FD0(p))!=0 && (*(u8**)(p+0x220))[0x20D]!=2) {
   p[7]++;
   p[0x20B]=0xC3;
   func_00185770(p,target);
   func_001757E0(p,0xF,3);
  }
 }
}

void func_002986A0(u8 *p)
{
 float v,a;
 p[6]++;
 func_00185490(p);
 func_0018C4B0(p,2);
 *(float*)(p+0x38)=*(float*)(p+0x430);
 p[0x20D]=0;
 *(s16*)(p+0x1C)=0;
 *(float*)(p+0x60)=0.0f;
 *(float*)(p+0x6C)=0.0f;
 v=p[0x212]?-16.6666660308837890625f:-23.333332061767578125f;
 a=p[0x212]?0.677083313465118408203125f:0.78125f;
 *(float*)(p+0x5C)=p[0x1E6]?v:-v;
 *(float*)(p+0x68)=p[0x1E6]?a:-a;
 func_001757E0(p,0x15,0x15);
}

void func_0034EAF0(u8 *p)
{
 float *ax=(float*)(p+0x68);
 *(float*)(p+0x34)+=*(float*)(p+0x5C);
 *(float*)(p+0x5C)+=*(float*)(p+0x68);
 func_00175700(p);
 if(*(s8*)(p+0x1B2)) {
  if((*(u8**)(p+0x1C4))[3]==0) {
   p[5]++;
   if(!func_00174470(p))func_0034FA60(p);
   else func_001E7F60(p);
  } else {
   p[5]=2;
   *(s16*)(p+0x1C)=24;
   func_001757E0(p,0x17,0x11);
  }
 } else {
  if(*(s8*)(p+0x1B3)) {
   func_0018D930(p);
   p[5]++;
   func_001757E0(p,0x17,0x15);
   *ax=0.0f;
   *(float*)(p+0x6C)=0.0f;
   *(float*)(p+0x5C)=*(s16*)(p+0x140)?-15.0f:15.0f;
   *(float*)(p+0x60)=4.28571414947509765625f;
  }
  if(!func_00174470(p))func_0034FA60(p);
  else func_001E7F60(p);
 }
}

void func_0034ED50(u8 *p)
{
 if(*(s16*)(p+0x1C)>=0) {
  if((*(u8**)(p+0x18))[5])func_0034FA60(p);
  else --*(s16*)(p+0x1C);
 } else {
  p[0x13C]=1;
  func_00175700(p);
  *(float*)(p+0x34)+=*(float*)(p+0x5C);
  *(float*)(p+0x5C)+=*(float*)(p+0x68);
  *(float*)(p+0x38)+=*(float*)(p+0x60);
  *(float*)(p+0x60)+=*(float*)(p+0x6C);
  if(*(float*)(p+0x38)<*(float*)(*(u8**)(p+0x18)+0x430)) {
   p[5]++;
   *(float*)(p+0x38)=*(float*)(*(u8**)(p+0x18)+0x430);
   func_001757E0(p,0x17,0x12);
  }
  if(*(s8*)(p+0x1B3))func_0034F330(p);
  else {
   if(*(s8*)(p+0x1B2))func_0034F3B0(p);
   func_001E7F60(p);
  }
 }
}

void func_00272C50(u8 *p)
{
 float offset[3];
 if(p[0x22]&1) {
  p[0x1E6]=*(s16*)(p+0x140)=p[0x1E6]^1;
  (*(u8**)(p+0x1DC))[0x1E6]=*(s16*)(*(u8**)(p+0x1DC)+0x140)=p[0x1E6]^1;
 }
 func_0018C6E0(p);
 p[0x1B4]=10;
 offset[0]=-61.66666412353515625f;
 offset[1]=137.142852783203125f;
 offset[2]=0.0f;
 func_0015D010(p,offset);
 func_001757E0(p,0xF,0);
 func_001B87E0(p,0);
}
