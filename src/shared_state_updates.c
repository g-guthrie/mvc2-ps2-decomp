/* Resolve the pending actor state and advance its animation when appropriate. */
typedef unsigned char u8;
extern void func_001E3B30(u8 *);
extern void func_00158C70(void *,int);
extern int func_00169CE0(u8 *,int,int);
extern void func_00186CE0(u8 *,int);
extern int func_00175700(u8 *);
extern u8 D_004F1F45,D_004F1F46;
static inline int selected_flag(int value) {
 if (value<5) return 1;
 return 3;
}

#define STATE_UPDATE(name) \
void name(u8 *p) { \
 p[0x1ff]=2; \
 if (*(short *)(p+0x28c)<0) goto advance; \
 if (*(short *)(p+0x434)>0 && *(short *)(p+0x28c)>0) goto advance; \
 *(short *)(p+0x28c)=-1; \
 func_001E3B30(p); \
 func_00158C70(p+0x34,p[2]); \
 if (p[0x247]!=1) { \
  int flag=selected_flag(p[0x21b]); \
  D_004F1F45=flag;D_004F1F46=1; \
 } \
 if (p[0x249] || !*(short *)(p+0x434) || !*(signed char *)(p+0x24a)) goto advance; \
 if (*(signed char *)(p+0x539)) { \
  if (func_00169CE0(p,29,2)) *(signed char *)(p+0x24a)=-1; \
  else p[0x24a]=0; \
 } \
 if (*(signed char *)(p+0x24a)<0) { \
  p[0x1e7]=0; \
  func_00186CE0(p,17); \
  return; \
 } \
 advance: \
 if ((signed char)func_00175700(p)<0) func_00186CE0(p,23); \
}

STATE_UPDATE(func_0017D710)
STATE_UPDATE(func_0017DD90)
STATE_UPDATE(func_0017ED50)
STATE_UPDATE(func_0017F4B0)
STATE_UPDATE(func_0017F930)
STATE_UPDATE(func_0017FDE0)
