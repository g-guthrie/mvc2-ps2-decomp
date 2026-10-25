/* Select the initial animation by actor type and record the random branch. */
#pragma padloop on
typedef unsigned char u8;
extern int func_00174170(void),func_001757E0(u8 *,int,int);
extern void func_001266A0(u8 *,int,int);
void func_00235180(u8 *p,u8 *work)
{
 ++p[6];
 switch(p[0x20]){
 case 0:
  if((p[0x21]=func_00174170()&1)==0)func_001757E0(p,19,0);
  else{work[0x39]=0;func_001757E0(p,19,1);func_001266A0(p,1,13);}
  break;
 case 2:func_001757E0(p,19,2);break;
 case 1:case 3:case 4:func_001757E0(p,19,3);break;
 }
}
