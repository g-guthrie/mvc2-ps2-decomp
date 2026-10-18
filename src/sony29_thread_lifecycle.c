typedef unsigned short u16;
extern int D_0043B404;
extern int func_00103DF0(int);
extern int func_00103CD0(void);
extern int func_00103B60(u16,void (*)(int,u16,void *),void *);
extern int func_00103D00(void);
extern void func_00110748(int,u16,void *);
int func_0010FF48(void){if(D_0043B404>=0){func_00103DF0(D_0043B404);D_0043B404=-1;}return 1;}
void func_00110770(u16 time){func_00103B60(time,func_00110748,(void *)func_00103CD0());func_00103D00();}
