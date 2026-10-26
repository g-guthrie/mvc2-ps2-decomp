typedef unsigned char u8;typedef signed char s8;
extern void func_001266A0(u8*,int,int),func_0015D010(u8*,const float*),func_0018C6E0(u8*);
extern int func_001757E0(u8*,int,int);
void func_00202400(u8*p){
 float position[3];
 if(*(unsigned short*)(p+0x20E)&0x400){*(s8*)(p+0x1E6)^=1;*(short*)(p+0x140)^=1;}
 p[0x1B4]=10;p[6]=0;func_001266A0(p,5,5);
 position[0]=-53.33333206176758f;position[1]=137.14285278320312f;func_0015D010(p,position);
 func_0018C6E0(p);func_001757E0(p,15,0);
}
