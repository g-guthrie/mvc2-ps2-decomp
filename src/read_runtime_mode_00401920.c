typedef signed char s8;
typedef signed int s32;

extern const char D_004BC048[];
extern void func_003FB128(const char *message);

s32 func_00401920(s8 *object)
{
    if (object == 0) {
        func_003FB128(D_004BC048);
        return -1;
    }
    return object[1];
}
