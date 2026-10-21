typedef unsigned char u8;
typedef unsigned long long u64;
typedef signed long long s64;
/* Native signed mode at +0 and wait method at +8; not a full object extent. */
typedef struct {short mode; u8 reserved2[6]; int method;} DisplayStatePrefix;
extern void *func_00100468(void);
extern void func_00104270(void);
extern u64 func_00104300(void);
int func_00100E68(void) {
 DisplayStatePrefix *state=func_00100468();
 int method;
 short mode;
 method=state->method;
 if(!method) {
  func_00104270();
  mode=state->mode;
  if(mode==1) return (int)((*(volatile u64 *)0x12001000u>>13)&1);
 } else {
  u64 bit=((s64)func_00104300()>>13)&1;
  mode=state->mode;
  if(mode==1) return (int)bit;
 }
 return 1;
}
