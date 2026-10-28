#include "sony29_rpc_server_types.h"
typedef unsigned char u8;
typedef signed int s32;
/* EE-side SIF RPC state of the DMA-slot service (code 0x00408F88..0x00409810):
 * - +0x000: 0x220 bytes with no reader found (directly after the 8-slot DMA table
 *   data_rec_00487B60); kept as bytes.
 * - +0x220 (D_00487FA0): SonyRpcClient bound by func_004095C8 (func_00106C98, polls ->server)
 *   and used for the calls in func_004090D8/func_00409148/func_00409708 (func_00106E68).
 * - +0x248 (D_00487FC8): SonyRpcServer registered by func_00409058 (func_00107130) with
 *   dispatcher func_00408F88 and receive buffer D_00488010.
 * - +0x290 (D_00488010): the server's receive buffer; func_00408F88 reads its s32 words.
 * - +0x390 (D_00488110): 0x40 handlers for commands 0x400..0x43F, called by func_00408F88
 *   as D_00488110[c - 0x400](D_00488210[c - 0x400], buffer, size >> 2).
 * - +0x490 (D_00488210): the matching 0x40 handler arguments. */
typedef void (*SdkRpcHandler)(s32 argument, s32 *buffer, unsigned int words);
typedef struct {
    u8 unreferenced_000[0x220];
    SonyRpcClient client;
    SonyRpcServer server;
    u8 pad_28C[4];
    s32 serverBuffer[0x40];
    SdkRpcHandler handlers[0x40];
    s32 handlerArguments[0x40];
} SdkRpcState;
typedef char SonyRpcClient_size_check[(sizeof(SonyRpcClient) == 0x28) ? 1 : -1];
typedef char SonyRpcServer_size_check[(sizeof(SonyRpcServer) == 0x44) ? 1 : -1];
typedef char SdkRpcState_size_check[(sizeof(SdkRpcState) == 0x590) ? 1 : -1];
SdkRpcState data_raw_00487D80 = { { 0 } };
