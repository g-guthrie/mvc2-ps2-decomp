typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
typedef float f32;

extern s32 func_00175700(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);
extern s32 func_00185980(u8 *);
extern void func_001266A0(u8 *, s32, s32);
extern void func_00185770(u8 *, u8 *);
extern void func_0015D010(u8 *, const f32 *);
extern void func_001E3210(u8 *, s32);

void func_0020DFA0(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);

    if ((s8)p[0x1B2] != 0) {
        *(s16 *)(p + 0x1C) = 1;
        if (func_00185980(p) != 0) {
            f32 position[3];
            func_001266A0(p, 8, 8);
            {
                u32 count = p[6];
                p[6] = count + 2;
            }
            p[0x20B] = 0xC2;
            func_00185770(p, *(u8 **)(p + 0x1C4));
            p[0x1B4] = 10;
            position[0] = -96.66666412353515625f;
            position[1] = 128.5714263916015625f;
            position[2] = 0.0f;
            func_0015D010(p, position);
            func_001E3210(p, 5);
            func_001757E0(p, 0xF, 5);
            return;
        }
    }

    {
        s16 timer = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = timer;
        if (timer != 0) return;
    }

    {
        u32 count = p[6];
        p[6] = count + 1;
    }
    p[0x40D] = 0;
    p[0x40C] = 0;
    p[0x33B] = 0;
    p[0x33C] = 0;
    {
        f32 velocity;
        if (p[0x1E6] != 0)
            velocity = 11.6666660308837890625f;
        else
            velocity = -11.6666660308837890625f;
        *(f32 *)(p + 0x5C) = velocity;
        if (p[0x1E6] != 0)
            velocity = -0.208333328366279602f;
        else
            velocity = 0.208333328366279602f;
        *(f32 *)(p + 0x68) = velocity;
    }
    func_001757E0(p, 0x16, 0x1F);
}
