typedef unsigned char u8;typedef signed char s8;
extern void func_0015D010(u8*,const float*),func_001266A0(u8*,int,int),func_0018C6E0(u8*);
extern void func_001AFCB0(void*,u8);
extern int func_001757E0(u8*,int,int);
void func_0025B560(u8*p){
 float position[3];
 if(*(unsigned short*)(p+0x20E)&0x400){*(s8*)(p+0x1E6)^=1;*(short*)(p+0x140)^=1;}
 position[0]=-83.33332824707031f;position[1]=158.57142639160156f;func_0015D010(p,position);
 p[0x1B4]=10;func_001266A0(p,5,5);func_0018C6E0(p);func_001AFCB0(p,0);
 func_001757E0(*(u8**)(p+0x1DC),13,5);func_001757E0(p,15,0);
}
