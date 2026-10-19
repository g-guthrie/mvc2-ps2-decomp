#include "runtime_object_storage.h"

void func_004007A0(RuntimeObjectStorage *object, int count)
{
    if (count < 0) {
        int bytes = object->byte_length;
        int sectors = bytes / 2048;
        int remainder = bytes - sectors * 2048;

        count = sectors + 1;
        object->sector_count = sectors;
        if (remainder <= 0)
            return;
    }
    object->sector_count = count;
}
