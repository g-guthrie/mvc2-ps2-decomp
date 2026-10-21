#include "action_record.h"
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern Mvc2ActionRecord D_00455EF0[];
extern void func_0028D810(u8 *, u8 *);
extern int func_001757E0(u8 *, s32, s32);
extern s32 func_00175700(u8 *);
extern void func_00419FE0(u8 *, s32);
extern void func_0028CD30(u8 *);
extern void func_0028D8B0(u8 *);

void func_0028C8F0(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s16)(--*(s16 *)(p + 0x1C)) == 0) {
        p[6]++;
        func_0028D810(p, (u8 *)D_00455EF0);
        func_001757E0(p, 0x16, 4);
        return;
    }
    if (*(s16 *)(p + 0x1C) & 1)
        p[0x1B5] = 0x4C;
    else
        p[0x1B5] = 0x44;
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        func_00419FE0(p, 3);
        func_00419FE0(p, 4);
        func_00419FE0(p, 9);
        func_00419FE0(p, 10);
    }
    func_0028CD30(p);
    func_0028D8B0(p);
}
