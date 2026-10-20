typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x,y,z; } V3;
typedef struct { u32 words[49]; } Payload;
typedef struct { u8 gap0[0x34]; V3 position; u8 gap40[0x1C]; f32 velocityX; u8 gap60[8]; f32 accelerationX; } MotionView;
extern void func_001757E0(u8 *,int,int);
/* The 00194170 event head supplies the owner in a1; its inner dispatchers preserve it. */
void func_001941C0(u8 *p,u8 *q) {
 p[4]++;
 *(Payload *)(p+0xEC)=*(Payload *)(q+0xEC);
 p[0x13C]=1;
 p[2]=q[2];p[1]=q[1];
 *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
 *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
 p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
 *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
 *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 p[0x31]=4;
 func_001757E0(p,15,6);
 if(*(s16 *)(p+0x140)!=0) *(f32 *)(p+0x34)=*(f32 *)(q+0x34)+520.0f/3.0f;
 else *(f32 *)(p+0x34)=*(f32 *)(q+0x34)-520.0f/3.0f;
 *(f32 *)(p+0x38)=*(f32 *)(q+0x38)+1005.0f/7.0f;
}

void func_00194480(u8 *p,u8 *q) {
 p[4]++;
 *(Payload *)(p+0xEC)=*(Payload *)(q+0xEC);
 p[0x13C]=1;
 p[2]=q[2];p[1]=q[1];
 *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
 *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
 p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
 *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
 *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 p[0x31]=2;
 func_001757E0(p,20,3);
 {
 MotionView *m=(MotionView *)p;
 MotionView *owner=(MotionView *)q;
 m->velocityX=160.0f/3.0f;
 m->accelerationX=0.0f;
 m->position.x=520.0f/3.0f;
 if(*(s16 *)(p+0x140)!=0) m->position.x=owner->position.x+m->position.x;
 else {
  m->velocityX=-m->velocityX;
  m->position.x=owner->position.x-m->position.x;
 }
 m->position.y=owner->position.y+1005.0f/7.0f;
 }
}
