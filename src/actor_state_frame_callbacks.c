typedef unsigned char u8;typedef signed short s16;typedef unsigned int u32;
typedef struct {u8 pad[0x1c];s16 timer;} Timer;
extern void func_00179150(void *,void *);extern int func_001757E0(u8 *,int,int);
extern u8 *D_004C2840 __attribute__((section(".sdata")));
void func_002541A0(u8 *p){u8 *q=*(u8 **)(p+0x1dc);if(q[6]>=2)func_00179150(q,p);}
void func_002F3BB0(u8 *p){Timer *t=(Timer *)p;t->timer=0;p[0x168]=6;if(*(u32 *)(D_004C2840+0x1c)&1){t->timer=1;p[0x168]=0;}func_001757E0(p,19,p[0x168]);}
