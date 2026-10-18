typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *D_004C2794;
extern signed char data_s8_004C0324[12] __attribute__((section(".sdata")));
extern signed char D_004C0E24[4] __attribute__((section(".sdata")));
extern signed char D_004C0E28[4] __attribute__((section(".sdata")));
extern signed char D_004C0E2C[4] __attribute__((section(".sdata")));
extern void func_001E3210(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_001E3710(u8 *, int);

static inline void reset_move_counters(u8 *p, u8 command, int mode) {
 *(volatile u8 *)(p+0x1b5)=command;
 p[0x1b2]=*(u16 *)(p+0x1c0)=0;
 *(int *)(p+0x1d8)=0;
 { unsigned int offset=p[2]*2; offset += (unsigned int)D_004C2794; ++*(short *)(offset+0x7c); }
 func_001757E0(p,mode,p[0x168]);
}

void func_00244280(u8 *p) {
 unsigned int sel;
 sel = p[0x1fc];
 switch(sel) {
 case 0:
  p[0x168]=0;
  p[0x1b5]=9;
  func_001E3710(p,20);
  *(signed char **)(p+0x408)=(signed char *)&data_s8_004C0324[0];
  p[0x1bb]=0;
  break;
 case 1:
  p[0x168]=1;
  p[0x1b5]=10;
  *(signed char **)(p+0x408)=(signed char *)&data_s8_004C0324[4];
  p[0x1bb]=1;
  func_001E3710(p,21);
  break;
 case 2:
  p[0x168]=2;
  p[0x1b5]=11;
  *(signed char **)(p+0x408)=(signed char *)&data_s8_004C0324[8];
  p[0x1bb]=2;
  func_001E3710(p,22);
  break;
 }
 reset_move_counters(p,p[0x1b5],10);
}

void func_002C61B0(u8 *p) {
 switch(p[0x1fc]) {
 case 0:
  p[0x168]=0;
  p[0x1b5]=9;
  func_001E3710(p,20);
  *(signed char **)(p+0x408)=(signed char *)&D_004C0E24[0];
  p[0x1bb]=0;
  break;
 case 1:
  p[0x168]=1;
  p[0x1b5]=10;
  func_001E3710(p,21);
  *(signed char **)(p+0x408)=(signed char *)&D_004C0E28[0];
  p[0x1bb]=1;
  break;
 case 2:
  p[0x168]=2;
  p[0x1b5]=11;
  *(signed char **)(p+0x408)=(signed char *)&D_004C0E2C[0];
  p[0x1bb]=1;
  func_001E3210(p,3);
  func_001E3710(p,41);
  break;
 }
 reset_move_counters(p,p[0x1b5],10);
}
