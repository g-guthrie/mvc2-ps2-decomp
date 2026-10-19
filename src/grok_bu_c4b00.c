typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern void (*jtbl_0044CC10[])(u8 *);
extern void func_00175670(u8 *);

void func_001C4B00(u8 *p)
{
    u8 *q;
    s16 t;

    t = *(s16 *)(p + 0x1C);
    q = *(u8 **)(p + 0x18);
    t = t - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t == 0) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    if (t >= 0x3D) {
        if (p[1] != q[1] || q[4] >= 2) {
            p[4] = 2;
            p[5] = 0;
            p[0x13C] = 0;
            return;
        }
    }
    if (t >= 0x15) {
        u32 v;
        if (q[0x1E4] == 0x15) {
            v = q[0x1FD];
            if (v == 7 || v - 4 < 2u || v == 0xD) {
                p[5] = 5;
                *(s16 *)(p + 0x1C) = 0x14;
                return;
            }
        }
    }
    jtbl_0044CC10[4 + p[5]](p);
    func_00175670(p);
}
