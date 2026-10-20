/* Synchronize both pad buffers and select the newer signed sequence value. */
typedef unsigned char u8;
typedef signed int s32;
typedef struct BufferSlot {
    u8 *buffer;
    u8 *command;
    s32 reserved0;
    s32 reserved1;
    s32 enabled;
    s32 tail0;
    s32 tail1;
} BufferSlot;
extern BufferSlot D_004C83D0[][4];
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
