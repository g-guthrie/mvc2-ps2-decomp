typedef unsigned char u8;typedef short s16;typedef float f32;
extern int func_001757E0(u8 *,int,int);
typedef struct {u8 pad[0x34];f32 x;} Position;
void func_0029D200(u8 *p) {
 Position *position=(Position *)p;
 p[6]++;p[0x13c]=1;*(f32 *)(p+0x68)=position->x;
 if (*(s16 *)(p+0x140)!=0) {position->x-=213.3333282470703125f;*(f32 *)(p+0x5c)=5.0f;}
 else {position->x+=213.3333282470703125f;*(f32 *)(p+0x5c)=-5.0f;}
 func_001757E0(p,18,0);
}
