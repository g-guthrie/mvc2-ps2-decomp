typedef signed char s8;

extern const char D_004BE2F8[];
extern void func_0040D5A0(const char *message);

s8 func_0040D178(const s8 *object)
{
    if (object == 0) {
        func_0040D5A0(D_004BE2F8);
        return -1;
    }

    return object[1];
}
