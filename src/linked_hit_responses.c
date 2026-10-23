/* Owner-linked hit responses and fixed-point fade motion. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int),func_00185980(u8 *);
extern int func_001A00E0(u8 *,int,int,int),func_001A4B50(u8 *,int,int,int);
extern void func_00185870(u8 *,u8 *),func_001E7F60(u8 *);
extern const u8 D_004C1B54[] __attribute__((section(".sdata")));
extern const u8 D_004C1B50[] __attribute__((section(".sdata")));
extern const u8 D_004C1BA0[] __attribute__((section(".sdata")));
extern const u8 D_004C1B9C[] __attribute__((section(".sdata")));

extern const u8 D_004631D8[][4],D_004633E0[][4];
extern const s32 D_004631F0[][2],D_004633F0[][2];
void func_0035C0B0(u8 *p,u8 *owner)
{
 u8 *state=owner+0x2B8;
 u8 *target;
 if(owner[5]||owner[0x1E4]!=21)goto fade;
 *(float*)(p+0x34)=*(float*)(owner+0x34)+*(float*)(state+0x24);
 *(float*)(p+0x38)=*(float*)(owner+0x38)+*(float*)(state+0x28);
 if((s8)func_00175700(p)<0)goto fade;
 if(*(s8*)(p+0x1B2)) {
  target=*(u8**)(p+0x1C4);
  if(func_00185980(p)) {
   if(!(state[((target[0x1B8]>>target[2])>>1)+1]&2)) {
    func_001A00E0(owner,12,p[0x1B7],*(s8*)(p+0x151));
    state[7]=1;owner[0x201]=32;owner[0x1B1]=0;owner[0x20B]=196;*(s8*)(owner+0x16A)=-1;
    func_00185870(p,target);
    p[4]=2;p[0x13C]=0;target[0x208]=2;return;
   }
  }
  p[5]=2;*(s8*)(state+7)=-1;
  func_001757E0(p,23,(u8)(D_004C1B54[p[0x1B7]]+*(s8*)(p+0x151)));
  return;
 }
 func_001E7F60(p);return;
fade:
 {
  const u8 *color;
  const s32 *velocity;
  p[5]++;*(s8*)(state+7)=-1;
  color=D_004631D8[p[0x1B7]];
  p[0x14C]=color[0];p[0x14D]=color[1];p[0x14E]=color[2];p[0x14F]=color[3];
  velocity=D_004631F0[p[0x1B7]];
  *(float*)(p+0x5C)=1.66666662693023681640625f*(float)velocity[0]/65536.0f;
  *(float*)(p+0x60)=1.66666662693023681640625f*(float)velocity[1]/65536.0f;
  *(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
  if(*(s16*)(p+0x140))*(float*)(p+0x5C)=-*(float*)(p+0x5C);
  func_001757E0(p,23,(u8)(D_004C1B50[p[0x1B7]]+*(s8*)(p+0x151)));
 }
}
void func_0035F660(u8 *p,u8 *owner)
{
 u8 *state=owner+0x2B8;
 u8 *target;
 *(s8*)(p+0x24)=*(s8*)(owner+0x24);p[0x31]=8;
 if(owner[5]||owner[0x1E4]!=21||owner[0x1FD]!=2)goto fade;
 *(float*)(p+0x34)=*(float*)(owner+0x34)+*(float*)(state+12);
 *(float*)(p+0x38)=*(float*)(owner+0x38)+*(float*)(state+16);
 if((s8)func_00175700(p)<0)goto fade;
 if(*(s8*)(p+0x1B2)) {
  if(func_00185980(p)) {
   target=*(u8**)(p+0x1C4);
   func_001A4B50(owner,10,p[0x1B7],*(s8*)(p+0x151));
   state[6]=1;owner[0x201]=32;owner[0x1B1]=0;owner[0x20B]=195;*(s8*)(owner+0x16A)=-1;
   func_00185870(p,target);
   p[4]=2;target[0x208]=2;return;
  }
  p[5]=2;*(s8*)(state+6)=-1;
  func_001757E0(p,23,(u8)(D_004C1BA0[p[0x1B7]]+*(s8*)(p+0x151)));
  return;
 }
 func_001E7F60(p);return;
fade:
 {
  const u8 *color;
  const s32 *velocity;
  p[5]++;*(s8*)(state+6)=-1;
  color=D_004633E0[p[0x1B7]];
  p[0x14C]=color[0];p[0x14D]=color[1];p[0x14E]=color[2];p[0x14F]=color[3];
  velocity=D_004633F0[p[0x1B7]];
  *(float*)(p+0x5C)=1.66666662693023681640625f*(float)velocity[0]/65536.0f;
  *(float*)(p+0x60)=1.66666662693023681640625f*(float)velocity[1]/65536.0f;
  *(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
  if(*(s16*)(p+0x140))*(float*)(p+0x5C)=-*(float*)(p+0x5C);
  func_001757E0(p,23,(u8)(D_004C1B9C[p[0x1B7]]+*(s8*)(p+0x151)));
 }
}
