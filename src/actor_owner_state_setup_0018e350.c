#pragma padloop on
typedef unsigned char u8;typedef short s16;
extern void *func_0011D8F8(void*,int,unsigned int);
extern void func_0018E6C0(u8*);
extern int func_001757E0(u8*,int,int);
void func_0018E350(u8*p,u8*owner) {
 u8 state;
 func_0011D8F8(p+0x370,0,8);
 p[0x24A]=120;p[0x247]=15;p[0x248]=0;p[0x1B7]=owner[0x1B7];
 state=p[0x23E]=5;
 if(state!=p[0x23F])p[0x23D]=0;
 p[0x23C]=5;
 if(p[0x20D]!=2)func_0018E6C0(p);
 else {*(s16*)(p+0x1C)=10;func_001757E0(p,13,16);}
}
