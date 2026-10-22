typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef struct {float x,y,z;} Vec3;
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int),func_00185980(u8 *);
extern void func_001E3270(u8 *,int,float),func_001266A0(u8 *,int,int);
extern void func_0034A6B0(u8 *,u8),func_00185770(u8 *,u8 *),func_00185490(u8 *);
extern void func_001820A0(u8 *);
extern void func_00381E40(u8 *,int,int),func_00183770(u8 *,const float *),func_00280330(void *);
extern int func_00174170(void);

void func_00200690(u8 *p)
{
 u8 *state=p+0x2B8;
 func_00175700(p);
 *(float*)(p+0x34)+=*(float*)(p+0x5C);
 *(float*)(p+0x5C)+=*(float*)(p+0x68);
 if(*(s8*)(p+0x1B2)<0) {
  state[0x1C]=0;
  func_001E3270(p,0x1F,32.0f);
  if(!(*(s8*)(p+0x1B2)&0x7F) && func_00185980(p)) {
   p[6]++;p[7]=0;
   func_001266A0(p,5,5);
   *(float*)(p+0x38)=*(float*)(p+0x430);
   *(u8**)state=*(u8**)(p+0x1C4);
   state[0xD]=0;state[0x16]=0;
   func_0034A6B0(p,0);
   func_001757E0(p,0x16,0xF);
   p[0x20B]=0xC5;
   func_00185770(p,*(u8**)(p+0x1C4));
  } else {
   *(float*)(p+0x38)=*(float*)(p+0x430);
   p[7]=1;
   *(float*)(p+0x5C)=3.3333332538604736328125f;
   *(float*)(p+0x68)=0.0f;
   *(float*)(p+0x60)=17.142856597900390625f;
   *(float*)(p+0x6C)=-0.803571403026580810546875f;
   if(*(s16*)(p+0x140)) {
    *(float*)(p+0x5C)=-*(float*)(p+0x5C);
    *(float*)(p+0x68)=-*(float*)(p+0x68);
   }
   func_001757E0(p,0x16,0xB);
  }
 } else if(--*(s16*)(p+0x1C)==0) {
  state[0x1C]=0;
  func_001E3270(p,0x1F,32.0f);
  p[6]=3;p[7]=0;
  *(float*)(p+0x60)=0.0f;
  *(float*)(p+0x6C)=0.0f;
  *(float*)(p+0x5C)/=2.0f;
  func_001757E0(p,0x16,0xA);
 }
}

void func_00201430(u8 *p)
{
 u8 *state=p+0x2B8;
 u8 *owner;
 func_00175700(p);
 *(float*)(p+0x34)+=*(float*)(p+0x5C);
 *(float*)(p+0x5C)+=*(float*)(p+0x68);
 if(*(s8*)(p+0x1B2)<0) {
  state[0x1C]=0;
  func_001E3270(p,0x1F,32.0f);
  if(!(*(s8*)(p+0x1B2)&0x7F)) {
   owner=*(u8**)(p+0x1C4);
   if(func_00185980(p)) {
    *(float*)(owner+0x38)=*(float*)(p+0x38);
    p[6]++;p[7]=0;
    func_001266A0(p,5,5);
    *(u8**)state=*(u8**)(p+0x1C4);
    state[0xD]=0;state[0x16]=0;
    func_0034A6B0(p,1);
    func_001757E0(p,0x16,0x15);
    p[0x20B]=0xC5;
    func_00185770(p,*(u8**)(p+0x1C4));
    return;
   }
  }
  p[7]=1;
  *(float*)(p+0x5C)=3.3333332538604736328125f;
  *(float*)(p+0x68)=0.0f;
  *(float*)(p+0x60)=17.142856597900390625f;
  *(float*)(p+0x6C)=-0.803571403026580810546875f;
  if(*(s16*)(p+0x140)) {
   *(float*)(p+0x5C)=-*(float*)(p+0x5C);
   *(float*)(p+0x68)=-*(float*)(p+0x68);
  }
  func_001757E0(p,0x16,0xB);
 } else if(--*(s16*)(p+0x1C)==0) {
  p[7]++;
  state[0x1C]=0;
  func_001E3270(p,0x1F,32.0f);
  *(float*)(p+0x5C)/=2.0f;
  *(float*)(p+0x68)=0.0f;
  *(float*)(p+0x60)=-2.142857074737548828125f;
  *(float*)(p+0x6C)=-0.803571403026580810546875f;
  func_001757E0(p,1,9);
 }
}

void func_0031E0B0(u8 *p)
{
 u8 *state=p+0x2B8;
 int direction_mask;
 u8 input;
 *(float*)(p+0x34)+=*(float*)(p+0x5C);
 *(float*)(p+0x5C)+=*(float*)(p+0x68);
 *(float*)(p+0x38)+=*(float*)(p+0x60);
 *(float*)(p+0x60)+=*(float*)(p+0x6C);
 if(*(s8*)(p+0x1B2)) {
  p[6]++;p[7]=0;
  *(float*)(p+0x60)=18.2142848968505859375f;
  *(float*)(p+0x6C)=-0.803571403026580810546875f;
  *(float*)(p+0x5C)/=8.0f;
  if(*(s8*)(p+0x1B2)&1)*(float*)(p+0x5C)/=8.0f;
  *(float*)(p+0x5C)=-*(float*)(p+0x5C);
  p[0x20D]=2;
  func_00185490(p);
  func_001757E0(p,0x15,0x13);
 } else {
  direction_mask=*(s8*)(p+0x211);
  if(direction_mask && !(direction_mask&(1<<p[0x1E6])) && (input=p[0x22]) && input!=4) {
   p[7]=2;
   func_001757E0(p,0x15,0x14);
  } else if(*(float*)(p+0x38)<*(float*)(p+0x430)) {
   p[7]=1;
   *(float*)(p+0x38)=*(float*)(p+0x430);
   func_00185490(p);
   p[0x20D]=1;
   func_001757E0(p,0x15,0x15);
  } else if((s8)func_00175700(p)<0) {
   p[6]++;p[7]=0;
   *(float*)(p+0x6C)=-0.803571403026580810546875f;
   p[0x20D]=2;
   state[0]=1;
   func_001820A0(p);
   func_001757E0(p,0x15,(u8)(p[0x168]+1));
  }
 }
}

void func_0027DD50(u8 *p)
{
 Vec3 position;
 int frame,toggle;
 switch(p[6]) {
 case 0:
  p[0x20D]=0;
  p[6]++;
  func_001757E0(p,0x15,0);
  func_00381E40(p,0,0);
  *(s16*)(p+0x1C)=10;
  *(s16*)(p+0x1E)=0;
  p[0x22]=0;
  break;
 case 1:
  func_00175700(p);
  if(*(s8*)(p+0x151)) {
   p[6]++;
   p[0x151]=0;
   position.x=-101.66666412353515625f**(float*)(p+0x50);
   position.y=165.0f**(float*)(p+0x54);
   position.z=*(float*)(p+0x3C);
   func_00183770(p,&position.x);
  }
  break;
 case 2:
  p[0x33C]=5;
  if(--*(s16*)(p+0x1E)<=0) {
   *(s16*)(p+0x1E)=func_00174170()&7;
   toggle=(*(s8*)(p+0x22)+1)&1;
   p[0x22]=toggle;
   if(toggle) {
    *(s16*)(p+0x1E)+=8;
    --*(s16*)(p+0x1C);
    frame=p[0x1C];
   } else frame=(u8)(((unsigned int)func_00174170()%3)+0x80);
   func_00381E40(p,6,frame);
   if(*(s16*)(p+0x1C)<=0)p[6]++;
  }
  /* The native state machine also advances animation on this turn. */
 case 3:
  if((s8)func_00175700(p)<0) {
   *(float*)(p+0x5C)=0.0f;*(float*)(p+0x60)=0.0f;
   *(float*)(p+0x68)=0.0f;*(float*)(p+0x6C)=0.0f;
   func_00280330(p);
  }
  break;
 }
}
