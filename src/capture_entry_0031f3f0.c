/* Capture entry: validate the target and record it in actor-local scratch state. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {float x,y,z;} Vec3;
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int);
extern void func_001266A0(u8 *,int,int);
void func_0031F3F0(u8 *p,void *state)
{
 u8 *target;
 float *velocity=(float*)(p+0x5C);
 float *acceleration=(float*)(p+0x68);
 s8 flags;
 p[0x40C]=2;p[0x33C]=5;
 *(float*)(p+0x34)+=*(float*)(p+0x5C);
 *(float*)(p+0x5C)+=*(float*)(p+0x68);
 func_00175700(p);
 flags=*(s8*)(p+0x211);
 if(flags&&flags!=(1<<p[0x1E6])) {
  p[0x40D]=0;p[0x40C]=0;p[0x33B]=0;p[0x33C]=0;
  p[6]++;p[7]=0;
  func_001757E0(p,22,3);return;
 }
 flags=*(s8*)(p+0x1B2);
 if(flags) {
  target=*(u8**)(p+0x1C4);
  if(target[3]==0&&!(flags&1)&&target[0x20D]!=3&&target[5]==3) {
   float offset;
   p[7]++;target[0x20D]=0;
   func_001266A0(p,8,8);
   *(u8**)((u8*)state+4)=target;*(s16*)((u8*)state+8)=0;
   *(Vec3*)(target+0x34)=*(Vec3*)(p+0x34);
   offset=-100.0f;
   if(p[0x1E6])offset=-offset;
   *(float*)(target+0x34)+=offset;
   *velocity=0;*acceleration=0;
   func_001757E0(p,22,1);
  } else {
   p[0x40D]=0;p[0x40C]=0;p[0x33B]=0;p[0x33C]=0;
   p[6]++;p[7]=0;
   *velocity=0;*(float*)(p+0x60)=0;*acceleration=0;*(float*)(p+0x6C)=0;
   func_001757E0(p,22,4);
  }
 }
}
