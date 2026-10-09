typedef unsigned char u8;
typedef unsigned int u32;

u32 func_003F5180(const u8 *object, u32 value)
{
    u32 alignment;

    if (object[5] == 0)
        alignment = 16;
    else
        alignment = 128;
    if (value % alignment != 0)
        value += alignment - ((value - (value / alignment) * alignment) % alignment);
    return value;
}
