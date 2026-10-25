typedef unsigned char u8;
extern int func_00175700(u8*),func_001A1330(u8*,int,u8);
extern void func_00238B70(u8*,float*);
void func_002361F0(u8 *p,u8 *work) {
 *(float*)(p+0x34)+=*(float*)(p+0x5C);*(float*)(p+0x5C)+=*(float*)(p+0x68);
 *(float*)(p+0x38)+=*(float*)(p+0x60);*(float*)(p+0x60)+=*(float*)(p+0x6C);
 func_00175700(p);
 if(p[0x15B]) {
  int count;
  ++p[7];func_00238B70(p,(float*)work);
  count=8;if(p[0x1B7])count+=2;
  if(func_001A1330(p,count,0)==0)p[6]=2;
 }
}
