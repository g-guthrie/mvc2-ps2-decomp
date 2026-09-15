typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);

void func_003A6A80(u8 *p, u8 *q)
{
    u8 *r = q + 0x2B8;
    if (func_00175700(p) < 0) {
        p[5]++;
        r[3] = 1;
        I(p, 0x5C) = 0;
        I(p, 0x60) = 0;
        I(p, 0x68) = 0;
        I(p, 0x6C) = 0;
        U(p, 0x6C) = 0xBF092492;
    }
}

void func_003B2B50(u8 *p, u8 *q)
{
    u8 *r = q + 0x2B8;
    if (func_00175700(p) < 0) {
        p[5]++;
        r[3] = 1;
        I(p, 0x5C) = 0;
        I(p, 0x60) = 0;
        I(p, 0x68) = 0;
        I(p, 0x6C) = 0;
        U(p, 0x6C) = 0xBF092492;
    }
}

void func_0023C700(u8 *p)
{
    if (func_00175700(p) >= 0) {
        p[7]++;
        I(p, 0x5C) = 0;
        I(p, 0x60) = 0;
        I(p, 0x68) = 0;
        I(p, 0x6C) = 0;
        U(p, 0x6C) = 0xBF4DB6DB;
        p[0x210] = 2;
        p[0x169] = 0x15;
        p[0x168] = 0x0C;
        func_001757E0(p, p[0x169], p[0x168]);
    }
}

void func_0023D1F0(u8 *p)
{
    if (func_00175700(p) >= 0) {
        p[7]++;
        I(p, 0x5C) = 0;
        I(p, 0x60) = 0;
        I(p, 0x68) = 0;
        I(p, 0x6C) = 0;
        U(p, 0x6C) = 0xBF4DB6DB;
        p[0x210] = 2;
        p[0x169] = 0x15;
        p[0x168] = 0x0C;
        func_001757E0(p, p[0x169], p[0x168]);
    }
}


