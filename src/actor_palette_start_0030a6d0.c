typedef unsigned char u8;typedef short s16;
extern u8 *D_004C28DC __attribute__((section(".sdata")));
extern void func_00176160(u8*,int,int,int),func_001DB320(u8*);extern int func_001757E0(u8*,int,int);
void func_0030A6D0(u8*p){
 D_004C28DC=p+0x2B8;++p[6];p[0x13C]=1;
 *(float*)(p+0x38)=*(float*)(p+0x430)-381.428558349609375f;
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 *(float*)(p+0x60)=8.5714282989501953125f;*(s16*)(p+0x1C)=0;*(s16*)(p+0x1E)=4;
 if(p[0x25]&1){func_00176160(p,1,32,1);func_00176160(p,2,33,1);}
 else {func_00176160(p,1,35,1);func_00176160(p,2,36,1);}
 D_004C28DC[7]=0;func_001DB320(p);func_001757E0(p,18,0);
}
