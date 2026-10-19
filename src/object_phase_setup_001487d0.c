typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x,y,z; } V3;
typedef struct { f32 x,y,z,w; } V4;
typedef struct { V3 position; u16 id; u8 tail[2]; } Entry;
extern V4 D_004439B0;
extern Entry D_00442AB0[];
extern s32 D_004C2804;
extern u8 *D_004C2840;
extern void func_00147750(u8 *,u8 *,s32);
void func_001487D0(u8 *p) {
 Entry *entry;
 unsigned int mode;
 p[4]++;
 p[0x13C]=1;
 *(s32 *)(p+0xD0)|=0x420;
 *(V4 *)(p+0x74)=D_004439B0;
 mode=p[0x23];
 if(mode==0) {
  entry=&D_00442AB0[p[0x20]];
  *(u16 *)(p+0xCC)=entry->id;
  *(s32 *)(p+0x84)=D_004C2804;
  *(V3 *)(p+0x34)=entry->position;
  func_00147750(p,(u8 *)2,p[0x20]);
 } else if((u8)mode==1) {
  *(u16 *)(p+0xCC)=0x8E;
  *(s32 *)(p+0x84)=D_004C2804;
  *(s32 *)(p+0xD8)=*(s16 *)(D_004C2840+8);
  *(s16 *)(p+0x1E)=0;
 }
}
