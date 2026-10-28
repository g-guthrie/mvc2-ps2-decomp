typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#include "runtime_object_storage.h"
#include "runtime_file_entry.h"
extern char D_004BBF18[];

RuntimeObjectStorage *func_00400468(void *a, s32 b, s32 c)
{
    extern s32 func_00406B50(void *);
    extern s32 func_00406C10(void *, s32);
    extern RuntimeFileEntry *func_004064E8(void *, s32, s32);
    extern s32 func_00400658(s32 *, s32);
    extern void func_003FB178(s32, s32);
    RuntimeFileEntry *r; RuntimeObjectStorage *w; s32 v;
    if (b == 0) {
        v = func_00406B50(a);
    } else {
        v = func_00406C10(a, b);
    }
    r = func_004064E8(a, b, 0);
    if (r == 0) {
        func_003FB178((s32)(u32)D_004BBF18, (s32)(u32)a);
        return 0;
    }
    w = func_00400258((s32)(u32)r, 0, v, c);
    if (w != 0) func_00400658((s32 *)w, 0);
    return w;
}
