typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_004C22C4;
extern s32 func_003FF190(void *);
extern s32 func_003FF1A8(void *);
extern s32 func_003FFFC0(void *);
extern s32 func_003FF5C8(s32);
extern void func_003FF160(s32, s32);
extern s32 func_00401F38(u8 *);
extern void func_0011D8F8(s32, s32, s32);

void func_00403900(u8 *p)
{
    s32 a = *(s32 *)(p + 0xC);
    s32 b = *(s32 *)(p + 4);
    s32 c;
    s32 d;
    c = func_003FF190((void *)a);
    d = func_003FF1A8((void *)a);
    if (!(c < *(s32 *)(p + 0x48) * 2) || !(func_003FFFC0((void *)b) < d) || func_003FF5C8(*(s32 *)(p + 4)) == 3) {
        if (*(s8 *)(p + 0x70) == 0) {
            if (*(s8 *)(p + 0x72) == 0) {
                func_003FF160(a, 1);
                *(s32 *)(p + 0x9C) = 0;
                *(s32 *)(p + 0xA0) = D_004C22C4;
            }
            p[1] = 3;
        }
        p[0x71] = 1;
    }
    if (func_003FF5C8(*(s32 *)(p + 4)) == 3) {
        s32 n;
        s32 m;
        s32 **q;
        s32 i;
        s32 *o;
        s32 sp[2];
        n = func_00401F38(p);
        m = *(s32 *)(p + 0x48) * n * 2;
        if (n > 0) {
            q = (s32 **)(p + 0x18);
            i = n;
            do {
                o = *q;
                q++;
                (*(void (**)(s32 *, s32, s32, s32 *))(*(s32 *)o + 0x18))(o, 0, m, sp);
                func_0011D8F8(sp[0], 0, sp[1]);
                (*(void (**)(s32 *, s32, s32 *))(*(s32 *)o + 0x20))(o, 1, sp);
            } while (--i != 0);
        }

    }
}
