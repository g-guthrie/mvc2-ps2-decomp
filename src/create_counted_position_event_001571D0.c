/* Caller 0x0015482C supplies the unused middle argument and kind in A2. */
typedef unsigned char u8;
typedef signed char s8;
typedef struct {float x,y,z;} Float3;
extern void *func_003DA750(void *,int,int);
extern void func_00157140(u8 *);
extern s8 D_004D1900;
void func_001571D0(const Float3 *position, int ignored, int kind) {
 u8 *p=func_003DA750(0,kind,1);
 if(p) {
  D_004D1900++;
  p[316]=0;
  *(void (**)(u8 *))(p+16)=func_00157140;
  *(Float3 *)(p+52)=*position;
  p[35]=kind;
 }
}
