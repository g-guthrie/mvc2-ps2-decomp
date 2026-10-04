/* Retail initializes command, animation and strength only for selectors 0..2. */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *D_004C2794;
extern void func_001E3710(u8 *,int);
extern void func_001757E0(u8 *,int,int);
extern int D_004BFEDC;
extern int D_004BFEE0;
extern int D_004BFEE4;
extern int D_004C0198;
extern int D_004C019C;
extern int D_004C01A0;
extern int D_004C01A4;
extern int D_004C01A8;
extern int D_004C01AC;
extern int D_004C01BC;
extern int D_004C01C0;
extern int D_004C01C4;
extern int D_004C02C0;
extern int D_004C02C4;
extern int D_004C02C8;
extern int D_004C02CC;
extern int D_004C02D0;
extern int D_004C02D4;
extern int D_004C1060;
extern int D_004C1064;
extern int D_004C1068;
extern int D_004C106C;
extern int D_004C1070;
extern int D_004C1074;
extern int D_004C1084;
extern int D_004C1088;
extern int D_004C108C;
extern int D_004C10D4;
extern int D_004C10D8;
extern int D_004C10DC;
extern int D_004C174C;
extern int D_004C1750;
extern int D_004C1754;

#define DEFERRED_SETUP(name,command0,table0,command1,table1,command2,table2,mode) \
void name(u8 *p) { \
 int command,animation,strength; \
 unsigned int offset; \
 switch(p[0x1fc]) { \
 case 0: \
  command=command0; \
  strength=0; \
  *(int **)(p+0x408)=&table0; \
  animation=20; \
  p[0x1bb]=0; \
  break; \
 case 1: \
  command=command1; \
  strength=1; \
  *(int **)(p+0x408)=&table1; \
  animation=21; \
  p[0x1bb]=1; \
  break; \
 case 2: \
  command=command2; \
  strength=2; \
  *(int **)(p+0x408)=&table2; \
  animation=22; \
  p[0x1bb]=2; \
  break; \
 } \
 p[0x1b5]=command; \
 p[0x1b2]=*(u16 *)(p+0x1c0)=0; \
 *(int *)(p+0x1d8)=0; \
 offset=p[2]*2; \
 offset+=(unsigned int)D_004C2794; \
 ++*(short *)(offset+0x7c); \
 func_001E3710(p,(u8)animation); \
 func_001757E0(p,mode,(u8)strength); \
}

DEFERRED_SETUP(func_002168B0, 3, D_004BFEDC, 4, D_004BFEE0, 5, D_004BFEE4, 8)
DEFERRED_SETUP(func_002169A0, 9, D_004BFEDC, 10, D_004BFEE0, 11, D_004BFEE4, 10)
DEFERRED_SETUP(func_00233D80, 6, D_004C0198, 7, D_004C019C, 8, D_004C01A0, 9)
DEFERRED_SETUP(func_00233E70, 3, D_004C01A4, 4, D_004C01A8, 5, D_004C01AC, 8)
DEFERRED_SETUP(func_00233F60, 9, D_004C01A4, 10, D_004C01A8, 11, D_004C01AC, 10)
DEFERRED_SETUP(func_002341F0, 15, D_004C01BC, 16, D_004C01C0, 17, D_004C01C4, 12)
DEFERRED_SETUP(func_0023F7D0, 6, D_004C02C0, 7, D_004C02C4, 8, D_004C02C8, 9)
DEFERRED_SETUP(func_0023F8C0, 3, D_004C02CC, 4, D_004C02D0, 5, D_004C02D4, 8)
DEFERRED_SETUP(func_0023F9B0, 9, D_004C02CC, 10, D_004C02D0, 11, D_004C02D4, 10)
DEFERRED_SETUP(func_002DCBC0, 6, D_004C1060, 7, D_004C1064, 8, D_004C1068, 9)
DEFERRED_SETUP(func_002DCCB0, 3, D_004C106C, 4, D_004C1070, 5, D_004C1074, 8)
DEFERRED_SETUP(func_002DCDA0, 9, D_004C106C, 10, D_004C1070, 11, D_004C1074, 10)
DEFERRED_SETUP(func_002DD030, 15, D_004C1084, 16, D_004C1088, 17, D_004C108C, 12)
DEFERRED_SETUP(func_002E4B60, 9, D_004C10D4, 10, D_004C10D8, 11, D_004C10DC, 10)
DEFERRED_SETUP(func_0031BCA0, 3, D_004C174C, 4, D_004C1750, 5, D_004C1754, 8)
DEFERRED_SETUP(func_0031BD90, 9, D_004C174C, 10, D_004C1750, 11, D_004C1754, 10)
