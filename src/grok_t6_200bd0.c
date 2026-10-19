/* Metrowerks 3.0: ./try.sh src/grok_t6_200bd0.c "-O3 -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00198100(u8 *, int);
extern void func_00190D50(u8 *, u8 *);
extern void func_0018FDB0(u8 *);
extern void func_00200990(u8 *);

void func_00200BD0(u8 *p)
{
    u8 *q;
    u8 st;
    q = p + 0x2B8;
    if (func_00175700(p) < 0) {
        q[0xE] = 0;
        p[7]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(f32 *)(p + 0x5C) = 0;
        *(f32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x42092492;
        *(u32 *)(p + 0x6C) = 0xBF092492;
        func_001757E0(p, 0x16, 0xD);
        return;
    }
    {
        st = p[0x151];
        if (st == 0)
            return;
        p[0x151] = 0;
        if ((st & 0xFF) == 0x3E) {
            u8 *s;
            func_00198100(p, 0);
            s = *(u8 **)q;
            *(u8 **)(s + 0x1C8) = p;
            s[0x1B5] = st;
            *(s16 *)(s + 0x140) = *(s16 *)(p + 0x140);
            s[0x20A] = 0x11;
            s[0x20D] = 2;
            func_00190D50(s, p);
            func_00190D50(s, p);
        } else {
            u8 *s = *(u8 **)q;
            *(u8 **)(s + 0x1C8) = p;
            p[0x1B5] = st;
            s[0x1B5] = st;
            func_0018FDB0(p);
            func_00190D50(s, p);
            func_0018FDB0(p);
            func_00190D50(s, p);
        }
        func_00200990(p);
    }
}
