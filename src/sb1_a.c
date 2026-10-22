#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef int s32;
typedef struct { u8 prefix[0x1C]; s16 firstTimer; s16 secondTimer; } ActorTimersB;

extern void func_001E3210(u8 *, s32);
extern s32 func_00175700(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);
extern void func_002482C0(u8 *, u8 *);
extern void func_00248320(u8 *);
extern void func_00360530(u8 *, u8, u8);

void func_00246C70(u8 *p, u8 *context)
{
    ActorTimersB *timers = (ActorTimersB *)p;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (timers->firstTimer == 0x5A)
        func_001E3210(p, 0x15);
    func_002482C0(p, context);
    func_00175700(p);
    func_00248320(p);

    {
        s16 timer = timers->firstTimer;
        timers->firstTimer = timer - 1;
        if (timer == 0) {
            p[7]++;
            func_001757E0(p, 0x16, 8);
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            return;
        }
    }

    {
        s16 timer = timers->secondTimer;
        timers->secondTimer = timer - 1;
        if (timer != 0)
            return;
    }

    {
        s32 i = 10;
        timers->secondTimer = i;
        if (context[7] == 0)
            return;
        context[7]--;
        for (; i < 15; i++)
            func_00360530(p, 1, (u8)i);
    }
    func_001E3210(p, 0x1F);
}
