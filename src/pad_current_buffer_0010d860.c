/* Synchronize both pad buffers and select the newer signed sequence value. */
typedef unsigned char u8;
typedef signed int s32;
#include "sony_pad_slot.h"

extern void func_001046D8(void *first, void *last);
u8 *func_0010D860(s32 port, s32 slot) {
    u8 *buffer;
    s32 offset;
    buffer = D_004C83D0[port][slot].buffer;
    func_001046D8(buffer, buffer + 0x100);
    offset = 0;
    if (*(s32 *)(buffer + 0x58) < *(s32 *)(buffer + 0xD8)) {
        offset = 0x80;
    }
    return buffer + offset;
}
