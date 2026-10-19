/* Strength-selecting move setup and shared timer/counter reset. */
typedef unsigned char u8;
typedef unsigned short u16;
/* Partial actor view; used only through an existing actor pointer. */
typedef struct {u8 prefix[0x1B5];u8 action;} ActorActionView;
typedef char ActorActionOffsetCheck[((unsigned int)&((ActorActionView *)0)->action == 0x1B5) ? 1 : -1];
extern u8 *D_004C2794;
extern signed char data_s8_004C066C[4] __attribute__((section(".sdata")));
extern signed char data_s8_004C0670[4] __attribute__((section(".sdata")));
extern signed char data_s8_004C0674[4] __attribute__((section(".sdata")));
extern signed char data_s8_004BFB04[12] __attribute__((section(".sdata")));
extern signed char data_s8_004BFC50[16] __attribute__((section(".sdata")));
extern signed char data_s8_004BFCD4[24] __attribute__((section(".sdata")));
extern signed char data_s8_004BFCF8[12] __attribute__((section(".sdata")));
extern signed char data_s8_004BFD80[28] __attribute__((section(".sdata")));
extern signed char data_s8_004BFDA8[12] __attribute__((section(".sdata")));
extern signed char data_s8_004BFE80[12] __attribute__((section(".sdata")));
extern signed char data_s8_004BFFA4[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C00E4[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C0324[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C0630[24] __attribute__((section(".sdata")));
extern signed char data_s8_004C0654[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C0898[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C0910[24] __attribute__((section(".sdata")));
extern signed char data_s8_004C0934[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C094C[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C09C0[28] __attribute__((section(".sdata")));
extern signed char data_s8_004C09E8[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C0A80[28] __attribute__((section(".sdata")));
extern signed char data_s8_004C0AA8[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C0B50[24] __attribute__((section(".sdata")));
extern signed char data_s8_004C0BD0[36] __attribute__((section(".sdata")));
extern signed char data_s8_004C0C00[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C0D30[16] __attribute__((section(".sdata")));
extern signed char data_s8_004C0EC0[28] __attribute__((section(".sdata")));
extern signed char data_s8_004C0EE8[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C1294[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C1344[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C1474[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C16A8[12] __attribute__((section(".sdata")));
extern signed char data_s8_004BFB70[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C0214[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C13D0[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C1514[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C06AC[4] __attribute__((section(".sdata")));
extern signed char data_s8_004C06B0[8] __attribute__((section(".sdata")));
extern signed char data_s8_004C06C4[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C0E30[48] __attribute__((section(".sdata")));
extern signed char data_s8_004BFB7C[12] __attribute__((section(".sdata")));
extern signed char data_s8_004C03B0[64] __attribute__((section(".sdata")));
extern signed char data_s8_004C0720[64] __attribute__((section(".sdata")));
extern signed char data_s8_004C0590[64] __attribute__((section(".sdata")));
extern signed char data_s8_004C0440[64] __attribute__((section(".sdata")));
extern signed char data_s8_004C1690[4] __attribute__((section(".sdata")));
extern signed char data_s8_004C1694[8] __attribute__((section(".sdata")));
extern signed char data_s8_004BFDC8[72] __attribute__((section(".sdata")));
extern signed char data_s8_004C0688[4] __attribute__((section(".sdata")));
extern signed char data_s8_004C0CC0[64] __attribute__((section(".sdata")));
extern signed char data_s8_004C0D00[8] __attribute__((section(".sdata")));
extern signed char data_s8_004C1134[4] __attribute__((section(".sdata")));
extern signed char data_s8_004C1138[4] __attribute__((section(".sdata")));
extern signed char data_s8_004C113C[4] __attribute__((section(".sdata")));
extern signed char data_s8_004BFF34[4] __attribute__((section(".sdata")));
extern signed char data_s8_004BFF38[4] __attribute__((section(".sdata")));
extern signed char data_s8_004BFF3C[4] __attribute__((section(".sdata")));
extern signed char data_s8_004C0F30[64] __attribute__((section(".sdata")));
extern signed char data_s8_004C0F70[8] __attribute__((section(".sdata")));
extern signed char data_s8_004C068C[8] __attribute__((section(".sdata")));
extern signed char data_s8_004C0694[4] __attribute__((section(".sdata")));
extern signed char data_s8_004C0698[8] __attribute__((section(".sdata")));
extern const unsigned int D_004C1588[] __attribute__((section(".sdata")));
extern unsigned int data_u32_004C06A0[1] __attribute__((section(".sdata")));
extern unsigned int data_ff_004C06A4[2] __attribute__((section(".sdata")));
extern unsigned int data_u32_004C06B8[3] __attribute__((section(".sdata")));
extern signed char data_s8_004C158C[8] __attribute__((section(".sdata")));
extern signed char data_s8_004C1594[4] __attribute__((section(".sdata")));
extern signed char data_s8_004C1598[8] __attribute__((section(".sdata")));
extern signed char data_s8_004C15A0[4] __attribute__((section(".sdata")));
extern signed char data_s8_004C15A4[8] __attribute__((section(".sdata")));
extern signed char data_s8_004C15AC[4] __attribute__((section(".sdata")));
extern signed char data_s8_004C15B0[8] __attribute__((section(".sdata")));
extern signed char data_s8_004C15B8[24] __attribute__((section(".sdata")));
extern int func_001757E0(u8 *, int, int);
extern void func_00176160(u8 *, int, int, int);
extern void func_003092C0(u8 *);
extern int D_004BFC48;
extern int D_004BFC4C;
extern int D_004BFD78;
extern int D_004BFD7C;
extern int D_004C0438;
extern int D_004C043C;
extern int D_004C0718;
extern int D_004C071C;
extern int D_004C09B8;
extern int D_004C09BC;
extern int D_004C0A78;
extern int D_004C0A7C;
extern int D_004C0D28;
extern int D_004C0D2C;
extern int D_004C0EB8;
extern int D_004C0EBC;
extern void func_001E3210(u8 *,int);
extern void func_001E3710(u8 *,int);

extern int D_004C03F0;
extern int D_004C03F4;
extern int D_004C05D0;
extern int D_004C05D4;


extern int D_004BFF34;
extern int D_004BFF38;
extern int D_004BFF3C;
extern int D_004C0688;
extern int D_004C068C;
extern int D_004C0690;
extern int D_004C0694;
extern int D_004C0698;
extern int D_004C069C;
extern int D_004C1134;
extern int D_004C1138;
extern int D_004C113C;

static inline void reset_move_counters(u8 *p,u8 command, int mode) {
 /* Retain the command write performed again by the retail reset sequence. */
 ((ActorActionView *)p)->action=command;
 p[0x1b2]=*(u16 *)(p+0x1c0)=0;
 *(int *)(p+0x1d8)=0;
 { unsigned int offset=p[2]*2; offset += (unsigned int)D_004C2794; ++*(short *)(offset+0x7c); }
 func_001757E0(p,mode,p[0x168]);
}

#define MOVE_SETUP(name,set0,command0,animation0,table0,set1,command1,animation1,table1,set2,command2,animation2,table2,mode) \
void name(u8 *p) { \
 switch(p[0x1fc]) { \
 case 0: \
  p[0x168]=0; \
  p[0x1b5]=command0; \
  set0(p,animation0); \
  *(signed char **)(p+0x408)=(signed char *)&table0; \
  p[0x1bb]=0; \
  break; \
 case 1: \
  p[0x168]=1; \
  p[0x1b5]=command1; \
  set1(p,animation1); \
  *(signed char **)(p+0x408)=(signed char *)&table1; \
  p[0x1bb]=1; \
  break; \
 case 2: \
  p[0x168]=2; \
  p[0x1b5]=command2; \
  set2(p,animation2); \
  *(signed char **)(p+0x408)=(signed char *)&table2; \
  p[0x1bb]=2; \
  break; \
 } \
 reset_move_counters(p,p[0x1b5],mode); \
}

MOVE_SETUP(func_001E9B40, func_001E3710, 9, 20, data_s8_004BFB04[0], func_001E3710, 10, 21, data_s8_004BFB04[4], func_001E3710, 11, 22, data_s8_004BFB04[8], 10)
MOVE_SETUP(func_001EEC40, func_001E3710, 3, 20, data_s8_004BFB7C[0], func_001E3710, 4, 21, data_s8_004BFB7C[4], func_001E3710, 5, 22, data_s8_004BFB7C[8], 8)
MOVE_SETUP(func_001F7CC0, func_001E3710, 6, 20, D_004BFC48, func_001E3710, 7, 21, D_004BFC4C, func_001E3710, 8, 22, data_s8_004BFC50[0], 9)
MOVE_SETUP(func_001F7FA0, func_001E3710, 9, 20, data_s8_004BFC50[4], func_001E3710, 10, 21, data_s8_004BFC50[8], func_001E3710, 11, 22, data_s8_004BFC50[12], 10)
MOVE_SETUP(func_001FCE30, func_001E3710, 9, 20, data_s8_004BFCD4[0], func_001E3710, 10, 21, data_s8_004BFCD4[4], func_001E3710, 11, 22, data_s8_004BFCD4[8], 10)
MOVE_SETUP(func_00203EB0, func_001E3710, 6, 20, D_004BFD78, func_001E3710, 7, 21, D_004BFD7C, func_001E3710, 8, 22, data_s8_004BFD80[0], 9)
MOVE_SETUP(func_002041B0, func_001E3710, 9, 20, data_s8_004BFD80[4], func_001E3710, 10, 21, data_s8_004BFD80[8], func_001E3710, 11, 22, data_s8_004BFD80[12], 10)
MOVE_SETUP(func_00208EC0, func_001E3710, 6, 20, data_s8_004BFDC8[0], func_001E3210, 7, 30, data_s8_004BFDC8[4], func_001E3210, 8, 30, data_s8_004BFDC8[8], 9)
MOVE_SETUP(func_00208FC0, func_001E3710, 3, 20, data_s8_004BFDC8[12], func_001E3210, 4, 30, data_s8_004BFDC8[16], func_001E3210, 5, 30, data_s8_004BFDC8[20], 8)
MOVE_SETUP(func_00223450, func_001E3710, 3, 20, data_s8_004BFFA4[0], func_001E3710, 4, 21, data_s8_004BFFA4[4], func_001E3710, 5, 22, data_s8_004BFFA4[8], 8)
MOVE_SETUP(func_00223550, func_001E3710, 9, 20, data_s8_004BFFA4[0], func_001E3710, 10, 21, data_s8_004BFFA4[4], func_001E3710, 11, 22, data_s8_004BFFA4[8], 10)
MOVE_SETUP(func_0022D370, func_001E3710, 3, 20, data_s8_004C00E4[0], func_001E3710, 4, 21, data_s8_004C00E4[4], func_001E3710, 5, 22, data_s8_004C00E4[8], 8)
MOVE_SETUP(func_0022D470, func_001E3710, 9, 20, data_s8_004C00E4[0], func_001E3710, 10, 21, data_s8_004C00E4[4], func_001E3710, 11, 22, data_s8_004C00E4[8], 10)
MOVE_SETUP(func_00248CF0, func_001E3710, 9, 20, data_s8_004C03B0[12], func_001E3710, 10, 21, data_s8_004C03B0[16], func_001E3710, 11, 22, data_s8_004C03B0[20], 10)
MOVE_SETUP(func_0024E3F0, func_001E3710, 6, 20, D_004C0438, func_001E3710, 7, 21, D_004C043C, func_001E3710, 8, 22, data_s8_004C0440[0], 9)
MOVE_SETUP(func_0024E4F0, func_001E3710, 3, 20, data_s8_004C0440[4], func_001E3710, 4, 21, data_s8_004C0440[8], func_001E3710, 5, 22, data_s8_004C0440[12], 8)
MOVE_SETUP(func_0024E5F0, func_001E3710, 9, 20, data_s8_004C0440[4], func_001E3710, 10, 21, data_s8_004C0440[8], func_001E3710, 11, 22, data_s8_004C0440[12], 10)
MOVE_SETUP(func_0025CD60, func_001E3710, 6, 20, data_s8_004C0590[0], func_001E3710, 7, 21, data_s8_004C0590[4], func_001E3710, 8, 26, data_s8_004C0590[8], 9)
MOVE_SETUP(func_0025CE60, func_001E3710, 3, 20, data_s8_004C0590[12], func_001E3710, 4, 21, data_s8_004C0590[16], func_001E3710, 5, 22, data_s8_004C0590[20], 8)
MOVE_SETUP(func_00262F10, func_001E3710, 6, 20, data_s8_004C0630[0], func_001E3710, 7, 21, data_s8_004C0630[4], func_001E3710, 8, 22, data_s8_004C0630[8], 9)
MOVE_SETUP(func_00263150, func_001E3710, 9, 20, data_s8_004C0630[12], func_001E3710, 10, 21, data_s8_004C0630[16], func_001E3710, 11, 22, data_s8_004C0630[20], 10)
MOVE_SETUP(func_0026F750, func_001E3210, 6, 31, D_004C0718, func_001E3210, 7, 32, D_004C071C, func_001E3210, 8, 33, data_s8_004C0720[0], 9)
MOVE_SETUP(func_0026F850, func_001E3710, 3, 20, data_s8_004C0720[4], func_001E3710, 4, 21, data_s8_004C0720[8], func_001E3710, 5, 22, data_s8_004C0720[12], 8)
MOVE_SETUP(func_0026F950, func_001E3710, 9, 20, data_s8_004C0720[4], func_001E3710, 10, 21, data_s8_004C0720[8], func_001E3710, 11, 22, data_s8_004C0720[12], 10)
MOVE_SETUP(func_00281B80, func_001E3710, 6, 20, data_s8_004C0898[0], func_001E3710, 7, 21, data_s8_004C0898[4], func_001E3710, 8, 22, data_s8_004C0898[8], 9)
MOVE_SETUP(func_0028E770, func_001E3710, 6, 20, D_004C09B8, func_001E3710, 7, 21, D_004C09BC, func_001E3710, 8, 22, data_s8_004C09C0[0], 9)
MOVE_SETUP(func_00295B90, func_001E3710, 6, 20, D_004C0A78, func_001E3710, 7, 21, D_004C0A7C, func_001E3710, 8, 22, data_s8_004C0A80[0], 9)
MOVE_SETUP(func_00295DD0, func_001E3710, 9, 20, data_s8_004C0A80[4], func_001E3710, 10, 21, data_s8_004C0A80[8], func_001E3710, 11, 22, data_s8_004C0A80[12], 10)
MOVE_SETUP(func_002A15F0, func_001E3710, 6, 20, data_s8_004C0B50[0], func_001E3710, 7, 21, data_s8_004C0B50[4], func_001E3710, 8, 22, data_s8_004C0B50[8], 9)
MOVE_SETUP(func_002A1820, func_001E3710, 9, 20, data_s8_004C0B50[12], func_001E3710, 10, 21, data_s8_004C0B50[16], func_001E3710, 11, 22, data_s8_004C0B50[20], 10)
MOVE_SETUP(func_002A7A60, func_001E3710, 6, 20, data_s8_004C0BD0[0], func_001E3710, 7, 21, data_s8_004C0BD0[4], func_001E3710, 8, 22, data_s8_004C0BD0[8], 9)
MOVE_SETUP(func_002A7CE0, func_001E3710, 9, 20, data_s8_004C0BD0[12], func_001E3710, 10, 21, data_s8_004C0BD0[16], func_001E3710, 11, 22, data_s8_004C0BD0[20], 10)
MOVE_SETUP(func_002B8CA0, func_001E3710, 6, 20, D_004C0D28, func_001E3710, 7, 21, D_004C0D2C, func_001E3710, 8, 22, data_s8_004C0D30[0], 9)
MOVE_SETUP(func_002B8ED0, func_001E3710, 9, 20, data_s8_004C0D30[4], func_001E3710, 10, 21, data_s8_004C0D30[8], func_001E3710, 11, 22, data_s8_004C0D30[12], 10)
MOVE_SETUP(func_002CC600, func_001E3710, 6, 20, D_004C0EB8, func_001E3710, 7, 21, D_004C0EBC, func_001E3710, 8, 22, data_s8_004C0EC0[0], 9)
MOVE_SETUP(func_002CC840, func_001E3710, 9, 20, data_s8_004C0EC0[4], func_001E3710, 10, 21, data_s8_004C0EC0[8], func_001E3710, 11, 22, data_s8_004C0EC0[12], 10)

#define EXTENDED_MOVE_SETUP(name,set0,command0,animation0,table0,alternate0,set1,command1,animation1,table1,alternate1,set2,command2,animation2,table2,alternate2,mode,mask,step) \
void name(u8 *p) { \
 switch(p[0x1fc]) { \
 case 0: \
  p[0x168]=0; \
  p[0x1b5]=command0; \
  set0(p,animation0); \
  if (p[0x210] == 0) *(signed char **)(p+0x408)=(signed char *)&table0; \
  else *(signed char **)(p+0x408)=(signed char *)&alternate0; \
  p[0x1bb]=0; \
  break; \
 case 1: \
  p[0x168]=1; \
  p[0x1b5]=command1; \
  set1(p,animation1); \
  if (p[0x210] == 0) *(signed char **)(p+0x408)=(signed char *)&table1; \
  else *(signed char **)(p+0x408)=(signed char *)&alternate1; \
  p[0x1bb]=1; \
  break; \
 case 2: \
  p[0x168]=2; \
  p[0x1b5]=command2; \
  set2(p,animation2); \
  if (p[0x210] == 0) *(signed char **)(p+0x408)=(signed char *)&table2; \
  else *(signed char **)(p+0x408)=(signed char *)&alternate2; \
  p[0x1bb]=2; \
  break; \
 } \
 reset_move_counters(p,p[0x1b5],mode); \
 if (*(signed char *)(p+0x1ea) & mask) *(signed char *)(p+0x1ea) -= step; \
}

EXTENDED_MOVE_SETUP(func_001FCFC0, func_001E3710, 12, 20, data_s8_004BFCD4[12], data_s8_004BFCF8[0], func_001E3710, 13, 21, data_s8_004BFCD4[16], data_s8_004BFCF8[4], func_001E3710, 14, 22, data_s8_004BFCD4[20], data_s8_004BFCF8[8], 11, 15, 1)
EXTENDED_MOVE_SETUP(func_00204350, func_001E3710, 12, 20, data_s8_004BFD80[16], data_s8_004BFDA8[0], func_001E3710, 13, 21, data_s8_004BFD80[20], data_s8_004BFDA8[4], func_001E3710, 14, 22, data_s8_004BFD80[24], data_s8_004BFDA8[8], 11, 15, 1)
EXTENDED_MOVE_SETUP(func_002092D0, func_001E3710, 12, 20, data_s8_004BFDC8[24], data_s8_004BFDC8[48], func_001E3210, 13, 30, data_s8_004BFDC8[28], data_s8_004BFDC8[52], func_001E3210, 14, 30, data_s8_004BFDC8[32], data_s8_004BFDC8[56], 11, 15, 1)
EXTENDED_MOVE_SETUP(func_00209420, func_001E3710, 15, 20, data_s8_004BFDC8[36], data_s8_004BFDC8[60], func_001E3210, 16, 30, data_s8_004BFDC8[40], data_s8_004BFDC8[64], func_001E3210, 17, 30, data_s8_004BFDC8[44], data_s8_004BFDC8[68], 12, 240, 16)
EXTENDED_MOVE_SETUP(func_00248EC0, func_001E3710, 12, 20, data_s8_004C03B0[24], data_s8_004C03B0[48], func_001E3710, 13, 21, data_s8_004C03B0[28], data_s8_004C03B0[52], func_001E3710, 14, 22, data_s8_004C03B0[32], data_s8_004C03B0[56], 11, 15, 1)
EXTENDED_MOVE_SETUP(func_00249010, func_001E3710, 15, 20, data_s8_004C03B0[36], data_s8_004C03B0[60], func_001E3710, 16, 21, data_s8_004C03B0[40], D_004C03F0, func_001E3710, 17, 22, data_s8_004C03B0[44], D_004C03F4, 12, 240, 16)
EXTENDED_MOVE_SETUP(func_0024E790, func_001E3710, 12, 20, data_s8_004C0440[16], data_s8_004C0440[40], func_001E3710, 13, 21, data_s8_004C0440[20], data_s8_004C0440[44], func_001E3710, 14, 22, data_s8_004C0440[24], data_s8_004C0440[48], 11, 15, 1)
EXTENDED_MOVE_SETUP(func_0024E8E0, func_001E3710, 15, 20, data_s8_004C0440[28], data_s8_004C0440[52], func_001E3710, 16, 21, data_s8_004C0440[32], data_s8_004C0440[56], func_001E3710, 17, 22, data_s8_004C0440[36], data_s8_004C0440[60], 12, 240, 16)
EXTENDED_MOVE_SETUP(func_0025D0F0, func_001E3710, 12, 20, data_s8_004C0590[24], data_s8_004C0590[48], func_001E3710, 13, 21, data_s8_004C0590[28], data_s8_004C0590[52], func_001E3710, 14, 26, data_s8_004C0590[32], data_s8_004C0590[56], 11, 15, 1)
EXTENDED_MOVE_SETUP(func_0025D240, func_001E3710, 15, 20, data_s8_004C0590[36], data_s8_004C0590[60], func_001E3710, 16, 21, data_s8_004C0590[40], D_004C05D0, func_001E3710, 17, 22, data_s8_004C0590[44], D_004C05D4, 12, 240, 16)
EXTENDED_MOVE_SETUP(func_00263470, func_001E3710, 15, 20, data_s8_004C0654[0], data_s8_004C066C[0], func_001E3710, 16, 21, data_s8_004C0654[4], data_s8_004C0670[0], func_001E3710, 17, 22, data_s8_004C0654[8], data_s8_004C0674[0], 12, 240, 16)
EXTENDED_MOVE_SETUP(func_0026BDB0, func_001E3710, 15, 20, data_s8_004C06AC[0], data_s8_004C06C4[0], func_001E3710, 16, 21, data_s8_004C06B0[0], data_s8_004C06C4[4], func_001E3710, 17, 22, data_s8_004C06B0[4], data_s8_004C06C4[8], 12, 240, 16)
EXTENDED_MOVE_SETUP(func_0026FAF0, func_001E3210, 12, 31, data_s8_004C0720[16], data_s8_004C0720[40], func_001E3210, 13, 32, data_s8_004C0720[20], data_s8_004C0720[44], func_001E3210, 14, 33, data_s8_004C0720[24], data_s8_004C0720[48], 11, 15, 1)
EXTENDED_MOVE_SETUP(func_0026FC40, func_001E3710, 15, 20, data_s8_004C0720[28], data_s8_004C0720[52], func_001E3710, 16, 21, data_s8_004C0720[32], data_s8_004C0720[56], func_001E3710, 17, 22, data_s8_004C0720[36], data_s8_004C0720[60], 12, 240, 16)
EXTENDED_MOVE_SETUP(func_00287370, func_001E3710, 15, 20, data_s8_004C0934[0], data_s8_004C094C[0], func_001E3710, 16, 21, data_s8_004C0934[4], data_s8_004C094C[4], func_001E3710, 17, 22, data_s8_004C0934[8], data_s8_004C094C[8], 12, 240, 16)
EXTENDED_MOVE_SETUP(func_0028EAF0, func_001E3710, 12, 20, data_s8_004C09C0[16], data_s8_004C09E8[0], func_001E3710, 13, 21, data_s8_004C09C0[20], data_s8_004C09E8[4], func_001E3710, 14, 22, data_s8_004C09C0[24], data_s8_004C09E8[8], 11, 15, 1)
EXTENDED_MOVE_SETUP(func_00295F10, func_001E3710, 12, 20, data_s8_004C0A80[16], data_s8_004C0AA8[0], func_001E3710, 13, 21, data_s8_004C0A80[20], data_s8_004C0AA8[4], func_001E3710, 14, 22, data_s8_004C0A80[24], data_s8_004C0AA8[8], 11, 15, 1)
EXTENDED_MOVE_SETUP(func_002A7E80, func_001E3710, 12, 20, data_s8_004C0BD0[24], data_s8_004C0C00[0], func_001E3710, 13, 21, data_s8_004C0BD0[28], data_s8_004C0C00[4], func_001E3710, 14, 22, data_s8_004C0BD0[32], data_s8_004C0C00[8], 11, 15, 1)
EXTENDED_MOVE_SETUP(func_002B3680, func_001E3710, 12, 20, data_s8_004C0CC0[24], data_s8_004C0CC0[48], func_001E3710, 13, 21, data_s8_004C0CC0[28], data_s8_004C0CC0[52], func_001E3710, 14, 22, data_s8_004C0CC0[32], data_s8_004C0CC0[56], 11, 15, 1)
EXTENDED_MOVE_SETUP(func_002B37D0, func_001E3710, 15, 20, data_s8_004C0CC0[36], data_s8_004C0CC0[60], func_001E3710, 16, 21, data_s8_004C0CC0[40], data_s8_004C0D00[0], func_001E3710, 17, 22, data_s8_004C0CC0[44], data_s8_004C0D00[4], 12, 240, 16)
EXTENDED_MOVE_SETUP(func_002C6380, func_001E3710, 12, 20, data_s8_004C0E30[0], data_s8_004C0E30[24], func_001E3710, 13, 21, data_s8_004C0E30[4], data_s8_004C0E30[28], func_001E3710, 14, 22, data_s8_004C0E30[8], data_s8_004C0E30[32], 11, 15, 1)
EXTENDED_MOVE_SETUP(func_002C64D0, func_001E3710, 15, 20, data_s8_004C0E30[12], data_s8_004C0E30[36], func_001E3710, 16, 21, data_s8_004C0E30[16], data_s8_004C0E30[40], func_001E3710, 17, 22, data_s8_004C0E30[20], data_s8_004C0E30[44], 12, 240, 16)
EXTENDED_MOVE_SETUP(func_002CC980, func_001E3710, 12, 20, data_s8_004C0EC0[16], data_s8_004C0EE8[0], func_001E3710, 13, 21, data_s8_004C0EC0[20], data_s8_004C0EE8[4], func_001E3710, 14, 22, data_s8_004C0EC0[24], data_s8_004C0EE8[8], 11, 15, 1)
EXTENDED_MOVE_SETUP(func_002D20E0, func_001E3710, 12, 20, data_s8_004C0F30[24], data_s8_004C0F30[48], func_001E3710, 13, 21, data_s8_004C0F30[28], data_s8_004C0F30[52], func_001E3710, 14, 22, data_s8_004C0F30[32], data_s8_004C0F30[56], 11, 15, 1)
EXTENDED_MOVE_SETUP(func_002D2230, func_001E3710, 15, 20, data_s8_004C0F30[36], data_s8_004C0F30[60], func_001E3710, 16, 21, data_s8_004C0F30[40], data_s8_004C0F70[0], func_001E3710, 17, 22, data_s8_004C0F30[44], data_s8_004C0F70[4], 12, 240, 16)
EXTENDED_MOVE_SETUP(func_00310510, func_001E3710, 12, 20, data_s8_004C1690[0], data_s8_004C16A8[0], func_001E3710, 13, 21, data_s8_004C1694[0], data_s8_004C16A8[4], func_001E3710, 14, 22, data_s8_004C1694[4], data_s8_004C16A8[8], 11, 15, 1)

#define THIRD_STATE_SETUP(name,command0,table0,command1,table1,command2,table2,mode) \
void name(u8 *p) { \
 switch(p[0x1fc]) { \
 case 0: \
  p[0x168]=0; \
  p[0x1b5]=command0; \
  func_001E3710(p,20); \
  *(signed char **)(p+0x408)=(signed char *)&table0; \
  p[0x1bb]=0; \
  break; \
 case 1: \
  p[0x168]=1; \
  p[0x1b5]=command1; \
  func_001E3710(p,21); \
  *(signed char **)(p+0x408)=(signed char *)&table1; \
  p[0x1bb]=1; \
  break; \
 case 2: \
  p[0x168]=2; \
  p[0x1b5]=command2; \
  *(signed char **)(p+0x408)=(signed char *)&table2; \
  p[0x1bb]=2; \
  break; \
 } \
 reset_move_counters(p,p[0x1b5],mode); \
}

THIRD_STATE_SETUP(func_001EEB50, 6, data_s8_004BFB70[0], 7, data_s8_004BFB70[4], 8, data_s8_004BFB70[8], 9)
THIRD_STATE_SETUP(func_001EED40, 9, data_s8_004BFB7C[0], 10, data_s8_004BFB7C[4], 11, data_s8_004BFB7C[8], 10)
THIRD_STATE_SETUP(func_00210E50, 6, data_s8_004BFE80[0], 7, data_s8_004BFE80[4], 8, data_s8_004BFE80[8], 9)
THIRD_STATE_SETUP(func_0023A850, 3, data_s8_004C0214[0], 4, data_s8_004C0214[4], 5, data_s8_004C0214[8], 8)
THIRD_STATE_SETUP(func_00244190, 3, data_s8_004C0324[0], 4, data_s8_004C0324[4], 5, data_s8_004C0324[8], 8)
THIRD_STATE_SETUP(func_0025CF60, 9, data_s8_004C0590[12], 10, data_s8_004C0590[16], 11, data_s8_004C0590[20], 10)
THIRD_STATE_SETUP(func_00286EB0, 6, data_s8_004C0910[0], 7, data_s8_004C0910[4], 8, data_s8_004C0910[8], 9)
THIRD_STATE_SETUP(func_00286FA0, 3, data_s8_004C0910[12], 4, data_s8_004C0910[16], 5, data_s8_004C0910[20], 8)
THIRD_STATE_SETUP(func_00287090, 9, data_s8_004C0910[12], 10, data_s8_004C0910[16], 11, data_s8_004C0910[20], 10)
THIRD_STATE_SETUP(func_0028E870, 3, data_s8_004C09C0[4], 4, data_s8_004C09C0[8], 5, data_s8_004C09C0[12], 8)
THIRD_STATE_SETUP(func_0028E960, 9, data_s8_004C09C0[4], 10, data_s8_004C09C0[8], 11, data_s8_004C09C0[12], 10)
THIRD_STATE_SETUP(func_002F2AA0, 3, data_s8_004C1294[0], 4, data_s8_004C1294[4], 5, data_s8_004C1294[8], 8)
THIRD_STATE_SETUP(func_002F7850, 3, data_s8_004C1344[0], 4, data_s8_004C1344[4], 5, data_s8_004C1344[8], 8)
THIRD_STATE_SETUP(func_002FCB90, 3, data_s8_004C13D0[0], 4, data_s8_004C13D0[4], 5, data_s8_004C13D0[8], 8)
THIRD_STATE_SETUP(func_00305890, 9, data_s8_004C1514[0], 10, data_s8_004C1514[4], 11, data_s8_004C1514[8], 10)

/* These handlers install the third state before its animation callback. */
#define FINAL_ANIMATION_SETUP(name,command0,table0,command1,table1,command2,table2,mode) \
void name(u8 *p) { \
 switch(p[0x1fc]) { \
 case 0: \
  p[0x168]=0; \
  p[0x1b5]=command0; \
  func_001E3710(p,20); \
  *(signed char **)(p+0x408)=(signed char *)&table0; \
  p[0x1bb]=0; \
  break; \
 case 1: \
  p[0x168]=1; \
  p[0x1b5]=command1; \
  func_001E3710(p,21); \
  *(signed char **)(p+0x408)=(signed char *)&table1; \
  p[0x1bb]=1; \
  break; \
 case 2: \
  p[0x168]=2; \
  p[0x1b5]=command2; \
  *(signed char **)(p+0x408)=(signed char *)&table2; \
  p[0x1bb]=2; \
  func_001E3710(p,22); \
  break; \
 } \
 reset_move_counters(p,p[0x1b5],mode); \
}

FINAL_ANIMATION_SETUP(func_0021DA40, 9, data_s8_004BFF34[0], 10, data_s8_004BFF38[0], 11, data_s8_004BFF3C[0], 10)
FINAL_ANIMATION_SETUP(func_0026B8B0, 6, data_s8_004C0688[0], 7, data_s8_004C068C[0], 8, data_s8_004C068C[4], 9)
FINAL_ANIMATION_SETUP(func_0026B9B0, 3, data_s8_004C0694[0], 4, data_s8_004C0698[0], 5, data_s8_004C0698[4], 8)
FINAL_ANIMATION_SETUP(func_0026BAB0, 9, data_s8_004C0694[0], 10, data_s8_004C0698[0], 11, data_s8_004C0698[4], 10)
FINAL_ANIMATION_SETUP(func_002B32E0, 6, data_s8_004C0CC0[0], 7, data_s8_004C0CC0[4], 8, data_s8_004C0CC0[8], 9)
FINAL_ANIMATION_SETUP(func_002B33E0, 3, data_s8_004C0CC0[12], 4, data_s8_004C0CC0[16], 5, data_s8_004C0CC0[20], 8)
FINAL_ANIMATION_SETUP(func_002B34E0, 9, data_s8_004C0CC0[12], 10, data_s8_004C0CC0[16], 11, data_s8_004C0CC0[20], 10)
FINAL_ANIMATION_SETUP(func_002D1D40, 6, data_s8_004C0F30[0], 7, data_s8_004C0F30[4], 8, data_s8_004C0F30[8], 9)
FINAL_ANIMATION_SETUP(func_002D1E40, 3, data_s8_004C0F30[12], 4, data_s8_004C0F30[16], 5, data_s8_004C0F30[20], 8)
FINAL_ANIMATION_SETUP(func_002D1F40, 9, data_s8_004C0F30[12], 10, data_s8_004C0F30[16], 11, data_s8_004C0F30[20], 10)
FINAL_ANIMATION_SETUP(func_002E9780, 3, data_s8_004C1134[0], 4, data_s8_004C1138[0], 5, data_s8_004C113C[0], 8)
FINAL_ANIMATION_SETUP(func_00300F40, 3, data_s8_004C1474[0], 4, data_s8_004C1474[4], 5, data_s8_004C1474[8], 8)

void func_00309450(u8 *p) {
 switch (p[0x1fc]) {
 case 0:
  p[0x168] = 0;
  p[0x1b5] = 0;
  func_001E3710(p, 20);
  *(const signed char **)(p + 0x408) = (const signed char *)(D_004C1588);
  p[0x1bb] = 0;
  break;
 case 1:
  p[0x168] = 1;
  p[0x1b5] = 1;
  func_001E3710(p, 21);
  *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C158C[0]);
  p[0x1bb] = 1;
  func_00176160(p, 1, 18, 1);
  break;
 case 2:
  p[0x168] = 2;
  p[0x1b5] = 2;
  func_001E3710(p, 22);
  *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C158C[4]);
  p[0x1bb] = 2;
  func_003092C0(p);
  break;
 }
 reset_move_counters(p, p[0x1b5], 7);
}

void func_00309560(u8 *p) {
 switch (p[0x1fc]) {
 case 0:
  p[0x168] = 0;
  p[0x1b5] = 6;
  func_001E3710(p, 20);
  *(const signed char **)(p + 0x408) = (const signed char *)(D_004C1588);
  p[0x1bb] = 0;
  break;
 case 1:
  p[0x168] = 1;
  p[0x1b5] = 7;
  func_001E3710(p, 21);
  *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C158C[0]);
  p[0x1bb] = 1;
  break;
 case 2:
  p[0x168] = 2;
  p[0x1b5] = 8;
  func_001E3710(p, 22);
  *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C158C[4]);
  p[0x1bb] = 2;
  func_003092C0(p);
  break;
 }
 reset_move_counters(p, p[0x1b5], 9);
}

void func_00309670(u8 *p) {
 switch (p[0x1fc]) {
 case 0:
  p[0x168] = 0;
  p[0x1b5] = 3;
  func_001E3710(p, 20);
  *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C1594[0]);
  p[0x1bb] = 0;
  break;
 case 1:
  p[0x168] = 1;
  p[0x1b5] = 4;
  func_001E3710(p, 21);
  *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C1598[0]);
  p[0x1bb] = 1;
  break;
 case 2:
  p[0x168] = 2;
  p[0x1b5] = 5;
  func_001E3710(p, 22);
  *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C1598[4]);
  p[0x1bb] = 2;
  func_003092C0(p);
  break;
 }
 reset_move_counters(p, p[0x1b5], 8);
}

void func_00309780(u8 *p) {
 switch (p[0x1fc]) {
 case 0:
  p[0x168] = 0;
  p[0x1b5] = 9;
  func_001E3710(p, 20);
  *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C1594[0]);
  p[0x1bb] = 0;
  break;
 case 1:
  p[0x168] = 1;
  p[0x1b5] = 10;
  func_001E3710(p, 21);
  *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C1598[0]);
  p[0x1bb] = 1;
  break;
 case 2:
  p[0x168] = 2;
  p[0x1b5] = 11;
  func_001E3710(p, 22);
  *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C1598[4]);
  p[0x1bb] = 2;
  func_003092C0(p);
  break;
 }
 reset_move_counters(p, p[0x1b5], 10);
}

void func_00309930(u8 *p) {
 switch (p[0x1fc]) {
 case 0:
  p[0x168] = 0;
  p[0x1b5] = 12;
  func_001E3710(p, 20);
  if (p[0x210] == 0)
   *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C15A0[0]);
  else
   *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C15B8[0]);
  p[0x1bb] = 0;
  break;
 case 1:
  p[0x168] = 1;
  p[0x1b5] = 13;
  func_001E3710(p, 21);
  if (p[0x210] == 0)
   *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C15A4[0]);
  else
   *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C15B8[4]);
  p[0x1bb] = 1;
  func_00176160(p, 1, 18, 1);
  break;
 case 2:
  p[0x168] = 2;
  p[0x1b5] = 14;
  func_001E3710(p, 22);
  if (p[0x210] == 0)
   *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C15A4[4]);
  else
   *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C15B8[8]);
  p[0x1bb] = 2;
  func_003092C0(p);
  break;
 }
 reset_move_counters(p, p[0x1b5], 11);
 if (*(signed char *)(p + 0x1ea) & 0x0F)
  *(signed char *)(p + 0x1ea) -= 1;
}

void func_00309AA0(u8 *p) {
 switch (p[0x1fc]) {
 case 0:
  p[0x168] = 0;
  p[0x1b5] = 15;
  func_001E3710(p, 20);
  if (p[0x210] == 0)
   *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C15AC[0]);
  else
   *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C15B8[12]);
  p[0x1bb] = 0;
  break;
 case 1:
  p[0x168] = 1;
  p[0x1b5] = 16;
  func_001E3710(p, 21);
  if (p[0x210] == 0)
   *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C15B0[0]);
  else
   *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C15B8[16]);
  p[0x1bb] = 1;
  break;
 case 2:
  p[0x168] = 2;
  p[0x1b5] = 17;
  func_001E3710(p, 22);
  if (p[0x210] == 0)
   *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C15B0[4]);
  else
   *(const signed char **)(p + 0x408) = (const signed char *)(&data_s8_004C15B8[20]);
  p[0x1bb] = 2;
  func_003092C0(p);
  break;
 }
 reset_move_counters(p, p[0x1b5], 12);
 if (*(signed char *)(p + 0x1ea) & 0xF0)
  *(signed char *)(p + 0x1ea) -= 16;
}


void func_0026BC50(u8 *p) {
 switch (p[0x1fc]) {
 case 0:
  p[0x168] = 0;
  p[0x1b5] = 12;
  func_001E3710(p, 20);
  if (p[0x210] == 0)
   *(const signed char **)(p + 0x408) = (const signed char *)data_u32_004C06A0;
  else
   *(const signed char **)(p + 0x408) = (const signed char *)data_u32_004C06B8;
  p[0x1bb] = 0;
  break;
 case 1:
  p[0x168] = 1;
  p[0x1b5] = 13;
  func_001E3710(p, 21);
  if (p[0x210] == 0)
   *(const signed char **)(p + 0x408) = (const signed char *)data_ff_004C06A4;
  else
   *(const signed char **)(p + 0x408) = (const signed char *)&data_u32_004C06B8[1];
  p[0x1bb] = 1;
  break;
 case 2:
  p[0x168] = 2;
  p[0x1b5] = 14;
  func_001E3710(p, 22);
  if (p[0x210] == 0)
   *(const signed char **)(p + 0x408) = (const signed char *)&data_ff_004C06A4[1];
  else
   *(const signed char **)(p + 0x408) = (const signed char *)&data_u32_004C06B8[2];
  p[0x1bb] = 2;
  func_001E3710(p, 22);
  break;
 }
 reset_move_counters(p, p[0x1b5], 11);
 if (*(signed char *)(p + 0x1ea) & 0x0F)
  *(signed char *)(p + 0x1ea) -= 1;
}

void func_00301040(u8 *p) {
 switch (p[0x1fc]) {
 case 0:
  p[0x168] = 0;
  p[0x1b5] = 9;
  func_001E3710(p, 20);
  *(signed char **)(p + 0x408) = &data_s8_004C1474[0];
  p[0x1bb] = 0;
  break;
 case 1:
  p[0x168] = 1;
  p[0x1b5] = 10;
  *(signed char **)(p + 0x408) = &data_s8_004C1474[4];
  p[0x1bb] = 1;
  break;
 case 2:
  p[0x168] = 2;
  p[0x1b5] = 11;
  *(signed char **)(p + 0x408) = &data_s8_004C1474[8];
  p[0x1bb] = 2;
  func_001E3710(p, 22);
  break;
 }
 reset_move_counters(p, p[0x1b5], 10);
}

/* The first three command states use the same reset behavior. */
MOVE_SETUP(func_00208DD0, func_001E3710, 0, 20, data_s8_004BFDC8[0], func_001E3210, 1, 30, data_s8_004BFDC8[4], func_001E3210, 2, 30, data_s8_004BFDC8[8], 7)
MOVE_SETUP(func_00248A20, func_001E3710, 0, 20, data_s8_004C03B0[0], func_001E3710, 1, 21, data_s8_004C03B0[4], func_001E3710, 2, 22, data_s8_004C03B0[8], 7)
MOVE_SETUP(func_0024E300, func_001E3710, 0, 20, D_004C0438, func_001E3710, 1, 21, D_004C043C, func_001E3710, 2, 22, data_s8_004C0440[0], 7)
MOVE_SETUP(func_0025CC70, func_001E3710, 0, 20, data_s8_004C0590[0], func_001E3710, 1, 21, data_s8_004C0590[4], func_001E3710, 2, 26, data_s8_004C0590[8], 7)
MOVE_SETUP(func_0028E680, func_001E3710, 0, 20, D_004C09B8, func_001E3710, 1, 21, D_004C09BC, func_001E3710, 2, 22, data_s8_004C09C0[0], 7)
MOVE_SETUP(func_002CC510, func_001E3710, 0, 20, D_004C0EB8, func_001E3710, 1, 21, D_004C0EBC, func_001E3710, 2, 22, data_s8_004C0EC0[0], 7)

void func_002E9880(u8 *p)
{
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 9;
        func_001E3710(p, 20);
        *(const signed char **)(p + 0x408) = data_s8_004C1134;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 10;
        *(const signed char **)(p + 0x408) = data_s8_004C1138;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 11;
        *(const signed char **)(p + 0x408) = data_s8_004C113C;
        p[0x1BB] = 2;
        func_001E3710(p, 22);
        break;
    }
    reset_move_counters(p, p[0x1B5], 10);
}
