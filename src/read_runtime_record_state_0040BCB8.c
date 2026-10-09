typedef signed char s8;
typedef signed int s32;

extern const char D_004BE080[];
extern void func_0040AF58(s32 auxiliary, const char *message);

s8 func_0040BCB8(const s8 *object)
{
    if (object == 0) {
        func_0040AF58(0, D_004BE080);
        return 0;
    }

    return object[2];
}
