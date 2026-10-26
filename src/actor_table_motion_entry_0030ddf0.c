typedef unsigned char u8;typedef unsigned short u16;typedef short s16;
typedef struct {u8 pad[0x7C];s16 count[2];} Counters;
extern Counters *D_004C2794 __attribute__((section(".sdata")));extern u8 D_004C1658[] __attribute__((section(".sdata")));extern float D_0045D1E0[];
extern void func_00185490(u8*),func_0018C4B0(u8*,int),func_00183D10(u8*),func_00176160(u8*,int,int,int);
extern int func_001757E0(u8*,int,int);
void func_0030DDF0(u8*p) {
 float vx,ax;float *v;
 ++p[6];func_00185490(p);func_0018C4B0(p,5);
 if(p[0x20D]!=2) {p[0x20D]=0;func_00183D10(p);}
 v=&D_0045D1E0[p[0x1B7]*2];vx=v[0];ax=v[1];
 if(p[0x1E6]) {vx=-vx;ax=-ax;}
 *(float*)(p+0x5C)=vx;*(float*)(p+0x68)=ax;*(float*)(p+0x60)=0;*(float*)(p+0x6C)=0;
 func_00176160(p,1,20,1);
 p[0x1B5]=D_004C1658[p[0x1B7]*2];p[0x1B2]=*(u16*)(p+0x1C0)=0;*(int*)(p+0x1D8)=0;
 ++D_004C2794->count[p[2]];func_001757E0(p,21,p[0x1B7]);
}
