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

void func_002D3270(u8 *p)
{
    p[6]++;
    p[525] = 2;
    if (p[486] != 0)
        *(int *)(p + 92) = 0x41F00000;
    else
        *(int *)(p + 92) = 0xC1F00000;
    *(int *)(p + 104) = 0;
    *(int *)(p + 96) = 0x3E892492;
    *(int *)(p + 108) = 0xBF4DB6DB;
    p[437] = 51;
    p[434] = *(unsigned short *)(p + 448) = 0;
    *(int *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 20, 2);
}

void func_002F5D50(u8 *p)
{
    p[6]++;
    p[525] = 2;
    *(int *)(p + 92) = 0x42055555;
    if (p[486] == 0)
        *(float *)(p + 92) = -*(float *)(p + 92);
    *(int *)(p + 104) = 0;
    *(int *)(p + 96) = 0;
    *(int *)(p + 108) = 0xBF3C9249;
    p[437] = 48;
    p[434] = *(unsigned short *)(p + 448) = 0;
    *(int *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 20, 2);
}

void func_002B6E10(u8 *p)
{
    p[6]++;
    func_00185490(p);
    func_00183D10(p);
    p[437] = 77;
    p[434] = *(unsigned short *)(p + 448) = 0;
    *(int *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 22, 4);
    *(int *)(p + 92) = 0;
    *(int *)(p + 96) = 0;
    *(int *)(p + 104) = 0;
    *(int *)(p + 108) = 0;
}

void func_002BB5A0(u8 *p)
{
    int command;
    p[6]++;
    func_00185490(p);
    *(float *)(p + 56) = *(float *)(p + 1072);
    p[525] = 0;
    *(int *)(p + 92) = 0;
    *(int *)(p + 96) = 0;
    *(int *)(p + 104) = 0;
    *(int *)(p + 108) = 0;
    func_0018C4B0(p, 10);
    func_00183D10(p);
    command = p[439] != 0 ? 32 : 14;
    func_001757E0(p, 21, (u8)command);
}
