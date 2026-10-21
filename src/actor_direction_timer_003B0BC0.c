#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
extern int func_00175700(u8 *);
extern int func_00175910(u8 *,int,int,int);
extern int func_00174170(void);
void func_003B0BC0(u8 *p) {
 if((s8)func_00175700(p)<0) {
  int direction;
  p[5]++;
  if(*(s16 *)(p+0x140)) direction=16-p[0x22]/2;
  else direction=p[0x22]/2;
  func_00175910(p,23,3,direction&15);
  *(s16 *)(p+0x1c)=(func_00174170()&7)+4;
 }
}
