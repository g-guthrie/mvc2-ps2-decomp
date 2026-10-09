typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *func_003F19B0(u8 *file, s32 index);
extern s32 *func_003F1F90(void *header, s32 tag);

s32 func_003F1E70(u8 *file, s32 index, u32 *output)
{
    u8 *header;
    s32 *entry;
    u32 *source;
    u32 outputOffset;

    header = func_003F19B0(file, index);
    if (header[0] != 2)
        return 0;
    entry = func_003F1F90(header, 0x200);
    if (entry == 0)
        return 0;
    source = (u32 *)(entry + 3);
    index = 0;
    outputOffset = 0;
    while ((u32)index < (u32)entry[1]) {
        *(u32 *)((u8 *)output + outputOffset) = *source;
        source++;
        outputOffset += 4;
        index++;
    }
    return 1;
}
