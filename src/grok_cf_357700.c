typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

extern u8 *func_003DA750(u8 *, s32, s32);
extern void func_00357C40(void);

void func_00357700(u8 *p)
{
    s8 i;
    s8 n = 11;
    for (i = 0; (s8)i < 11; i = (s8)(i + 1)) {
        u8 *o = func_003DA750(p, 1, 2);
        if (o != 0) {
            s16 code = 0x903;
            *(void **)(o + 0x10) = func_00357C40;
            o[0x20] = 1;
            o[0x21] = p[0x21];
            o[6] = n;
            n = (s8)(n - 1);
            *(u8 **)(o + 0x18) = *(u8 **)(p + 0x18);
            *(u8 **)(o + 0x14) = p;
            o[1] = p[1];
            *(s16 *)(o + 0x26) = code;
        }
    }
}
