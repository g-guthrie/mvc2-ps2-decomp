typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;

extern void func_0019D7C0(u8 *, u8 *);
extern void func_0019DAE0(u8 *, u8 *);

void func_0019D970(u8 *p, u8 *q)
{
    u8 *o = *(u8 **)(p + 0x18);
    if (o[0] != 0 && q[5] == 0) {
        *(s8 *)(p + 0x24) = (s8)q[0x24] + (s8)p[0x31];
        if (*(s8 *)(p + 0x24) > 7) {
            *(s8 *)(p + 0x24) = 7;
        }
        if (*(s8 *)(p + 0x24) < 0)
            *(s8 *)(p + 0x24) = 0;
        if (p[0x20] == 0) {
            if ((s8)q[0x1B4] == 0) {
                if (p[0x21] != 0 && q[0x20D] != 2) {
                    p[0x21] = 0;
                    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
                }
                {
                    s16 ang = *(s16 *)(p + 0x1C) + 0x4000;
                    *(s16 *)(p + 0x1C) = ang;
                    if (ang == 0)
                        func_0019D7C0(p, q);
                }
            }
        } else {
            if ((s8)q[0x1B4] == 0) {
                {
                    s16 t = *(s16 *)(p + 0x1E) - 1;
                    *(s16 *)(p + 0x1E) = t;
                    if (t == 0)
                        goto fail;
                }
            }
            if (*(s16 *)(p + 0x1E) < 0x10)
                *(s16 *)(p + 0x13E) = *(s16 *)(q + 0x13E) + 5;
            if (*(s16 *)(p + 0x1E) < 6)
                *(s8 *)(p + 0x13C) = *(s8 *)(p + 0x13C) ^ 1;
        }
        if (*(s32 *)(q + 0x2DC) > 0)
            return;
    }
fail:
    func_0019DAE0(p, q);
}
