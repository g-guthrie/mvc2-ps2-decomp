typedef unsigned char u8; typedef signed char s8; typedef signed short s16; typedef float f32;
typedef struct {u8 pad[0x1e]; s16 countdown;} Timer;
extern u8 *D_004C28DC __attribute__((section(".sdata")));
extern int func_00175700(u8 *);
extern void func_0030A330(u8 *);
void func_001C05D0(u8 *p) {
 Timer *timer=(Timer *)p;
 *(f32 *)(p+0x50)+=*(f32 *)(p+0x88); *(f32 *)(p+0x54)+=*(f32 *)(p+0x8c); *(f32 *)(p+0x118)-=0.04f;
 if (--timer->countdown<=0) { p[4]++; timer->countdown=19; }
}
void func_0030A2D0(u8 *p) {
 func_00175700(p);
 if (*(s8 *)(p+0x151)==0) {
  p[6]++; D_004C28DC[8]=0; *(f32 *)(p+0x5c)=0.0f; *(f32 *)(p+0x60)=0.0f; *(f32 *)(p+0x68)=0.0f; *(f32 *)(p+0x6c)=0.0f; func_0030A330(p);
 }
}
