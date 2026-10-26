typedef unsigned char u8;typedef short s16;
extern void func_00183D50(u8*);extern int func_001757E0(u8*,int,int),func_00175700(u8*);
static void func_00255620(u8*p) {
 if(*(s16*)(p+0x2B8)>0) {p[0x40D]=0;p[0x40C]=0;p[0x33C]=5;}
 else {p[0x40D]=0;p[0x40C]=0;p[0x33B]=0;p[0x33C]=0;}
}
void func_0025A3F0(u8*p) {
 func_00255620(p);
 if(*(float*)(p+0x38)<*(float*)(p+0x430)) {
  ++p[6];p[0x20D]=0;*(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
  *(float*)(p+0x38)=*(float*)(p+0x430);func_00183D50(p);func_001757E0(p,22,5);
 }
 func_00175700(p);
 *(float*)(p+0x34)+=*(float*)(p+0x5C);*(float*)(p+0x5C)+=*(float*)(p+0x68);
 *(float*)(p+0x38)+=*(float*)(p+0x60);*(float*)(p+0x60)+=*(float*)(p+0x6C);
}
