#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a684(struct Actor *, int, int, int);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c1b0b40(struct Actor *, int);
extern unsigned int func_0c02849a(void);
extern unsigned char dat_0c2f837e;
extern unsigned char table_0c2482a0[];

void func_0c0cfd40(struct Actor *a)
{
    if (!a->b6) {
        a->b6++;
        if (!dat_0c2f837e) a->b7 = 0;
        else { unsigned short m = a->w4dc & 0x360; if (m) { int r = 0; if (m & 0x200) r = 0; if (m & 0x100) r = 1; if ((m & 0x300) == 0x300) r = 3; if (m & 64) r = 0; if (m & 32) r = 1; if ((m & 96) == 96) r = 3; a->b7 = r; } else a->b7 = table_0c2482a0[func_0c02849a() & 7]; }
        func_0c02a0c4(a, 19, (signed char)a->b7);
        a->s28 = 0;
        func_0c02a684(a, 3, 11, 1);
    } else {
        func_0c02a026(a);
        if (a->b7 == 1) {
            if (a->s28 && --a->s28 <= 0) {
                func_0c0344a0(a, 19);
                a->s28 = 0;
            }
            a->b326 = 0xff;
            if (a->b141) {
                a->s28 = 60;
                a->b141 = 0;
                func_0c1b0b40(a, 14);
            }
        }
    }
}
