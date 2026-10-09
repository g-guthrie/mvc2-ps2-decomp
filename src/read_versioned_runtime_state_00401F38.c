typedef signed char s8;
typedef signed int s32;

extern const char D_004BC0F8[];
extern const char D_004BC0C8[];
extern void func_003FB128(const char *message);
extern s32 func_003FFF90(void *handle);
extern s32 func_003FFF78(void *handle);

s32 func_00401F38(s8 *object)
{
    if (object == 0) {
        func_003FB128(D_004BC0F8);
        return -1;
    }
    if (object[1] >= 2)
        return func_003FFF90(*(void **)(object + 4));
    return 0;
}

s32 func_00401EE8(s8 *object)
{
    if (object == 0) {
        func_003FB128(D_004BC0C8);
        return -1;
    }
    if (object[1] >= 2)
        return func_003FFF78(*(void **)(object + 4));
    return 0;
}
