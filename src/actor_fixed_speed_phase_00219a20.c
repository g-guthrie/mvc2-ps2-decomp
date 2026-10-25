#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef struct {u8 prefix[0x5C];float vx;} Motion;
extern int func_00175700(u8*),func_001757E0(u8*,int,int);
extern int D_004BFEF8[] __attribute__((section(".sdata")));
void func_00219A20(u8 *p)
{
 Motion *motion=(Motion*)p;
 if((s8)func_00175700(p)<0){
  ++p[7];*(s16*)(p+0x1C)=4;p[0x206]=3;
  motion->vx=1.6666666269302368f*(float)D_004BFEF8[p[0x1B7]]/65536.0f;
  if(p[0x1E6])motion->vx=-motion->vx;
  func_001757E0(p,21,39);
 }
}
