typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef float f32;

extern void func_001757E0(u8 *, int, int);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern u8 *D_004C2794;

void func_002AD6F0(u8 *p)
{
    f32 distance;
    f32 velocity;

    p[316] = 1;
    p[7]++;
    *(s16 *)(p + 28) = 32;
    *(f32 *)(p + 696) = *(f32 *)(p + 52);
    distance = 640.0f;
    velocity = 13.333333f;
    if (*(s16 *)(p + 320) != 0) {
        distance = -distance;
        velocity = -velocity;
    }
    *(f32 *)(p + 92) = velocity;
    *(f32 *)(p + 52) = *(f32 *)(p + 52) - distance;
    *(u32 *)(p + 108) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    func_001757E0(p, 18, 0);
}

void func_002F03F0(u8 *p)
{
    p[6]++;
    func_00185490(p);
    func_00183D10(p);
    p[437] = 53;
    p[434] = *(unsigned short *)(p + 448) = 0;
    *(int *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    func_001757E0(p, 20, 5);
}

void func_002E5F00(u8 *p)
{
    p[6]++;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    p[528] = 0;
    p[437] = 48;
    p[434] = *(unsigned short *)(p + 448) = 0;
    *(int *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_00185490(p);
    func_00183D10(p);
    func_00175C00(p, 0);
    func_001757E0(p, 21, p[439]);
}
