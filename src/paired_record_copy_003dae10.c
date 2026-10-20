typedef signed short s16;
typedef signed int s32;
extern s16 D_0058EEF0[];
extern s16 D_0058EF14[];
extern s16 D_0058EF16[];
extern s16 D_0058EF18[];
extern void func_003ED8E0(s32, s16, s16, s16);

void func_003DAE10(s16 *src, s32 index)
{
    s32 count;
    s16 first;
    s16 second;
    s16 *dst = D_0058EEF0 + index * 22;
    count = 11;
    do {
        first = src[0];
        count--;
        second = src[1];
        src += 2;
        dst[0] = first;
        dst[1] = second;
        dst += 2;
    } while (count > 0);
    func_003ED8E0(index,
                  D_0058EF14[index * 22],
                  D_0058EF16[index * 22],
                  D_0058EF18[index * 22]);
}
