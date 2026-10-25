/* Select the stage-edge movement branch and its follow-up callback. */
#pragma padloop on
typedef unsigned char u8;
extern float D_004F1FC8,D_004F1FCC;
extern void func_00175C00(u8 *,int),func_00176160(u8 *,int,int,int),func_0024AA60(u8 *),func_0024AB20(u8 *);
extern int func_001757E0(u8 *,int,int);
void func_0024A940(u8 *p)
{
 func_00175C00(p,0);func_00176160(p,5,0,1);
 *(float*)(p+0x38)=*(float*)(p+0x430);p[0x210]=0;p[0x20D]=0;
 if((!*(short*)(p+0x140) && *(float*)(p+0x34)>D_004F1FCC-320.0f) || (*(short*)(p+0x140) && *(float*)(p+0x34)<320.0f+D_004F1FC8)){
  ++p[7];
  if(!*(short*)(p+0x140))*(float*)(p+0x5C)=-6.666666507720947f;
  else *(float*)(p+0x5C)=6.666666507720947f;
  *(float*)(p+0x68)=0;*(float*)(p+0x60)=0;*(float*)(p+0x6C)=0;
  func_001757E0(p,0,2);func_0024AA60(p);
 }else{p[7]=2;func_0024AB20(p);}
}
