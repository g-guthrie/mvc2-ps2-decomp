typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern s8 func_00175700(u8 *);
extern void func_00220F50(u8 *);
extern s16 func_00220260(u8 *);
extern void func_00220E40(u8 *);
extern void func_001E3210(u8 *, int);

void func_00220D50(u8 *p)
{
    u8 *sub = p + 0x2B8;
    u16 m;

    if ((s8)func_00175700(p) >= 0) {
        if (*(u16 *)(p + 0x362) & 0x360)
            p[7] = 1;
        return;
    }
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    if (*(s8 *)(p + 0x539) == 0) {
        if (p[7] == 0) {
            func_00220F50(p);
            return;
        }
        m = *(u16 *)(p + 0x35E);
    } else
        m = *(u16 *)(sub + 0x2A);
    m = (u16)(m & 0x3C00);
    if (m) {
        s16 r;
        p[6]++;
        *(u16 *)(sub + 0x24) = 0x10;
        r = func_00220260(p);
        *(u16 *)(sub + 0x1C) = r;
        func_00220E40(p);
        func_001E3210(p, 0x22);
    } else
        func_00220F50(p);
}
