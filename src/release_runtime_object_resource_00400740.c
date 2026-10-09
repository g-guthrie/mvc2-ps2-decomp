typedef signed char s8;
typedef signed int s32;

extern void func_00406A30(s32 handle);

void func_00400740(s8 *object)
{
    object[1] = 1;
    if (object[2] == 1) {
        s32 handle = *(s32 *)(object + 8);
        if (handle != 0) {
            func_00406A30(handle);
            object[2] = 0;
        }
    }
}
