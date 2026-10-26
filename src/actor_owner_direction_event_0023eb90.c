typedef unsigned char u8;typedef signed char s8;
extern int func_00175700(u8*);
extern void func_001843A0(u8*),func_001E3A40(u8*);
void func_0023EB90(u8*p){
 if((s8)func_00175700(p)<0){*(short*)(p+0x140)^=1;func_001843A0(p);return;}
 if(*(s8*)(p+0x151)){
  u8*owner;
  p[0x151]=0;owner=*(u8**)(p+0x1DC);owner[0x20A]=11;owner[0x20D]=2;p[0x1B5]=owner[0x1B5]=32;
  owner[0x1E6]=p[0x1E6];p[0x1E6]^=1;func_001E3A40(owner);
 }
}
