typedef unsigned char u8;
typedef signed char s8;

extern u8 D_004C1268;
extern u8 D_004C1270;
extern u8 D_004C1278;
extern u8 D_004C1279;
extern u8 D_004C1280;
extern u8 D_004C1281;
extern void func_00186A60(u8 *, int);

void func_002F1E50(u8 *p)
{
    u8 v;

    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    v = p[1245];
    if (v == 2)
        v += p[724];
    p[509] = (&D_004C1268)[v];
    func_00186A60(p, 29);
}

void func_002F1EA0(u8 *p)
{
    u8 v;

    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    v = p[1245];
    if (v == 2)
        v += p[724];
    p[509] = (&D_004C1270)[v];
    func_00186A60(p, 29);
}

void func_002F1EF0(u8 *p)
{
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[509] = (&D_004C1278)[(s8)p[1245] * 2];
    p[439] = (&D_004C1279)[(s8)p[1245] * 2];
    func_00186A60(p, 21);
}

void func_002F1F40(u8 *p)
{
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[509] = (&D_004C1280)[(s8)p[1245] * 2];
    p[439] = (&D_004C1281)[(s8)p[1245] * 2];
    func_00186A60(p, 21);
}
