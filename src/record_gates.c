/* Require both transition acceptance and an enabled actor record. */
typedef unsigned char u8;
extern void func_0018A990(u8 *,u8 *);
extern void func_00186A60(u8 *,int);
extern u8 D_0044FB90[];
extern u8 D_00450E10[];
extern u8 D_00450E20[];
extern u8 D_004521E0[];
extern u8 D_00452870[];
extern u8 D_00452880[];
extern u8 D_00453550[];
extern u8 D_00453560[];
extern u8 D_004539A0[];
extern u8 D_00454770[];
extern u8 D_00455920[];
extern u8 D_00455930[];
extern u8 D_00455940[];
extern u8 D_00458380[];
extern u8 D_00458390[];
extern u8 D_004583A0[];
extern u8 D_00458760[];
extern u8 D_00458770[];
extern u8 D_00458780[];
extern u8 D_00458AC0[];
extern u8 D_00458F00[];
extern u8 D_004592D0[];
extern u8 D_004592F0[];
extern u8 D_004598E0[];
extern u8 D_00459CF0[];
extern u8 D_0045A650[];
extern u8 D_0045ABF0[];
extern u8 D_0045AC00[];
extern u8 D_0045D9B0[];
extern u8 D_0045D9C0[];
extern int func_00189310(u8 *,u8 *,u8 *);
extern int func_00189EE0(u8 *,u8 *,u8 *);

#define RECORD_GATE(name,predicate,descriptor,offset,state,second,third) \
int name(u8 *p) { \
 int result; \
 if (!predicate(p,descriptor,p+offset)) return 0; \
 if (!**(signed char **)(p+0x420)) result=0; \
 else { \
  func_0018A990(p,p+offset); \
  p[5]=0; \
  p[second]=0; \
  p[third]=0; \
  p[0x1fd]=state; \
  func_00186A60(p,29); \
  result=1; \
 } \
 return result; \
}

RECORD_GATE(func_001F76E0, func_00189310, D_0044FB90, 0x3A0, 4, 7, 6)
RECORD_GATE(func_002160A0, func_00189310, D_00450E10, 0x3A0, 4, 6, 7)
RECORD_GATE(func_00216130, func_00189310, D_00450E20, 0x3A8, 5, 6, 7)
RECORD_GATE(func_00233880, func_00189310, D_004521E0, 0x3B0, 6, 6, 7)
RECORD_GATE(func_0023F290, func_00189310, D_00452870, 0x398, 3, 6, 7)
RECORD_GATE(func_0023F320, func_00189310, D_00452880, 0x3A0, 4, 6, 7)
RECORD_GATE(func_002547F0, func_00189310, D_00453550, 0x390, 3, 7, 6)
RECORD_GATE(func_00254880, func_00189310, D_00453560, 0x398, 4, 7, 6)
RECORD_GATE(func_0025C7D0, func_00189EE0, D_004539A0, 0x3B0, 9, 7, 6)
RECORD_GATE(func_0026F220, func_00189310, D_00454770, 0x3A0, 4, 7, 6)
RECORD_GATE(func_00281490, func_00189310, D_00455920, 0x398, 3, 7, 6)
RECORD_GATE(func_00281520, func_00189310, D_00455930, 0x3A0, 4, 7, 6)
RECORD_GATE(func_002815B0, func_00189310, D_00455940, 0x3A8, 5, 7, 6)
RECORD_GATE(func_002A0FF0, func_00189310, D_00458380, 0x3B0, 6, 7, 6)
RECORD_GATE(func_002A1080, func_00189310, D_00458390, 0x3B8, 7, 7, 6)
RECORD_GATE(func_002A1110, func_00189310, D_004583A0, 0x3C0, 8, 7, 6)
RECORD_GATE(func_002A7480, func_00189310, D_00458760, 0x398, 2, 7, 6)
RECORD_GATE(func_002A7510, func_00189310, D_00458770, 0x3A0, 4, 7, 6)
RECORD_GATE(func_002A75A0, func_00189310, D_00458780, 0x3A8, 3, 7, 6)
RECORD_GATE(func_002ABC10, func_00189310, D_00458AC0, 0x388, 14, 7, 6)
RECORD_GATE(func_002B2C50, func_00189310, D_00458F00, 0x3B8, 11, 7, 6)
RECORD_GATE(func_002B8690, func_00189310, D_004592D0, 0x3B8, 7, 7, 6)
RECORD_GATE(func_002B87E0, func_00189310, D_004592F0, 0x3C8, 14, 7, 6)
RECORD_GATE(func_002C02B0, func_00189310, D_004598E0, 0x3C0, 6, 7, 6)
RECORD_GATE(func_002C59E0, func_00189310, D_00459CF0, 0x3C8, 15, 7, 6)
RECORD_GATE(func_002D6240, func_00189310, D_0045A650, 0x388, 1, 7, 6)
RECORD_GATE(func_002DC5F0, func_00189310, D_0045ABF0, 0x3A0, 3, 6, 7)
RECORD_GATE(func_002DC730, func_00189310, D_0045AC00, 0x3A8, 5, 6, 7)
RECORD_GATE(func_0031B670, func_00189310, D_0045D9B0, 0x3A0, 4, 6, 7)
RECORD_GATE(func_0031B700, func_00189310, D_0045D9C0, 0x3A8, 5, 6, 7)
