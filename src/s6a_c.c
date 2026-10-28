/* func_00106E68: Sony EE GCC 2.9, ./trysony29.sh src/s6a_c.c 0 O2 "-fno-strict-aliasing" (exact). Volatile stores of the client end_parameter/packet/end_function fields keep retail store order. */
/* Native SIF RPC call request (SifCallRpc layout from the public SIF RPC ABI). */
#include "sony29_rpc_packet_header.h"
typedef unsigned int u32;
typedef struct {int current,limit,initial,waiters;u32 attributes,option;} SemaParams;
typedef SonyRpcClient Client;
typedef struct {SonyRpcHeader header;Client *client;int rpc_number;int send_size;void *receive;int recv_size;int rmode;void *server;} Call;
extern SonyRpcPacketPool D_004C5480;
extern int func_00103DE0(SemaParams *);
extern int func_00103DF0(int),func_00103E20(int);
extern u32 func_001063D0(u32,void *,int,void *,void *,int);
extern void func_00106578(void *,int);
int func_00106E68(Client *client,int rpc_number,int mode,void *send,int ssize,void *receive,int rsize,void (*end_function)(void *),void *end_parameter)
{
 SemaParams sema;
 Call *packet=(Call *)func_001067F0(&D_004C5480);
 if(!packet)return -1;
 client->receive.rpc_id=packet->header.rpc_id;
 *(void * volatile *)&client->end_parameter=end_parameter;
 *(void * volatile *)&client->receive.packet=&packet->header;
 *(void (* volatile *)(void *))&client->end_function=end_function;
 packet->rpc_number=rpc_number;
 packet->send_size=ssize;
 packet->receive=receive;
 packet->recv_size=rsize;
 packet->header.pkt_addr=packet;
 packet->server=client->server;
 packet->client=client;
 if(!(mode&2)){
  if(send==receive){
   func_00106578(send,ssize<rsize?rsize:ssize);
  }else{
   if(ssize>0)func_00106578(send,ssize);
   if(rsize>0)func_00106578(receive,rsize);
  }
 }
 if(mode&1){
  if(!end_function)packet->rmode=0;else packet->rmode=1;
  client->receive.semaphore=-1;
  if(func_001063D0(0x8000000a,packet,64,send,client->buffer,ssize))return 0;
  func_00106898(&packet->header);return -2;
 }
 sema.limit=1;sema.initial=0;
 client->receive.semaphore=func_00103DE0(&sema);
 if(client->receive.semaphore<0){func_00106898(&packet->header);return -3;}
 packet->rmode=1;
 if(!func_001063D0(0x8000000a,packet,64,send,client->buffer,ssize)){
  func_00103DF0(client->receive.semaphore);func_00106898(&packet->header);return -2;
 }
 func_00103E20(client->receive.semaphore);func_00103DF0(client->receive.semaphore);
 return 0;
}
