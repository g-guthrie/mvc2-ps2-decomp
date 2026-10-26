typedef unsigned char u8;typedef unsigned short u16;
typedef struct {u8 prefix[0x7C];short count[2];} Counters;
extern Counters *D_004C2794 __attribute__((section(".sdata")));
extern void func_00175C00(u8*,int),func_00185490(u8*),func_0018C4B0(u8*,int),func_00183D10(u8*);
extern int func_001757E0(u8*,int,int);
/* The native dispatcher supplies actor+0x2B8; this phase does not read it. */
void func_00213CD0(u8*p,void*work_context){
 (void)work_context;
 ++p[6];func_00175C00(p,0);func_00185490(p);func_0018C4B0(p,5);func_00183D10(p);
 p[0x20D]=1;p[0x1B5]=53;p[0x1B2]=(*(u16*)(p+0x1C0)=0);*(int*)(p+0x1D8)=0;
 ++D_004C2794->count[p[2]];func_001757E0(p,22,5);
}
