/* Retail initializes command, animation and strength only for selectors 0..2. */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *D_004C2794;
extern signed char data_s8_004BFEDC[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C01A0[16] __attribute__((section(".sdata")));
extern signed char data_s8_004C01BC[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C1060[24] __attribute__((section(".sdata")));
extern signed char data_s8_004C1084[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C174C[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C02C0[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C02CC[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C10D4[12] __attribute__((section(".sdata")));
extern signed char D_004C10C8[12] __attribute__((section(".sdata")));
extern void func_001E3710(u8 *,int);
extern int func_001757E0(u8 *, int, int);
extern int D_004C0198;
extern int D_004C019C;

#define DEFERRED_SETUP(name,command0,table0,command1,table1,command2,table2,mode) \
void name(u8 *p) { \
 int command,strength; \
 unsigned int offset; \
 switch(p[0x1fc]) { \
 case 0: \
  command=command0; \
  strength=0; \
  *(signed char **)(p+0x408)=(signed char *)&table0; \
  p[0x1bb]=0; \
  func_001E3710(p,20); \
  break; \
 case 1: \
  command=command1; \
  strength=1; \
  *(signed char **)(p+0x408)=(signed char *)&table1; \
  p[0x1bb]=1; \
  func_001E3710(p,21); \
  break; \
 case 2: \
  command=command2; \
  strength=2; \
  *(signed char **)(p+0x408)=(signed char *)&table2; \
  p[0x1bb]=2; \
  break; \
 } \
 p[0x1b5]=command; \
 p[0x1b2]=*(u16 *)(p+0x1c0)=0; \
 *(int *)(p+0x1d8)=0; \
 offset=p[2]*2; \
 offset+=(unsigned int)D_004C2794; \
 ++*(short *)(offset+0x7c); \
 func_001757E0(p,mode,(u8)strength); \
}

DEFERRED_SETUP(func_002E4890, 0, D_004C10C8[0], 1, D_004C10C8[4], 2, D_004C10C8[8], 7)
DEFERRED_SETUP(func_002E4980, 6, D_004C10C8[0], 7, D_004C10C8[4], 8, D_004C10C8[8], 9)
DEFERRED_SETUP(func_002E4A70, 3, data_s8_004C10D4[0], 4, data_s8_004C10D4[4], 5, data_s8_004C10D4[8], 8)
