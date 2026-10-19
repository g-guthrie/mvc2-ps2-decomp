/* Metrowerks 3.0: ./try.sh src/grok_t6_2017c0.c "-O3 -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001266A0(u8 *, int, int);
extern void func_00198100(u8 *, int);
extern void func_00190D50(u8 *, u8 *);
extern void func_00200990(u8 *);
extern void func_0018FDB0(u8 *);

void func_002017C0(u8 *p)
{
    u8 *q = p + 0x2B8;
    if (((s8)func_00175700(p)) < 0) {
        p[7]++;
        func_001757E0(p, 0x16, 0x17);
        return;
    }
    {
        u8 st = p[0x151];
        p[0x151] = 0;
        if (st != 0) {
            if ((st & 0xFF) == 0x42) {
                u8 *s = *(u8 **)q;
                *(u8 **)(s + 0x1C8) = p;
                *(s16 *)(s + 0x140) = *(s16 *)(p + 0x140);
                s[0x20A] = 0x11;
                s[0x20D] = 2;
                s[0x1B5] = st;
                *(s8 *)(q + 0x10) = -1;
                func_001266A0(p, 0xC, 0xC);
                func_00198100(p, 0);
                func_00190D50(s, p);
                func_00190D50(s, p);
                func_00200990(p);
                return;
            } else {
                u8 *s = *(u8 **)q;
                *(u8 **)(s + 0x1C8) = p;
                p[0x1B5] = st;
                s[0x1B5] = st;
                func_0018FDB0(p);
                func_00190D50(s, p);
                func_0018FDB0(p);
                func_00190D50(s, p);
                func_00200990(p);
            }
        }
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)q[0x10] == 0) {
        u8 *s = *(u8 **)q;
        *(f32 *)(s + 0x38) = *(f32 *)(p + 0x38);
    }
}
