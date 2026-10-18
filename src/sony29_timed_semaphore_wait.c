typedef unsigned short u16;
typedef struct {int current; int limit; int initial; int waiters; unsigned int attributes; unsigned int option;} SemaParams;
extern int func_00103DE0(SemaParams *);
extern int func_00103B60(u16,void (*)(int,u16,void *),void *);
extern int func_00103E20(int);
extern int func_00103DF0(int);
extern void func_0010E5E0(int,u16,void *);
void func_0010E608(u16 time){SemaParams params;int sem;params.limit=1;params.initial=0;params.option=0;sem=func_00103DE0(&params);func_00103B60(time,func_0010E5E0,(void *)sem);func_00103E20(sem);func_00103DF0(sem);}
