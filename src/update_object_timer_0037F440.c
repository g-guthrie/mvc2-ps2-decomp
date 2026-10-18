typedef signed char s8;
typedef signed short s16;
extern s8 *D_004C299C;
void func_0037F440(s8 *p)
{
    s16 value = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = value;
    if (value <= 0) {
        *(s16 *)(p + 0x1C) = 1;
        (*D_004C299C)--;
    }
}
