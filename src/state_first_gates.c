/* Install the accepted command state before clearing its step counters. */
typedef unsigned char u8;
extern 
#define STATE_FIRST_GATE(name,command,state) \
int func_001891F0(u8 *,int); \
extern void func_00186A60(u8 *,int); \
int name(u8 *p) { \
 if (!func_001891F0(p,command)) return 0; \
 p[0x1fd]=state;p[5]=0;p[7]=0;p[6]=0; \
 func_00186A60(p,21); \
 return 1; \
}

STATE_FIRST_GATE(func_002264D0, 19, 19)
STATE_FIRST_GATE(func_002D9570, 8, 8)
STATE_FIRST_GATE(func_002EE040, 13, 13)
STATE_FIRST_GATE(func_0030CB20, 8, 8)
