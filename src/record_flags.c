/* Mark an accepted transition whose actor record is enabled. */
typedef unsigned char u8;
extern int func_00189310(u8 *,u8 *,u8 *);
extern u8 D_00454A90[];
extern u8 D_00458070[];
extern u8 D_0045A650[];
extern u8 D_0045B410[];
extern u8 D_0045C860[];
extern u8 D_0045CAE0[];
extern u8 D_0045CD50[];

#define RECORD_FLAG(name,descriptor,offset) \
int name(u8 *p) { \
 int result; \
 if (!func_00189310(p,descriptor,p+offset)) return 0; \
 if (!**(signed char **)(p+0x420)) result=0; \
 else { p[0x26c]=1; result=1; } \
 return result; \
}

RECORD_FLAG(func_00273D10, D_00454A90, 0x380)
RECORD_FLAG(func_0029B8B0, D_00458070, 0x378)
RECORD_FLAG(func_002D6510, D_0045A650, 0x388)
RECORD_FLAG(func_002E92E0, D_0045B410, 0x3A0)
RECORD_FLAG(func_00300BA0, D_0045C860, 0x3A0)
RECORD_FLAG(func_003052D0, D_0045CAE0, 0x378)
RECORD_FLAG(func_00309200, D_0045CD50, 0x380)
