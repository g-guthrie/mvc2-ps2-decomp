typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;

extern const char gPs2SystemText_004AA980[];
extern s32 func_00107E90(const char *, s32);
extern s32 func_001084D0(s32, void *, s32);
extern void func_00108118(s32);
extern s32 func_00119DA0(const char *);

s32 func_001004E0(void)
{
    s8 buffer[256];
    s32 handle = func_00107E90(gPs2SystemText_004AA980, 1);

    if (handle < 0)
        return -1;

    {
        u32 length = 0;
        s8 *cursor = buffer;

        for (; length < 256; ++length) {
            func_001084D0(handle, cursor, 1);
            if (*cursor == 0)
                break;
            cursor++;
        }

        func_00108118(handle);
        return func_00119DA0((const char *)(buffer + (length - 9))) > 0x01315670;
    }
}
