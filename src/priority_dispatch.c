/* Handle a priority condition before dispatching the current state. */
typedef unsigned char u8;
typedef void (*Handler)(u8 *);
extern int func_001BA290(u8 *);
extern int func_003D92F0(u8 *);
extern void func_001843A0(u8 *);
extern void func_001B9D40(u8 *);
extern void func_0030F650(u8 *);
extern Handler D_0044BF90[];
extern Handler D_00450450[];
extern Handler D_00452660[];
extern Handler D_00452F40[];
extern Handler D_004532A0[];
extern Handler D_00453740[];
extern Handler D_00453E90[];
extern Handler D_0045B580[];
extern Handler D_0045BB60[];
extern Handler D_0045BEB0[];
extern Handler D_0045C100[];
extern Handler D_0045C9B0[];
extern Handler D_0045D180[];

#define PRIORITY_DISPATCH(name,predicate,override,handlers,state_offset) \
void name(u8 *p) { \
 if (predicate(p)) override(p); \
 else handlers[p[state_offset]](p); \
}

PRIORITY_DISPATCH(func_001B9DD0, func_001BA290, func_001B9D40, D_0044BF90, 0x4)
PRIORITY_DISPATCH(func_002057F0, func_003D92F0, func_001843A0, D_00450450, 0x20)
PRIORITY_DISPATCH(func_0023BD70, func_003D92F0, func_001843A0, D_00452660, 0x20)
PRIORITY_DISPATCH(func_0024A810, func_003D92F0, func_001843A0, D_00452F40, 0x20)
PRIORITY_DISPATCH(func_0024F800, func_003D92F0, func_001843A0, D_004532A0, 0x20)
PRIORITY_DISPATCH(func_00258C00, func_003D92F0, func_001843A0, D_00453740, 0x20)
PRIORITY_DISPATCH(func_0025E120, func_003D92F0, func_001843A0, D_00453E90, 0x20)
PRIORITY_DISPATCH(func_002EB420, func_003D92F0, func_001843A0, D_0045B580, 0x20)
PRIORITY_DISPATCH(func_002F3C10, func_003D92F0, func_001843A0, D_0045BB60, 0x20)
PRIORITY_DISPATCH(func_002F8B90, func_003D92F0, func_001843A0, D_0045BEB0, 0x20)
PRIORITY_DISPATCH(func_002FDD30, func_003D92F0, func_001843A0, D_0045C100, 0x20)
PRIORITY_DISPATCH(func_00302AB0, func_003D92F0, func_001843A0, D_0045C9B0, 0x20)
PRIORITY_DISPATCH(func_0030DC70, func_003D92F0, func_0030F650, D_0045D180, 0x20)
