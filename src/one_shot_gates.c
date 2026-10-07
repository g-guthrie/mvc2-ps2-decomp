/* Prevent repeated transitions in the restricted actor state. */
typedef unsigned char u8;
extern int func_00189310(u8 *,u8 *,u8 *);
extern void func_0018A990(u8 *,u8 *);
extern void func_00186A60(u8 *,int);
extern u8 D_004502D0[];
extern u8 D_004502E0[];
extern u8 D_004502F0[];
extern u8 D_00452B30[];
extern u8 D_004540B0[];
extern u8 D_004540C0[];
extern u8 D_004540F0[];
extern u8 D_00454130[];
extern u8 D_00458050[];
extern u8 D_0045B3C0[];
extern u8 D_0045BD50[];
extern u8 D_0045C020[];
extern u8 D_0045C820[];
extern u8 D_0045D6E0[];

#define ONE_SHOT_GATE(name,descriptor,offset,state) \
int name(u8 *p) { \
 if (!func_00189310(p,descriptor,p+offset)) return 0; \
 if (p[0x20d] == 2) { \
  if (p[0x210] == 0) { \
   int once=*(signed char *)(p+0x1e8); \
   if (once) return 0; \
   p[0x1e8]=once+1; \
  } \
 } \
 func_0018A990(p,p+offset); \
 p[5]=0;p[7]=0;p[6]=0;p[0x1fd]=state; \
 func_00186A60(p,21); \
 return 1; \
}

ONE_SHOT_GATE(func_00203560, D_004502D0, 0x388, 1)
ONE_SHOT_GATE(func_00203610, D_004502E0, 0x390, 2)
ONE_SHOT_GATE(func_002036C0, D_004502F0, 0x398, 3)
ONE_SHOT_GATE(func_002438B0, D_00452B30, 0x388, 1)
ONE_SHOT_GATE(func_002624A0, D_004540B0, 0x388, 2)
ONE_SHOT_GATE(func_00262550, D_004540C0, 0x390, 3)
ONE_SHOT_GATE(func_002626C0, D_004540F0, 0x3A0, 5)
ONE_SHOT_GATE(func_00262910, D_00454130, 0x3C0, 11)
ONE_SHOT_GATE(func_0029B4E0, D_00458050, 0x3D0, 12)
ONE_SHOT_GATE(func_002E8DD0, D_0045B3C0, 0x380, 2)
ONE_SHOT_GATE(func_002F6DD0, D_0045BD50, 0x398, 3)
ONE_SHOT_GATE(func_002FC000, D_0045C020, 0x388, 1)
ONE_SHOT_GATE(func_003007A0, D_0045C820, 0x380, 2)
ONE_SHOT_GATE(func_00316F50, D_0045D6E0, 0x390, 4)
