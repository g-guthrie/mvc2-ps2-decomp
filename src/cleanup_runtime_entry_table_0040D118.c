typedef signed char s8;
typedef signed int s32;

extern s8 D_00489818[];
extern void func_0040DA50(void *entry);

void func_0040D118(void)
{
    s8 *entry = D_00489818;
    s32 index = 15;

    do {
        if (entry[0] == 1)
            func_0040DA50(entry);
        entry += 1080;
    } while (--index >= 0);
}
