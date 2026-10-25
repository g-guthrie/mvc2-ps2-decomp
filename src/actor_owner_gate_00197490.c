typedef unsigned char u8;
extern int func_00197860(u8*,u8*);
extern void func_00197470(u8*,u8*),func_00196E30(u8*,u8*);
void func_00197490(u8 *p,u8 *owner) {
 u8 *local=p+0x88;
 u8 *work=owner+0x2b8;
 if(func_00197860(p,owner)) {work[12]=0;local[0]=0;}
 else if(p[0x21]>0)func_00197470(p,owner);
 else func_00196E30(p,owner);
}
