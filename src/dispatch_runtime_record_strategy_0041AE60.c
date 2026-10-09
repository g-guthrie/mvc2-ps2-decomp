typedef unsigned char u8;
typedef signed int s32;

extern void func_0041AEA0(void *record, s32 value);
extern void func_0041AF70(void *record, s32 value);

void func_0041AE60(u8 *record)
{
    u8 mode = record[32];
    s32 value = *(s32 *)(record + 24);

    if (mode == 0)
        func_0041AEA0(record, value);
    else
        func_0041AF70(record, value);
}
