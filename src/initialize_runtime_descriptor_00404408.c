#include "runtime_decode_descriptor.h"
typedef signed int s32;

s32 func_00404408(RuntimeDecodeDescriptor *object, const void *first, s32 second, short *third)
{
    if (object->state == 0) {
        object->input = first;
        object->count = second;
        object->output = third;
        object->mode = 1;
        object->output2 = 0;
        return 1;
    }

    return 0;
}
