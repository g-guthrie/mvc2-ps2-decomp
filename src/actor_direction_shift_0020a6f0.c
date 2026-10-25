typedef unsigned char u8;
typedef short s16;
extern void func_0034E160(void*,u8);
extern int func_001757E0(u8*,int,int);
void func_0020A6F0(u8 *p,void *context) {
 u8 *work=context;
 float dx;
 ++p[7];*(float*)(work+16)=*(float*)(p+0x34);*(float*)(work+20)=*(float*)(p+0x38);
 if(p[0x1E6])dx=640;else dx=-640;
 *(float*)(p+0x34)+=dx;p[0x1E6]^=1;*(s16*)(p+0x140)=p[0x1E6];work[4]=1;
 func_0034E160(p,5);*(s16*)(p+0x1C)=48;func_001757E0(p,10,1);
}
