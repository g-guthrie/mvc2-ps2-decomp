typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
extern void func_003DA650(u8),func_00146C80(int),func_001489E0(int,int),func_0041D9A0(void),func_003298B0(int,int,int);
extern u8 *func_0041D6E0(int);
extern void func_0041C2C0(int,int);
extern u8 D_004C2B58 __attribute__((section(".sdata")));
typedef struct {u8 p0[5];u8 b5;u8 b6;} A;
typedef struct {u8 p0[5];u8 b5;} B;
extern A *D_004C2B6C __attribute__((section(".sdata")));
extern B *D_004C2840 __attribute__((section(".sdata")));
extern void (*D_0043CD0C)(int,int);
void func_0041C220(int state,int mode)
{
 func_003DA650(13);func_00146C80(5);func_001489E0(19,11);
 D_004C2B6C=(A *)func_0041D6E0(D_004C2B58);
 func_0041D9A0();func_003298B0((int)0xff000000,10,0);
 D_004C2840->b5=0;
 D_0043CD0C=func_0041C2C0;
 D_0043CD0C(state,(u16)mode);
}
