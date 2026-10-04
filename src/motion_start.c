/* Begin facing-dependent horizontal motion with exact vertical constants. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef union FloatWord { float value; unsigned int bits; } FloatWord;
extern void func_00175C00(u8 *,int);
extern void func_001757E0(u8 *,int,int);
extern u8 *D_004C2794;

#define MOTION_START(name,y_velocity,command,effect) \
void name(u8 *p) { \
 unsigned int offset; \
 func_00175C00(p,0); \
 ++p[6]; \
 p[0x20d]=2; \
 *(float *)(p+0x5c)=30.0f; \
 if (p[0x1e6] == 0) *(float *)(p+0x5c)=-*(float *)(p+0x5c); \
 *(float *)(p+0x68)=0; \
 ((FloatWord *)(p+0x60))->bits=y_velocity; \
 ((FloatWord *)(p+0x6c))->bits=0xbf4db6db; \
 p[0x1b5]=command; \
 p[0x1b2]=*(u16 *)(p+0x1c0)=0; \
 *(int *)(p+0x1d8)=0; \
 offset=p[2]*2; \
 offset += (unsigned int)D_004C2794; \
 ++*(short *)(offset+0x7c); \
 func_001757E0(p,20,effect); \
}

MOTION_START(func_001EDA30, 0x40892492u, 84, 8)
MOTION_START(func_002146D0, 0x40892492u, 58, 7)
MOTION_START(func_0021EBB0, 0x40892492u, 81, 3)
MOTION_START(func_00225ED0, 0x40892492u, 59, 5)
MOTION_START(func_00232690, 0x3E892492u, 85, 6)
MOTION_START(func_00285900, 0x40892492u, 80, 5)
MOTION_START(func_0029AED0, 0x40892492u, 82, 8)
MOTION_START(func_002C42E0, 0x40892492u, 73, 13)
MOTION_START(func_002CB520, 0x40892492u, 64, 4)
MOTION_START(func_002D10D0, 0x40892492u, 81, 6)
MOTION_START(func_002D2BF0, 0x40892492u, 51, 2)
MOTION_START(func_002E3590, 0x40892492u, 61, 5)
MOTION_START(func_00207900, 0x40892492u, 84, 0)
MOTION_START(func_0020F010, 0x40892492u, 51, 0)
MOTION_START(func_00252FC0, 0x40892492u, 51, 0)
MOTION_START(func_0026AE20, 0x40892492u, 71, 0)
MOTION_START(func_0026CB40, 0x40892492u, 54, 0)
MOTION_START(func_002728D0, 0x40892492u, 72, 0)
MOTION_START(func_002A03B0, 0x40892492u, 67, 0)
MOTION_START(func_002A6B20, 0x40892492u, 70, 0)
MOTION_START(func_002B4B00, 0x40892492u, 76, 0)
MOTION_START(func_002FB100, 0x40892492u, 48, 0)
MOTION_START(func_0030B980, 0x40892492u, 63, 0)
