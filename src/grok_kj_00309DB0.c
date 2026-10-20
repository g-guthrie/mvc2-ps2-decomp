/* ./try.sh src/grok_kj_00309DB0.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

void func_00309DB0(u8 *p)
{
    extern void func_0030C470(u8 *);
    extern void func_003BA230(u8 *, s32, u8);
    extern void func_00309310(u8 *);
    u8 i;
    switch (p[0x1FC]) {
    case 2:
        if (*(s8 *)(p + 0x151) != 0) {
            if ((u8)*(s8 *)(p + 0x151) != 0x81)
                func_0030C470(p);
            p[0x151] = 0;
            for (i = 0; i < 3; i++)
                func_003BA230(p, 1, i);
        }
        break;
    case 1:
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            func_003BA230(p, 7, 0);
        }
        break;
    }
    func_00309310(p);
}
