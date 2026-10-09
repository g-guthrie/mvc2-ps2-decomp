typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_004959F0[];

s32 func_004105D8(const char *text)
{
    u32 hash;

    hash = (u32)D_004959F0[(s8)text[0]];
    hash = (hash << 4) + (u32)D_004959F0[(s8)text[1]];
    hash = (hash << 4) + (u32)D_004959F0[(s8)text[2]];
    hash = (hash << 4) + (u32)D_004959F0[(s8)text[3]];
    hash = (hash << 4) + (u32)D_004959F0[(s8)text[4]];
    hash = (hash << 4) + (u32)D_004959F0[(s8)text[5]];
    hash = (hash << 4) + (u32)D_004959F0[(s8)text[6]];
    return (s32)hash;
}
