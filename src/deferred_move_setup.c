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
extern void func_001E3710(u8 *,int);
extern int func_001757E0(u8 *, int, int);
extern int D_004C0198;
extern int D_004C019C;

#define DEFERRED_SETUP(name,command0,table0,command1,table1,command2,table2,mode) \
void name(u8 *p) { \
 int command,animation,strength; \
 unsigned int offset; \
 switch(p[0x1fc]) { \
 case 0: \
  command=command0; \
  strength=0; \
  *(signed char **)(p+0x408)=(signed char *)&table0; \
  animation=20; \
  p[0x1bb]=0; \
  break; \
 case 1: \
  command=command1; \
  strength=1; \
  *(signed char **)(p+0x408)=(signed char *)&table1; \
  animation=21; \
  p[0x1bb]=1; \
  break; \
 case 2: \
  command=command2; \
  strength=2; \
  *(signed char **)(p+0x408)=(signed char *)&table2; \
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

DEFERRED_SETUP(func_002168B0, 3, data_s8_004BFEDC[0], 4, data_s8_004BFEDC[4], 5, data_s8_004BFEDC[8], 8)
DEFERRED_SETUP(func_002169A0, 9, data_s8_004BFEDC[0], 10, data_s8_004BFEDC[4], 11, data_s8_004BFEDC[8], 10)
DEFERRED_SETUP(func_00233C90, 0, D_004C0198, 1, D_004C019C, 2, data_s8_004C01A0[0], 7)
DEFERRED_SETUP(func_00233D80, 6, D_004C0198, 7, D_004C019C, 8, data_s8_004C01A0[0], 9)
DEFERRED_SETUP(func_00233E70, 3, data_s8_004C01A0[4], 4, data_s8_004C01A0[8], 5, data_s8_004C01A0[12], 8)
DEFERRED_SETUP(func_00233F60, 9, data_s8_004C01A0[4], 10, data_s8_004C01A0[8], 11, data_s8_004C01A0[12], 10)
DEFERRED_SETUP(func_002341F0, 15, data_s8_004C01BC[0], 16, data_s8_004C01BC[4], 17, data_s8_004C01BC[8], 12)
DEFERRED_SETUP(func_0023F6E0, 0, data_s8_004C02C0[0], 1, data_s8_004C02C0[4], 2, data_s8_004C02C0[8], 7)
DEFERRED_SETUP(func_0023F7D0, 6, data_s8_004C02C0[0], 7, data_s8_004C02C0[4], 8, data_s8_004C02C0[8], 9)
DEFERRED_SETUP(func_0023F8C0, 3, data_s8_004C02CC[0], 4, data_s8_004C02CC[4], 5, data_s8_004C02CC[8], 8)
DEFERRED_SETUP(func_0023F9B0, 9, data_s8_004C02CC[0], 10, data_s8_004C02CC[4], 11, data_s8_004C02CC[8], 10)
DEFERRED_SETUP(func_002DCBC0, 6, data_s8_004C1060[0], 7, data_s8_004C1060[4], 8, data_s8_004C1060[8], 9)
DEFERRED_SETUP(func_002DCCB0, 3, data_s8_004C1060[12], 4, data_s8_004C1060[16], 5, data_s8_004C1060[20], 8)
DEFERRED_SETUP(func_002DCDA0, 9, data_s8_004C1060[12], 10, data_s8_004C1060[16], 11, data_s8_004C1060[20], 10)
DEFERRED_SETUP(func_002DD030, 15, data_s8_004C1084[0], 16, data_s8_004C1084[4], 17, data_s8_004C1084[8], 12)
DEFERRED_SETUP(func_002E4B60, 9, data_s8_004C10D4[0], 10, data_s8_004C10D4[4], 11, data_s8_004C10D4[8], 10)
DEFERRED_SETUP(func_0031BCA0, 3, data_s8_004C174C[0], 4, data_s8_004C174C[4], 5, data_s8_004C174C[8], 8)
DEFERRED_SETUP(func_0031BD90, 9, data_s8_004C174C[0], 10, data_s8_004C174C[4], 11, data_s8_004C174C[8], 10)
