typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern s32 func_003FFF90(s32 handle);
extern void func_003FF270(s32 handle, s32 flag, s32 value);

void func_00403228(u8 *p)
{
    s16 v;
    s32 h = *(s32 *)(p + 12);
    if (func_003FFF90(*(s32 *)(p + 4)) == 1) {
        v = *(s16 *)(p + 0x42);
        if (v == -128)
            func_003FF270(h, 0, 0);
        else
            func_003FF270(h, 0, v);
        return;
    }
    v = *(s16 *)(p + 0x42);
    if (v == -128)
        func_003FF270(*(s32 *)(p + 12), 0, -15);
    else
        func_003FF270(*(s32 *)(p + 12), 0, v);
    v = *(s16 *)(p + 0x44);
    if (v == -128)
        func_003FF270(*(s32 *)(p + 12), 1, 15);
    else
        func_003FF270(*(s32 *)(p + 12), 1, v);
}
