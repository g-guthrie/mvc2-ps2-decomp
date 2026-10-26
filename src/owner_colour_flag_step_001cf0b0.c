typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;
typedef struct {u8 pad[0x160];s8 flags[8];} FlagOwner;
extern u16 *D_004C2718 __attribute__((section(".sdata")));
extern void func_001CF6F0(u8*),func_001CF6A0(u8*),func_001CF720(u8*),func_00175C00(u8*,int);
extern int func_00175670(u8*);
void func_001CF0B0(u8*p){
 FlagOwner *owner;s8 *flags,*flag; s8 value;
 func_001CF6F0(p);p[0x13C]=1;p[0x24]=*(s8*)(*(u8**)(p+0x18)+0x24);*(s8*)(p+0x31)=-2;
 if(*D_004C2718==*(u16*)(*(u8**)(p+0x18)+0x168)){
  owner=*(FlagOwner**)(p+0x18);flags=owner->flags;value=flags[1];flag=flags+1;
  if(value){*flag=0;if((s8)func_00175670(p)<0){func_00175C00(*(u8**)(p+0x18),0);func_001CF6A0(p);return;}}
  func_001CF720(p);
 }else{func_00175C00(*(u8**)(p+0x18),0);func_001CF6A0(p);}
}
