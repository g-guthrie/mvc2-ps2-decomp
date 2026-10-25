#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
extern int func_00175700(u8*);
extern void func_00377E10(void*),func_00184540(u8*),func_001843A0(u8*);

/* Real retail floor integration; the build checks this entire static copy at 0x00270B60. */
typedef struct {u8 prefix[0x38];float y;} FloorPosition;
static void func_00270B60(u8 *p) {
    FloorPosition *position=(FloorPosition*)p;
    *(float *)(p + 52) += *(float *)(p + 92);
    *(float *)(p + 92) += *(float *)(p + 104);
    position->y += *(float *)(p + 96);
    *(float *)(p + 96) += *(float *)(p + 108);
    if (position->y <= *(float *)(p + 1072))
        position->y = *(float *)(p + 1072);
}

void func_00270D30(u8 *p)
{
 func_00270B60(p);if(*(s8*)(p+0x151)){func_00377E10(p);p[0x151]=0;}
 if((s8)func_00175700(p)<0){
  if(p[0x20D]==2){*(float*)(p+0x60)=0;*(float*)(p+0x6C)=0;func_00184540(p);return;}
  func_001843A0(p);
 }
}
