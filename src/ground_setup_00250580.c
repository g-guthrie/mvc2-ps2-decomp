typedef unsigned char u8;
extern void func_00250940(u8*,int),func_0018C4B0(u8*,int),func_00185490(u8*),func_00183D10(u8*);
extern int func_001757E0(u8*,int,int);
void func_00250580(u8*p){
 ++p[7];func_00250940(p,0);func_0018C4B0(p,5);func_00185490(p);
 *(float*)(p+0x38)=*(float*)(p+0x430);p[0x20D]=0;
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 func_00183D10(p);func_001757E0(p,21,(u8)(p[0x1B7]+7));
}
