typedef signed char s8;
typedef signed int s32;

extern const char D_004BDBA8[];
extern void func_004098A8(s32 auxiliary, const char *message);

s8 func_0040A218(const s8 *object)
{
    if (object == 0) {
        func_004098A8(0, D_004BDBA8);
        return 0;
    }

    return object[2];
}
