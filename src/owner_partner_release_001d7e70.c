typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef unsigned int u32;
extern int func_00174170(void),func_001754A0(u8*,int,int);
extern void func_001D8570(u8*,void*),func_001D8000(u8*,void*);
extern u8 *D_004C2840 __attribute__((section(".sdata")));
void func_001D7E70(u8*p,void*owner_context){
 u8*owner=(u8*)owner_context;
 u8*partner;
 if(*(int*)(p+0xD0)!=*(u16*)(owner+0x168)){func_001D8570(p,owner_context);return;}
 partner=*(u8**)(owner+0x1C4);
 if(*(s8*)(owner+0x1B2)&&partner[5]==3&&owner==*(u8**)(partner+0x1C8)&&partner[0x1B6]==*(int*)(p+0xD4)){
  ++p[5];p[0x13C]=1;p[0x24]=*(s8*)(partner+0x24);
  *(short*)(p+0x1C)=(func_00174170()&63)+120;
  *(float*)(p+0x68)=1.6666666269302368f*(float)(((u32)func_00174170()&63)-32u);
  *(float*)(p+0x6C)=2.142857074737549f*(float)((u32)func_00174170()%partner[0x14C]);
  *(u8**)(p+0xD8)=partner;
  func_001754A0(p,27,(u8)((*(u32*)(D_004C2840+0x1C)&3)+6));func_001D8000(p,owner_context);
 }
}
