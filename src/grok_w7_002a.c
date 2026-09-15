typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))

extern void func_00175700(u8 *);
extern void func_00183D10(u8 *);
extern void func_00391650(u8 *, int);
extern void func_002AA0E0(u8 *);
extern void func_00394780(u8 *, int, int);
extern void func_00186A20(u8 *);

void func_002B0F60(u8 *p)
{
    s16 t;

    p[1036] = 2;
    p[828] = 5;
    t = S(p, 28);
    t = t + 1;
    S(p, 28) = t;
    t = S(p, 28) & 0xf;
    S(p, 28) = t;
    if (t == 0)
        func_00183D10(p);
    func_00175700(p);
}

void func_002A9DE0(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    func_002AA0E0(p);
    if (*(s8 *)(p + 353) & 1) {
        p[6]++;
        p[525] = 2;
        func_00394780(p, 8, 0);
    }
}

void func_002B5D10(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 337) == 0) {
        p[6]++;
        p[337] = 0;
        I(p, 92) = 0;
        I(p, 104) = 0;
        I(p, 96) = 0x42092492;
        I(p, 108) = 0xBF892492;
        func_00186A20(p);
    }
}

void func_002A5750(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 337) != 0) {
        p[6]++;
        p[337] = 0;
        func_00391650(p, 4);
        S(p, 28) = 104;
        S(p, 30) = 27;
    }
}
