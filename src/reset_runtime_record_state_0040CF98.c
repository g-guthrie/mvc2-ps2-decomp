typedef signed char s8;
typedef unsigned char u8;
typedef signed int s32;

extern const char D_004BE2F8[];
extern void func_0040D5A0(const char *message);

void func_0040CF98(u8 *object)
{
    if (object == 0) {
        func_0040D5A0(D_004BE2F8);
        return;
    }

    if (((s8 *)object)[1] == 0) {
        *(s32 *)(object + 28) = 0;
        *(s32 *)(object + 32) = 0;
        *(s32 *)(object + 36) = 0;
    }
}
