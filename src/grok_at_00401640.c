typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern void func_003FF5D0(s32 handle, s32 value);
extern void func_003FF628(s32 handle);
extern s32 D_004C2274;

void func_00401640(u8 *p, s32 value)
{
    s32 i;
    s8 n = (s8)p[3];
    u8 **items;
    if (n > 0) {
        items = (u8 **)(p + 24);
        i = 0;
        do {
            u8 *o = items[i];
            (*(void (**)(u8 *))(*(s32 *)o + 20))(o);
            i++;
        } while (i < (s8)p[3]);
    }
    func_003FF5D0(*(s32 *)(p + 4), value);
    *(s32 *)(p + 20) = value;
    func_003FF628(*(s32 *)(p + 4));
    p[1] = 1;
    p[0x71] = 0;
    *(s32 *)(p + 0x8C) = 0x7FFFFFFF;
    *(s32 *)(p + 0x90) = -1;
    *(s32 *)(p + 0xA0) = D_004C2274;
    *(s32 *)(p + 0x4C) = 0;
    *(s32 *)(p + 0x9C) = 0;
    *(s32 *)(p + 0xA4) = 0;
}
