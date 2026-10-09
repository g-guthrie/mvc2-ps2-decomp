typedef signed char s8;
typedef unsigned int u32;

extern u32 D_004959F0[];

/* Decode the seven hexadecimal digits stored in an archive record. */
u32 func_004105D8(const char *text)
{
    u32 value;

    value = D_004959F0[(s8)text[0]];
    value = (value << 4) + D_004959F0[(s8)text[1]];
    value = (value << 4) + D_004959F0[(s8)text[2]];
    value = (value << 4) + D_004959F0[(s8)text[3]];
    value = (value << 4) + D_004959F0[(s8)text[4]];
    value = (value << 4) + D_004959F0[(s8)text[5]];
    value = (value << 4) + D_004959F0[(s8)text[6]];
    return value;
}
