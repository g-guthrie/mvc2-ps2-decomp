#include "runtime_backend_types.h"
typedef unsigned int u32;
typedef signed int s32;

struct MenuNoticeData
{
    u32 words[8];
};

extern struct MenuNoticeData D_004A6F50;
extern s32 D_004C28B8;
extern struct BackendState *D_004C2840;
extern s32 func_0012E560(struct MenuNoticeData *data);
extern void func_00415020(s32 mode, struct MenuNoticeData *data);
extern void func_00152990(s32 value);
extern s32 func_003298B0(s32 value, s32 duration, s32 mode);
extern s32 func_00420400(void);

void func_004207C0(void)
{
    struct MenuNoticeData data = D_004A6F50;

    data.words[2] = D_004C28B8;
    if (func_0012E560(&data) != 0)
    {
        D_004C2840->selectedBackend++;
        func_00415020(0x910, &data);
        func_00152990((s32)func_00420400);
        func_003298B0(-1, 30, 0);
    }
}
