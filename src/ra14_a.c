extern int D_004399A8;
extern int D_004399AC;
extern int D_004399A0;
extern int D_004399B0;
extern int D_00439994;
extern int D_004399D4;
extern int func_00103DF0(int);
extern int func_00103E00(int);
extern int func_0010CA20(void);
extern void func_0010CA68(void);
extern void func_00106270(unsigned int);

void func_0010EA40(void)
{
 int enabled;
 if(D_00439994){
  D_004399D4=-1;
  do{func_00103E00(D_004399A0);}while(0);
 }
 func_00103DF0(D_004399A8);
 func_00103DF0(D_004399AC);
 func_00103DF0(D_004399A0);
 enabled=func_0010CA20();
 func_00106270(0x80000012u);
 if(enabled)func_0010CA68();
}
