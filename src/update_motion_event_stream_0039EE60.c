typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern u8 *func_0039E4E0(u8 *,int);
extern void func_0039EF70(u8 *);
void func_0039EE60(u8 *p) {
 u8 *event;
 s16 delta;
 const s16 *stream;
 if(D_004D18DC & (1u<<D_004D18DB))return;
 --*(s16 *)(p+28);
 if(*(s16 *)(p+28)>=0)return;
 stream=*(const s16 **)(p+160);
 delta=stream[0];
 *(s16 *)(p+28)=stream[1];
 *(const s16 **)(p+160)=stream+2;
 if(*(s16 *)(p+320)!=0)delta=-delta;
 *(float *)(p+52)+=1.6666666269302368f*delta/256.0f;
 event=func_0039E4E0(p,2);
 if(event){
  *(float *)(event+52)=*(float *)(p+52);
  *(float *)(event+56)=*(float *)(p+56);
  --*(s16 *)(p+30);
  if(*(s16 *)(p+30)<=0)func_0039EF70(p);
 }
}
