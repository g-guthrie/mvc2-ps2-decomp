/* Set up the airborne animation before installing its command and callbacks. */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *D_004C2794;
extern void func_001861B0(u8 *);
extern void func_001757E0(u8 *,int,int);
extern void func_001E3210(u8 *,int);
extern void func_0018C4B0(u8 *,int);
extern void func_00183D90(u8 *);
extern void func_001863F0(u8 *);
extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
static inline void reset_command(u8 *p,u8 command) {
 unsigned int offset;
 p[0x1b5]=command;
 p[0x1b2]=*(u16 *)(p+0x1c0)=0;
 *(int *)(p+0x1d8)=0;
 offset=p[2]*2;
 offset+=(unsigned int)D_004C2794;
 ++*(short *)(offset+0x7c);
}
extern void func_001E3710(u8 *,int);

#define LATE_AIR_STEP(name,effect,command,set_animation,animation,finish_setup,setup_arg) \
void name(u8 *p) { \
 if (p[6] == 0) { \
  func_001861B0(p); \
  ++p[6]; \
  p[0x20d]=1; \
  func_001757E0(p,20,effect); \
  reset_command(p,command); \
  set_animation(p,animation); \
  finish_setup(p,setup_arg); \
 } \
 if (p[0x213] == 3) func_00183D90(p); \
 *(float *)(p+0x34) += *(float *)(p+0x5c); \
 *(float *)(p+0x5c) += *(float *)(p+0x68); \
 *(float *)(p+0x38) += *(float *)(p+0x60); \
 *(float *)(p+0x60) += *(float *)(p+0x6c); \
 func_001863F0(p); \
 if ((signed char)func_00175700(p) < 0) func_001843A0(p); \
}

LATE_AIR_STEP(func_00209BF0, 17, 89, func_001E3210, 30, func_0018C4B0, 5)
LATE_AIR_STEP(func_00282C20, 13, 98, func_001E3710, 22, func_0018C4B0, 5)
LATE_AIR_STEP(func_002A2330, 5, 72, func_001E3710, 22, func_0018C4B0, 5)
LATE_AIR_STEP(func_002A8740, 8, 85, func_001E3710, 22, func_0018C4B0, 5)
LATE_AIR_STEP(func_002B3DA0, 2, 85, func_0018C4B0, 5, func_001E3710, 22)
