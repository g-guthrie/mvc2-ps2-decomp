typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef float f32;

extern s8 func_00175700(u8 *);
extern u8 *func_0034B070(u8 *, int);
extern u8 *func_0034B5A0(u8 *, int);
extern void func_00198690(u8 *, int, int);

void func_00206380(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x33C] = 5;
    {
        s16 t = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = t;
        if ((s8)t < 0) {
            func_00175700(p);
            if ((s8)p[0x151] != 0) {
                p[6]++;
                p[0x151] = 0;
                p[0x1B2] = 0;
                {
                    s16 n = *(s16 *)(p + 0x1C) + 1;
                    *(s16 *)(p + 0x1C) = n;
                    if ((s8)n < 4) {
                        int i;
                        u8 *s;
                        *(s16 *)(p + 0x1E) = 0x60;
                        s = func_0034B5A0(p, p[0x1C]);
                        if (s != 0) {
                            int k = 0;
                            for (i = 0; i < 4; i++, k += 0x20)
                                func_00198690(s, 2, k & 0xFF);
                        }
                    } else {
                        u8 *s;
                        p[0x40D] = 0;
                        p[0x40C] = 0;
                        p[0x33B] = 0;
                        p[0x33C] = 0;
                        *(s16 *)(p + 0x1E) = 0;
                        s = func_0034B070(p, 2);
                        if (s != 0) {
                            u8 *o = *(u8 **)(p + 0x14);
                            if (o == 0)
                                o = *(u8 **)(p + 0x220);
                            *(f32 *)(s + 0x34) = *(f32 *)(o + 0x34);
                            s[0x22] = 0;
                            if ((s8)p[0x539] == 0) {
                                if (*(u16 *)(p + 0x354) & 0x8000)
                                    s[0x22] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
