typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
extern s16 D_0044A270[8][3],D_0044A272[8][3];
extern void func_00197600(void);
extern unsigned func_00417A40(void);
extern int func_00175580(u8*,int,int,int);
/* func_00194A20 constructs these actors with selectors 0 through 7. */
void func_00195490(u8 *p,u8 *q) {
 ++p[5];func_00197600();
 *(s16*)(p+0x140)=*(s16*)(q+0x140);
 *(float*)(p+0x34)=*(float*)(q+0x34);*(float*)(p+0x38)=*(float*)(q+0x38);
 if(*(s16*)(p+0x140))*(float*)(p+0x34)+=(5.0f/3.0f)*(float)D_0044A270[p[0x21]][0]/256.0f;
 else *(float*)(p+0x34)-=(5.0f/3.0f)*(float)D_0044A270[p[0x21]][0]/256.0f;
 *(float*)(p+0x38)+=(15.0f/7.0f)*(float)D_0044A272[p[0x21]][0]/256.0f;
 /* Native code stores the low byte of the row address, not its contents. */
 p[0x31]=(s8)(unsigned)&D_0044A270[p[0x21]][0];
 func_00175580(p,27,8,func_00417A40()&3);
}
