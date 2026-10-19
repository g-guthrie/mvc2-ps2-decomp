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

void func_00200BD0(u8 *s1)
{
    u8 *s2 = s1 + 0x2B8;
    u8 s0;
    if (func_00175700(s1) < 0) {
        s2[0xE] = 0;
        s1[7]++;
        *(f32 *)(s1 + 0x38) = *(f32 *)(s1 + 0x430);
        *(u32 *)(s1 + 0x5C) = 0;
        *(u32 *)(s1 + 0x68) = 0;
        *(u32 *)(s1 + 0x60) = 0x42092492;
        *(u32 *)(s1 + 0x6C) = 0xBF092492;
        func_001757E0(s1, 0x16, 0xD);
        return;
    }
    s0 = s1[0x151];
    if (s0 == 0)
        return;
    s1[0x151] = 0;
    if ((s0 & 0xFF) == 0x3E) {
        u8 *s;
        func_00198100(s1, 0);
        s = *(u8 **)s2;
        *(u8 **)(s + 0x1C8) = s1;
        s[0x1B5] = s0;
        *(s16 *)(s + 0x140) = *(s16 *)(s1 + 0x140);
        s[0x20A] = 0x11;
        s[0x20D] = 2;
        func_00190D50(s, s1);
        func_00190D50(s, s1);
    } else {
        u8 *s = *(u8 **)s2;
        *(u8 **)(s + 0x1C8) = s1;
        s1[0x1B5] = s0;
        s[0x1B5] = s0;
        func_0018FDB0(s1);
        func_00190D50(s, s1);
        func_0018FDB0(s1);
        func_00190D50(s, s1);
    }
    func_00200990(s1);
}
