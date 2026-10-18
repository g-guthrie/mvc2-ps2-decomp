typedef unsigned int u32;
typedef signed int s32;
extern s32 D_00496708[];
s32 func_00411B00(u32 index)
{
    u32 valid = index < 5;
    u32 offset = index << 2;
    u32 address = (u32)D_00496708 + offset;
    if (valid)
        return *(s32 *)address;
    return 0;
}
