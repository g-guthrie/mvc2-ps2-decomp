typedef unsigned char u8;
extern void func_001266A0(u8*,int,int),func_0015D010(u8*,const float*),func_0018C6E0(u8*);
extern int func_001757E0(u8*,int,int);
void func_00242E50(u8*p){
 float offset[3];
 func_001266A0(p,5,5);
 if(*(unsigned short*)(p+0x20E)&0x400){*(short*)(p+0x140)^=1;p[0x1E6]^=1;}
 offset[0]=-146.66665649414062f;offset[1]=188.57142639160156f;func_0015D010(p,offset);func_0018C6E0(p);
 p[0x1B4]=10;p[6]=0;p[7]=0;func_001757E0(p,15,0);
}
