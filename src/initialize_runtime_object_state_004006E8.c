typedef unsigned char u8;
typedef signed int s32;

extern s32 func_004006A0(s32 *object);

s32 func_004006E8(u8 *object)
{
    if (*(s32 *)(object + 20) == 0) {
        *(s32 *)(object + 52) = 0;
        *(s32 *)(object + 12) = 0;
        object[1] = 3;
    } else {
        s32 value;
        *(s32 *)(object + 52) = 0;
        object[1] = 2;
        value = func_004006A0((s32 *)object);
        object[3] = 0;
        *(s32 *)(object + 12) = value;
    }
    return 1;
}
