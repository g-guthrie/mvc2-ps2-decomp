extern int D_00634300;
extern int func_001044C8(int);
int func_00119E80(void *context, int descriptor)
{
 int *error = context;
 int result;
 D_00634300 = 0;
 result = func_001044C8(descriptor);
 if (result == -1 && D_00634300 != 0) *error = D_00634300;
 return result;
}
