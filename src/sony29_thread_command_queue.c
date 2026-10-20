/* Native Sony thread-command consumer and its worker-thread initializer. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {int count,limit,initial,waiters;u32 attributes,option;} SemaParams;
typedef void (*ThreadEntry)(void *);
typedef struct {
 int status;ThreadEntry entry;void *stack;int stack_size;void *gp;
 int initial_priority,current_priority;u32 attributes,option;
} ThreadParams;
typedef struct {u8 operation,thread;} ThreadCommand;
typedef struct {int read,write;ThreadCommand commands[512];} ThreadQueue;
extern int D_004C3160,D_00438258;
extern ThreadQueue D_004C3168;
extern u8 D_004C2D60[],_gp[];
extern char D_004AAF30[];
extern int func_00103E20(int);
extern int func_00103D10(int);
extern int func_00103C90(int);
extern int func_00103D50(int);
extern void func_00105E48(void *,...);
extern int func_00103DE0(SemaParams *);
extern int func_00103DF0(int);
extern int func_00103BE0(ThreadParams *);
extern int func_00103C00(int,void *);
extern int func_00103CD0(void);
extern int func_00103C70(int,int);
void func_00104AE0(void *argument)
{
 ThreadQueue *queue=argument;
 for(;;){
  int index;
  func_00103E20(D_004C3160);
  index=queue->read&511;
  queue->read=index+1;
  switch(queue->commands[index].operation){
   case 0:func_00103D10(queue->commands[index].thread);break;
   case 1:func_00103C90(queue->commands[index].thread);break;
   case 2:func_00103D50(queue->commands[index].thread);break;
   default:func_00105E48(D_004AAF30);break;
  }
 }
}
int func_00104BB8(void)
{
 ThreadParams thread;
 SemaParams semaphore;
 if(D_00438258>0)return -1;
 semaphore.limit=255;
 semaphore.initial=0;
 D_004C3160=func_00103DE0(&semaphore);
 if(D_004C3160<0)return -1;
 thread.entry=func_00104AE0;
 thread.stack=D_004C2D60;
 thread.stack_size=1024;
 thread.gp=_gp;
 thread.initial_priority=0;
 D_00438258=func_00103BE0(&thread);
 if(D_00438258<0){func_00103DF0(D_004C3160);return -1;}
 D_004C3168.read=0;
 D_004C3168.write=0;
 func_00103C00(D_00438258,&D_004C3168);
 func_00103C70(func_00103CD0(),1);
 return D_00438258;
}
