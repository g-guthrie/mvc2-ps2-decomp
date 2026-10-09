typedef unsigned int u32;
typedef signed int s32;

extern void *func_0011D8F8(void *destination, s32 value, u32 size);

s32 func_00416A70(void)
{
    s32 value;

    func_0011D8F8(&value, 0, sizeof(value));
    return value;
}
