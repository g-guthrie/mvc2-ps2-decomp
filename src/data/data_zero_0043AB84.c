#include "sony29_rpc_packet_header.h"
typedef unsigned char u8;
/* CD/DVD command RPC buffers and client (src/sony29_*). The block runs from the end of the
 * 4-byte status word data_rpc_response_0043AB80 to data_u32_0043B3F0, and its interior is
 * split by the two addresses the code references:
 * - +0x000: rest of the 64-byte-aligned receive buffer D_0043AB80. func_0010FC98 receives 16
 *   bytes there and copies the 8-byte clock reply from D_0043AB80 + 4; the remaining bytes up
 *   to the send buffer have no reader.
 * - +0x43C (D_0043AFC0): 64-byte-aligned send buffer; func_0010F8A0 stores the command word
 *   (sw), passes it to func_00106578 with size 4 and sends it with RPC function 0x22.
 * - +0x844 (D_0043B3C8): the SonyRpcClient bound by func_0010F258 (func_00106C98; func_0010F1E8 polls it) and passed to
 *   every func_00106E68 call of these readers (func_0010F8A0, func_0010FB48, func_0010FBE0,
 *   func_0010FC98). */
typedef struct {
    u8 receiveTail[0x43C];
    int send[0x102];
    SonyRpcClient client;
} CdvdCommandRpc;
typedef char SonyRpcClient_size_check[(sizeof(SonyRpcClient) == 0x28) ? 1 : -1];
typedef char CdvdCommandRpc_size_check[(sizeof(CdvdCommandRpc) == 0x86C) ? 1 : -1];
CdvdCommandRpc data_zero_0043AB84 = { { 0 } };
