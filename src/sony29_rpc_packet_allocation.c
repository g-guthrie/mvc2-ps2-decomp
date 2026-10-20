/* Complete native RPC packet-slot allocator. Packet headers follow the
 * public SIF RPC layout; the backing pool uses native 64-byte slots. */
typedef unsigned char u8;
typedef unsigned int u32;
#include "sony29_rpc_packet_header.h"
typedef SonyRpcHeader RpcHeader;
typedef SonyRpcPacketPool PacketPool;
extern int func_0010CA20(void);
extern void func_0010CA68(void);
RpcHeader *func_001067F0(PacketPool *pool)
{
 RpcHeader *packet;
 int index;
 u32 id;
 func_0010CA20();
 packet=(RpcHeader *)pool->buffer;
 for(index=0;index<pool->count;index++,packet=(RpcHeader *)((u8 *)packet+64)){
  if(!(packet->rec_id&1)){
   packet->rec_id=((u32)index<<16)|5;
   if(++pool->counter==1)id=pool->counter++;
   else id=pool->counter;
   packet->pkt_addr=packet;
   packet->rpc_id=id;
   func_0010CA68();
   return packet;
  }
 }
 func_0010CA68();
 return 0;
}
