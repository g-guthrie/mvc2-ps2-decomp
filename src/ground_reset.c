/* Clear motion, restore ground height, and enter the follow-up state. */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_00175C00(u8 *,int);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *,int,int);
extern u8 *D_004C2794;

#define GROUND_RESET(name,command,mode,effect) \
void name(u8 *p) { \
 unsigned int offset; \
 ++p[6]; \
 *(float *)(p+0x5c)=0; \
 *(float *)(p+0x60)=0; \
 *(float *)(p+0x68)=0; \
 *(float *)(p+0x6c)=0; \
 p[0x20d]=0; \
 *(float *)(p+0x38)=*(float *)(p+0x430); \
 func_00175C00(p,0); \
 func_00185490(p); \
 func_00183D10(p); \
 p[0x1b5]=command; \
 p[0x1b2]=*(u16 *)(p+0x1c0)=0; \
 *(int *)(p+0x1d8)=0; \
 offset=p[2]*2; \
 offset += (unsigned int)D_004C2794; \
 ++*(short *)(offset+0x7c); \
 func_001757E0(p,mode,effect); \
}

GROUND_RESET(func_001ECE30, 94, 21, 23)
GROUND_RESET(func_001F5E40, 58, 21, 16)
GROUND_RESET(func_00201DF0, 58, 21, 17)
GROUND_RESET(func_0020EEA0, 88, 21, 54)
GROUND_RESET(func_002144F0, 67, 21, 47)
GROUND_RESET(func_00221C70, 82, 21, 51)
GROUND_RESET(func_00225450, 60, 20, 8)
GROUND_RESET(func_0024C660, 67, 21, 7)
GROUND_RESET(func_00252E50, 52, 21, 25)
GROUND_RESET(func_0025AE10, 66, 20, 2)
GROUND_RESET(func_0026E6E0, 62, 21, 17)
GROUND_RESET(func_00289EC0, 80, 21, 15)
GROUND_RESET(func_00299BF0, 89, 20, 11)
GROUND_RESET(func_002B1870, 107, 21, 42)
GROUND_RESET(func_002B77F0, 84, 21, 43)
GROUND_RESET(func_002BDC40, 94, 21, 28)
GROUND_RESET(func_002D01D0, 91, 21, 28)
GROUND_RESET(func_002D52A0, 74, 21, 22)
GROUND_RESET(func_002E3760, 63, 21, 22)
GROUND_RESET(func_0031A020, 87, 21, 38)
