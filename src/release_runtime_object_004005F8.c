#include "runtime_file_entry.h"
typedef unsigned char u8;
typedef signed int s32;

extern void func_00400740(signed char *object);
extern void func_00406818(RuntimeFileEntry *handle);
extern void *func_00400308(void *object);

void func_004005F8(u8 *object)
{
    if (object == 0)
        return;
    func_00400740((signed char *)object);
    if (*(RuntimeFileEntry **)(object + 8) != 0)
        func_00406818(*(RuntimeFileEntry **)(object + 8));
    func_00400308(object);
}
