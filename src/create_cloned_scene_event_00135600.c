typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
typedef struct {float x,y,z;} Float3;
extern void *func_003DA750(void *,int,int);
extern void func_001356A0(u8 *);
void func_00135600(u8 *owner){
 u8 *p=func_003DA750(0,13,1);
 if(p){
 p[316]=1;
 *(void (**)(u8 *))(p+16)=func_001356A0;
 *(s16 *)(p+204)=*(s16 *)(owner+204);
 *(u32 *)(p+132)=*(u32 *)(owner+132);
 *(u32 *)(p+208)=*(u32 *)(owner+208)|0x00800020;
 *(Float3 *)(p+52)=*(Float3 *)(owner+52);
 *(u32 *)(p+68)=*(u32 *)(owner+68);
 *(float *)(p+116)=0.5f;
 }
}
