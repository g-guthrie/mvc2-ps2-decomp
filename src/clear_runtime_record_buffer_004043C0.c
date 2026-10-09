typedef unsigned int u32;
typedef signed int s32;

extern void *func_0011D8F8(void *destination, s32 value, u32 size);

void func_004043C0(void *buffer)
{
    if (buffer != 0) {
        *(u32 *)buffer = 0;
        func_0011D8F8(buffer, 0, 60);
    }
}
