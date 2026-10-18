typedef unsigned int u32;
extern void func_00103E90(u32 *);
extern void func_00103E80(const u32 *);
int func_0010CD50(void){u32 previous;u32 probe;func_00103E90(&previous);probe=(previous&0xFFFF1FFFu)|0x2000;func_00103E80(&probe);func_00103E90(&probe);func_00103E80(&previous);return ((probe>>13)&7)==0;}
