typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern const char D_004BC218[];
extern s32 func_003FB128(const char *message, s32 value);
extern s32 func_003FF258(s32 callback, s32 value);

s32 func_004020D8(void *object, s32 value)
{
    if (object == 0)
        return func_003FB128(D_004BC218, value);
    *(s16 *)((u8 *)object + 64) = value;
    return func_003FF258(*(s32 *)((u8 *)object + 12), value);
}
