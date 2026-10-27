typedef unsigned short u16; typedef int s32;
extern u16 func_0012ABC0(s32, s32);
extern s32 func_00131720(void);
extern void func_001E3CE0(s32), func_0041C7D0(s32, s32);
extern void (*D_0043CD0C)(s32, s32);
extern float D_004C2B64 __attribute__((section(".sdata")));
extern float D_004C2B68 __attribute__((section(".sdata")));
extern float D_004C2B5C __attribute__((section(".sdata")));
extern float D_004C2B60 __attribute__((section(".sdata")));
void func_0041C890(s32 a, s32 b) {
 float dx=0.0f,dy=0.0f,x,y;
 u16 buttons=func_0012ABC0(3,1);
 if(buttons & 0x2000) dy=2.0f;
 if(buttons & 0x1000) dy=-2.0f;
 if(buttons & 0x0800) dx=2.0f;
 if(buttons & 0x0400) dx=-2.0f;
 x=dx+D_004C2B64;
 if(x > -750.0f && x < 750.0f) D_004C2B64=x;
 y=dy+D_004C2B68;
 if(y > -600.0f && y < 600.0f) D_004C2B68=y;
 D_004C2B5C=D_004C2B64;
 D_004C2B60=D_004C2B68;
 if(func_00131720()) {func_001E3CE0(3);D_0043CD0C=func_0041C7D0;D_0043CD0C(a,b);}
}
