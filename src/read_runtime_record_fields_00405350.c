typedef signed int s32;
typedef unsigned char u8;

void func_00405350(u8 *base, s32 index, s32 *first, s32 *second)
{
    if (first != 0)
        *first = *(s32 *)(base + index * 16 + 692);
    if (second != 0)
        *second = *(s32 *)(base + index * 16 + 696);
}
