typedef struct {char pad[0x24]; int f24;} S6C;
extern S6C D_004C6CC0;
extern int D_00438318;
extern int func_00106C98(S6C *, unsigned, int);
int func_0010AC48(void){
 int i;int r;
 for(;;){ if(func_00106C98(&D_004C6CC0,0x80000003,0)<0)return -1; if(D_004C6CC0.f24!=0){D_00438318=0;r=0;break;} i=0x100000;do{ i--; asm volatile("nop"); }while(i!=-1); } return r;
}
