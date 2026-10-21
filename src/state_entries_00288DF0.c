#include "action_record.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern void func_00175C00(void *, int);
extern void func_0028D810(u8 *, u8 *);
extern void func_0028D8B0(u8 *);
extern int func_001757E0(void *, int, int);
extern void func_00288E80(u8 *);
extern Mvc2ActionRecord D_00455D20[];

void func_00288DF0(u8 *p)
{
    p[7]++;
    func_00175C00(p, 0);
    func_0028D810(p, (u8 *)D_00455D20);
    func_0028D8B0(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x210] = 0;
    p[0x20D] = 0;
    func_001757E0(p, 0x13, 5);
    func_00288E80(p);
}
