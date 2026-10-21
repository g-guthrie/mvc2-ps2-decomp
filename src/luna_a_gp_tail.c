#include "runtime_resource_record.h"
typedef unsigned int u32;

/* Preserve the existing ordered shared-address snapshot reads. */
extern u32 *volatile D_004C28AC;
extern void *volatile D_004C28B8;
extern volatile u32 D_004C280C;

void func_00170140(void) {
    int arg0;
    u32 arg1;
    u32 arg2;
    u32 arg3;
    int arg4;

    arg2 = (u32)D_004C28AC;
    arg0 = 0xD10;
    arg3 = (u32)D_004C28B8;
    arg4 = 6;
    arg1 = (u32)D_004C280C;
    func_0016F5B0(arg0, arg1, (u32 *)arg2, (ResourceRecord *)arg3, arg4, 0);
}
