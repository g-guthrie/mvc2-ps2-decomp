typedef unsigned char u8;typedef signed char s8;typedef short s16;
typedef struct {float x,y,z;} V3;
extern int func_00175580(u8*,int,int,int);
void func_00198FC0(u8*p) {
 u8 *owner=*(u8**)(p+0x18);s8 state=*(s8*)(owner+0x161);
 if(state) {
  p[0x13C]=1;*(V3*)(p+0x34)=*(V3*)(owner+0x34);
  *(s16*)(p+0x140)=*(s16*)(owner+0x140);
  *(float*)(p+0x118)=*(float*)(owner+0x118);
  *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
  if(state<0) {*(float*)(p+0x38)=*(float*)(owner+0x430);state&=0x7F;}
  if(state!=*(s16*)(p+0x1C)) {func_00175580(p,27,(u8)(p[0x22]+1),state);*(s16*)(p+0x1C)=state;}
 } else {p[0x13C]=0;*(s16*)(p+0x1C)=0;}
}
