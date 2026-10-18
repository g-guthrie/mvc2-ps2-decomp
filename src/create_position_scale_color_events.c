typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
typedef struct {float x,y,z;} Float3;
extern void *func_003DA750(void *,int,int);
extern void func_00157890(u8 *);
extern void func_00157600(u8 *);
extern u32 D_004C2838;
void func_00157970(const Float3 *position){
 u8 *p=func_003DA750(0,9,1);
 if(p){
 p[316]=1;
 *(void (**)(u8 *))(p+16)=func_00157890;
 *(s16 *)(p+204)=57;
 *(u32 *)(p+132)=D_004C2838;
 *(u32 *)(p+208)=0x00800411;
 *(Float3 *)(p+52)=*position;
 *(float *)(p+80)=1.0f;*(float *)(p+84)=1.0f;*(float *)(p+88)=1.0f;
 *(float *)(p+120)=1.0f;*(float *)(p+124)=1.0f;*(float *)(p+128)=1.0f;
 }
}

void func_001576A0(const Float3 *position){
 u8 *p=func_003DA750(0,9,1);
 if(p){
 p[316]=1;
 *(void (**)(u8 *))(p+16)=func_00157600;
 *(s16 *)(p+204)=43;
 *(u32 *)(p+132)=D_004C2838;
 *(u32 *)(p+208)=0x00800411;
 *(Float3 *)(p+52)=*position;
 *(float *)(p+80)=0.5f;*(float *)(p+84)=0.5f;*(float *)(p+88)=0.5f;
 *(float *)(p+120)=1.0f;*(float *)(p+124)=1.0f;*(float *)(p+128)=1.0f;
 }
}
