/* Enabled-record transitions with a restricted-state repeat guard. */
typedef unsigned char u8;
extern void func_00186A60(u8 *,int);
extern u8 D_0044F2B0[];
extern u8 D_00450300[];
extern u8 D_00450318[];
extern u8 D_00450350[];
extern u8 D_00450A40[];
extern u8 D_00450A50[];
extern u8 D_0045CB60[];
extern u8 D_0045CD60[];
extern int func_00189310(u8 *,u8 *,u8 *);
extern int func_00189EE0(u8 *,u8 *,u8 *);

#define ENABLED_ONE_SHOT(name,predicate,descriptor,offset,state) \
int name(u8 *p) { \
 int result; \
 if (!predicate(p,descriptor,p+offset)) return 0; \
 if (!**(signed char **)(p+0x420)) result=0; \
 else { \
  if (p[0x20d] == 2 && p[0x210] == 0) { \
   int once=*(signed char *)(p+0x1e8); \
   if (once) return 0; \
   p[0x1e8]=once+1; \
  } \
  p[5]=0;p[7]=0;p[6]=0;p[0x1fd]=state; \
  func_00186A60(p,29); \
  result=1; \
 } \
 return result; \
}

ENABLED_ONE_SHOT(func_001E9470, func_00189310, D_0044F2B0, 0x3A0, 5)
ENABLED_ONE_SHOT(func_00203770, func_00189EE0, D_00450300, 0x3A0, 4)
ENABLED_ONE_SHOT(func_00203830, func_00189310, D_00450318, 0x3A8, 5)
ENABLED_ONE_SHOT(func_00203970, func_00189310, D_00450350, 0x3B8, 7)
ENABLED_ONE_SHOT(func_002105D0, func_00189310, D_00450A40, 0x388, 2)
ENABLED_ONE_SHOT(func_00210690, func_00189310, D_00450A50, 0x380, 1)
ENABLED_ONE_SHOT(func_00304CC0, func_00189310, D_0045CB60, 0x3A8, 8)
ENABLED_ONE_SHOT(func_00308FB0, func_00189310, D_0045CD60, 0x398, 8)
