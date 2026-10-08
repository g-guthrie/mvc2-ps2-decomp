/* Consume the positive animation flag and reset the selected command. */
typedef unsigned char u8;
extern u8 *D_004C2794;
extern void residual_002D3D40(u8 *, int);

#define COMMAND_RESET(name,command_base) \
void name(u8 *p) { \
 if (*(signed char *)(p+0x151)>0) { \
  unsigned int offset; \
  p[0x151]=0; \
  p[0x1b5]=*(signed char *)(p+0x1b7)+command_base; \
  p[0x1b2]=*(unsigned short *)(p+0x1c0)=0; \
  *(int *)(p+0x1d8)=0; \
  offset=p[2]*2; offset+=(unsigned int)D_004C2794; \
  ++*(short *)(offset+0x7c); \
 } \
}

COMMAND_RESET(func_001EB470, 57)
COMMAND_RESET(func_001EB830, 60)
COMMAND_RESET(func_002975D0, 58)
COMMAND_RESET(func_002979A0, 61)
COMMAND_RESET(func_002CDEB0, 58)
COMMAND_RESET(func_002CE330, 61)

void func_002D3E50(u8 *p) {
 p[0x1b5]=62;
 p[0x1b2]=*(unsigned short *)(p+0x1c0)=0;
 *(int *)(p+0x1d8)=0;
 { unsigned int offset=p[2]*2; offset+=(unsigned int)D_004C2794; ++*(short *)(offset+0x7c); }
 residual_002D3D40(p,0);
}

void func_002D46B0(u8 *p) {
 p[0x1b5]=61;
 p[0x1b2]=*(unsigned short *)(p+0x1c0)=0;
 *(int *)(p+0x1d8)=0;
 { unsigned int offset=p[2]*2; offset+=(unsigned int)D_004C2794; ++*(short *)(offset+0x7c); }
 residual_002D3D40(p,0);
}
