/* Compute the side-dependent jump target with a shared double-to-float rounding point. */
#pragma padloop on
typedef unsigned char u8;
extern float D_004F1F4C;
extern void func_0018C4B0(u8 *,int),func_00185490(u8 *),func_00183D10(u8 *),func_001266A0(u8 *,int,int);
extern int func_001757E0(u8 *,int,int);
void func_0020BC60(u8 *p,u8 *work)
{
 double target;
 float position;
 ++p[6];func_0018C4B0(p,4);func_00185490(p);
 p[0x20D]=0;
 *(float*)(p+0x38)=*(float*)(p+0x430);
 func_00183D10(p);func_001266A0(p,1,13);
 *(short*)(p+0x1C)=32;
 work[9]=0;work[10]=0;work[11]=2;
 if(p[0x1E6])target=D_004F1F4C-320.0-13.333333015441895;
 else target=13.333333015441895+(320.0+D_004F1F4C);
 position=target;
 *(float*)(p+0x5C)=(position-*(float*)(p+0x34))/32.0;
 *(float*)(p+0x68)=0;
 *(float*)(p+0x60)=p[0x1B7]?21.428569793701172f:12.857142448425293f;
 *(float*)(p+0x6C)=-0.5357142686843872f;
 func_001757E0(p,1,8);
}
