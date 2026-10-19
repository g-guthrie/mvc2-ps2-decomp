#include "dispatch_state_6.h"

typedef unsigned int u32;
typedef signed short s16;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_0022C220(u8 *, u8 *);
extern void func_00185770(u8 *, u8 *);
extern void func_001E3710(u8 *, int);
extern void func_001266A0(u8 *, int, int);

void func_00229910(DispatchState_6 *state)
{
    u8 *p = (u8 *)state;

    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    {
        float *vy = (float *)(p + 0x60);
        float *ay = (float *)(p + 0x6C);

        *(float *)(p + 0x34) += *(float *)(p + 0x5C);
        *(float *)(p + 0x5C) += *(float *)(p + 0x68);
        *(float *)(p + 0x38) += *(float *)(p + 0x60);
        *(float *)(p + 0x60) += *(float *)(p + 0x6C);
        if (--*(s16 *)(p + 0x1C) == 0) {
            u8 *target;

            p[6] = 7;
            *vy = 0;
            *ay = 0;
            p[0x20D] = 2;
            target = *(u8 **)(p + 0x1C4);
            *(u32 *)(p + 0x2BC) = target[1];
            func_0022C220(p, target);
            p[0x20B] = 0xC0;
            func_00185770(p, target);
            func_001E3710(p, 0x23);
            func_001266A0(p, 5, 5);
            p[0x1B4] = 10;
            *(float *)(*(u8 **)(p + 0x1DC) + 0x38) += 51.42856979370117f;
            *(s16 *)(p + 0x1C) = 64;
            func_001757E0(p, 15, 0);
        }
    }
}
