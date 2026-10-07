/* Initialize the animation once, then advance it on subsequent callbacks. */
typedef unsigned char u8;
extern int func_001757E0(u8 *,int,int);
extern int func_00175700(u8 *);

#define FRAME_CALLBACK(name) \
void name(u8 *p) { \
 if (p[6] == 0) { ++p[6]; func_001757E0(p,19,2); } \
 else func_00175700(p); \
}

FRAME_CALLBACK(func_0023BC80)
FRAME_CALLBACK(func_00245A80)
FRAME_CALLBACK(func_003029C0)
FRAME_CALLBACK(func_00312640)
