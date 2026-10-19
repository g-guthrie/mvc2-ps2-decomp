#include "runtime_object_storage.h"

typedef signed char s8;
typedef signed int s32;

extern void func_003F9630(void);
extern void func_00400AD0(void *entry);
extern void func_003F9660(void);

void func_00400AF8(void)
{
    s32 i;
    RuntimeObjectStorage *entry;

    func_003F9630();
    entry = gRuntimeObjectPool_00484AC0;
    for (i = 39; i >= 0; i--) {
        if (entry->active == 1)
            func_00400AD0(entry);
        entry++;
    }
    func_003F9660();
}
