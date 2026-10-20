/* Native SIF RPC bind and other-data requests. SIF packet/client fields
 * and NOWAIT semantics are corroborated by the public SIF RPC ABI. */
#include "sony29_rpc_packet_header.h"
typedef unsigned int u32;
typedef struct {int current,limit,initial,waiters;u32 attributes,option;} SemaParams;
typedef SonyRpcReceive Receive;
typedef SonyRpcClient Client;
typedef struct {SonyRpcHeader header;Receive *receive;void *source,*destination;int size;} OtherData;
typedef struct {SonyRpcHeader header;Client *client;int sid;} Bind;
extern SonyRpcPacketPool D_004C5480;
extern int func_00103DE0(SemaParams *);
extern int func_00103DF0(int),func_00103E20(int);
extern u32 func_001063D0(u32,void *,int,void *,void *,int);
int func_00106A40(Receive *receive,void *source,void *destination,int size,int mode)
{
 OtherData *packet=(OtherData *)func_001067F0(&D_004C5480);
 SemaParams sema;
 if(!packet)return -1;
 receive->packet=&packet->header;
 receive->rpc_id=packet->header.rpc_id;
 packet->source=source;
 packet->destination=destination;
 packet->size=size;
 packet->header.pkt_addr=packet;
 packet->receive=receive;
 if(!(mode&1)){
  sema.limit=1;sema.initial=0;
  receive->semaphore=func_00103DE0(&sema);
  if(receive->semaphore<0){func_00106898(&packet->header);return -3;}
  if(!func_001063D0(0x8000000c,packet,64,0,0,0)){
   func_00106898(&packet->header);func_00103DF0(receive->semaphore);return -2;
  }
  func_00103E20(receive->semaphore);func_00103DF0(receive->semaphore);
 }else{
  receive->semaphore=-1;
  if(!func_001063D0(0x8000000c,packet,64,0,0,0)){
   func_00106898(&packet->header);return -2;
  }
 }
 return 0;
}
int func_00106C98(Client *client,int sid,int mode)
{
 Bind *packet;
 SemaParams sema;
 client->command=0;client->server=0;
 packet=(Bind *)func_001067F0(&D_004C5480);
 if(!packet)return -1;
 client->receive.packet=&packet->header;
 client->receive.rpc_id=packet->header.rpc_id;
 packet->sid=sid;
 packet->header.pkt_addr=packet;
 packet->client=client;
 if(!(mode&1)){
  sema.limit=1;sema.initial=0;
  client->receive.semaphore=func_00103DE0(&sema);
  if(client->receive.semaphore<0){func_00106898(&packet->header);return -3;}
  if(!func_001063D0(0x80000009,packet,64,0,0,0)){
   func_00106898(&packet->header);func_00103DF0(client->receive.semaphore);return -2;
  }
  func_00103E20(client->receive.semaphore);func_00103DF0(client->receive.semaphore);
 }else{
  client->receive.semaphore=-1;
  if(!func_001063D0(0x80000009,packet,64,0,0,0)){
   func_00106898(&packet->header);return -2;
  }
 }
 return 0;
}
