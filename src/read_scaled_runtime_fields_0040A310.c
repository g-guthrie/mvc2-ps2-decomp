typedef unsigned char u8;
typedef signed int s32;
typedef signed long long s64;

s32 func_0040A310(const u8 *object)
{
    s64 value = *(const s32 *)(object + 20);
    value <<= 11;
    value &= 0xFFFFFFFFULL;
    return (s32)value;
}

s32 func_0040A350(const u8 *object)
{
    s64 value = *(const unsigned int *)(object + 4);
    value <<= 11;
    value &= 0xFFFFFFFFULL;
    return (s32)value;
}
