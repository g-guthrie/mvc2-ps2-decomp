typedef unsigned char u8;
typedef short s16;
extern int func_00174170(void);
extern void func_001CADB0(u8*),func_001CAC90(u8*),func_001CA9F0(u8*);
void func_001CA5C0(u8 *p) {
 if(!p[5]) {
  ++p[5];
  *(s16*)(p+0x1c)=func_00174170()&15;
  func_001CADB0(p);
  *(s16*)(p+0x1e)=2;
  func_001CAC90(p);
 }
 func_001CA9F0(p);
}
