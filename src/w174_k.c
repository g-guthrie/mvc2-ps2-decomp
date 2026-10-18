typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0039E940(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_0039EF70(u8 *);
    extern void func_001E7F60(u8 *);
    s16 i;
    u8 v;
    u8 *n;
    s8 t;
    u8 *q;
    u8 *s;
    q = p[0x20] ? *(u8 **)(p + 0x14) : p;
    s = q + 0x88;
    if (q[0x96] != 0) return;
    p[0x1B3] = 0;
    if ((s8)func_00175700(p) < 0) {
        func_0039EF70(p);
        return;
    }
    if (p[0x20] == 0) {
        if (p[6] != 0) return;
        n = p;
        for (i = 0; i < *(u16 *)(s + 4); i++) {
            t = *(s8 *)(*(u8 **)(n + 0xC) + 0x1B2);
            if (t != 0) {
                v = t;
                n = p;
                for (i = 0; i < *(u16 *)(s + 4); i++) {
                    n[0x1B2] = v;
                    n = *(u8 **)(n + 0xC);
                }
                p[6]++;
            }
        }
    }
    func_001E7F60(p);
}
