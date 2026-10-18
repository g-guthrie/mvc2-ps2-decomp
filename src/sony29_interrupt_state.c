typedef unsigned int u32;
extern u32 D_004C8640;
extern int func_0010F148(int);
extern int func_0010CA20(void);
extern void func_0010CA68(void);
u32 func_0010E670(u32 value){u32 old;int enabled;if(func_0010F148(1))return 0;enabled=func_0010CA20();old=D_004C8640;D_004C8640=value;if(enabled)func_0010CA68();return old;}

extern void func_0010CFD0(void);
extern void func_00103A00(int);
void func_0010D090(int value){func_0010CFD0();func_00103A00(value);}
