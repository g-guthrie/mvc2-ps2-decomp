#include "runtime_decode_descriptor.h"
typedef signed int s32;
typedef unsigned int u32;
extern void func_004095C8(void);
extern s32 D_00495BB4;
extern s32 D_00495BB0;
extern s32 func_00404438(RuntimeDecodeDescriptor *, const void *, s32, short *, short *);
extern s32 func_00404468(RuntimeDecodeDescriptor *);

void func_00410B88(void) {
    volatile s32 *unused = &D_00495BB0;
    s32 n = D_00495BB4;
    s32 x = *unused;
    if (n == 0) { func_004095C8(); n = D_00495BB4; }
    D_00495BB4 = n + 1;
}
s32 func_003F8490(s32 *p, s32 idx) {
    struct Input { const void *input; s32 pad[4]; short *output; s32 pad2; s32 stride, start; };
    struct Input *q = (struct Input *)(p + 18);
    RuntimeDecodeDescriptor *h = *(RuntimeDecodeDescriptor **)(p + 2);
    short *a = q->output + q->start;
    func_00404438(h, q->input, idx * 2, a, a + q->stride);
    return func_00404468(h);
}
