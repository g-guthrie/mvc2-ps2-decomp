/* Enter the selected state only when the command predicate succeeds. */
typedef unsigned char u8;
extern int func_001891F0(u8 *,int);
extern void func_00186A60(u8 *,int);

#define COMMAND_GATE(name,predicate,command,state,mode,setter,first,second,third) \
int name(u8 *p) { \
 if (!predicate(p,command)) return 0; \
 p[first]=0; p[second]=0; p[third]=0; p[0x1fd]=state; \
 setter(p,mode); \
 return 1; \
}

COMMAND_GATE(func_001EE500, func_001891F0, 9, 9, 21, func_00186A60, 5, 7, 6)
COMMAND_GATE(func_001FC680, func_001891F0, 8, 8, 21, func_00186A60, 5, 7, 6)
COMMAND_GATE(func_0022CE20, func_001891F0, 4, 4, 21, func_00186A60, 5, 7, 6)
COMMAND_GATE(func_00233910, func_001891F0, 7, 7, 21, func_00186A60, 5, 6, 7)
COMMAND_GATE(func_0023F3B0, func_001891F0, 5, 5, 21, func_00186A60, 5, 6, 7)
COMMAND_GATE(func_002AB9F0, func_001891F0, 2, 2, 21, func_00186A60, 5, 7, 6)
COMMAND_GATE(func_002D6440, func_001891F0, 4, 4, 21, func_00186A60, 5, 7, 6)
COMMAND_GATE(func_002E1370, func_001891F0, 6, 6, 21, func_00186A60, 5, 7, 6)
COMMAND_GATE(func_00305270, func_001891F0, 7, 7, 21, func_00186A60, 5, 7, 6)
COMMAND_GATE(func_00317330, func_001891F0, 7, 7, 21, func_00186A60, 5, 7, 6)
