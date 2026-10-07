/* Apply and consume the command queued by animation record data. */
typedef unsigned char u8;
extern u8 *D_004C2794;

#define PENDING_COMMAND(name) \
void name(u8 *p) { \
 int command=p[0x15b]; \
 if (command) { \
  unsigned int offset; \
  p[0x1b5]=command; \
  p[0x1b2]=*(unsigned short *)(p+0x1c0)=0; \
  *(int *)(p+0x1d8)=0; \
  offset=p[2]*2;offset+=(unsigned int)D_004C2794; \
  ++*(short *)(offset+0x7c); \
  p[0x15b]=0; \
 } \
}

PENDING_COMMAND(func_001ECF90)
PENDING_COMMAND(func_00296FB0)
PENDING_COMMAND(func_00299010)
PENDING_COMMAND(func_002CFA20)
