#pragma padloop on
typedef unsigned char u8;
extern float D_004F1FE8;
extern void func_002BD610(u8*,u8*);
extern int func_001757E0(u8*,int,int);
int func_002BD330(u8 *p,u8 *work)
{
 if(p[0x22]==24)return 0;
 if(*(float*)(p+0x38)<(float)(240.0+(double)D_004F1FE8-137.14285278320312))return 0;
 p[7]=1;func_002BD610(p,work);*(float*)(work+8)=-137.14285278320312f;func_001757E0(p,22,1);return 1;
}
