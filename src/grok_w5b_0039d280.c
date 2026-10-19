typedef unsigned char u8;
typedef signed short s16;

extern int func_0039C690(u8 *);
extern void func_0039D300(u8 *);

void func_0039D280(u8 *p)
{
    if (!func_0039C690(p)) {
        p[5]++;
        func_0039D300(p);
        return;
    }
    *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 1;
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
    if (*(s16 *)(p + 0x1C) == 0)
        p[5]++;
    func_0039D300(p);
}
