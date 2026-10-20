/* SIF RPC reply completion: the command dispatcher passes data and context.
 * Protocol layouts follow the Sony-compatible public PS2SDK SIF RPC headers. */
typedef unsigned int u32;
#include "sony29_rpc_packet_header.h"
typedef SonyRpcHeader RpcHeader;
typedef SonyRpcClient RpcClient;
typedef struct {RpcHeader header;RpcClient *client;u32 command;void *server,*buffer,*callback_buffer;} Reply;
extern int func_00103E10(int);
void func_00106928(void *data,void *context)
{
 Reply *reply=data;
 RpcClient *client;
 switch(reply->command){
 case 0x8000000c: break;
 case 0x8000000a:
  client=reply->client;
  if(client->end_function)client->end_function(client->end_parameter);
  break;
 case 0x80000009:
  client=reply->client;
  client->server=reply->server;
  client->buffer=reply->buffer;
  client->callback_buffer=reply->callback_buffer;
  break;
 }
 client=reply->client;
 if(client->receive.semaphore>=0)func_00103E10(client->receive.semaphore);
 func_00106898(client->receive.packet);
 client->receive.packet=0;
}
