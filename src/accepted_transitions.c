/* Conditional transition setup with reset step counters. */
typedef unsigned char u8;
extern u8 D_00450540[];
extern u8 D_00450DE0[];
extern u8 D_00452170[];
extern u8 D_004528B0[];
extern u8 D_00453520[];
extern u8 D_00454D40[];
extern u8 D_0045AB80[];
extern u8 D_0045B3E0[];
extern u8 D_0045C830[];
extern u8 D_0045CB10[];
extern u8 D_0045D260[];
extern int func_00189310(u8 *,u8 *,u8 *);
extern int func_00189660(u8 *,u8 *,u8 *);
extern void func_0018A990(u8 *,u8 *);
extern void func_00186A60(u8 *,int);

#define ACCEPTED_TRANSITION(name,descriptor,offset,mode,first_step,second_step,third_step,predicate) \
int name(u8 *p) { \
 if (!predicate(p,descriptor,p+offset)) return 0; \
 func_0018A990(p,p+offset); \
 p[first_step]=0; \
 p[second_step]=0; \
 p[third_step]=0; \
 p[0x1fd]=0; \
 func_00186A60(p,mode); \
 return 1; \
}

ACCEPTED_TRANSITION(func_00208740, D_00450540, 0x3C0, 21, 5, 7, 6, func_00189310)
ACCEPTED_TRANSITION(func_00215DD0, D_00450DE0, 0x380, 21, 5, 6, 7, func_00189310)
ACCEPTED_TRANSITION(func_00233430, D_00452170, 0x380, 21, 5, 6, 7, func_00189310)
ACCEPTED_TRANSITION(func_0023F140, D_004528B0, 0x380, 21, 5, 6, 7, func_00189310)
ACCEPTED_TRANSITION(func_00254680, D_00453520, 0x378, 21, 5, 7, 6, func_00189310)
ACCEPTED_TRANSITION(func_00278440, D_00454D40, 0x380, 21, 5, 7, 6, func_00189310)
ACCEPTED_TRANSITION(func_002DC480, D_0045AB80, 0x380, 21, 5, 6, 7, func_00189310)
ACCEPTED_TRANSITION(func_002E8EF0, D_0045B3E0, 0x390, 21, 5, 7, 6, func_00189310)
ACCEPTED_TRANSITION(func_00300850, D_0045C830, 0x390, 21, 5, 7, 6, func_00189310)
ACCEPTED_TRANSITION(func_00304FD0, D_0045CB10, 0x380, 21, 5, 7, 6, func_00189310)
ACCEPTED_TRANSITION(func_0030F940, D_0045D260, 0x378, 21, 5, 7, 6, func_00189660)
