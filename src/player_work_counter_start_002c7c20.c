typedef unsigned char u8;typedef unsigned short u16;
typedef struct {u8 prefix[0x7C];short count[2];} Counters;
extern Counters *D_004C2794 __attribute__((section(".sdata")));
extern void func_0018C4B0(u8*,int),func_00185490(u8*),func_00183D10(u8*);
extern int func_001757E0(u8*,int,int);
void func_002C7C20(u8*p,void*work_context){
 u8*work=work_context;
 ++p[7];func_0018C4B0(p,10);func_00185490(p);
 *(float*)(p+0x38)=*(float*)(p+0x430);p[0x20D]=0;*(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 if(p[0x269]!=3){
  p[0x1B5]=p[0x1B7]?52:48;p[0x1B2]=(*(u16*)(p+0x1C0)=0);*(int*)(p+0x1D8)=0;++D_004C2794->count[p[2]];
 }else{
  p[0x1B5]=66;p[0x1B2]=(*(u16*)(p+0x1C0)=0);*(int*)(p+0x1D8)=0;++D_004C2794->count[p[2]];
 }
 func_00183D10(p);work[2]=0;func_001757E0(p,21,1);
}
