typedef signed char s8;
typedef signed int s32;

extern s32 func_0040C070(s32 value);

s32 func_0040C088(s32 first, s32 second)
{
    s8 first_byte = (s8)first;
    s8 second_byte = (s8)second;
    s32 first_normalized = func_0040C070(first_byte);
    s32 second_normalized = func_0040C070(second_byte);

    return first_normalized != second_normalized ? -1 : 0;
}
