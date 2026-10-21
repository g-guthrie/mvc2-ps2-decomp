#include "runtime_resource_record.h"
#include "runtime_backend_types.h"
typedef unsigned int u32;
typedef signed int s32;

extern ResourceRecordPair D_004A6F50;
extern void *D_004C28B8;
extern struct BackendState *D_004C2840;
extern s32 func_0012E560(void);
extern void func_00152990(s32 value);
extern s32 func_003298B0(s32 value, s32 duration, s32 mode);
extern s32 func_00420400(void);

void func_004207C0(void)
{
    ResourceRecordPair data = D_004A6F50;

    data.records[0].payload.data = D_004C28B8;
    if (func_0012E560() != 0)
    {
        D_004C2840->selectedBackend++;
        func_00415020(0x910, data.records);
        func_00152990((s32)func_00420400);
        func_003298B0(-1, 30, 0);
    }
}
