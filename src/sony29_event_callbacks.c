typedef unsigned int u32;
typedef void (*UserCallback)(void *);
extern UserCallback D_004C8644;
extern void *D_004C8648;
extern int D_004399BC,D_004399A4;
extern int func_0010CA20(void);
extern void func_0010CA68(void);
extern void func_00106240(u32,void (*)(void *,void *),void *);
int func_0010EB90(void);
UserCallback func_0010EAD8(UserCallback callback,void *argument){UserCallback previous;int enabled;if(D_004399BC<0)func_0010EB90();enabled=func_0010CA20();previous=D_004C8644;D_004C8648=argument;D_004C8644=callback;if(enabled)func_0010CA68();return previous;}
void func_0010EB50(void *packet,void *common){if(D_004C8644&&!D_004399A4)D_004C8644(D_004C8648);}
int func_0010EB90(void){int enabled;D_004399A4=1;enabled=func_0010CA20();func_00106240(0x80000012u,func_0010EB50,0);if(enabled)func_0010CA68();D_004399A4=0;D_004399BC=1;return 1;}
