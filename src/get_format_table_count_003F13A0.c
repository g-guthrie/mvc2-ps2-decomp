typedef unsigned int u32;
typedef signed int s32;

extern u32 *func_003F1530(void *file);

s32 func_003F13A0(void *file)
{
    u32 *header = func_003F1530(file);
    s32 count = header[1];

    if ((header[0] & 0x80000000u) != 0)
        count--;
    return count;
}
