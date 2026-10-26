#include "sony29_rpc_packet_header.h"

/* A receive is busy only while its packet still belongs to this RPC. */
int func_00107058(void *arg)
{
    SonyRpcReceive *receive = (SonyRpcReceive *)arg;
    SonyRpcHeader *packet = (SonyRpcHeader *)receive->packet;
    if (packet == 0 || receive->rpc_id != packet->rpc_id || !(packet->rec_id & 1))
        return 0;
    return 1;
}
