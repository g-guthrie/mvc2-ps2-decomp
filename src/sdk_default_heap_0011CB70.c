typedef unsigned int u32;
extern void *D_0043B6F8;
extern void func_0011D9B8(void *context);
extern void func_0011DA38(void *context);
extern void *func_0011CE68(void *context, u32 size);
void *func_0011CB70(u32 size)
{
 void *result;
 func_0011D9B8(D_0043B6F8);
 result = func_0011CE68(D_0043B6F8, size);
 func_0011DA38(D_0043B6F8);
 return result;
}
extern void func_0011BAE0(void *context, void *memory);
void func_0011CBC8(void *memory)
{
 func_0011D9B8(D_0043B6F8);
 func_0011BAE0(D_0043B6F8, memory);
 func_0011DA38(D_0043B6F8);
}
