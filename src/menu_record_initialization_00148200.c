/* Provisional: selector bounds and overlapping data views remain unproved.
 * Non-case selectors leave the native loop inputs unresolved. */
typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef unsigned int u32;typedef int s32;typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u32 v[7];} Mapping;
typedef struct {u8 pad[8]; s16 h8;} Global;
extern Mapping D_00443A70;
extern V3 D_00443A40[];
extern Global *D_004C2840;
extern s8 D_004C2868,D_004C2860,D_004C2858,D_004C2854;
extern u8 D_004434B0[],D_00443500[],D_00443530[],D_00443580[];
void func_00148200(u8 *p) {
 Mapping mapping=D_00443A70; u32 t;u8 *dst;s32 n,lim=0,i;
 p[4]++;p[0x13c]=1;
 *(V3 *)(p+0x34)=D_00443A40[mapping.v[p[0x20]]];
 if (p[0x20]==D_004C2840->h8) {
  *(f32 *)(p+0x78)=1.0f;*(f32 *)(p+0x7c)=1.0f;*(f32 *)(p+0x80)=1.0f;
 } else {
  *(f32 *)(p+0x78)=0.7f;*(f32 *)(p+0x7c)=0.7f;*(f32 *)(p+0x80)=0.7f;
 }
 *(f32 *)(p+0x74)=1.0f;
 t=p[0x20];
 switch(t) {
 case 0: lim=D_004C2868;n=8;dst=D_004434B0; *(u8 **)(p+0xd8)=dst; break;
 case 2: lim=D_004C2860;n=4;dst=D_00443500; *(u8 **)(p+0xd8)=dst; break;
 case 5: lim=D_004C2858;n=8;dst=D_00443530; *(u8 **)(p+0xd8)=dst; break;
 case 6: lim=D_004C2854;n=8;dst=D_00443580; *(u8 **)(p+0xd8)=dst; break;
 }
 for(i=0;i<n;i++){if(i<=lim)dst[0]=1;else dst[0]=0;dst+=8;}
}
