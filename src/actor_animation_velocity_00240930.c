#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {
    u8 prefix[0x34];
    f32 x, y, z;
    u8 middle[0x1C];
    f32 vx, vy, vz, ax, ay;
} ActorMotion;

extern s32 func_00175700(u8 *);
extern void func_001A3A10(u8 *, u8, u8);
extern void func_001E3210(u8 *, s32);
extern void func_00186A20(u8 *);
extern f32 D_004528D0[];

void func_00240930(u8 *p)
{
    ActorMotion *motion = (ActorMotion *)p;
    u8 *velocityTable;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0)
        return;

    p[6]++;
    if (p[0x20D] != 2)
        func_001A3A10(p, 1, 0);

    {
        f32 displacement = -53.33333206176758f;
        if (p[0x1E6] != 0)
            displacement = -displacement;
        motion->x = motion->x + displacement;
    }

    velocityTable = (u8 *)D_004528D0;
    /* Valid selector callers provide p[0x1B7] < 2; this is not a global table bound. */
    if (p[0x20D] == 2)
        velocityTable += 0x10;
    velocityTable += (u32)p[0x1B7] * 8;
    motion->vx = *(f32 *)velocityTable;
    motion->vy = *(f32 *)(velocityTable + 4);
    motion->ax = 0.0f;
    motion->ay = -1.6071428060531616f;
    if (p[0x1E6] != 0)
        motion->vx = -motion->vx;

    func_001A3A10(p, 0, 0);
    func_001E3210(p, 0x14);
    func_00186A20(p);
}
