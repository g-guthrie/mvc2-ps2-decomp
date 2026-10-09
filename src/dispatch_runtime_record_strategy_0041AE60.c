typedef unsigned char u8;
typedef signed int s32;

extern s32 func_0041AEA0(void *record, s32 value);
extern s32 func_0041AF70(void *record, s32 value);

s32 func_0041AE60(u8 *record)
{
    u8 mode = record[32];
    s32 value = *(s32 *)(record + 24);
    s32 result;

    if (mode == 0)
        result = func_0041AEA0(record, value);
    else
        result = func_0041AF70(record, value);

    return result;
}
