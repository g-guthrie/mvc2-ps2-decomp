/* Metrowerks 3.0.3 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;

extern void *func_003DA750(void *, s32, s32);
extern void func_00357C40(u8 *);

void func_00357700(u8 *p)
{
    s8 i = 0;
    s8 n = 11;
    u8 *o;
    while ((s8)i < 11) {
        o = func_003DA750(p, 1, 2);
        if (o != 0) {
            u16 code;
            *(void (**)(u8 *))(o + 0x10) = func_00357C40;
            o[0x20] = 1;
            code = 0x903;
            o[0x21] = p[0x21];
            o[6] = n;
            *(u8 **)(o + 0x18) = *(u8 **)(p + 0x18);
            *(u8 **)(o + 0x14) = p;
            o[1] = p[1];
            *(u16 *)(o + 0x26) = code;
            n--;
        }
        i = (s8)(i + 1);
    }
}
