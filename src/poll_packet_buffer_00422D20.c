typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

#include "sony29_rpc_packet_header.h"
extern s32 func_00422C20(s32 request);

s32 func_00422D20(volatile u8 *buffer, u32 tag)
{
    s32 status;
    s32 retries = 1024;

    do {
        status = func_00106C98((SonyRpcClient *)(void *)buffer, tag, 0);
        if (status < 0)
            return -1;
        if (*(volatile s32 *)(buffer + 36) != 0)
            break;
        status = func_00422C20(1);
        if (status < 0)
            return -1;
        retries--;
    } while (retries > 0);
    return 0;
}
