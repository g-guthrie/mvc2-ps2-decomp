typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
typedef struct {float x,y,z;} Float3;
typedef union {float value;u32 bits;} FloatBits;
extern void *func_003DA750(void *,int,int);
extern void func_00144630(u8 *);
extern u8 *D_004C2808;
extern Float3 D_004B31E0;
void func_001445A0(void){
 u8 *p=func_003DA750(0,13,1);
 if(p){
 p[316]=1;
 *(void (**)(u8 *))(p+16)=func_00144630;
 *(s16 *)(p+204)=4;
 *(u8 **)(p+132)=D_004C2808;
 *(Float3 *)(p+52)=D_004B31E0;
 *(u32 *)(p+208)=2065;
 *(s16 *)(p+28)=0;*(s16 *)(p+30)=0;
 ((FloatBits *)(p+80))->bits=0x3DCCCCCD;
 ((FloatBits *)(p+84))->bits=0x3DCCCCCD;
 ((FloatBits *)(p+88))->bits=0x3DCCCCCD;
 }
}
