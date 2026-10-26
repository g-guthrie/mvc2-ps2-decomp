typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern s32 D_00449F00[][6],D_00449F04[][6],D_00449F08[][6],D_00449F0C[][6],D_00449F10[][6],D_00449F14[][6];
extern void func_00197600(void);
extern int func_00417A40(void);
extern int func_00175580(u8*,int,int,int);
void func_00195F60(u8 *p,u8 *q) {
 u8 *work=p+0x88;float vx,ax,extraAx;
 ++p[5];func_00197600();*(s16*)(p+0x140)=*(s16*)(q+0x140);
 *(float*)(p+0x34)=*(float*)(q+0x34);*(float*)(p+0x38)=120.0f+*(float*)(q+0x38);
 vx=(float)D_00449F00[p[0x21]][0];
 *(float*)(p+0x60)=(15.0f/7.0f)*(float)D_00449F04[p[0x21]][0]/65536.0f;
 ax=(float)D_00449F08[p[0x21]][0];extraAx=(float)D_00449F0C[p[0x21]][0];
 *(float*)(p+0x6C)=(15.0f/7.0f)*(float)D_00449F10[p[0x21]][0]/65536.0f;
 *(float*)(work+0x14)=(15.0f/7.0f)*(float)D_00449F14[p[0x21]][0]/65536.0f;
 if(*(s16*)(p+0x140)==0){vx=-vx;ax=-ax;extraAx=-extraAx;}
 *(float*)(p+0x5C)=(5.0f/3.0f)*vx/65536.0f;
 *(float*)(p+0x68)=(5.0f/3.0f)*ax/65536.0f;
 *(float*)(work+0x10)=(5.0f/3.0f)*extraAx/65536.0f;
 *(s16*)(p+0x1C)=60;func_00175580(p,27,8,func_00417A40()&3);
}
