#include "actor_action_event.h"
typedef float f32;
extern void func_001E3710(u8 *,int);
extern void func_001E3210(u8 *,int);
extern u8 D_004BFF34[] __attribute__((section(".sdata")));
extern u8 D_004BFF38[] __attribute__((section(".sdata")));
extern u8 D_004BFF3C[] __attribute__((section(".sdata")));
#define F(p,n) (*(f32 *)((p)+(n)))
#define SELECT_EVENT(event) select_event(p,p[0x1B5],event)
void func_0021D7C0(u8 *p)
{
    switch(p[0x1FC]) {
    case 0:
        p[0x168]=0; p[0x1B5]=3;
        func_001E3710(p,20);
        *(u8 **)(p+0x408)=D_004BFF34; p[0x1BB]=0;
        break;
    case 1:
        p[7]=0; p[0x168]=1; p[0x1B5]=4;
        func_001E3710(p,21);
        func_001E3210(p,3);
        *(u8 **)(p+0x408)=D_004BFF38; p[0x1BB]=1;
        break;
    case 2:
        if (*(u16 *)(p+0x20E)&0x400) {
            p[7]=1;
            if (p[0x1E6]) {
                F(p,0x5C)=-5.0f; F(p,0x68)=0.1041666641831398f;
                F(p,0x34)+=-40.0f;
            } else {
                F(p,0x5C)=5.0f; F(p,0x68)=-0.1041666641831398f;
                F(p,0x34)+=40.0f;
            }
            F(p,0x38)+=66.4285659790039f;
            F(p,0x60)=15.0f; F(p,0x6C)=-1.741071343421936f;
            p[0x1B5]=19; p[0x168]=5;
            func_001E3210(p,4);
        } else if (*(u16 *)(p+0x20E)&0x800) {
            f32 x=-5.8333330154418945f, y=0.0520833320915699f;
            p[7]=2; p[0x168]=4; p[0x1B5]=20;
            F(p,0x5C)=x;
            F(p,0x68)=y;
            if (p[0x1E6]) {
                F(p,0x5C)=5.8333330154418945f; F(p,0x68)=-0.0520833320915699f;
            } else {
                F(p,0x5C)=x; F(p,0x68)=y;
            }
            F(p,0x60)=10.714284896850586f; F(p,0x6C)=-0.8035714030265808f;
            func_001E3210(p,4);
        } else {
            p[7]=0; p[0x168]=2; p[0x1B5]=5;
            func_001E3210(p,4);
        }
        func_001E3710(p,22);
        *(u8 **)(p+0x408)=D_004BFF3C; p[0x1BB]=2;
        break;
    }
    SELECT_EVENT(8);
}
