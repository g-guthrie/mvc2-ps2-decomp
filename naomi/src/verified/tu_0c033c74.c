#pragma section Ctrl
#include "objects.h"
extern struct ActorFlags *dat_0c2d6f84;
extern struct Control_0c2fb1f0 dat_0c2fb1f0;
extern int dat_0c2fb208,dat_0c2fb1f8;
extern void func_0c1f35d0(int),func_0c035106(int);
extern void func_0c1f3240(int,int,int),func_0c1fa8b0(int,int);
void func_0c033c74(int value)
{
    if (dat_0c2d6f84->b67 || dat_0c2d6f84->i20!=64) {
        func_0c1f35d0(value);
        dat_0c2fb208=value;
        func_0c035106(value);
    }
}
void func_0c033ca6(int value)
{
    func_0c1f35d0(value);dat_0c2fb208=value;func_0c035106(value);
}
void func_0c033cbe(void)
{
    func_0c1f3240(0,0x100a0,0);
}
void func_0c033cc8(signed char value)
{
    func_0c1f3240(value,0x1100a0,0);
}
void func_0c033cd8(void)
{
    func_0c1f3240(0,0x300a0,0);
}
void func_0c033ce2(signed char a,unsigned char b)
{
    b &= 0x7f;
    func_0c1f3240(a,0x4a0,b);
}
void func_0c033d00(unsigned char value)
{
    value &= 0x7f;
    func_0c1fa8b0(dat_0c2fb1f8,value);
}
void func_0c033d16(int a,unsigned char b)
{
    b &= 0x7f;func_0c1f3240(a,0xaa0,b);
}
void func_0c033d2a(int a,unsigned char b)
{
    b &= 0x7f;func_0c1f3240(a,0x9a0,b);
}
void func_0c033d3e(register unsigned char value)
{
    float amount;
    value &= 0x7f;
    amount=(int)((int)dat_0c2fb1f0.i84 / value);
    dat_0c2fb1f0.values[0]-=amount;
    if (dat_0c2fb1f0.values[0]<0.0f) dat_0c2fb1f0.values[0]=0.0f;
    func_0c1f3240(0,0x1a0,(unsigned char)(int)dat_0c2fb1f0.values[0]);
}

#pragma section Ctrl
#include "objects.h"
extern struct Control_0c2fb1f0 dat_0c2fb1f0;
extern void func_0c1f3240(int,int,int);
void func_0c033db8(register unsigned char value)
{
    float amount;
    value &= 0x7f;
    amount=(int)((int)dat_0c2fb1f0.i84 / value);
    dat_0c2fb1f0.values[0]+=amount;
    if (dat_0c2fb1f0.values[0]>(float)(int)dat_0c2fb1f0.i84)
        dat_0c2fb1f0.values[0]=(float)(int)dat_0c2fb1f0.i84;
    func_0c1f3240(0,0x1a0,(unsigned char)(int)dat_0c2fb1f0.values[0]);
}
void func_0c033e0e(int channel,register unsigned char value)
{
    float amount;
    register struct Control_0c2fb1f0 *control=&dat_0c2fb1f0;
    value &= 0x7f;
    amount=(int)((int)control->i84 / value);
    control->values[(unsigned short)channel]-=amount;
    if (control->values[(unsigned short)channel]<0.0f)
        control->values[(unsigned short)channel]=0.0f;
    func_0c1f3240(channel,0x10a0,(unsigned char)(int)control->values[(unsigned short)channel]);
}
void func_0c033e6c(int channel,register unsigned char value)
{
    float amount;
    register struct Control_0c2fb1f0 *control=&dat_0c2fb1f0;
    value &= 0x7f;
    amount=(int)((int)control->i84 / value);
    control->values[(unsigned short)channel]+=amount;
    if (control->values[(unsigned short)channel]>(float)(int)control->i84)
        control->values[(unsigned short)channel]=(float)(int)control->i84;
    func_0c1f3240(channel,0x10a0,(unsigned char)(int)control->values[(unsigned short)channel]);
}
void func_0c033ed6(register unsigned char value)
{
    value &= 0x7f;
    dat_0c2fb1f0.f48=-(float)(int)((int)dat_0c2fb1f0.i84 / value);
}
void func_0c033ef8(register unsigned char value)
{
    value &= 0x7f;
    dat_0c2fb1f0.f48=(int)((int)dat_0c2fb1f0.i84 / value);
}

#pragma section Ctrl
extern int func_0c1fa450(int,int,int);
extern void func_0c1f3340(int,int,int,int);
void func_0c033f28(void)
{
    dat_0c2fb1f0.f44+=dat_0c2fb1f0.f48;
    if (dat_0c2fb1f0.f44>(float)(int)dat_0c2fb1f0.i84)
        dat_0c2fb1f0.f44=(float)(int)dat_0c2fb1f0.i84;
    if (dat_0c2fb1f0.f44<0.0f) dat_0c2fb1f0.f44=0.0f;
    func_0c033d00((int)dat_0c2fb1f0.f44);
}
void func_0c033f6c(void)
{
    dat_0c2fb1f8=1;func_0c1f3240(0,0x800a0,0);
}
void func_0c033f7c(void)
{
    dat_0c2fb1f8=0;func_0c1f3240(0,0x900a0,0);
}
void func_0c033f8e(void)
{
    unsigned int offset;
    for(offset=0;offset<sizeof(dat_0c2fb1f0.values);offset+=sizeof(float))
        *(float *)((char *)dat_0c2fb1f0.values+offset)=127.0f;
    dat_0c2fb1f0.i12=func_0c1fa450(1,1,0);
    dat_0c2fb1f0.f48=0.0f;dat_0c2fb1f0.f44=127.0f;dat_0c2fb1f0.i84=127;
}
void func_0c033fd0(int value)
{
    unsigned int offset;
    for(offset=0;offset<sizeof(dat_0c2fb1f0.values);offset+=sizeof(float))
        *(float *)((char *)dat_0c2fb1f0.values+offset)=(float)value;
    func_0c1f3340(1,16,0x27b0,value&0x7f);
    func_0c1f3340(2,16,0x27b0,value&0x7f);
    func_0c1f3340(3,16,0x27b0,value&0x7f);
    func_0c1f3340(4,16,0x27b0,value&0x7f);
    func_0c1f3340(5,16,0x27b0,value&0x7f);
    func_0c1f3340(6,16,0x27b0,value&0x7f);
    func_0c1f3340(7,16,0x27b0,value&0x7f);
    dat_0c2fb1f0.f44=(float)value;dat_0c2fb1f0.i84=value;
}
void func_0c034060(void)
{
    if (dat_0c2d6f84->b67==2) func_0c033fd0(95);
    else func_0c033fd0(127);
}
