typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
typedef struct { s32 vx,ax,vy,ay; } Motion;
extern Motion D_004B7270[][2];
void func_00235C40(u8 *p,s32 index) {
 Motion *m;
 m=D_004B7270[index];
 m+=p[0x1B7];
 *(f32 *)(p+0x5C)=((5.0f/3.0f)*m->vx)/65536.0f;
 *(f32 *)(p+0x68)=((5.0f/3.0f)*m->ax)/65536.0f;
 *(f32 *)(p+0x60)=((15.0f/7.0f)*m->vy)/65536.0f;
 *(f32 *)(p+0x6C)=((15.0f/7.0f)*m->ay)/65536.0f;
 if(*(s16 *)(p+0x140)!=0) {
  *(f32 *)(p+0x5C)=-*(f32 *)(p+0x5C);
  *(f32 *)(p+0x68)=-*(f32 *)(p+0x68);
 }
}
