typedef unsigned char u8;
extern u8 D_004D18A0;
extern int func_00174170(void),func_001757E0(u8*,int,int);
extern void func_001E0760(void*,u8);
void func_00323250(u8 *p) {
 p[0x13C]=0;
 if(D_004D18A0>=2) {
  u8 *parent;int choice;
  p[0x13C]=1;parent=*(u8**)(p+0x220);choice=func_00174170()&1;
  if(parent[1]==58)choice=p[2];
  if(choice==0) {p[6]=2;p[0x20D]=0;func_001E0760(p,0);}
  else {p[6]=1;p[0x20D]=2;*(float*)(p+0x38)+=(15.0f/7.0f)*256.0f;*(float*)(p+0x60)=0;*(float*)(p+0x6C)=-0.401785702f;}
  func_001757E0(p,18,(u8)choice);
 }
}
