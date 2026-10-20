#include "sony29_rpc_packet_header.h"

void func_00106898(SonyRpcHeader *packet)
{
    packet->rpc_id = 0;
    packet->rec_id &= 0xFFFFFFFEu;
}
