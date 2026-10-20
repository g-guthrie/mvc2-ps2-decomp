#include "sony29_rpc_packet_header.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

u8 *func_001068E8(u8 *p, s32 i)
{
    extern u8 *func_001068B8(SonyRpcPacketPool *);
    u8 *r;
    if (i < 0 || i >= *(s32 *)(p + 0x20)) {
        r = func_001068B8((SonyRpcPacketPool *)p);
    } else {
        r = (u8 *)(*(s32 *)(p + 0x1C) + (i << 6));
    }
    return r;
}
