#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
extern f32 D_004B8330[];
extern s8 D_004B8348[];
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern int func_001757E0(u8 *,int,int);
typedef struct {u8 prefix[0x34];f32 x,y;u8 mid[0x20];f32 vx,vy,offset,ay;u8 tail[0x140-0x6c];s16 facing;} Motion;
void func_0034C1E0(u8 *p) {
 Motion *m=(Motion *)p;
 u8 *q=*(u8 **)(p+0x18);
 s16 facing;
 m->x=-80.0f;
 m->y=D_004B8330[p[0x22]];
 *(s8 *)(p+0x24)=D_004B8348[p[0x22]];
 p[0x21]=p[0x22];
 m->offset=-80.0f;
 m->vx=-26.66666603088379f;
 facing=*(s16 *)(q+0x140);
 m->facing=facing;
 if(facing) {
  m->vx=-m->vx;
  m->offset=-m->offset;
 }
 m->y+=*(f32 *)(q+0x38);
 m->x=*(f32 *)(q+0x34)+m->offset;
 m->ay=80.0f;
 p[0x22]=0;
 if(*(u32 *)(D_004C2840+0x1c)&3) {
  p[0x1b5]=69;p[0x1b2]=*(u16 *)(p+0x1c0)=0;*(u32 *)(p+0x1d8)=0;
  {u32 address=p[2]*2;address+=(u32)D_004C2794;address+=0x7c;++*(s16 *)address;}
 }else{
  p[0x1b5]=68;p[0x1b2]=*(u16 *)(p+0x1c0)=0;*(u32 *)(p+0x1d8)=0;
  {u32 address=p[2]*2;address+=(u32)D_004C2794;address+=0x7c;++*(s16 *)address;}
 }
 func_001757E0(p,22,17);
}
