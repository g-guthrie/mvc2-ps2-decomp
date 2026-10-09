typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern s32 *func_003F1540(u8 *file, u32 tag);

s32 func_003F1410(u8 *file, s32 index)
{
    s32 *entry = func_003F1540(file, 0);
    u32 *values;

    if (entry != 0 && (u32)index < (u32)entry[1]) {
        values = (u32 *)((u8 *)entry + 12);
        return values[index];
    }
    return -1;
}
