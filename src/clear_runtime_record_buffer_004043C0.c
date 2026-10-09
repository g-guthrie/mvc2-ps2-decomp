typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;

extern void *func_0011D8F8(void *destination, s32 value, u32 size);

void func_004043C0(void *buffer)
{
    if (buffer != 0) {
        *(u32 *)buffer = 0;
        func_0011D8F8(buffer, 0, 60);
    }
}

void func_00404488(u8 *object)
{
    *(u32 *)(object + 12) = 0;
    func_0011D8F8(object + 40, 0, 8);
}
