typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *func_003F19B0(u8 *file, s32 index);
extern u32 *func_003F1F90(u8 *header, u32 tag);

s32 func_003F1E10(u8 *file, s32 index)
{
    u8 *header;
    u32 *entry;

    header = func_003F19B0(file, index);
    if (header[0] != 2)
        return 0;
    entry = func_003F1F90(header, 0x200);
    if (entry == 0)
        return 0;
    return entry[1];
}
