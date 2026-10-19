/* Unary actor setup called at 0021661C. Selectors 0..2 initialize
 * the command, animation and strength, as in the adjacent deferred setups. */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *D_004C2794;
extern signed char D_004BFED0[] __attribute__((section(".sdata")));
extern void func_001E3210(u8 *, int);
extern int func_001757E0(u8 *, int, int);
void func_00216670(u8 *p) {
 int command,animation,strength;
 unsigned int offset;
 switch(p[0x1fc]) {
 case 0:
  command=0;
  strength=0;
  *(signed char **)(p+0x408)=(signed char *)&D_004BFED0[0];
  animation=30;
  p[0x1bb]=0;
  break;
 case 1:
  p[0x20]=0;
  command=1;
  strength=1;
  *(signed char **)(p+0x408)=(signed char *)&D_004BFED0[4];
  animation=31;
  p[0x1bb]=1;
  break;
 case 2:
  command=2;
  strength=2;
  *(signed char **)(p+0x408)=(signed char *)&D_004BFED0[8];
  animation=32;
  p[0x1bb]=2;
  break;
 }
 p[0x1b5]=command;
 p[0x1b2]=*(u16 *)(p+0x1c0)=0;
 *(int *)(p+0x1d8)=0;
 offset=p[2]*2;
 offset+=(unsigned int)D_004C2794;
 ++*(short *)(offset+0x7c);
 func_001E3210(p,(u8)animation);
 func_001757E0(p,7,(u8)strength);
}

extern signed char D_004C1740[] __attribute__((section(".sdata")));
/* Native call at 0031BA0C. As in retail, only cases 0, 1 and 2
 * initialize command/animation/strength; no default values are invented. */
void func_0031BA60(u8 *p) {
 int command,animation,strength;
 unsigned int offset;
 switch(p[0x1fc]) {
 case 0:
  command=0;
  strength=0;
  *(signed char **)(p+0x408)=(signed char *)&D_004C1740[0];
  animation=30;
  p[0x1bb]=0;
  break;
 case 1:
  p[0x20]=0;
  command=1;
  strength=1;
  *(signed char **)(p+0x408)=(signed char *)&D_004C1740[4];
  animation=31;
  p[0x1bb]=1;
  break;
 case 2:
  command=2;
  strength=2;
  *(signed char **)(p+0x408)=(signed char *)&D_004C1740[8];
  animation=32;
  p[0x1bb]=2;
  break;
 }
 p[0x1b5]=command;
 p[0x1b2]=*(u16 *)(p+0x1c0)=0;
 *(int *)(p+0x1d8)=0;
 offset=p[2]*2;
 offset+=(unsigned int)D_004C2794;
 ++*(short *)(offset+0x7c);
 func_001E3210(p,(u8)animation);
 func_001757E0(p,7,(u8)strength);
}
