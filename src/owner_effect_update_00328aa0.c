typedef unsigned char u8;typedef signed short s16;typedef unsigned int u32;
extern short D_004C27A4 __attribute__((section(".sdata")));
extern u32 func_00174170(void);
extern void func_00328B90(void *,void *),func_00328BB0(u8 *,u8 *);
void func_00328AA0(u8 *p,u8 *owner) {
 if (owner[0] && (owner[0x23e]==1 || owner[0x23e]==0) && p[1]==owner[1] && --*(s16 *)(p+0x1e)>=0 && (owner[5]==3 || owner[5]==2)) {
  func_00328B90(p,owner);
  if (--*(s16 *)(p+0x1c)<0) {*(s16 *)(p+0x1c)=(func_00174170()&3)+5; if(D_004C27A4>32)return;}
 } else func_00328BB0(p,owner);
}
