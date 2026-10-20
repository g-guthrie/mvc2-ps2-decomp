/* Native bounded line buffer feeding the kernel DECI2 string operation. */
extern int D_00438260;
extern char D_004C3980[];
extern int func_00104FF8(char *);
void func_00105578(int character)
{
 int length=D_00438260;
 if(length>=126){
  D_00438260=0;
  D_004C3980[127]=0;
  func_00104FF8(D_004C3980);
  length=D_00438260;
 }
 if(character==10){
  D_00438260=0;
  D_004C3980[length]=character;
  D_004C3980[length+1]=0;
  func_00104FF8(D_004C3980);
 }else{
  D_00438260=length+1;
  D_004C3980[length]=character;
 }
}
