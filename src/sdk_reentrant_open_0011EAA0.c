extern int D_00634300;
extern int func_001044A0(const char *path, int flags, int mode);
int func_0011EAA0(void *context, const char *path, int flags, int mode)
{
 int *error=context;
 int result;
 D_00634300=0;
 result=func_001044A0(path,flags,mode);
 if(result==-1 && D_00634300!=0) *error=D_00634300;
 return result;
}
