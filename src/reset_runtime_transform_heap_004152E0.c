typedef unsigned int u32;
typedef signed int s32;
extern void *func_0011D8F8(void *destination, s32 value, u32 size);
extern s32 D_004C28A0;
extern unsigned char D_0056EE70[];

void *func_004152E0(void)
{
    D_004C28A0 = 0;
    return func_0011D8F8((void *)D_0056EE70, 0, 0xF700);
}
