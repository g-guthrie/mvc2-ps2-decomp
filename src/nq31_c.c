typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*ThreadEntry)(void *);
typedef struct {
 int status;ThreadEntry entry;void *stack;int stack_size;void *gp;
 int initial_priority,current_priority;u32 attributes,option;
} ThreadParams;
extern int D_00439994,D_004C8650;
extern int D_004C8658[];
extern ThreadParams D_004C8688;
extern u8 _gp[];
extern void func_0010E770(void *);
extern int func_00103CD0(void);
extern int func_00103CE0(int,void *);
extern int func_00103BE0(ThreadParams *);
extern int func_00103C00(int,void *);
extern int func_00103C70(int,int);
int func_0010E830(int priority,void *stack,int stack_size)
{
 int result=1;
 if(D_00439994==0){
  D_004C8650=func_00103CD0();
  func_00103CE0(D_004C8650,D_004C8658);
  D_004C8688.stack_size=stack_size;
  D_004C8688.gp=_gp;
  D_004C8688.entry=func_0010E770;
  D_004C8688.stack=stack;
  D_004C8688.initial_priority=priority;
  D_00439994=func_00103BE0(&D_004C8688);
  func_00103C00(D_00439994,0);
 }else{
  func_00103C70(D_00439994,priority);
  result=0;
 }
 return result;
}
